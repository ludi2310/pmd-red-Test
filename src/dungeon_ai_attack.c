#include "global.h"
#include "dungeon_ai_attack.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "charge_move.h"
#include "dungeon_action.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "move_util.h"
#include "moves.h"
#include "move_checks.h"
#include "position_util.h"
#include "status_checks.h"
#include "status_checks_1.h"
#include "targeting.h"
#include "targeting_flags.h"
#include "type_effectiveness.h"

#define REGULAR_ATTACK_INDEX 4

const s16 gRegularAttackWeights[] = {100, 20, 30, 40, 50};

extern bool8 gCanAttackInDirection[NUM_DIRECTIONS];
extern s32 gNumPotentialTargets;
extern s32 gPotentialAttackTargetWeights[NUM_DIRECTIONS];
extern u8 gPotentialAttackTargetDirections[NUM_DIRECTIONS];
extern struct Entity *gPotentialTargets[NUM_DIRECTIONS];

extern void sub_8055A00(struct Entity *, u8, u32, u32, u32);
extern void sub_806A9B4(struct Entity *, u8);
extern bool8 sub_8044B28(void);
extern void sub_8057588(struct Entity *, u32);
extern void sub_806A1B0(struct Entity *);


void DecideAttack(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    s32 i;
    s32 chargeStatus = STATUS_CHARGING;
    struct AIPossibleMove aiPossibleMove[MAX_MON_MOVES + 1];
    bool8 willNotUnlinkMove[MAX_MON_MOVES];
    s32 randomWeight;
    bool8 hasPPChecker;
    s32 numUsableMoves;
    s32 total;
    s32 weightCounter;
    bool8 hasWeakTypePicker;
    s32 regularAttackTargetDir;
    bool8 canTargetRegularAttack;
    s32 maxWeight;
    if (CannotAttack(pokemon, FALSE) ||
        ShouldMonsterRunAwayAndShowEffect(pokemon, TRUE) ||
        HasTactic(pokemon, TACTIC_KEEP_YOUR_DISTANCE) ||
        (pokemonInfo->volatileStatus == STATUS_CONFUSED && DungeonRandOutcome(gConfusedAttackChance)))
    {
        return;
    }
    if (pokemonInfo->chargingStatus != STATUS_NONE)
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (pokemonInfo->moves[i].moveFlags & MOVE_FLAG_EXISTS &&
                MoveMatchesChargingStatus(pokemon, &pokemonInfo->moves[i]) &&
                pokemonInfo->chargingStatusMoveIndex == i)
            {
                s32 chosenMoveIndex;
                SetMonsterActionFields(&pokemonInfo->action, ACTION_USE_MOVE_AI);
                chosenMoveIndex = i;
                if (i > 0 && pokemonInfo->moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)
                {
                    while (--chosenMoveIndex > 0)
                    {
                        if (!(pokemonInfo->moves[chosenMoveIndex].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
                        {
                            break;
                        }
                    }
                }
                pokemonInfo->action.actionUseIndex = chosenMoveIndex;
                TargetTileInFront(pokemon);
                return;
            }
        }
    }
    total = 0;
    numUsableMoves = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        struct Move *move = &pokemonInfo->moves[i];
        if (pokemonInfo->moves[i].moveFlags & MOVE_FLAG_EXISTS)
        {
            if (pokemonInfo->moves[i].moveFlags & MOVE_FLAG_ENABLED_FOR_AI)
            {
                numUsableMoves++;
            }
            total += move->PP;
        }
    }
    if (total == 0)
    {
        struct Move struggle;
        InitPokemonMove(&struggle, MOVE_STRUGGLE);
        AIConsiderMove(&aiPossibleMove[0], pokemon, &struggle);
        if (aiPossibleMove[0].canBeUsed)
        {
            SetMonsterActionFields(&pokemonInfo->action, ACTION_STRUGGLE);
            pokemonInfo->action.direction = aiPossibleMove[0].direction & DIRECTION_MASK;
            TargetTileInFront(pokemon);
        }
        return;
    }
    hasWeakTypePicker = IQSkillIsEnabled(pokemon, IQ_WEAK_TYPE_PICKER);
    hasPPChecker = IQSkillIsEnabled(pokemon, IQ_PP_CHECKER) != FALSE;
    total = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        willNotUnlinkMove[i] = TRUE;
    }
    if (hasPPChecker)
    {
        s32 minPP = 99;
        s32 linkedMoveStartIndex = 0;
        // Linked moves unlink if any move in the chain runs out of PP.
        // With PP Checker, the AI avoids this by not using linked moves if any move in the chain has 1 PP left.
        // This requires a separate check from the 0-PP check used for unlinked moves.
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            struct Move *move = &pokemonInfo->moves[i];
            if (!(move->moveFlags & MOVE_FLAG_EXISTS))
            {
                break;
            }
            if (i != 0 && !(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            {
                if (linkedMoveStartIndex + 1 < i && minPP <= 1 && linkedMoveStartIndex + 1 <= i)
                {
                    s32 j;
                    for (j = linkedMoveStartIndex; j < i; j++)
                    {
                        willNotUnlinkMove[j] = FALSE;
                    }
                }
                minPP = move->PP;
                linkedMoveStartIndex = i;
            }
            else
            {
                s32 newMinPP = move->PP;
                if (newMinPP > minPP)
                {
                    newMinPP = minPP;
                }
                minPP = newMinPP;
            }
        }
        if (linkedMoveStartIndex + 1 < i && minPP <= 1 && linkedMoveStartIndex + 1 <= i)
        {
            s32 j;
            for (j = linkedMoveStartIndex; j < i; j++)
            {
                willNotUnlinkMove[j] = FALSE;
            }
        }
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        struct Move *move;
        aiPossibleMove[i].canBeUsed = FALSE;
        move = &pokemonInfo->moves[i];
        if (move->moveFlags & MOVE_FLAG_EXISTS &&
            willNotUnlinkMove[i] &&
            CanAIUseMove(pokemon, i, hasPPChecker) &&
            move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI)
        {
            aiPossibleMove[i].canBeUsed = TRUE;
            if (pokemonInfo->chargingStatus == chargeStatus)
            {
                if (move->id == MOVE_CHARGE)
                {
                    aiPossibleMove[i].weight = 0;
                    continue;
                }
                else if (GetMoveTypeForMonster(pokemon, move) == TYPE_ELECTRIC)
                {
                    aiPossibleMove[i].weight = GetMoveAIWeight(move);
                }
                else
                {
                    aiPossibleMove[i].weight = 1;
                }
            }
            else if (hasWeakTypePicker)
            {
                struct AIPossibleMove *results = &aiPossibleMove[i];
                results->weight = AIConsiderMove(results, pokemon, move);
            }
            else
            {
                aiPossibleMove[i].weight = GetMoveAIWeight(move);
            }
            total += aiPossibleMove[i].weight;
        }
    }
    aiPossibleMove[REGULAR_ATTACK_INDEX].weight = 0;
    if (!IQSkillIsEnabled(pokemon, IQ_EXCLUSIVE_MOVE_USER) && pokemonInfo->chargingStatus != chargeStatus)
    {
        aiPossibleMove[REGULAR_ATTACK_INDEX].canBeUsed = TRUE;
        if (pokemonInfo->chargingStatus == chargeStatus)
        {
            // Never reached? Charge already skips the regular attack in the outer block.
            aiPossibleMove[REGULAR_ATTACK_INDEX].weight = 1;
        }
        else if (hasWeakTypePicker)
        {
            aiPossibleMove[REGULAR_ATTACK_INDEX].weight = 2;
        }
        else
        {
            aiPossibleMove[REGULAR_ATTACK_INDEX].weight = gRegularAttackWeights[numUsableMoves];
        }
        total += aiPossibleMove[REGULAR_ATTACK_INDEX].weight;
    }
    if (hasWeakTypePicker)
    {
        s32 i;
        maxWeight = 0;
        total = 0;
        for (i = 0; i < MAX_MON_MOVES + 1; i++)
        {
            if (!aiPossibleMove[i].canBeUsed)
            {
                aiPossibleMove[i].weight = 0;
            }
            else if (maxWeight < aiPossibleMove[i].weight)
            {
                maxWeight = aiPossibleMove[i].weight;
            }
        }
        for (i = 0; i < MAX_MON_MOVES + 1; i++)
        {
            if (aiPossibleMove[i].canBeUsed)
            {
                if (maxWeight != aiPossibleMove[i].weight)
                {
                    // Only the move(s) with the highest weight can be used, instead of a weighted random.
                    // This has the side effect of making the AI use a STAB ranged move consistently when at a distance.
                    aiPossibleMove[i].weight = 0;
                }
                total += aiPossibleMove[i].weight;
            }
        }
    }
    if (total == 0)
    {
        return;
    }
    randomWeight = DungeonRandInt(total);
    weightCounter = 0;
    if (!IQSkillIsEnabled(pokemon, IQ_EXCLUSIVE_MOVE_USER))
    {
        canTargetRegularAttack = TargetRegularAttack(pokemon, &regularAttackTargetDir, TRUE);
    }
    else
    {
        canTargetRegularAttack = FALSE;
        regularAttackTargetDir = DIRECTION_SOUTH;
    }
    for (i = 0; i <= REGULAR_ATTACK_INDEX; i++)
    {
        if (aiPossibleMove[i].canBeUsed && aiPossibleMove[i].weight != 0)
        {
            weightCounter += aiPossibleMove[i].weight;
            if (weightCounter >= randomWeight)
            {
                if (i == REGULAR_ATTACK_INDEX)
                {
                    if (canTargetRegularAttack)
                    {
                        SetMonsterActionFields(&pokemonInfo->action, ACTION_REGULAR_ATTACK);
                        pokemonInfo->action.direction = regularAttackTargetDir & DIRECTION_MASK;
                        TargetTileInFront(pokemon);
                    }
                }
                else
                {
                    AIConsiderMove(&aiPossibleMove[i], pokemon, &pokemonInfo->moves[i]);
                    if (aiPossibleMove[i].canBeUsed)
                    {
                        s32 chosenMoveIndex;
                        SetMonsterActionFields(&pokemonInfo->action, ACTION_USE_MOVE_AI);
                        chosenMoveIndex = i;
                        if (i > 0 && pokemonInfo->moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)
                        {
                            while (--chosenMoveIndex > 0)
                            {
                                if (!(pokemonInfo->moves[chosenMoveIndex].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
                                {
                                    break;
                                }
                            }
                        }
                        pokemonInfo->action.direction = aiPossibleMove[i].direction & DIRECTION_MASK;
                        pokemonInfo->action.actionUseIndex = chosenMoveIndex;
                        TargetTileInFront(pokemon);
                    }
                    else
                    {
                        break;
                    }
                }
                return;
            }
        }
    }
    if (canTargetRegularAttack)
    {
        SetMonsterActionFields(&pokemonInfo->action, ACTION_REGULAR_ATTACK);
        pokemonInfo->action.direction = regularAttackTargetDir & DIRECTION_MASK;
        TargetTileInFront(pokemon);
    }
}

s32 AIConsiderMove(struct AIPossibleMove *aiPossibleMove, struct Entity *pokemon, struct Move *move)
{
    s32 targetingFlags;
    s32 moveWeight = 1;
    struct EntityInfo *pokemonInfo = pokemon->info;
    s32 numPotentialTargets = 0;
    s32 i;
    bool8 hasStatusChecker;
    s32 rangeTargetingFlags;
    s32 rangeTargetingFlags2;
    for (i = 0; i < NUM_DIRECTIONS; i++)
    {
        gCanAttackInDirection[i] = FALSE;
    }
    targetingFlags = GetMoveTargetAndRangeForPokemon(pokemon, move, TRUE);
    hasStatusChecker = IQSkillIsEnabled(pokemon, IQ_STATUS_CHECKER);
    aiPossibleMove->canBeUsed = FALSE;
    if ((pokemonInfo->volatileStatus == STATUS_TAUNTED && !MovesIgnoresTaunted(move)) ||
        (hasStatusChecker && !CanUseOnSelfWithStatusChecker(pokemon, move)))
    {
        return 1;
    }
    rangeTargetingFlags = targetingFlags & 0xF0;
    if (rangeTargetingFlags == TARGETING_FLAG_TARGET_OTHER ||
        rangeTargetingFlags == TARGETING_FLAG_TARGET_FRONTAL_CONE ||
        rangeTargetingFlags == TARGETING_FLAG_TARGET_AROUND)
    {
        if (pokemonInfo->eyesightStatus == STATUS_BLINKER)
        {
            u8 direction = pokemonInfo->action.direction;
            i = direction; // Fixes a regswap.
            if (!gCanAttackInDirection[i])
            {
                gCanAttackInDirection[i] = TRUE;
                gPotentialAttackTargetDirections[numPotentialTargets] = i;
                gPotentialAttackTargetWeights[numPotentialTargets] = 99;
                gPotentialTargets[numPotentialTargets] = NULL;
                numPotentialTargets++;
            }
        }
        else
        {
            for (i = 0; i < NUM_DIRECTIONS; i++)
            {
                // Double assignment to fix a regswap.
                s16 rangeTargetingFlags = rangeTargetingFlags2 = targetingFlags & 0xF0;
                struct Tile *adjacentTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[i].x,
                    pokemon->pos.y + gAdjacentTileOffsets[i].y);
                struct Entity *adjacentPokemon = adjacentTile->monster;
                if (adjacentPokemon != NULL && GetEntityType(adjacentPokemon) == ENTITY_MONSTER)
                {
                    if (rangeTargetingFlags != TARGETING_FLAG_TARGET_FRONTAL_CONE &&
                        rangeTargetingFlags != TARGETING_FLAG_TARGET_AROUND)
                    {
                        if (!CanAttackInDirection(pokemon, i))
                        {
                            continue;
                        }
                    }
                    numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, adjacentPokemon, move, hasStatusChecker);
                }
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_ROOM)
    {
        s32 i;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
        {
            struct Entity *target = gDungeon->allPokemon[i];
            if (EntityExists(target) && CanSeeTarget(pokemon, target))
            {
                numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, target, move, hasStatusChecker);
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_2_TILES_AHEAD)
    {
        for (i = 0; i < NUM_DIRECTIONS; i++)
        {
            struct Tile *targetTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[i].x,
                pokemon->pos.y + gAdjacentTileOffsets[i].y);
            if (CanAttackInDirection(pokemon, i))
            {
                struct Entity *targetPokemon = targetTile->monster;
                if (targetPokemon != NULL && GetEntityType(targetPokemon) == ENTITY_MONSTER)
                {
                    s32 prevNumPotentialTargets = numPotentialTargets;
                    numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, targetPokemon, move, hasStatusChecker);
                    if (prevNumPotentialTargets != numPotentialTargets)
                    {
                        continue;
                    }
                }
                targetTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[i].x * 2,
                    pokemon->pos.y + gAdjacentTileOffsets[i].y * 2);
                targetPokemon = targetTile->monster;
                if (targetPokemon != NULL && GetEntityType(targetPokemon) == ENTITY_MONSTER)
                {
                    numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, targetPokemon, move, hasStatusChecker);
                }
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_LINE || rangeTargetingFlags == TARGETING_FLAG_CUT_CORNERS)
    {
        s32 maxRange = 1;
        s32 i;
        if (rangeTargetingFlags == TARGETING_FLAG_TARGET_LINE)
        {
            maxRange = 10;
        }
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
        {
            struct Entity *target = gDungeon->allPokemon[i];
            if (EntityExists(target) && pokemon != target)
            {
                s32 direction = GetDirectionTowardsPosition(&pokemon->pos, &target->pos);
                if (!gCanAttackInDirection[direction] &&
                    CanSeeTarget(pokemon, target) &&
                    IsTargetInLineRange(pokemon, target, maxRange) &&
                    IsAITargetEligible(targetingFlags, pokemon, target, move, hasStatusChecker) &&
                    IsTargetInRange(pokemon, target, direction, maxRange))
                {
                    gCanAttackInDirection[direction] = TRUE;
                    gPotentialAttackTargetDirections[numPotentialTargets] = direction;
                    gPotentialAttackTargetWeights[numPotentialTargets] = WeightMove(pokemon, targetingFlags, target, GetMoveTypeForMonster(pokemon, move));
                    gPotentialTargets[numPotentialTargets] = target;
                    numPotentialTargets++;
                }
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_FLOOR)
    {
        s32 i;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
        {
            struct Entity *target = gDungeon->allPokemon[i];
            if (EntityExists(target))
            {
                numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, target, move, hasStatusChecker);
            }
        }
    }
    else if (rangeTargetingFlags == TARGETING_FLAG_TARGET_SELF)
    {
        numPotentialTargets = TryAddTargetToAITargetList(numPotentialTargets, targetingFlags, pokemon, pokemon, move, hasStatusChecker);
    }
    if (numPotentialTargets == 0)
    {
        aiPossibleMove->canBeUsed = FALSE;
    }
    else
    {
        s32 totalWeight = 0;
        s32 maxWeight = 0;
        s32 weightCounter;
        s32 i;
        for (i = 0; i < numPotentialTargets; i++)
        {
            if (maxWeight < gPotentialAttackTargetWeights[i])
            {
                maxWeight = gPotentialAttackTargetWeights[i];
            }
        }
        for (i = 0; i < numPotentialTargets; i++)
        {
            if (maxWeight != gPotentialAttackTargetWeights[i])
            {
                gPotentialAttackTargetWeights[i] = 0;
            }
        }
        moveWeight = maxWeight;
        for (i = 0; i < numPotentialTargets; i++)
        {
            totalWeight += gPotentialAttackTargetWeights[i];
        }
        weightCounter = DungeonRandInt(totalWeight);
        for (i = 0; i < numPotentialTargets; i++)
        {
            weightCounter -= gPotentialAttackTargetWeights[i];
            if (weightCounter < 0)
            {
                break;
            }
        }
        aiPossibleMove->canBeUsed = TRUE;
        aiPossibleMove->direction = gPotentialAttackTargetDirections[i];
        aiPossibleMove->weight = 8;
    }
    return moveWeight;
}

bool8 IsTargetInLineRange(struct Entity *user, struct Entity *target, s32 range)
{
    s32 distanceX = user->pos.x - target->pos.x;
    s32 distanceY, distance;
    s32 direction;
    if (distanceX < 0)
    {
        distanceX = -distanceX;
    }
    distanceY = user->pos.y - target->pos.y;
    if (distanceY < 0)
    {
        distanceY = -distanceY;
    }
    distance = distanceY;
    if (distanceY < distanceX)
    {
        distance = distanceX;
    }
    if (distance > RANGED_ATTACK_RANGE || distance > range)
    {
        return FALSE;
    }
    direction = -1;
    if (distanceX == distanceY)
    {
        if (user->pos.x < target->pos.x &&
            (user->pos.y < target->pos.y || user->pos.y > target->pos.y))
        {
            returnTrue:
            return TRUE;
        }
        if (user->pos.x > target->pos.x); // Fixes register loading order.
        direction = DIRECTION_SOUTHWEST;
        if (user->pos.x <= target->pos.x || user->pos.y <= target->pos.y)
        {
            goto checkDirectionSet;
        }
        goto returnTrue;
    }
    else if (user->pos.x == target->pos.x && user->pos.y < target->pos.y)
    {
        return TRUE;
    }
    else if (user->pos.x < target->pos.x && user->pos.y == target->pos.y)
    {
        return TRUE;
    }
    else if (user->pos.x == target->pos.x && user->pos.y > target->pos.y)
    {
        return TRUE;
    }
    else if (user->pos.x > target->pos.x && user->pos.y == target->pos.y)
    {
        direction = DIRECTION_WEST;
    }
    checkDirectionSet:
    if (direction < 0)
    {
        return FALSE;
    }
    return TRUE;
}

s32 TryAddTargetToAITargetList(s32 numPotentialTargets, s32 targetingFlags, struct Entity *user, struct Entity *target, struct Move *move, bool32 hasStatusChecker)
{
    s32 direction;
    s32 targetingFlags2 = (s16) targetingFlags;
    bool8 hasStatusChecker2 = hasStatusChecker;
    struct EntityInfo *userData = user->info;
    if ((user->pos.x == target->pos.x && user->pos.y == target->pos.y) ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_ROOM ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_FLOOR ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_SELF)
    {
        direction = userData->action.direction;
    }
    else
    {
        direction = GetDirectionTowardsPosition(&user->pos, &target->pos);
    }
    if (!gCanAttackInDirection[direction] &&
        IsAITargetEligible(targetingFlags2, user, target, move, hasStatusChecker2))
    {
        gCanAttackInDirection[direction] = TRUE;
        do { gPotentialAttackTargetDirections[numPotentialTargets] = direction; } while (0);
        gPotentialAttackTargetWeights[numPotentialTargets] = WeightMove(user, targetingFlags2, target, GetMoveTypeForMonster(user, move));
        gPotentialTargets[numPotentialTargets] = target;
        numPotentialTargets++;
    }
    return numPotentialTargets;
}

bool8 IsAITargetEligible(s32 targetingFlags, struct Entity *user, struct Entity *target, struct Move *move, bool32 hasStatusChecker)
{
    struct EntityInfo *targetData;
    s32 targetingFlags2 = (s16) targetingFlags;
    bool8 hasStatusChecker2 = hasStatusChecker;
    bool8 hasTarget = FALSE;
    u32 categoryTargetingFlags = targetingFlags2 & 0xF;
    u32 *categoryTargetingFlags2 = &categoryTargetingFlags; // Fixes a regswap.
    if (*categoryTargetingFlags2 == TARGETING_FLAG_TARGET_OTHER)
    {
        if (CanTarget(user, target, FALSE, TRUE) == TARGET_CAPABILITY_CAN_TARGET)
        {
            hasTarget = TRUE;
        }
    }
    else if (categoryTargetingFlags == TARGETING_FLAG_HEAL_TEAM)
    {
        goto checkCanTarget;
    }
    else if (categoryTargetingFlags == TARGETING_FLAG_LONG_RANGE)
    {
        targetData = target->info;
        goto checkThirdParty;
    }
    else if (categoryTargetingFlags == TARGETING_FLAG_ATTACK_ALL)
    {
        targetData = target->info;
        if (user == target)
        {
            goto returnFalse;
        }
        checkThirdParty:
        hasTarget = TRUE;
        if (targetData->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER ||
            targetData->clientType == CLIENT_TYPE_DONT_MOVE ||
            targetData->clientType == CLIENT_TYPE_CLIENT)
        {
            returnFalse:
            return FALSE;
        }
    }
    else if (categoryTargetingFlags == TARGETING_FLAG_BOOST_TEAM)
    {
        if (user == target)
        {
            goto returnFalse;
        }
        checkCanTarget:
        if (CanTarget(user, target, FALSE, TRUE) == TARGET_CAPABILITY_CANNOT_ATTACK)
        {
            hasTarget = TRUE;
        }
    }
    else if ((u16) (categoryTargetingFlags - 3) <= 1) // categoryTargetingFlags == TARGETING_FLAG_ITEM
    {
        hasTarget = TRUE;
    }

    if (hasTarget)
    {
        if (hasStatusChecker2)
        {
            if (!CanUseOnTargetWithStatusChecker(user, target, move))
            {
                goto returnFalse;
            }
            if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_SET_TRAP)
            {
                goto rollMoveUseChance;
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_HEAL_HP)
            {
                if (!HasLowHealth(target))
                {
                    if (*categoryTargetingFlags2);
                    goto returnFalse;
                }
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_HEAL_STATUS)
            {
                if (!HasNegativeStatus(target))
                {
                    if (*categoryTargetingFlags2); // Flips the conditional.
                    goto returnFalse;
                }
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_DREAM_EATER)
            {
                if (!IsSleeping(target))
                {
                    if (*categoryTargetingFlags2); // Flips the conditional.
                    goto returnFalse;
                }
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_EXPOSE)
            {
                targetData = target->info;
                if ((targetData->types[0] != TYPE_GHOST && targetData->types[1] != TYPE_GHOST) || targetData->exposed)
                {
                    if (*categoryTargetingFlags2); // Flips the conditional.
                    goto returnFalse;
                }
            }
            else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_HEAL_ALL)
            {
                if (!HasNegativeStatus(target) && !HasLowHealth(target))
                {
                    if (*categoryTargetingFlags2); // Flips the conditional.
                    goto returnFalse;
                }
            }
        }
        else if ((targetingFlags2 & 0xF00) == TARGETING_FLAG_SET_TRAP)
        {
            s32 useChance;
            rollMoveUseChance:
            useChance = GetMoveAccuracyOrAIChance(move, ACCURACY_AI_CONDITION_RANDOM_CHANCE);
            if (DungeonRandInt(100) >= useChance)
            {
                goto returnFalse;
            }
        }
    }
    return hasTarget;
}

s32 WeightMove(struct Entity *user, s32 targetingFlags, struct Entity *target, u32 moveType)
{
#ifndef NONMATCHING
    register struct EntityInfo *targetData asm("r4");
#else
    struct EntityInfo *targetData;
#endif
    s32 targetingFlags2 = (s16) targetingFlags;
    u8 moveType2 = moveType;
    u8 weight = 1;
    struct EntityInfo *targetData2;
    targetData2 = targetData = target->info;
    if (!targetData->isNotTeamMember || (targetingFlags2 & 0xF) != TARGETING_FLAG_TARGET_OTHER)
    {
        return 1;
    }
    else if (IQSkillIsEnabled(user, IQ_EXP_GO_GETTER))
    {
        // BUG: expYieldRankings has lower values as the Pokémon's experience yield increases.
        // This causes Exp. Go-Getter to prioritize Pokémon worth less experience
        // instead of Pokémon worth more experience.
        weight = gDungeon->expYieldRankings[targetData->id];
    }
    else if (IQSkillIsEnabled(user, IQ_EFFICIENCY_EXPERT))
    {
        weight = -12 - targetData2->HP;
        if (weight == 0)
        {
            weight = 1;
        }
    }
    else if (IQSkillIsEnabled(user, IQ_WEAK_TYPE_PICKER))
    {
       weight = WeightWeakTypePicker(user, target, moveType2) + 1;
    }
    return weight;
}

bool8 TargetRegularAttack(struct Entity *pokemon, u32 *targetDir, bool8 checkPetrified)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    s32 numPotentialTargets = 0;
    s32 direction = pokemonInfo->action.direction;
    s32 faceTurnLimit = pokemonInfo->eyesightStatus == STATUS_BLINKER ? 1 : 8;
    s32 i;
    s32 potentialAttackTargetDirections[NUM_DIRECTIONS];
    s32 potentialAttackTargetWeights[NUM_DIRECTIONS];
    bool8 hasTargetingIQ = IQSkillIsEnabled(pokemon, IQ_EXP_GO_GETTER) || IQSkillIsEnabled(pokemon, IQ_EFFICIENCY_EXPERT);
    bool8 hasStatusChecker = IQSkillIsEnabled(pokemon, IQ_STATUS_CHECKER);
    for (i = 0; i < faceTurnLimit; i++, direction++)
    {
        struct Entity *target;
        direction &= DIRECTION_MASK;
        target = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
            pokemon->pos.y + gAdjacentTileOffsets[direction].y)->monster;
        if (target != NULL &&
            GetEntityType(target) == ENTITY_MONSTER &&
            CanAttackInDirection(pokemon, direction) &&
            CanTarget(pokemon, target, FALSE, checkPetrified) == TARGET_CAPABILITY_CAN_TARGET &&
            (!hasStatusChecker || target->info->immobilizeStatus != STATUS_FROZEN))
        {
            potentialAttackTargetDirections[numPotentialTargets] = direction;
            potentialAttackTargetWeights[numPotentialTargets] = WeightMove(pokemon, TARGETING_FLAG_TARGET_OTHER, target, TYPE_NONE);
            if (!hasTargetingIQ)
            {
                *targetDir = direction;
                return TRUE;
            }
            numPotentialTargets++;
        }
    }
    if (numPotentialTargets == 0)
    {
        return FALSE;
    }
    else
    {
        s32 totalWeight = 0;
        s32 maxWeight = 0;
        s32 weightCounter;
        s32 i;
        for (i = 0; i < numPotentialTargets; i++)
        {
            if (maxWeight < potentialAttackTargetWeights[i])
            {
                maxWeight = potentialAttackTargetWeights[i];
            }
        }
        for (i = 0; i < numPotentialTargets; i++)
        {
            if (maxWeight != potentialAttackTargetWeights[i])
            {
                potentialAttackTargetWeights[i] = 0;
            }
        }
        for (i = 0; i < numPotentialTargets; i++)
        {
            totalWeight += potentialAttackTargetWeights[i];
        }
        weightCounter = DungeonRandInt(totalWeight);
        for (i = 0; i < numPotentialTargets; i++)
        {
            weightCounter -= potentialAttackTargetWeights[i];
            if (weightCounter < 0)
            {
                break;
            }
        }
        *targetDir = potentialAttackTargetDirections[i];
        return TRUE;
    }

}

bool8 IsTargetInRange(struct Entity *pokemon, struct Entity *targetPokemon, s32 direction, s32 maxRange)
{
    s32 distanceX = pokemon->pos.x - targetPokemon->pos.x;
    s32 effectiveMaxRange;
    if (distanceX < 0)
    {
        distanceX = -distanceX;
    }
    effectiveMaxRange = pokemon->pos.y - targetPokemon->pos.y;
    if (effectiveMaxRange < 0)
    {
        effectiveMaxRange = -effectiveMaxRange;
    }
    if (effectiveMaxRange < distanceX)
    {
        effectiveMaxRange = distanceX;
    }
    if (effectiveMaxRange > maxRange)
    {
        effectiveMaxRange = maxRange;
    }
    if (!IQSkillIsEnabled(pokemon, IQ_COURSE_CHECKER))
    {
        // BUG: effectiveMaxRange is already capped at maxRange, so this condition always evaluates to TRUE.
        // The AI also has range checks elsewhere, so this doesn't become an issue in most cases.
        // If the AI has the Long Toss or Pierce statuses and Course Checker is disabled,
        // this incorrect check causes the AI to throw items at targets further than 10 tiles away.
        if (effectiveMaxRange <= maxRange)
        {
            return TRUE;
        }
    }
    else
    {
        s32 currentPosX = pokemon->pos.x;
        s32 currentPosY = pokemon->pos.y;
        s32 adjacentTileOffsetX = gAdjacentTileOffsets[direction].x;
        s32 adjacentTileOffsetY = gAdjacentTileOffsets[direction].y;
        s32 i;
        for (i = 0; i <= effectiveMaxRange; i++)
        {
            struct Tile *mapTile;
            currentPosX += adjacentTileOffsetX;
            currentPosY += adjacentTileOffsetY;
            if (currentPosX <= 0 || currentPosY <= 0 ||
                currentPosX >= DUNGEON_MAX_SIZE_X - 1 || currentPosY >= DUNGEON_MAX_SIZE_Y - 1)
            {
                break;
            }
            while (0); // Extra label needed to swap branch locations in ASM.
            mapTile = GetTile(currentPosX, currentPosY);
            if (!(mapTile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
            {
                break;
            }
            if (mapTile->monster == targetPokemon)
            {
                return TRUE;
            }
            if (mapTile->monster != NULL)
            {
                break;
            }
        }
    }
    return FALSE;
}

void sub_807CABC(struct Entity *target)
{
  struct EntityInfo *entityInfo;
  s32 counter;

  counter = 0; 
  while (1) {
        if(counter >= sub_8070828(target, TRUE)) break;
        entityInfo = target->info;
        sub_8055A00(target,(entityInfo->action).actionUseIndex,1,0,0);
        if(!EntityExists(target)) break;
        if(sub_8044B28()) break;
        if(entityInfo->unk159) break;
        counter++;
  }

  sub_8057588(target,1);
  if (EntityExists(target)) {
    sub_806A9B4(target,(target->info->action).actionUseIndex);
  }
  sub_806A1B0(target);
}
