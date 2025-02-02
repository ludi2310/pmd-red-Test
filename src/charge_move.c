#include "global.h"
#include "charge_move.h"

#include "constants/move_id.h"
#include "constants/status.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "moves.h"

struct MultiTurnChargeMove
{
    u16 moveID;
    u8 chargingStatus;
};

const struct MultiTurnChargeMove gMultiTurnChargeMoves[10] = {
    {MOVE_SOLARBEAM, STATUS_SOLARBEAM},
    {MOVE_SKY_ATTACK, STATUS_SKY_ATTACK},
    {MOVE_RAZOR_WIND, STATUS_RAZOR_WIND},
    {MOVE_FOCUS_PUNCH, STATUS_FOCUS_PUNCH},
    {MOVE_SKULL_BASH, STATUS_SKULL_BASH},
    {MOVE_FLY, STATUS_FLYING},
    {MOVE_BOUNCE, STATUS_BOUNCING},
    {MOVE_DIVE, STATUS_DIVING},
    {MOVE_DIG, STATUS_DIGGING},
    {MOVE_NOTHING, STATUS_NONE}
};

const u32 gMultiTurnChargingStatuses[10] = {
    STATUS_SOLARBEAM,
    STATUS_SKY_ATTACK,
    STATUS_RAZOR_WIND,
    STATUS_FOCUS_PUNCH,
    STATUS_SKULL_BASH,
    STATUS_FLYING,
    STATUS_BOUNCING,
    STATUS_DIVING,
    STATUS_DIGGING,
    STATUS_NONE
};

ALIGNED(4) const char chargingStatusFill[] = "pksdir0";

u32 sub_8057070(struct Move *move)
{
    u32 numberOfChainedHits;
    numberOfChainedHits = GetMoveNumberOfChainedHits(move);
    if(numberOfChainedHits == 0)
        return DungeonRandRange(2, 6);
    else
        return numberOfChainedHits;
}

bool8 MoveCausesPaused(struct Move *move)
{
    if(move->id == MOVE_FRENZY_PLANT) return TRUE;
    if(move->id == MOVE_HYDRO_CANNON) return TRUE;
    if(move->id == MOVE_HYPER_BEAM) return TRUE;
    if(move->id == MOVE_BLAST_BURN) return TRUE;

    return FALSE;
}

bool8 MoveMatchesChargingStatus(struct Entity *pokemon, struct Move *move)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        struct EntityInfo *pokemonInfo = pokemon->info;
        s32 i;
        for (i = 0; i < 100; i++)
        {
            if (gMultiTurnChargeMoves[i].moveID == MOVE_NOTHING)
            {
                return FALSE;
            }
            if (move->id == gMultiTurnChargeMoves[i].moveID &&
                pokemonInfo->chargingStatus == gMultiTurnChargeMoves[i].chargingStatus)
            {
                return TRUE;
            }
        }
        return FALSE;
    }
}

bool8 IsCharging(struct Entity *pokemon, bool8 checkCharge)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        struct EntityInfo *pokemonInfo = pokemon->info;
        int i = 0;
        u8 *chargingStatusPointer = &pokemonInfo->chargingStatus;
        u8 *chargingStatusPointer2;
        u8 chargeStatus = STATUS_CHARGING;
        for (; i < 100; i++)
        {
            u8 currentStatus = gMultiTurnChargingStatuses[i];
            u8 chargingStatus;
            if (currentStatus == STATUS_NONE)
            {
                return FALSE;
            }
            chargingStatus = *chargingStatusPointer;
            chargingStatusPointer2 = &pokemonInfo->chargingStatus;
            if (chargingStatus == currentStatus)
            {
                return TRUE;
            }
        }
        if (checkCharge && *chargingStatusPointer2 == chargeStatus)
        {
            return TRUE;
        }
        return FALSE;
    }
}
