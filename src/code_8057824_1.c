#include "global.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
#include "constants/friend_area.h"
#include "constants/weather.h"
#include "dungeon_global_data.h"
#include "dungeon_entity.h"
#include "dungeon_map_access.h"
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_util_1.h"
#include "friend_area.h"
#include "item.h"
#include "pokemon.h"
#include "position_util.h"

extern u32 gUnknown_202EDC8;
extern u8 gUnknown_202E038[0x50];
extern u8 gAvailablePokemonNames[0x58];
extern u8 gUnknown_202DE58[];

extern s16 gUnknown_80F57CA;
extern s16 gUnknown_80F57D2;
extern s16 gUnknown_80F57D0;
extern s16 gUnknown_80F57CE;

extern u32 gUnknown_8103D8C;
extern u32 gUnknown_8103D98;
extern u32 gUnknown_8103DD8;
extern u32 gUnknown_8103E28;
extern u32 gUnknown_8103BD8;
extern u32 gUnknown_8103C00;
extern u32 gUnknown_8103C3C;
extern u32 gUnknown_8103C74;
extern u32 gUnknown_8103CC4;
extern u32 gUnknown_8103D0C;
extern u32 gUnknown_8103D50;
extern u32 gRayquazaPostStoryPreFightDialogue_6;
extern u32 gRayquazaPostStoryPreFightDialogue_1;
extern u32 gRayquazaPostStoryPreFightDialogue_2;
extern u32 gRayquazaPostStoryPreFightDialogue_3;
extern u32 gRayquazaPostStoryPreFightDialogue_4;
extern u32 gRayquazaPostStoryPreFightDialogue_5;
extern u32 gRayquazaPreFightDialogue_7;
extern u32 gRayquazaReFightDialogue_1;
extern u32 gRayquazaReFightDialogue_2;
extern u32 gRayquazaReFightDialogue_3;
extern u32 gRayquazaReFightDialogue_4;
extern u32 gRayquazaPreFightDialogue_1;
extern u32 gRayquazaPreFightDialogue_2;
extern u32 gRayquazaPreFightDialogue_3;
extern u32 gRayquazaPreFightDialogue_4;
extern u32 gRayquazaPreFightDialogue_5;
extern u32 gRayquazaPreFightDialogue_6;
extern u32 gRayquazaPreFightDialogue_7;
extern u32 gRayquazaPreFightDialogue_8;
extern u32 gRayquazaPreFightDialogue_9;
extern u32 gRayquazaPreFightDialogue_10;
extern u32 gRayquazaPreFightDialogue_11;
extern u32 MagmaCavernMidDialogue_5;
extern u32 MagmaCavernMidDialogue_6;
extern u32 MagmaCavernMidDialogue_7;
extern u32 MagmaCavernMidDialogue_8;
extern u32 MagmaCavernMidDialogue_9;
extern u32 MagmaCavernMidDialogue_10;
extern u32 MagmaCavernMidDialogue_11;
extern u32 MagmaCavernMidDialogue_12;
extern u32 MagmaCavernMidDialogue_13;
extern u32 MagmaCavernMidDialogue_14;
extern u32 MagmaCavernMidDialogue_15;
extern u32 MagmaCavernMidDialogue_4;
extern u32 MagmaCavernMidDialogue_3;
extern u32 MagmaCavernMidDialogue_2;
extern u32 MagmaCavernMidDialogue_1;
extern u32 gUnknown_8103488;
extern u32 gGroudonPostStoryPreFightDialogue_1;
extern u32 gGroudonPostStoryPreFightDialogue_2;
extern u32 gGroudonPostStoryPreFightDialogue_3;
extern u32 gGroudonPostStoryPreFightDialogue_4;
extern u32 gGroudonReFightDialogue_1;
extern u32 gGroudonReFightDialogue_2;
extern u32 gGroudonReFightDialogue_3;
extern u32 gGroudonReFightDialogue_4;
extern u32 GroudonPreFightDialogue_1;
extern u32 GroudonPreFightDialogue_2;
extern u32 GroudonPreFightDialogue_3;
extern u32 GroudonPreFightDialogue_4;
extern u32 GroudonPreFightDialogue_5;
extern u32 GroudonPreFightDialogue_6;
extern u32 GroudonPreFightDialogue_7;
extern u32 GroudonPreFightDialogue_8;
extern u32 GroudonPreFightDialogue_9;
extern u32 GroudonPreFightDialogue_10;
extern u32 GroudonPreFightDialogue_11;
extern u32 GroudonPreFightDialogue_12;
extern u32 GroudonPreFightDialogue_13;
extern u32 GroudonPreFightDialogue_14;
extern u32 gUnknown_8102B10;
extern u32 gRegisteelPostFightDialogue_2;
extern u32 gRegicePostFightDialogue_2;
extern u32 gRegirockPostFightDialogue_2;
extern u32 gRegisteelPostFightDialogue_1;
extern u32 gRegicePostFightDialogue_1;
extern u32 gRegirockPostFightDialogue_1;
extern u32 gUnknown_810554C;
extern u32 gUnknown_8105558;
extern u32 gUnknown_81055F4;
extern u32 gRegicePreFightDialogue_1;
extern u32 gRegirockPreFightDialogue_1;
extern u32 gSuicuneReFightDialogue_1;
extern u32 gSuicuneReFightDialogue_2;
extern u32 gSuicuneReFightDialogue_3;
extern u32 gRegisteelPreFightDialogue_1;
extern u32 gJirachiPreFightDialogue_1;
extern u32 gJirachiPreFightDialogue_2;
extern u32 gJirachiPreFightDialogue_3;
extern u32 gJirachiPreFightDialogue_4;
extern u32 gLatiosReFightDialogue_1;
extern u32 gLatiosPreFightDialogue_2;
extern u32 gLatiosPreFightDialogue_3;
extern u32 gLatiosPreFightDialogue_1;
extern u32 HoOhReFightDialogue_1;
extern u32 HoOhReFightDialogue_2;
extern u32 HoOhReFightDialogue_3;
extern u32 HoOhReFightDialogue_4;
extern u32 HoOhReFightDialogue_5;
extern u32 gHoOhPreFightDialogue_1;
extern u32 gHoOhPreFightDialogue_2;
extern u32 gHoOhPreFightDialogue_3;
extern u32 gHoOhPreFightDialogue_4;
extern u32 gHoOhPreFightDialogue_5;
extern u32 gHoOhPreFightDialogue_6;
extern u32 gSuicunePostStoryPreFightDialogue_4;
extern u32 gSuicunePostStoryPreFightDialogue_1;
extern u32 gSuicunePostStoryPreFightDialogue_2;
extern u32 gSuicunePostStoryPreFightDialogue_3;
extern u32 gSuicunePreFightDialogue_1;
extern u32 gSuicunePreFightDialogue_2;
extern u32 gSuicunePreFightDialogue_3;
extern u32 gSuicunePreFightDialogue_4;
extern u32 gSuicunePreFightDialogue_5;
extern u32 gSuicunePreFightDialogue_6;
extern u32 gSuicunePreFightDialogue_7;
extern u32 gRaikouPostStoryPreFightDialogue_3;
extern u32 gRaikouPostStoryPreFightDialogue_4;
extern u32 gRaikouPostStoryPreFightDialogue_1;
extern u32 gRaikouPostStoryPreFightDialogue_2;
extern u32 gRaikouReFightDialogue_1;
extern u32 gRaikouReFightDialogue_2;
extern u32 gRaikouReFightDialogue_3;
extern u32 gRaikouPreFightDialogue_1;
extern u32 gRaikouPreFightDialogue_2;
extern u32 gRaikouPreFightDialogue_3;
extern u32 gRaikouPreFightDialogue_4;
extern u32 gRaikouPreFightDialogue_5;
extern u32 gRaikouPreFightDialogue_6;
extern u32 gEnteiPostStoryPreFightDialogue_4;
extern u32 gEnteiPostStoryPreFightDialogue_1;
extern u32 gEnteiPostStoryPreFightDialogue_2;
extern u32 gEnteiPostStoryPreFightDialogue_3;
extern u32 gEnteiReFightDialogue_1;
extern u32 gEnteiReFightDialogue_2;
extern u32 gEnteiReFightDialogue_3;
extern u32 gUnknown_8104FC8;
extern u32 gEnteiPreFightDialogue_1;
extern u32 gEnteiPreFightDialogue_2;
extern u32 gEnteiPreFightDialogue_3;
extern u32 gMewtwoReFightDialogue_5;
extern u32 gMewtwoReFightDialogue_4;
extern u32 gMewtwoReFightDialogue_3;
extern u32 gMewtwoReFightDialogue_2;
extern u32 gMewtwoReFightDialogue_1;
extern u32 gMewtwoPreFightDialogue_5;
extern u32 gMewtwoPreFightDialogue_1;
extern u32 gMewtwoPreFightDialogue_2;
extern u32 gMewtwoPreFightDialogue_3;
extern u32 gMewtwoPreFightDialogue_4;
extern u32 gUnknown_8103E34;
extern u32 gUnknown_8102A9C;
extern u32 gArticunoPostStoryPreFightDialogue_1;
extern u32 gArticunoPostStoryPreFightDialogue_2;
extern u32 gArticunoPostStoryPreFightDialogue_3;
extern u32 gArticunoPostStoryPreFightDialogue_4;
extern u32 gArticunoPostStoryPreFightDialogue_5;
extern u32 gArticunoReFightDialogue_1;
extern u32 gArticunoReFightDialogue_2;
extern u32 gArticunoReFightDialogue_3;
extern u32 gArticunoPreFightDialogue_1;
extern u32 gArticunoPreFightDialogue_2;
extern u32 gArticunoPreFightDialogue_3;
extern u32 gArticunoPreFightDialogue_4;
extern u32 gArticunoPreFightDialogue_5;
extern u32 gArticunoPreFightDialogue_6;
extern u32 gArticunoPreFightDialogue_7;
extern u32 gArticunoPreFightDialogue_8;
extern u32 gArticunoPreFightDialogue_9;
extern u32 gArticunoPreFightDialogue_10;
extern u32 gArticunoPreFightDialogue_11;
extern u32 gArticunoPreFightDialogue_12;
extern u32 gMoltresPostStoryPreFightDialogue_1;
extern u32 gMoltresPostStoryPreFightDialogue_2;
extern u32 gMoltresPostStoryPreFightDialogue_3;
extern u32 gMoltresPostStoryPreFightDialogue_4;
extern u32 gMoltresPostStoryPreFightDialogue_5;
extern u32 gUnknown_8100D3C;
extern u32 gMoltresReFightDialogue_1;
extern u32 gMoltresReFightDialogue_2;
extern u32 gMoltresReFightDialogue_3;
extern u32 gMoltresReFightDialogue_4;
extern u32 gMoltresReFightDialogue_5;
extern u32 gMoltresPreFightDialogue_1;
extern u32 gMoltresPreFightDialogue_2;
extern u32 gMoltresPreFightDialogue_3;
extern u32 gMoltresPreFightDialogue_4;
extern u32 gMoltresPreFightDialogue_5;
extern u32 gMoltresPreFightDialogue_6;
extern u32 gMoltresPreFightDialogue_7;
extern u32 gMoltresPreFightDialogue_8;
extern u32 gMoltresPreFightDialogue_9;
extern u32 gMoltresPreFightDialogue_10;
extern u32 gMoltresPreFightDialogue_11;
extern u32 gMoltresPreFightDialogue_12;
extern u32 gZapdosPostStoryPreFightDialogue_1;
extern u32 gZapdosPostStoryPreFightDialogue_2;
extern u32 gZapdosPostStoryPreFightDialogue_3;
extern u32 gZapdosPostStoryPreFightDialogue_4;
extern u32 gZapdosPostStoryPreFightDialogue_5;
extern u32 gZapdosPostStoryPreFightDialogue_6;
extern u32 gUnknown_8105668;
extern u32 gUnknown_8105674;
extern u32 gUnknown_81056B8;
extern u32 gUnknown_81056DC;
extern u32 gUnknown_810579C;
extern u32 gUnknown_8105974;
extern u32 gUnknown_810581C;

extern u32 gUnknown_8105BF4;
extern u32 gUnknown_8105D2C;
extern u32 gUnknown_8105D80;
extern u32 gUnknown_8105D9C;
extern u32 gUnknown_81058E0;
extern u32 gUnknown_810593C;
extern u32 gUnknown_8105A08;
extern u32 gUnknown_8105AD4;
extern u32 gUnknown_8105B20;
extern u32 gUnknown_8105B68;
extern u32 gUnknown_8105BA8;
extern u8 *gUnknown_8105798[];
extern u32 gJirachiReFightDialogue_1;
extern u32 gUnknown_202EDC8;

extern u32 gKyogrePreFightDialogue_8;
extern u32 gKyogrePreFightDialogue_1;
extern u32 gKyogrePreFightDialogue_2;
extern u32 gKyogrePreFightDialogue_3;
extern u32 gKyogrePreFightDialogue_4;
extern u32 gKyogrePreFightDialogue_5;
extern u32 gKyogrePreFightDialogue_6;
extern u32 gKyogrePreFightDialogue_7;
extern u32 gUnknown_810697C;
extern u64 gUnknown_8107544[];
extern u32 gMedichamRescueDialogue_1;
extern u32 gMedichamRescueDialogue_2;
extern u32 gMedichamRescueDialogue_3;
extern u32 gMedichamRescueDialogue_4;
extern u32 gSmeargleRescueDialogue_1;
extern u32 gSmeargleRescueDialogue_2;
extern u32 gSmeargleRescueDialogue_3;
extern u32 gSmeargleRescueDialogue_4;
extern u32 gUnknown_8106720;

extern u32 gCelebiJoinDialogue_10;
extern u32 gCelebiJoinDialogue_1;
extern u32 gCelebiJoinDialogue_2;
extern u32 gCelebiJoinDialogue_3;
extern u32 gCelebiJoinDialogue_4;
extern u32 gCelebiJoinDialogue_5;
extern u32 gCelebiJoinDialogue_6;
extern u32 gCelebiJoinDialogue_7;
extern u32 gCelebiJoinDialogue_8;
extern u32 gCelebiJoinDialogue_9;
extern u32 *gPtrPurityForestAllowCelebiToJoinText;
extern u32 gPurityForestAllowCelebiToJoinPrompt;
extern u32 *gPtrPurityForestRefuseCelebiConfirmText;
extern u32 gPurityForestRefuseCelebiConfirmPrompt;
extern u32 gDeoxysPreFightDialogue_1;
extern u32 gDeoxysPreFightDialogue_2;
extern u32 gDeoxysPreFightDialogue_3;
extern u32 gDeoxysPreFightDialogue_4;
extern u32 gDeoxysPreFightDialogue_5;
extern u32 gLugiaPreFightDialogue_8;
extern u32 gLugiaPreFightDialogue_1;
extern u32 gLugiaPreFightDialogue_2;
extern u32 gLugiaPreFightDialogue_3;
extern u32 gLugiaPreFightDialogue_4;
extern u32 gLugiaPreFightDialogue_5;
extern u32 gLugiaPreFightDialogue_6;
extern u32 gLugiaPreFightDialogue_7;
extern u32 gZapdosReFightDialogue_1;
extern u32 gUnknown_81015A0;
extern u32 gZapdosReFightDialogue_2;
extern u32 gZapdosReFightDialogue_3;
extern u32 gZapdosReFightDialogue_4;

extern u32 gUnknown_81058C4;
extern u32 gUnknown_81058A8;

extern u8 gUnknown_81074FC[];

extern u8 sub_800E9A8(u32);
extern void sub_800DC14(u32);

extern void sub_8086A3C(struct Entity *r0);
extern void sub_80854D4(void);
extern void sub_80855E4(void *);
extern void sub_8068FE0(struct Entity *, u32, u32);

extern void sub_803E708(u32, u32);
extern void sub_8086448(void);
extern void sub_8086598(void);
extern void SpriteLookAroundEffect(struct Entity *);
extern void SpriteShockEffect(struct Entity *);
extern void PlaySoundEffect(u32);
extern void sub_806CDD4(struct Entity *, u32, u32);
extern void sub_80869E4(struct Entity *, u32, u32, u32);
extern void sub_806CE68(struct Entity *, u32);
extern void sub_804539C(struct Entity *, u32, u32);
extern void sub_8042B0C(struct Entity *);
extern void DisplayDungeonDialogue(u32 *);
extern void sub_803E708(u32, u32);
extern u8 HasRecruitedMon(u32);
extern u8 sub_806FD18(struct Entity *);
extern void sub_80861D4(struct Entity *, u32, s32 direction);
extern void sub_806FDF4(struct Entity *, struct Entity *, struct Entity **);
extern u32 sub_80861F8(u32, struct Entity *, u32);
extern s32 GetCameraXPos();
extern s32 GetCameraYPos();
extern void sub_803F878(u32, s32);
extern void SetupBossFightHP(struct Entity *, u32, u32);
extern void sub_803E9D0(void);
extern void DeoxysScreenFlash(void);
extern void sub_8085EB0();
extern void sub_808563C(void *);

void SetupDeoxysFightHP(struct Entity *r0);
void sub_808C550(void);
void sub_808C590(struct Entity *r0);
void SetupDeoxysFacingDirection(struct Entity *r0);
void sub_808C9B0();
void sub_808C8E0(struct Entity *param_1);
void sub_808C360(void);
void KyogreScreenFlash();

void sub_808C0CC();
void LugiaScreenFlash();
void LugiaScreenFlash2();
extern void sub_80861B8(struct Entity *, u32, u32);

void nullsub_99();
extern bool8 *gFriendAreas;

extern void sub_8049884();
extern void sub_8049B8C();
extern void sub_8049ED4();
extern void sub_8040A84();
extern void sub_8086A54(struct Entity *);

extern void sub_806BFC0(struct EntityInfo *, u32);


extern struct Entity *xxx_call_GetLeader(void);
extern void sub_808BBA8(struct Entity * );
extern void sub_80855E4(void *);
extern void sub_8041888(u32);
extern void sub_80861B8(struct Entity *, u32, u32);
extern void sub_803E708(u32, u32);
extern void DisplayDungeonDialogue(u32 *r0);

extern void SpriteShockEffect(struct Entity *);
extern u32 sub_80861F8(u32, struct Entity *, u32);

extern void sub_8097FA8(u32);

extern void JirachiWish();
extern void JirachiSpinEffect(struct Entity *);
extern void JirachiWishGrantDialogue(struct Entity *jirachiEntity);
extern void JirachiWishGrantFlash();
extern void JirachiDropInEffect(struct Entity *param_1);
extern u8 JirachiFriendAreaSearch(void);

extern u8 sub_80860A8(u32);
extern void sub_8049ED4();
extern void sub_8092578(u8 *buffer, u8 index, u8 r2);
extern void sub_8052D44(s16 *, struct Entity *, struct Entity *);
extern void sub_8097FD0(u32);
extern void SetMessageArgument(u8 *, struct Entity *, u32);
extern struct Entity *GetLeader();
extern void sub_80421C0(struct Entity *, u32);
extern void sub_8046D20();
extern void sub_808B1CC(u8);
extern void sub_80464C8(struct Entity *, u32 *, struct Item *);
extern void sub_8098044(u32);
extern void SetDungeonBGColorRGB(u32, u32, u32, u32, u32);
extern void sub_803E46C(u32);
extern void sub_80866C4(u32 *);
extern void sub_808692C();

extern void sub_80868F4();
extern void sub_8086910();
extern u32 sub_8085EC8(u32, u32, u32, u32 *, u32);
extern void sub_808680C();
extern void sub_808682C();
extern void sub_8086854();
extern void sub_80867F4();
extern void sub_8086838(u32, u32, u32);
extern void sub_80426C8(u32, u32);
extern void sub_807EAA0(u32, u32);

extern void sub_808BCE4(void);
extern u8 sub_8098100(u32);
extern void sub_8086794();

void EnteiScreenFlash(void);
void RaikouScreenFlash(void);
void sub_808A528(struct Entity * param_1);
void SuicuneScreenFlash();
void HoOhDropInEffect(struct Entity * param_1);
void HoOhScreenFlash(void);
void LatiosScreenFlash(void);
void SetupRegiFacingDirection(struct Entity *r0);
void SetupRegirockFightHP(struct Entity *r0);
void SetupRegiceFightHP(struct Entity *r0);
void SetupRegisteelFightHP(struct Entity *r0);
void sub_808B50C(void);
void MewtwoDropInEffect(struct Entity *param_1);
void MewtwoScreenFlash(void);
void sub_80898F8(struct Entity *r0);
void sub_8089908(struct Entity *r0);
void RayquazaDropInEffect(struct Entity *param_1);
void RayquazaScreenFlash(void);
void sub_80891F0(void);
void sub_8089294(void);
void GroudonScreenFlash2(void);

extern u8 sub_8086AE4(u32);


extern void sub_8072008(struct Entity *, struct Entity *, s16, u32, u32);
extern struct Entity *GetPartnerEntity();
extern void sub_80869E4(struct Entity *, u32, u32, u32);
extern void sub_804539C(struct Entity *, u32, u32);
extern void sub_806CDD4(struct Entity *, u32, u32);
extern void sub_8085374();

extern void sub_8086848(u32 ,u32);
extern void sub_80856C8(struct Entity *, s32, s32);
extern void sub_8086738();
extern void sub_8086A54(struct Entity *);
extern void sub_8086764();

extern void sub_803F878(u32,s32);

void SceneGroudonMovement(struct Entity * param_1);
void GroudonScreenFlash(void);
void ArticunoScreenFlash(void);
void sub_8088484(struct Entity *param_1);
void sub_8088574(void);

void MoltresDropInEffect(struct Entity * param_1);
void MoltresScreenFlash1(s32 r0, s32 r1);
void MoltresScreenFlash2(s32 r0, s32 r1);
void MoltresScreenFlash3(void);
void sub_808654C(void);

extern void sub_8086598();
extern void sub_80865E8();


extern void sub_8086500(void);
extern void sub_8086690(void);
void MoltresScreenDarken(void);
extern void sub_808663C(void);
void ZapdosDropInEffect(struct Entity *param_1);
void ZapdosScreenFlash(int param_1);

extern s32 sub_8052C68(u32, u8 *, u32 *, u32);
extern void sub_80861A8(void);
extern void sub_8045C28(struct Item *, u8 , u8 *);
extern void sub_808BD38(void);
extern void sub_808BB3C(s16 *);
extern void sub_8046860(struct Entity *, s32 *, struct Item *, u32);
extern u32 sub_803D73C(u32);

void ZapdosReFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *ZapdosEntity;

  LeaderEntity = xxx_call_GetLeader();
  ZapdosEntity = GetEntityFromClientType(8);
  sub_8086448();
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_1);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(&gUnknown_81015A0);
  sub_803E708(10,0x46);
  ZapdosDropInEffect(ZapdosEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_2);
  ZapdosScreenFlash(1);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_3);
  ZapdosScreenFlash(2);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_4);
  SetupBossFightHP(ZapdosEntity,300,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void ZapdosPostStoryPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * ZapdosEntity;

  LeaderEntity = xxx_call_GetLeader();
  ZapdosEntity = GetEntityFromClientType(8);
  sub_8086448();
  if (sub_8086AE4(MONSTER_ZAPDOS)) {
    sub_80866C4(&gZapdosPostStoryPreFightDialogue_6);
  }
  else {
    ZapdosScreenFlash(1);
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_1);
    ZapdosDropInEffect(ZapdosEntity);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_2);
    ZapdosScreenFlash(1);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_3);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_4);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_5);
    sub_803E708(10,0x46);
    SetupBossFightHP(ZapdosEntity,300,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}


void ZapdosDropInEffect(struct Entity *zapdosEntity)
{
  int iVar1;

  zapdosEntity->info->unk15C = 1;
  zapdosEntity->info->unk15E = 0;
  zapdosEntity->info->unk174 = 200;
  PlaySoundEffect(0x1ea);
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    zapdosEntity->info->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
}

void ZapdosScreenFlash(s32 param_1)
{
  s32 iVar1;
  s32 iVar2;

  PlaySoundEffect(0x1f6);
  if (2 < param_1) {
    for(iVar2 = 250; iVar2 > 199; iVar2 -= 10)
    {
      SetDungeonBGColorRGB(iVar2,iVar2,iVar2 / 2,1,1);
      sub_803E46C(0x46);
    }
  }
  if (1 < param_1) {
    for(iVar2 = 250; iVar2 > 199; iVar2 -= 10)
    {
      SetDungeonBGColorRGB(iVar2,iVar2,iVar2 / 2,1,1);
      sub_803E46C(0x46);
    }
  }
  for(iVar2 = 250; iVar2 >= 0; iVar2 -= 10)
  {
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = iVar2 + 3;
    }
    SetDungeonBGColorRGB(iVar2,iVar2,iVar1 >> 2,1,1);
    sub_803E46C(0x46);
  }
  sub_8085EB0();
}



void sub_80877E8(void)
{
  struct Entity * LeaderEntity;
  struct Entity * MoltresEntity;

  LeaderEntity = xxx_call_GetLeader();
  MoltresEntity = GetEntityFromClientType(9);
  DungeonStartNewBGM(MUS_THE_MOUNTAIN_OF_FIRE);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_WEST);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(MoltresEntity, DIRECTION_SOUTH);
  sub_8086A3C(MoltresEntity);
  sub_8085860(LeaderEntity->pos.x + -3,LeaderEntity->pos.y + -2);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_MOLTRES);
}

void sub_8087848(void)
{
  struct Entity *LeaderEntity;
  struct Entity *MoltresEntity;

  u32 XPos;
  s32 YPos;

  LeaderEntity = xxx_call_GetLeader();
  MoltresEntity = GetEntityFromClientType(9);
  DungeonStartNewBGM(MUS_THE_MOUNTAIN_OF_FIRE);
  sub_80854D4();
  sub_8085930(DIRECTION_WEST);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_MOLTRES)) {
    sub_8068FE0(MoltresEntity,0x21c,0);
  }
  else {
    sub_8072008(MoltresEntity,MoltresEntity,gUnknown_80F57CE,0,0);
    SetFacingDirection(MoltresEntity, DIRECTION_SOUTH);
    sub_8086A3C(MoltresEntity);
  }
  sub_8085860(LeaderEntity->pos.x - 5, LeaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos, YPos + -0x1000);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_MOLTRES);
}



void sub_80878F4(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xF6000000U) >> 0x18 < 3) && (param_1 == 0x9)) {
    sub_8097FA8(0x7);
    gDungeon->unk2 = 1;
  }
}

void MoltresPreFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *PartnerEntity;
  struct Entity *MoltresEntity;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  MoltresEntity = GetEntityFromClientType(9);
  MoltresScreenFlash1(0xc,5);
  sub_8086500();
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,5);
  sub_803E708(4,0x46);
  SpriteLookAroundEffect(PartnerEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_2);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(0xc,5);
  MoltresScreenFlash2(9,5);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_3);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_4);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,2,6);
  sub_8086690();
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_5);
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  sub_8085930(DIRECTION_NORTH);
  PlaySoundEffect(0x2f2);
  DungeonStopBGM();
  MoltresScreenDarken();
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_7);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1cf);
  sub_80856E0(PartnerEntity, DIRECTION_NORTH);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_8);
  sub_803E708(10,0x46);
  MoltresScreenFlash3();
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_9);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(9,5);
  MoltresScreenFlash2(0xb,5);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_10);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(0xc,5);
  MoltresScreenFlash2(9,5);
  MoltresDropInEffect(MoltresEntity);
  sub_808663C();
  MoltresScreenFlash3();
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_11);
  sub_803E708(10,0x46);
  MoltresScreenFlash2(0xb,6);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_12);
  sub_803E708(10,0x46);
  SetupBossFightHP(MoltresEntity,400,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}


void MoltresReFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *PartnerEntity;
  struct Entity *MoltresEntity;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  MoltresEntity = GetEntityFromClientType(9);
  MoltresScreenFlash1(10,5);
  sub_8086500();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(PartnerEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresReFightDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  DisplayDungeonDialogue(&gMoltresReFightDialogue_2);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,2,6);
  sub_80869E4(LeaderEntity,4,2,6);
  sub_8086690();
  MoltresScreenDarken();
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  sub_8085930(DIRECTION_NORTH);
  MoltresDropInEffect(MoltresEntity);
  sub_808663C();
  MoltresScreenFlash3();
  DisplayDungeonDialogue(&gMoltresReFightDialogue_3);
  sub_803E708(10,0x46);
  MoltresScreenFlash2(0xb,6);
  DisplayDungeonDialogue(&gMoltresReFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresReFightDialogue_5);
  sub_803E708(10,0x46);
  SetupBossFightHP(MoltresEntity,400,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void MoltresPostStoryPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * MoltresEntity;

  LeaderEntity = xxx_call_GetLeader();
  MoltresEntity = GetEntityFromClientType(9);
  MoltresScreenFlash1(0xc,5);
  sub_808654C();
  if (sub_8086AE4(MONSTER_MOLTRES)) {
    sub_8085930(DIRECTION_NORTHWEST);
    sub_803E708(4,0x46);
    sub_8085930(DIRECTION_NORTH);
    sub_803E708(4,0x46);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gUnknown_8100D3C);
    sub_803E708(10,0x46);
    gDungeon->unk2 = 1;
  }
  else {
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_1);
    sub_8085930(DIRECTION_NORTHWEST);
    sub_803E708(4,0x46);
    sub_8085930(DIRECTION_NORTH);
    MoltresDropInEffect(MoltresEntity);
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_2);
    MoltresScreenFlash1(0xc,5);
    MoltresScreenFlash2(9,5);
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_3);
    MoltresScreenFlash3();
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_4);
    MoltresScreenFlash2(0xb,6);
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_5);
    sub_803E708(10,0x46);
    SetupBossFightHP(MoltresEntity,400,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void MoltresDropInEffect(struct Entity * moltresEntity)
{
  s32 iVar1;

  moltresEntity->info->unk15C = 1;
  moltresEntity->info->unk15E = 0;
  moltresEntity->info->unk174 = 0xc800;
  PlaySoundEffect(0x1f8);
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    moltresEntity->info->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
}

NAKED
void MoltresScreenFlash1(s32 r0, s32 r1)
{
	asm_unified("\tpush {lr}\n"
	"\tsub sp, 0x8\n"
	"\tadds r3, r1, 0\n"
	"\tlsls r1, r0, 1\n"
	"\tadds r1, r0\n"
	"\tlsls r1, 11\n"
	"\tmovs r2, 0xC0\n"
	"\tlsls r2, 4\n"
	"\tadds r0, r1, r2\n"
	"\tcmp r0, 0\n"
	"\tbge _08087D98\n"
	"\tadds r0, 0xFF\n"
"_08087D98:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tldr r1, _08087DE0\n"
	"\tldr r2, [sp, 0x4]\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tlsls r0, r3, 1\n"
	"\tadds r0, r3\n"
	"\tlsls r0, 11\n"
	"\tmovs r1, 0x80\n"
	"\tlsls r1, 5\n"
	"\tadds r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbge _08087DB8\n"
	"\tadds r0, 0xFF\n"
"_08087DB8:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tlsls r0, 16\n"
	"\tldr r1, _08087DE4\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tmovs r0, 0xB9\n"
	"\tlsls r0, 1\n"
	"\tmovs r1, 0\n"
	"\tstr r1, [sp]\n"
	"\tmovs r1, 0x10\n"
	"\tmovs r2, 0\n"
	"\tadd r3, sp, 0x4\n"
	"\tbl sub_8085EC8\n"
	"\tadd sp, 0x8\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08087DE0: .4byte 0xffff0000\n"
"_08087DE4: .4byte 0x0000ffff");
}

NAKED
void MoltresScreenFlash2(s32 r0, s32 r1)
{
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tsub sp, 0x8\n"
	"\tadds r3, r1, 0\n"
	"\tlsls r1, r0, 1\n"
	"\tadds r1, r0\n"
	"\tlsls r1, 11\n"
	"\tmovs r2, 0xC0\n"
	"\tlsls r2, 4\n"
	"\tadds r0, r1, r2\n"
	"\tcmp r0, 0\n"
	"\tbge _08087E00\n"
	"\tadds r0, 0xFF\n"
"_08087E00:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tldr r1, _08087EA8\n"
	"\tldr r2, [sp, 0x4]\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tlsls r0, r3, 1\n"
	"\tadds r0, r3\n"
	"\tlsls r0, 11\n"
	"\tmovs r1, 0x80\n"
	"\tlsls r1, 5\n"
	"\tadds r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbge _08087E20\n"
	"\tadds r0, 0xFF\n"
"_08087E20:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tlsls r0, 16\n"
	"\tldr r1, _08087EAC\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tmovs r0, 0xB9\n"
	"\tlsls r0, 1\n"
	"\tmovs r1, 0\n"
	"\tstr r1, [sp]\n"
	"\tmovs r1, 0x16\n"
	"\tmovs r2, 0\n"
	"\tadd r3, sp, 0x4\n"
	"\tbl sub_8085EC8\n"
	"\tadds r6, r0, 0\n"
	"\tmovs r0, 0xF6\n"
	"\tlsls r0, 1\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r4, 0xFA\n"
	"\tmovs r5, 0x1\n"
"_08087E4E:\n"
	"\tstr r5, [sp]\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x1\n"
	"\tbl SetDungeonBGColorRGB\n"
	"\tmovs r0, 0x46\n"
	"\tbl sub_803E46C\n"
	"\tsubs r4, 0xA\n"
	"\tcmp r4, 0x13\n"
	"\tbgt _08087E4E\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tmovs r4, 0xFA\n"
	"\tmovs r5, 0x1\n"
"_08087E74:\n"
	"\tstr r5, [sp]\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x1\n"
	"\tbl SetDungeonBGColorRGB\n"
	"\tmovs r0, 0x46\n"
	"\tbl sub_803E46C\n"
	"\tsubs r4, 0xA\n"
	"\tcmp r4, 0\n"
	"\tbge _08087E74\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tbl sub_8085EB0\n"
	"\tadds r0, r6, 0\n"
	"\tbl sub_8085F44\n"
	"\tadd sp, 0x8\n"
	"\tpop {r4-r6}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08087EA8: .4byte 0xffff0000\n"
"_08087EAC: .4byte 0x0000ffff");
}

void MoltresScreenFlash3(void)
{
  int iVar1;

  PlaySoundEffect(0x1ed);
  iVar1 = 0xfa;
  for(iVar1 = 250; iVar1 > 9; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
  sub_8085EB0();
}

void MoltresScreenDarken(void)
{
  s32 iVar1;

  for(iVar1 = 0; iVar1 >= -80; iVar1 -= 8)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,0,0);
    sub_803E46C(0x46);
  }
}


void sub_8087F54(void)
{
  struct Entity  *LeaderEntity;
  struct Entity *ArticunoEntity;

  LeaderEntity = xxx_call_GetLeader();
  ArticunoEntity = GetEntityFromClientType(0xd);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(ArticunoEntity, DIRECTION_SOUTH);
  sub_8086A3C(ArticunoEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_ARTICUNO);
}

void sub_8087FB4(void)
{
  struct Entity  *ArticunoEntity;

  ArticunoEntity = GetEntityFromClientType(0xd);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(ArticunoEntity, DIRECTION_SOUTH);
  sub_806CDD4(ArticunoEntity, 0xF, DIRECTION_SOUTH);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_ARTICUNO);
}

void sub_8087FF8(void)
{
  struct Entity  *LeaderEntity;
  struct Entity *ArticunoEntity;

  LeaderEntity = xxx_call_GetLeader();
  ArticunoEntity = GetEntityFromClientType(0xd);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_ARTICUNO)) {
    sub_8068FE0(ArticunoEntity,0x21c,0);
  }
  else {
    sub_8072008(ArticunoEntity,ArticunoEntity,gUnknown_80F57D0,0,0);
    SetFacingDirection(ArticunoEntity, DIRECTION_SOUTH);
    sub_8086A3C(ArticunoEntity);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_ARTICUNO);
}



void sub_8088088(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xF3000000U) >> 0x18 < 3) && (param_1 == 0xD)) {
    sub_8097FA8(0x9);
    gDungeon->unk2 = 1;
  }
}

void ArticunoPreFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *PartnerEntity;
  struct Entity *ArticunoEntity;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  ArticunoEntity = GetEntityFromClientType(0xd);
  sub_8086448();
  SpriteLookAroundEffect(PartnerEntity);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_8086598();
  DungeonStopBGM();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_2);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_3);
  sub_803E708(10,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_SOUTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_WEST);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_5);
  sub_803E708(10,0x46);
  sub_80869E4(LeaderEntity,4,1,4);
  sub_80869E4(PartnerEntity,4,2,4);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(PartnerEntity);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(LeaderEntity);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_7);
  sub_803E708(10,0x46);
  PlaySoundEffect(0); // snow flurry
  gDungeon->unkE265 = WEATHER_SNOW;
  sub_807EAA0(0,1);
  PlaySoundEffect(0x1ee); // flash effect?
  sub_8088574();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_8);
  sub_803E708(10,0x46);
  ArticunoScreenFlash();
  sub_8086738();
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_9);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1ea);
  sub_8088484(ArticunoEntity);
  sub_80865E8();
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_10);
  sub_806CDD4(ArticunoEntity,0xf,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_11);
  sub_806CDD4(ArticunoEntity,0x10,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_12);
  sub_806CDD4(ArticunoEntity,0xf,DIRECTION_SOUTH);
  sub_803E708(0x10,0x46);
  SetupBossFightHP(ArticunoEntity,0x1c2,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void ArticunoReFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *ArticunoEntity;

  LeaderEntity = xxx_call_GetLeader();
  ArticunoEntity = GetEntityFromClientType(0xd);
  gDungeon->unkE265 = WEATHER_SNOW;
  sub_807EAA0(0,1);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoReFightDialogue_1);
  sub_806CDD4(ArticunoEntity,0x10,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoReFightDialogue_2);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoReFightDialogue_3);
  sub_806CDD4(ArticunoEntity,0xf,DIRECTION_SOUTH);
  sub_803E708(0x28,0x46);
  SetupBossFightHP(ArticunoEntity,0x1c2,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void ArticunoPostStoryPreFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *ArticunoEntity;

  LeaderEntity = xxx_call_GetLeader();
  ArticunoEntity = GetEntityFromClientType(0xd);
  sub_8086448();
  if (sub_8086AE4(MONSTER_ARTICUNO)) {
    sub_80866C4(&gUnknown_8102A9C);
  }
  else {
    gDungeon->unkE265 = WEATHER_SNOW;
    sub_807EAA0(0,1);
    ArticunoScreenFlash();
    sub_8086738();
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_1);
    sub_803E708(10,0x46);
    sub_8088484(ArticunoEntity);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_2);
    sub_806CDD4(ArticunoEntity,0xf,DIRECTION_SOUTH);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_3);
    sub_806CDD4(ArticunoEntity,0x10,DIRECTION_SOUTH);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_4);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_5);
    sub_806CDD4(ArticunoEntity,0xf,DIRECTION_SOUTH);
    sub_803E708(0x28,0x46);
    SetupBossFightHP(ArticunoEntity,0x1c2,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void sub_8088484(struct Entity *param_1)
{
  int iVar1;

  param_1->info->unk15C = 1;
  param_1->info->unk15E = 0;
  PlaySoundEffect(0x1ea);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 5)
  {
    param_1->info->unk174 = iVar1 * 256;
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,0);
    sub_803E46C(0x46);
  }
}

void ArticunoScreenFlash(void)
{
  int iVar1;

  PlaySoundEffect(0x2ad);
  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  sub_8085EB0();
}

void sub_8088574(void)
{
  int iVar1;

  for(iVar1 = 0; iVar1 <= 80; iVar1 += 8)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,0,0);
    sub_803E46C(0x46);
  }
}

void sub_80885A0(void)
{
  DungeonFadeOutBGM(0x3c);
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  gDungeon->unk7 = 1;
}

void sub_80885C4(void)
{
  struct Entity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  DungeonFadeOutBGM(0x3c);
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
}

void sub_8088608(void)
{
    gDungeon->unk2 = 1;
}

void sub_8088618(void)
{
    sub_8086448();
    // The mountain's summit...
    // But there is no one here
    // It's time to go back
    sub_80866C4(&gUnknown_8102B10);
}

void sub_808862C(void)
{
  struct Entity * LeaderEntity;
  struct Entity * AlakazamEntity;
  struct Entity * GroudonEntity;

  LeaderEntity = xxx_call_GetLeader();
  AlakazamEntity = GetEntityFromClientType(10);
  GroudonEntity = GetEntityFromClientType(0xe);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(AlakazamEntity, DIRECTION_NORTH);
  sub_80861D4(AlakazamEntity,0xd,4);
  SetFacingDirection(GroudonEntity, DIRECTION_SOUTH);
  sub_8086A3C(GroudonEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y -3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_GROUDON);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ALAKAZAM);
}

void sub_80886C4(void)
{
  struct Entity * LeaderEntity;
  struct Entity * AlakazamEntity;
  struct Entity * GroudonEntity;

  u32 XPos;
  s32 YPos;

  LeaderEntity = xxx_call_GetLeader();
  AlakazamEntity = GetEntityFromClientType(10);
  GroudonEntity = GetEntityFromClientType(0xe);
  PlaySoundEffect(0x3e5);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_8068FE0(AlakazamEntity,0x21c,0);
  SetFacingDirection(GroudonEntity, DIRECTION_SOUTH);
  sub_8086A3C(GroudonEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + -0x1000);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_GROUDON);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ALAKAZAM);
}

void sub_808875C(void)
{
  struct Entity * LeaderEntity;
  struct Entity * AlakazamEntity;
  struct Entity * GroudonEntity;

  LeaderEntity = xxx_call_GetLeader();
  AlakazamEntity = GetEntityFromClientType(10);
  GroudonEntity = GetEntityFromClientType(0xe);
  sub_80867F4();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(AlakazamEntity,0x21c,0);
  if (sub_8086AE4(MONSTER_GROUDON)) {
    sub_8068FE0(GroudonEntity,0x21c,0);
  }
  else {
    sub_8072008(GroudonEntity,GroudonEntity,gUnknown_80F57D2,0,0);
    SetFacingDirection(GroudonEntity, DIRECTION_SOUTH);
    sub_80861D4(GroudonEntity,0xf,0);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_GROUDON);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ALAKAZAM);
}

void sub_8088818(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xEE000000U) >> 0x18 < 3) && (param_1 == 0xE)) {
    sub_8097FA8(0xC);
    gDungeon->unk2 = 1;
  }
}

void sub_8088848(void)
{
    sub_8086854();
}

void GroudonPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * PartnerEntity;
  struct Entity * AlakazamEntity;
  struct Entity * GroudonEntity;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  AlakazamEntity = GetEntityFromClientType(10);
  GroudonEntity = GetEntityFromClientType(0xe);
  sub_8086448();
  DisplayDungeonDialogue(&GroudonPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_2);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  sub_808682C();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_3);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_4);
  sub_803E708(10,0x46);
  GroudonScreenFlash();
  DisplayDungeonDialogue(&GroudonPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_6);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(PartnerEntity);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_7);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  sub_80861B8(AlakazamEntity,6,4);
  PlaySoundEffect(0x205);
  sub_8086738();
  sub_8068FE0(AlakazamEntity,0x21c,0);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_8);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_9);
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  sub_803E708(0x28,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(PartnerEntity);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_10);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_11);
  sub_803E708(10,0x46);
  DungeonStopBGM();
  GroudonScreenFlash2();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_12);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_13);
  sub_803E708(10,0x46);
  sub_803E708(0x1e,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  PlaySoundEffect(0x1fa);
  sub_8086738();
  sub_8085930(DIRECTION_NORTH);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_14);
  sub_803E708(10,0x46);
  sub_8086A54(GroudonEntity);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  SetupBossFightHP(GroudonEntity,500,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void GroudonReFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * GroudonEntity;

  LeaderEntity = xxx_call_GetLeader();
  GroudonEntity = GetEntityFromClientType(0xe);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&gGroudonReFightDialogue_1);
  sub_803E708(10,0x46);
  GroudonScreenFlash();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&gGroudonReFightDialogue_2);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gGroudonReFightDialogue_3);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  PlaySoundEffect(0x1fa);
  sub_8086738();
  DisplayDungeonDialogue(&gGroudonReFightDialogue_4);
  sub_803E708(10,0x46);
  sub_8086A54(GroudonEntity);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  SetupBossFightHP(GroudonEntity,500,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void GroudonPostStoryPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * GroudonEntity;

  LeaderEntity = xxx_call_GetLeader();
  GroudonEntity = GetEntityFromClientType(0xe);
  sub_8086448();
  if (sub_8086AE4(MONSTER_GROUDON)) {
      sub_80866C4(&gUnknown_8103488);
  }
  else{
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_1);
    sub_803E708(10,0x46);
    SceneGroudonMovement(GroudonEntity);
    SceneGroudonMovement(GroudonEntity);
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_2);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_3);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_4);
    sub_803E708(10,0x46);
    SetupBossFightHP(GroudonEntity,500,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

// Moves Groudon down in a walking fashion
void SceneGroudonMovement(struct Entity * param_1)
{
  int iVar1;

  sub_8086848(0x18,0x10);
  sub_806CDD4(param_1,0,DIRECTION_SOUTH);
  for(iVar1 = 0; iVar1 < 0x2C; iVar1++)
  {
    if ((iVar1 == 10) || (iVar1 == 0x20)) {
      PlaySoundEffect(0x1f9);
      sub_8086838(0,1,0);
      sub_808680C();
    }
    if ((iVar1 - 10U < 0xc) || (iVar1 > 0x1f)) {
      sub_804539C(param_1,0,0x100);
    }
    sub_803E46C(0x46);
  }
  sub_80856C8(param_1,param_1->pos.x,param_1->pos.y + 1);
  sub_80861D4(param_1,0xf,0);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_8085930(DIRECTION_NORTH);
  sub_803E708(0x22,0x46);
}

void GroudonScreenFlash(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void GroudonScreenFlash2(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}


void sub_8088DC0(void)
{
  struct Entity * LeaderEntity;
  struct Entity * uVar2;
  struct Entity * uVar3;

  LeaderEntity = xxx_call_GetLeader();
  uVar2 = GetEntityFromClientType(0xb);
  uVar3 = GetEntityFromClientType(0xc);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(uVar2);
  sub_806CDD4(uVar2,0xe,DIRECTION_SOUTH);
  sub_8086A3C(uVar3);
  sub_806CDD4(uVar3,0xe,DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_GROUDON);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ALAKAZAM);
}

void sub_8088E5C(void)
{
  struct Entity * LeaderEntity;
  struct Entity * uVar2;
  struct Entity * uVar3;

  LeaderEntity = xxx_call_GetLeader();
  uVar2 = GetEntityFromClientType(0xb);
  uVar3 = GetEntityFromClientType(0xc);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(uVar2,0x21c,0);
  sub_8068FE0(uVar3,0x21c,0);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_GROUDON);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ALAKAZAM);
}

void sub_8088EE8(void)
{
    sub_8086854();
}


void MagmaCavernMidDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * PartnerEntity;
  struct Entity * iVar3;
  struct Entity * iVar4;
  s16 IDStack [2];
  struct Position32 local_20;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  iVar3 = GetEntityFromClientType(0xb);
  iVar4 = GetEntityFromClientType(0xc);
  sub_8052D44(IDStack,LeaderEntity,PartnerEntity);
  sub_8086448();
  SpriteLookAroundEffect(PartnerEntity);
  // Let's see..
  // I wonder where we are?
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  // I know we've come pretty
  // far...
  //
  // I'm certain we've come quite
  // far already..
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_2);
  sub_803E708(10,0x46);
  DungeonStopBGM();
  sub_80855E4(sub_80868F4);
  sub_808680C();
  PlaySoundEffect(0x1c5);
  sub_803E708(0x28,0x46);
  // Waaah!
  // Qu-quake!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_3);
  sub_803E708(0x78,0x46);
  StopSoundEffect(0x1c5);
  sub_808682C();
  sub_80855E4(sub_8086910);
  sub_803E708(0x14,0x46);
  sub_8085930(DIRECTION_NORTH);
  sub_803E708(10,0x46);
  // Whew!
  // It settled down.
  //
  // Whew
  // It's over.
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_4);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(PartnerEntity);
  PlaySoundEffect(0x1c7);
  sub_80856E0(PartnerEntity, DIRECTION_NORTH);
  // Hey! {ARG_POKEMON_0}!
  // Over there!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_5);
  iVar3->info->unk15E = 0;
  iVar4->info->unk15E =0;
  local_20.x = (iVar3->pixelPos.x + iVar4->pixelPos.x) / 2;
  local_20.y = (iVar3->pixelPos.y + iVar4->pixelPos.y) / 2 + 0x800;
  ShiftCameraToPosition(&local_20,0x20);
  sub_803E708(0x3c,0x46);
  sub_80891F0();
  // Hey!
  // Are you OK?!
  //
  // Hey!
  // Snap out of it!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_6);
  sub_803E708(10,0x46);
  // Urrrrgh...
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_7);
  sub_803E708(10,0x46);
  sub_80869E4(LeaderEntity,4,2,5);
  // What happened to you?
  //
  // What happened here?
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_8);
  sub_803E708(10,0x46);
  // We challenged..
  // {ARG_POKEMON_2}...
  // And wiped out..
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_9);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_10);
  sub_803E708(10,0x46);
  sub_80869E4(LeaderEntity,4,1,3);
  sub_80869E4(PartnerEntity,4,1,3);
  // Grrgh..
  // We... It crushed us
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_11);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(PartnerEntity);
  // That's right...
  // What happened to {ARG_POKEMON_3}?
  // Where is {ARG_POKEMON_3}?
  //
  // Wait...
  // What about {ARG_POKEMON_3}?
  // Where did {ARG_POKEMON_3} go?
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_12);
  sub_803E708(0x1e,0x46);
  // {ARG_POKEMON_3} is...
  // Still battling {ARG_POKEMON_2}...
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_13);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  // {ARG_POKEMON_0}!
  // We've got to hurry!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_14);
  sub_8089294();
  // Be careful!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_15);
  sub_803E708(10,0x46);
  gDungeon->unk2 = 1;
}

void sub_8089168(void)
{
  struct Entity *LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(LeaderEntity);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void sub_808919C(struct Entity *r0)
{
    sub_804539C(r0, 0, 0xfffffe00);
}

void sub_80891B0(struct Entity *r0)
{
    sub_806CDD4(r0, 0, DIRECTION_NORTH);
    r0->info->unk15F = 1;
}


void sub_80891D0(struct Entity *r0)
{
    sub_806CDD4(r0, 7, DIRECTION_NORTH);
    r0->info->unk15F = 0;
}

void sub_80891F0(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 < 0x30; iVar1++)
  {
    sub_80855E4(sub_808919C);
    sub_803E46C(0x46);
  }
  sub_80855E4(sub_80891D0);
}

void sub_8089224(struct Entity * param_1)
{
  s32 iVar1;

  if (param_1->pixelPos.y < 0x9001) {
    return;
  }
  iVar1 = param_1->pixelPos.x;

  if(iVar1 < 0xE400)
  {
      if(iVar1 <= 0xB400)
      {
          // 0 - 0xB400
          sub_804539C(param_1, 0, 0xfffffe00);
      }
      else
      {
          // 0xB401 - 0xE3FF
           sub_804539C(param_1, 0xfffffe00, 0);
      }
  }
  else
  {
      if(iVar1 < 0xFC00)
      {
            sub_804539C(param_1, 0, 0xfffffe00);
      }
      else
      {
          if(iVar1 <= 0x11400)
          {
              sub_804539C(param_1, 0x200, 0);
          }
          else
          {
              sub_804539C(param_1, 0, 0xfffffe00);
          }
      }
  }
}

void sub_8089294(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 <= 0x77; iVar1++)
  {
    sub_80855E4(sub_8089224);
    sub_803E46C(0x46);
  }
  sub_80855E4(sub_80891D0);
}

void sub_80892C8(void)
{
  struct Entity * LeaderEntity;
  struct Entity * RayquazaEntity;

  LeaderEntity = xxx_call_GetLeader();
  RayquazaEntity = GetEntityFromClientType(0xf);
  DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(RayquazaEntity, DIRECTION_SOUTH);
  sub_8086A3C(RayquazaEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_RAYQUAZA);
}

void sub_8089328(void)
{
  struct Entity * LeaderEntity;
  struct Entity * RayquazaEntity;

  LeaderEntity = xxx_call_GetLeader();
  RayquazaEntity = GetEntityFromClientType(0xf);
  DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_RAYQUAZA)) {
    sub_8068FE0(RayquazaEntity,0x21c,0);
  }
  else {
    sub_8072008(RayquazaEntity,RayquazaEntity,gUnknown_80F57CA,0,0);
    sub_8086A3C(RayquazaEntity);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_RAYQUAZA);
}

void sub_80893B4(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xE9000000U) >> 0x18 < 3) && (param_1 == 0xF)) {
    sub_8097FA8(0xF);
    gDungeon->unk2 = 1;
  }
}

void RayquazaPreFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *PartnerEntity;
  struct Entity *RayquazaEntity;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  RayquazaEntity = GetEntityFromClientType(0xf);
  sub_8086448();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_1);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_2);
  sub_80856E0(PartnerEntity, DIRECTION_NORTH);
  SpriteLookAroundEffect(PartnerEntity);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_3);
  sub_80869E4(PartnerEntity,4,2,4);
  sub_80869E4(LeaderEntity,4,1,4);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_6);
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_7);
  RayquazaDropInEffect(RayquazaEntity);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_8);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_9);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_10);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_11);
  SetupBossFightHP(RayquazaEntity,600,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void RayquazaReFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *RayquazaEntity;

  LeaderEntity = xxx_call_GetLeader();
  RayquazaEntity = GetEntityFromClientType(0xf);
  sub_8086448();
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_7);
  sub_803E708(10,0x46);
  RayquazaDropInEffect(RayquazaEntity);
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_1);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_2);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_3);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_4);
  SetupBossFightHP(RayquazaEntity,600,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void RayquazaPostStoryPreFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *RayquazaEntity;

  LeaderEntity = xxx_call_GetLeader();
  RayquazaEntity = GetEntityFromClientType(0xf);
  sub_8086448();
  if (sub_8086AE4(MONSTER_RAYQUAZA)) {
    sub_80866C4(&gRayquazaPostStoryPreFightDialogue_6);
  }
  else {
    PlaySoundEffect(0x1da); // Rayquaza Cry
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_1);
    RayquazaDropInEffect(RayquazaEntity);
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_2);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_3);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_4);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_5);
    SetupBossFightHP(RayquazaEntity,600,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void RayquazaDropInEffect(struct Entity *rayquazaEntity)
{
  s32 iVar1;
  s32 iVar2;

  rayquazaEntity->info->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 0x600;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 0x18;
    if (iVar1 < 0x14) {
      iVar1 = 0x14;
    }
    if (iVar2 < 0) break;
    rayquazaEntity->info->unk174 = iVar2;
    sub_803E46C(0x46);
  }
  rayquazaEntity->info->unk174 = 0;
}

void RayquazaScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, 0, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}


void sub_808970C(void)
{
  struct Entity *LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  DungeonStartNewBGM(MUS_TINY_WOODS);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8089908);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -3);
}

void sub_808974C(void)
{
  struct Entity *LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_80898F8);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -3);
}

void sub_8089788(struct Entity *param_1, u8 param_2, s32 param_3)
{
  struct Entity *iVar2;
  s32 iVar3;
  u32 unk1;

  unk1 = 0;

  if ((((param_3 * 0x1000000) + 0xe6000000U) >> 0x18) < 2) {
    for(iVar3 = 0; iVar3 < DUNGEON_MAX_WILD_POKEMON; iVar3++)
    {
      iVar2 = gDungeon->wildPokemon[iVar3];
      if ((EntityExists(iVar2) != '\0') && (iVar2 != param_1) && (iVar2->info->clientType == param_2)) {
        return;
      }
    }
    // WTF is this??
    if(!unk1){
        sub_8097FA8(0x11);
        gDungeon->unk2 = 1;
    }
  }
}

void sub_80897F0(void)
{
  struct Entity *LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(SpriteShockEffect);
  sub_803E708(0x20,0x46);
  sub_808692C();
  DisplayDungeonDialogue(&gUnknown_8103BD8);
  // We don't like to brag or
  // nothing, but
  DisplayDungeonDialogue(&gUnknown_8103C00);
  // We get furious real easy
  // You know that?!
  DisplayDungeonDialogue(&gUnknown_8103C3C);
  // What really irritates us is
  // when we see some dim witted face
  DisplayDungeonDialogue(&gUnknown_8103C74);
  // .........
  // Wrooooooar!
  // That vacant expression
  DisplayDungeonDialogue(&gUnknown_8103CC4);
  // Gwoooh
  // It's ticking me off!
  // I'm seeing red!
  DisplayDungeonDialogue(&gUnknown_8103D0C);
  // Mukkkeeeeeh
  // Get 'em! It's frenzy time!
  DisplayDungeonDialogue(&gUnknown_8103D50);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}



void sub_8089878(void)
{
  struct Entity *LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(SpriteShockEffect);
  sub_803E708(0x20,0x46);
  sub_808692C();
  DisplayDungeonDialogue(&gUnknown_8103D8C);
  DisplayDungeonDialogue(&gUnknown_8103D98);
  DisplayDungeonDialogue(&gUnknown_8103DD8);
  DisplayDungeonDialogue(&gUnknown_8103E28);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void sub_80898E4(void)
{
    sub_8086448();
    sub_80866C4(&gUnknown_8103E34);
}

void sub_80898F8(struct Entity *r0)
{
    sub_8068FE0(r0, 0x21C, 0);
}

void sub_8089908(struct Entity *r0)
{
    SetFacingDirection(r0, DIRECTION_NORTH);
}

void sub_8089914(void)
{
  struct Entity *LeaderEntity;
  struct Entity *MewtwoEntity;

  LeaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromClientType(0x11);
  DungeonStopBGM();
  gDungeon->unk7 = 1;
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(MewtwoEntity, DIRECTION_SOUTH);
  sub_8086A3C(MewtwoEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_MEWTWO);
}

void sub_8089978(void)
{
  struct Entity *LeaderEntity;
  struct Entity *MewtwoEntity;

  LeaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromClientType(0x11);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if(HasRecruitedMon(MONSTER_MEWTWO)){
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8068FE0(MewtwoEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(MewtwoEntity, DIRECTION_SOUTH);
    sub_8086A3C(MewtwoEntity);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_MEWTWO);
}

void sub_8089A00(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xE3000000U) >> 0x18 < 3) && (param_1 == 0x11)) {
    sub_8097FA8(0x13);
    gDungeon->unk2 = 1;
  }
}

void MewtwoPreFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *MewtwoEntity;

  LeaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromClientType(0x11);
  sub_8086448();
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_1);
  sub_803E708(10,0x46);
  DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
  sub_8086794();
  sub_803E708(0x1e,0x46);
  MewtwoDropInEffect(MewtwoEntity);
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_2);
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_3);
  sub_803E708(10,0x46);
  MewtwoScreenFlash();
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_4);
  MewtwoScreenFlash();
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_5);
  sub_803E708(10,0x46);
  SetupBossFightHP(MewtwoEntity,900,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void MewtwoReFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *MewtwoEntity;

  LeaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromClientType(0x11);
  sub_8086448();
  if(HasRecruitedMon(MONSTER_MEWTWO)) {
    sub_80866C4(&gMewtwoReFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_1);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8086794();
    MewtwoDropInEffect(MewtwoEntity);
    sub_803E708(0x3c,0x46);
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_2);
    MewtwoScreenFlash();
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_3);
    MewtwoScreenFlash();
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_4);
    SetupBossFightHP(MewtwoEntity,900,MUS_BATTLE_WITH_RAYQUAZA);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void MewtwoDropInEffect(struct Entity *mewtwoEntity)
{
  s32 iVar1;
  s32 iVar2;

  mewtwoEntity->info->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 0x400;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 11;
    if (iVar1 < 0x1e) {
      iVar1 = 0x1e;
    }
    if (iVar2 < 0) break;
    mewtwoEntity->info->unk174 = iVar2;
    sub_803E46C(0x46);
  }
  mewtwoEntity->info->unk174 = 0;
}

void MewtwoScreenFlash(void)
{
  int iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_8089C44(void)
{
  struct Entity * LeaderEntity;
  struct Entity * EnteiEntity;

  LeaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromClientType(0x12);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(EnteiEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_ENTEI);
}


void sub_8089C90(void)
{
  struct Entity * LeaderEntity;
  struct Entity * EnteiEntity;

  LeaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromClientType(0x12);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
      sub_8068FE0(EnteiEntity,0x21c,0);
  }
  else {
      SetFacingDirection(EnteiEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_ENTEI);
}


void sub_8089CFC(char param_1,int param_2)
{
  if ((((param_2 * 0x1000000) + 0xE0000000U) >> 0x18 < 3) && (param_1 == 0x12)) {
    sub_8097FA8(0x15);
    gDungeon->unk2 = 1;
  }
}


void EnteiPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * EnteiEntity;

  LeaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromClientType(0x12);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_1);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_2);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void EnteiReFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * EnteiEntity;

  LeaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromClientType(0x12);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_1);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_2);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void EnteiPostStoryPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * EnteiEntity;

  LeaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromClientType(0x12);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
    sub_80866C4(&gEnteiPostStoryPreFightDialogue_4);
  }
  else {
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_1);
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_2);
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void EnteiScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, 0, 0, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_8089EFC(void)
{
  struct Entity * LeaderEntity;
  struct Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_RAIKOU);
}


void sub_8089F44(void)
{
  struct Entity * LeaderEntity;
  struct Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_RAIKOU);
}


void sub_8089F8C(void)
{
  struct Entity * LeaderEntity;
  struct Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
      sub_8068FE0(RaikouEntity,0x21c,0);
  }
  else {
      SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_RAIKOU);
}

void sub_8089FF0(char param_1,int param_2)
{
  if ((((param_2 * 0x1000000) + 0xdD000000U) >> 0x18 < 3) && (param_1 == 0x13)) {
    sub_8097FA8(0x17);
    gDungeon->unk2 = 1;
  }
}


void RaikouPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_2);
  gDungeon->unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_3);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_4);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_5);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_6);
  sub_803E708(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void RaikouReFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  gDungeon->unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_2);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void RaikouPostStoryPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
    sub_80866C4(&gRaikouPostStoryPreFightDialogue_4);
  }
  else {
    gDungeon->unkE265 = WEATHER_RAIN;
    sub_807EAA0(0,1);
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_1);
    RaikouScreenFlash();
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_2);
    RaikouScreenFlash();
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void RaikouScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A264(void)
{
  struct Entity * LeaderEntity;
  struct Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  sub_8086A3C(SuicuneEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SUICUNE);
}

void sub_808A2C0(void)
{
  struct Entity * LeaderEntity;
  struct Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SUICUNE);
}

void sub_808A308(void)
{
  struct Entity * LeaderEntity;
  struct Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_SUICUNE)) {
     sub_8068FE0(SuicuneEntity,0x21c,0);
  }
  else {
     SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SUICUNE);
}

void sub_808A36C(char param_1,int param_2)
{
  if ((((param_2 * 0x1000000) + 0xda000000U) >> 0x18 < 3) && (param_1 == 0x14)) {
    sub_8097FA8(0x19);
    gDungeon->unk2 = 1;
  }
}

void SuicunePreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  sub_8086448();
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_1);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_2);
  sub_803E708(10,70);
  sub_80426C8(1,2);
  sub_803E708(0x3c,70);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_3);
  sub_803E708(10,70);
  sub_808A528(SuicuneEntity);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_4);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_5);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_6);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_7);
  sub_803E708(10,70);
  SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void SuicuneReFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  DisplayDungeonDialogue(&gSuicuneReFightDialogue_1);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicuneReFightDialogue_2);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicuneReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void SuicunePostStoryPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  if (HasRecruitedMon(MONSTER_SUICUNE)) {
    sub_80866C4(&gSuicunePostStoryPreFightDialogue_4);
  }
  else {
    DisplayDungeonDialogue(&gSuicunePostStoryPreFightDialogue_1);
    SuicuneScreenFlash();
    DisplayDungeonDialogue(&gSuicunePostStoryPreFightDialogue_2);
    SuicuneScreenFlash();
    DisplayDungeonDialogue(&gSuicunePostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void sub_808A528(struct Entity * param_1)
{
  s32 iVar1;
  s32 iVar2;

  param_1->info->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 3072;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 96;
    if (iVar1 < 20) {
      iVar1 = 20;
    }
    if (iVar2 < 0) break;
    param_1->info->unk174 = iVar2;
    sub_803E46C(70);
  }
  param_1->info->unk174 = 0;
}

void SuicuneScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A608(void)
{
  struct Entity * LeaderEntity;
  struct Entity * HoOhEntity;

  LeaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromClientType(0x15);
  DungeonStartNewBGM(MUS_FRIEND_AREA_RAINBOW_PEAK);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(HoOhEntity, DIRECTION_SOUTH);
  sub_8086A3C(HoOhEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -6);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_HO_OH);
}

void sub_808A668(void)
{
  struct Entity * LeaderEntity;
  struct Entity * HoOhEntity;

  LeaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromClientType(0x15);
  DungeonStartNewBGM(MUS_FRIEND_AREA_RAINBOW_PEAK);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_HO_OH)) {
    sub_8068FE0(HoOhEntity,0x21c,0);
  }
  else {
    SetFacingDirection(HoOhEntity, DIRECTION_SOUTH);
    sub_8086A3C(HoOhEntity);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 6);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_HO_OH);
}

void sub_808A6E8(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xd7000000U) >> 0x18 < 2) && (param_1 == 0x15)) {
    sub_8097FA8(0x1A);
    gDungeon->unk2 = 1;
  }
}


void sub_808A718(void)
{
    sub_8086854();
}

void HoOhPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * HoOhEntity;
  struct Position32 local_14;

  LeaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromClientType(0x15);
  local_14.x = LeaderEntity->pixelPos.x;
  local_14.y = LeaderEntity->pixelPos.y + -0x1000;
  ShiftCameraToPosition(&local_14,0x88);
  sub_803E708(0x40,70);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_1);
  sub_803E708(10,70);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_2);
  sub_803E708(10,70);
  sub_80855E4(sub_80868F4);
  sub_808680C();
  PlaySoundEffect(0x1c5);
  sub_803E708(0xfa,70);
  HoOhDropInEffect(HoOhEntity);
  StopSoundEffect(0x1c5);
  sub_808682C();
  sub_80855E4(sub_8086910);
  sub_8085930(DIRECTION_NORTH);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_3);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_4);
  sub_803E708(0x1e,70);
  sub_803E708(0x1e,70);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_5);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_6);
  sub_803E708(10,70);
  SetupBossFightHP(HoOhEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void HoOhReFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * HoOhEntity;
  struct Position32 local_14;

  LeaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromClientType(0x15);

  local_14.x = LeaderEntity->pixelPos.x;
  local_14.y = LeaderEntity->pixelPos.y + -0x1000;
  ShiftCameraToPosition(&local_14,0x88);
  sub_803E708(0x40,70);
  if (HasRecruitedMon(MONSTER_HO_OH)) {
    sub_80866C4(&HoOhReFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(&HoOhReFightDialogue_1);
    HoOhScreenFlash();
    sub_80855E4(sub_80868F4);
    sub_808680C();
    sub_803E708(10,70);
    HoOhDropInEffect(HoOhEntity);
    sub_808682C();
    sub_80855E4(sub_8086910);
    sub_8085930(DIRECTION_NORTH);
    DisplayDungeonDialogue(&HoOhReFightDialogue_2);
    HoOhScreenFlash();
    DisplayDungeonDialogue(&HoOhReFightDialogue_3);
    HoOhScreenFlash();
    DisplayDungeonDialogue(&HoOhReFightDialogue_4);
    sub_803E708(10,70);
    SetupBossFightHP(HoOhEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void HoOhDropInEffect(struct Entity * param_1)
{
  s32 iVar1;
  s32 iVar2;

  param_1->info->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 3072;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 96;
    if (iVar1 < 20) {
      iVar1 = 20;
    }
    if (iVar2 < 0) break;
    param_1->info->unk174 = iVar2;
    sub_803E46C(70);
  }
  param_1->info->unk174 = 0;
}

void HoOhScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A9E4(void)
{
  struct Entity * LeaderEntity;
  struct Entity * LatiosEntity;

  LeaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromClientType(0x16);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(LatiosEntity, DIRECTION_NORTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 4);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_LATIOS);
}

void sub_808AA3C(void)
{
  struct Entity * LeaderEntity;
  struct Entity * LatiosEntity;

  LeaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromClientType(0x16);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(LatiosEntity, DIRECTION_NORTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_LATIOS);
}

void sub_808AA94(void)
{
  struct Entity * LeaderEntity;
  struct Entity * LatiosEntity;

  LeaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromClientType(0x16);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(LatiosEntity,0x21c,0);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_LATIOS);
}

void sub_808AAF0(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xd5000000U) >> 0x18 < 3) && (param_1 == 0x16)) {
    sub_8097FA8(0x1c);
    gDungeon->unk2 = 1;
  }
}

void LatiosPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * LatiosEntity;
  struct Position32 local_18;
  u32 local_19;

  LeaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromClientType(0x16);

  local_18.x = LatiosEntity->pixelPos.x;
  local_18.y = LatiosEntity->pixelPos.y + (0x80 << 6);
  local_19 = 0x7000fc;
  sub_8085EC8(0x1bd,0,0,&local_19,1);

  sub_803E708(0x1e,70);
  sub_8086448();
  ShiftCameraToPosition(&local_18,0x18);
  sub_803E708(2,70);
  SpriteShockEffect(LatiosEntity);
  sub_803E708(0x20,70);
  sub_808692C();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_1);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_2);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(LatiosEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void LatiosReFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * LatiosEntity;

  LeaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromClientType(0x16);
  sub_8086448();
  sub_808692C();
  DisplayDungeonDialogue(&gLatiosReFightDialogue_1);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_2);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(LatiosEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void sub_808AC3C(void)
{
    sub_8086448();
    // There appears to be no one here
    sub_80866C4(&gUnknown_8104FC8);
}

void LatiosScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
  gUnknown_202EDC8 = 0x1f;
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808ACC0(void)
{
  struct Entity * uVar2;

  if (HasRecruitedMon(MONSTER_REGIROCK)) {
    uVar2 = GetEntityFromClientType(0x17);
    sub_8068FE0(uVar2,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ROCK_PART);
  }
  else if (sub_80860A8(ITEM_ROCK_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_REGIROCK);
  }
}

void sub_808AD48(void)
{
  struct Entity * uVar2;

  if (HasRecruitedMon(MONSTER_REGICE)) {
    uVar2 = GetEntityFromClientType(0x18);
    sub_8068FE0(uVar2,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ICE_PART);
  }
  else if (sub_80860A8(ITEM_ICE_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_REGICE);
  }
}

void sub_808ADCC(void)
{

  struct Entity * uVar2;

  if (HasRecruitedMon(MONSTER_REGISTEEL)) {
    uVar2 = GetEntityFromClientType(0x19);
    sub_8068FE0(uVar2,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_STEEL_PART);
  }
  else if (sub_80860A8(ITEM_STEEL_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_REGISTEEL);
  }
}

void sub_808AE54(char param_1,char param_2,u32 *param_3)
{
  struct Entity * LeaderEntity;
  s16 IDStack[2];
  struct Item item;


  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x2E) && (param_1 == 0x17)) {
    sub_808B1CC(0);
    if (sub_8098100(0x1d) == 0) {
      xxx_init_itemslot_8090A8C(&item,ITEM_ROCK_PART,0);
      sub_80464C8(GetLeader(),param_3,&item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Regirock's body
      // Regirock was apparently guarding this item
      DisplayDungeonDialogue(&gRegirockPostFightDialogue_1);
    }
  }
}


void sub_808AEC8(char param_1,char param_2,u32 *param_3)
{
  struct Entity * LeaderEntity;
  s16 IDStack[2];
  struct Item item;


  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x2F) && (param_1 == 0x18)) {
    sub_808B1CC(0);
    if (sub_8098100(0x1d) == 0) {
      xxx_init_itemslot_8090A8C(&item,ITEM_ICE_PART,0);
      sub_80464C8(GetLeader(),param_3,&item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Regice's body
      // Regice was apparently guarding this item
      DisplayDungeonDialogue(&gRegicePostFightDialogue_1);
    }
  }
}

void sub_808AF3C(char param_1,char param_2,u32 *param_3)
{
  struct Entity * LeaderEntity;
  s16 IDStack[2];
  struct Item item;


  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x30) && (param_1 == 0x19)) {
    sub_808B1CC(0);
    if (sub_8098100(0x1d) == 0) {
      xxx_init_itemslot_8090A8C(&item,ITEM_STEEL_PART,0);
      sub_80464C8(GetLeader(),param_3, &item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Registeel's body
      // Registeel was apparently guarding this item
      DisplayDungeonDialogue(&gRegisteelPostFightDialogue_1);
    }
  }
}

void sub_808AFB0(char param_1)
{
  struct Entity * LeaderEntity;
  s16 IDStack [2];

  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x2E) && (sub_8098100(0x1d) == 0) && (sub_80860A8(ITEM_ROCK_PART) != 0)) {
    sub_8097FD0(0x1d);
    SetMessageArgument(gAvailablePokemonNames,GetLeader(),0);
    // {ARG_POKEMON_0} obtained the Rock Part that Regirock was guarding
    DisplayDungeonDialogue(&gRegirockPostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B030(char param_1)
{
  struct Entity * LeaderEntity;
  s16 IDStack [2];

  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x2F) && (sub_8098100(0x1d) == 0) && (sub_80860A8(ITEM_ICE_PART) != 0)) {
    sub_8097FD0(0x1d);
    SetMessageArgument(gAvailablePokemonNames,GetLeader(),0);
    // {ARG_POKEMON_0} obtained the Ice Part that Regice was guarding
    DisplayDungeonDialogue(&gRegicePostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B0B0(char param_1)
{
  struct Entity * LeaderEntity;
  s16 IDStack [2];

  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x30) && (sub_8098100(0x1d) == 0) && (sub_80860A8(ITEM_STEEL_PART) != 0)) {
    sub_8097FD0(0x1d);
    SetMessageArgument(gAvailablePokemonNames, GetLeader(), 0);
    // {ARG_POKEMON_0} obtained the Steel Part that Registeel was guarding
    DisplayDungeonDialogue(&gRegisteelPostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void RegirockPreFightDialogue(void)
{
  if (sub_8098100(0x22) == '\0') {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegirockPreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegirockFightHP);
  }
}

void RegicePreFightDialogue(void)
{
  if (sub_8098100(0x22) == '\0') {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegicePreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegiceFightHP);
  }
}

void RegisteelPreFightDialogue(void)
{
  if (sub_8098100(0x22) == '\0') {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegisteelPreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegisteelFightHP);
  }
}

NAKED
void sub_808B1CC(u8 r0)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tsub sp, 0x8\n"
	"\tlsls r0, 24\n"
	"\tlsrs r6, r0, 24\n"
	"\tldr r7, _0808B21C\n"
	"\tldr r2, [r7]\n"
	"\tldr r1, _0808B220\n"
	"\tadds r0, r2, r1\n"
	"\tldrh r0, [r0]\n"
	"\tldr r5, _0808B224\n"
	"\tldr r1, [sp]\n"
	"\tands r1, r5\n"
	"\torrs r1, r0\n"
	"\tstr r1, [sp]\n"
	"\tldr r3, _0808B228\n"
	"\tadds r2, r3\n"
	"\tldrh r0, [r2]\n"
	"\tlsls r0, 16\n"
	"\tldr r4, _0808B22C\n"
	"\tadds r2, r4, 0\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp]\n"
	"\tmov r0, sp\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tcmp r0, 0\n"
	"\tblt _0808B208\n"
	"\tcmp r2, 0\n"
	"\tbge _0808B244\n"
"_0808B208:\n"
	"\tbl GetLeader\n"
	"\tadds r2, r0, 0\n"
	"\tcmp r2, 0\n"
	"\tbne _0808B230\n"
	"\tldr r1, [r7]\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1, 0x2]\n"
	"\tb _0808B2A8\n"
	"\t.align 2, 0\n"
"_0808B21C: .4byte gDungeon\n"
"_0808B220: .4byte 0x00000684\n"
"_0808B224: .4byte 0xffff0000\n"
"_0808B228: .4byte 0x00000686\n"
"_0808B22C: .4byte 0x0000ffff\n"
"_0808B230:\n"
	"\tldrh r0, [r2, 0x4]\n"
	"\tldr r1, [sp]\n"
	"\tands r1, r5\n"
	"\torrs r1, r0\n"
	"\tstr r1, [sp]\n"
	"\tldrh r0, [r2, 0x6]\n"
	"\tlsls r0, 16\n"
	"\tands r1, r4\n"
	"\torrs r1, r0\n"
	"\tstr r1, [sp]\n"
"_0808B244:\n"
	"\tmov r5, sp\n"
	"\tmov r0, sp\n"
	"\tmovs r1, 0\n"
	"\tbl sub_807FE04\n"
	"\tmov r0, sp\n"
	"\tmovs r2, 0\n"
	"\tldrsh r0, [r0, r2]\n"
	"\tmovs r3, 0x2\n"
	"\tldrsh r1, [r5, r3]\n"
	"\tbl GetTileSafe\n"
	"\tldrh r2, [r0]\n"
	"\tmovs r3, 0x80\n"
	"\tlsls r3, 2\n"
	"\tadds r1, r3, 0\n"
	"\torrs r1, r2\n"
	"\tstrh r1, [r0]\n"
	"\tcmp r6, 0\n"
	"\tbeq _0808B2A0\n"
	"\tadds r0, r6, 0\n"
	"\tbl sub_80860A8\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0808B2A0\n"
	"\tmovs r0, 0x7A\n"
	"\tbl sub_80860A8\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0808B2A0\n"
	"\tadd r4, sp, 0x4\n"
	"\tadds r0, r4, 0\n"
	"\tadds r1, r6, 0\n"
	"\tmovs r2, 0\n"
	"\tbl xxx_init_itemslot_8090A8C\n"
	"\tldrh r0, [r5, 0x2]\n"
	"\tsubs r0, 0x1\n"
	"\tstrh r0, [r5, 0x2]\n"
	"\tmov r0, sp\n"
	"\tadds r1, r4, 0\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_80460F8\n"
"_0808B2A0:\n"
	"\tbl sub_8049ED4\n"
	"\tbl sub_8040A84\n"
"_0808B2A8:\n"
	"\tadd sp, 0x8\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0");
}


void SetupRegiFacingDirection(struct Entity *regiEntity)
{
    regiEntity->info->action.direction = DIRECTION_NORTH;
    sub_806CE68(regiEntity, DIRECTION_NORTH);
}


void SetupRegirockFightHP(struct Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}


void SetupRegiceFightHP(struct Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}


void SetupRegisteelFightHP(struct Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}

void sub_808B2F4(void)
{
  struct Entity * LeaderEntity;
  struct Entity * JirachiEntity;

  LeaderEntity = xxx_call_GetLeader();
  JirachiEntity = GetEntityFromClientType(0x1a);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  sub_808BCE4();
  sub_8049ED4();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(JirachiEntity, DIRECTION_SOUTH);
  sub_8086A3C(JirachiEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_JIRACHI);
}

void sub_808B35C(void)
{
  struct Entity * LeaderEntity;
  struct Entity * JirachiEntity;

  LeaderEntity = xxx_call_GetLeader();
  JirachiEntity = GetEntityFromClientType(0x1a);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_JIRACHI)) {
    sub_8068FE0(JirachiEntity,0x21c,0);
  }
  else {
    SetFacingDirection(JirachiEntity, DIRECTION_SOUTH);
    sub_8086A3C(JirachiEntity);
    sub_808BCE4();
    sub_8049ED4();

  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_JIRACHI);
}

#ifdef NONMATCHING
void sub_808B3E4(u8 param_1,u8 param_2,u8 param_3)
{
  u8 uVar1;

  // TODO R1 and R2 shifts are switched ordering but matches
  if (((((param_2 * 0x1000000) + 0xcf000000U) >> 0x18) < 2) && (param_1 == 0x1A)){
    sub_8097FA8(0x1e);
    if (param_3 != 0) {
      gDungeon->unk2 = 1;
    }
    else {
      uVar1 = gDungeon->unk1356C;
      if (sub_80860A8(0x36) != 0) {
           JirachiWish();
      }
      else {
          sub_808B50C();
      }
      gDungeon->unk1356C = uVar1;
      sub_8040A84();
    }
  }
}
#else
NAKED
void sub_808B3E4(u8 param_1, u8 param_2, u8 param_3)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tlsls r1, 24\n"
	"\tlsls r2, 24\n"
	"\tlsrs r4, r2, 24\n"
	"\tmovs r2, 0xCF\n"
	"\tlsls r2, 24\n"
	"\tadds r1, r2\n"
	"\tlsrs r1, 24\n"
	"\tcmp r1, 0x1\n"
	"\tbhi _0808B44E\n"
	"\tcmp r0, 0x1A\n"
	"\tbne _0808B44E\n"
	"\tmovs r0, 0x1E\n"
	"\tbl sub_8097FA8\n"
	"\tcmp r4, 0\n"
	"\tbeq _0808B418\n"
	"\tldr r0, _0808B414\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1, 0x2]\n"
	"\tb _0808B44E\n"
	"\t.align 2, 0\n"
"_0808B414: .4byte gDungeon\n"
"_0808B418:\n"
	"\tldr r0, _0808B434\n"
	"\tldr r0, [r0]\n"
	"\tldr r1, _0808B438\n"
	"\tadds r0, r1\n"
	"\tldrb r4, [r0]\n"
	"\tmovs r0, 0x36\n"
	"\tbl sub_80860A8\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _0808B43C\n"
	"\tbl JirachiWish\n"
	"\tb _0808B440\n"
	"\t.align 2, 0\n"
"_0808B434: .4byte gDungeon\n"
"_0808B438: .4byte 0x0001356c\n"
"_0808B43C:\n"
	"\tbl sub_808B50C\n"
"_0808B440:\n"
	"\tldr r0, _0808B454\n"
	"\tldr r0, [r0]\n"
	"\tldr r2, _0808B458\n"
	"\tadds r0, r2\n"
	"\tstrb r4, [r0]\n"
	"\tbl sub_8040A84\n"
"_0808B44E:\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0808B454: .4byte gDungeon\n"
"_0808B458: .4byte 0x0001356c");
}
#endif

void JirachiPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * JirachiEntity;

  LeaderEntity = xxx_call_GetLeader();
  JirachiEntity = GetEntityFromClientType(0x1a);
  sub_8086448();
  sub_803E708(0x40,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_1);
  sub_803E708(10,70);
  SpriteLookAroundEffect(LeaderEntity);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_2);
  sub_80861F8(0x37,JirachiEntity,1);
  sub_80855E4(SpriteShockEffect);
  sub_803E708(0x3c,70);
  JirachiDropInEffect(JirachiEntity);
  sub_803E708(0x5a,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_3);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_4);
  sub_803E708(10,70);
  SetupBossFightHP(JirachiEntity,0x15e,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void sub_808B50C(void)
{
  struct Entity * JirachiEntity;

  JirachiEntity = GetEntityFromClientType(0x1a);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(JirachiEntity);
  sub_8041888(0);
  JirachiEntity->info->unk15C = 1;
  JirachiEntity->info->unk15E = 0;
  sub_80861B8(JirachiEntity,0xe,0);
  DungeonFadeOutBGM(0x1e);
  sub_803E708(0x1e,70);
  // Fwaaaahhhh
  DisplayDungeonDialogue(&gUnknown_810554C);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  // I think I had a dream, and I was fighting in it
  // Did I imagine it?
  // I'm sleepy so I'm going back to sleep.
  DisplayDungeonDialogue(&gUnknown_8105558);
  sub_803E708(10,70);
  JirachiSpinEffect(JirachiEntity);
  DisplayDungeonDialogue(&gUnknown_81055F4);
  sub_803E708(10,70);
  gDungeon->unk2 = 1;
}

void JirachiWish(void)
{
  u8 friendArea;
  struct Entity *JirachiEntity;
  struct Position *LeaderPos;
  struct Entity *LeaderEntity;
  s32 wishChoice;
  s32 counter;
  u32 direction;
  s32 index;
  struct Item money [9];
  struct Item itemStack [9];
  struct Item strengthItems [9];
  s32 local_2c;
  s32 local_28;
  s32 local_24;
  s32 temp;
  s32 temp2;
  s32 temp3;

  JirachiEntity = GetEntityFromClientType(0x1a);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(JirachiEntity);
  sub_8041888(0);
  JirachiEntity->info->unk15C = 1;
  JirachiEntity->info->unk15E = 0;
  sub_80861B8(JirachiEntity,0xe,0);
  sub_80855E4(sub_80861A8);
  gDungeon->unk1356C = 1;
  DungeonFadeOutBGM(0x1e);
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&gUnknown_8105668);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1a7);
  sub_803E708(0x96,0x46);
  SpriteShockEffect(JirachiEntity);
  DisplayDungeonDialogue(&gUnknown_8105674);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  sub_803E708(10,0x46);
  sub_80856E0(JirachiEntity, DIRECTION_SOUTH);
  PlaySoundEffect(0x16a);
  DisplayDungeonDialogue(&gUnknown_81056B8);
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(JirachiEntity);
  DisplayDungeonDialogue(&gUnknown_81056DC);
  sub_803E708(10,0x46);
  while( 1 ) {
    while (1) {
#ifndef NONMATCHING
        register s32 r0 asm("r0");
        asm("mov\t%0, #0":"=r"(r0));
#else
        s32 r0 = 0;
#endif
        wishChoice = sub_8052C68(r0,*gUnknown_8105798,&gUnknown_810579C,0x705);
        if (wishChoice >= 1) break;
    }
    sub_803E708(10,0x46);
    if (wishChoice == 1) {
      s32 r8;
      // Lots of Money
      DisplayDungeonDialogue(&gUnknown_810581C);
      sub_803E708(10,0x46);
      JirachiWishGrantDialogue(JirachiEntity);

      for(counter = 0; counter < 6; counter = r8)
      {
        r8 = counter + 1;
        for(index = 0; index < 9; index++)
        {
          sub_8045C28(&money[index], 0x69, 0);
        }
        temp = (u16)(((((u16)JirachiEntity->pos.x + DungeonRandInt(3)) - 1) << 16) >> 16);
        local_2c &= 0xffff0000;
        local_2c |= temp;

        temp = ((u16)JirachiEntity->pos.y + DungeonRandInt(3) + -1) * 0x10000;
        local_2c &= 0xffff;
        local_2c |= temp;
        if ((GetTileSafe((s16)local_2c, local_2c >> 16)->terrainType & 3) != 0) {
          PlaySoundEffect(0x14c);
          sub_808BB3C((s16 *)&local_2c);
          sub_8046860(JirachiEntity,&local_2c,money,9);
        }
      }
      JirachiEntity->info->unk15D  = 0;
    }
    if (wishChoice == 2) {
      // Lots of Items
      DisplayDungeonDialogue(&gUnknown_8105974);
      sub_803E708(10,0x46);
      JirachiWishGrantDialogue(JirachiEntity);

      for(counter = 0; counter < 6; counter++)
      {
#ifndef NONMATCHING
        asm("":::"sl");
#endif
        for(index = 0; index < 9; index++)
        {
          sub_8045C28(&itemStack[index], sub_803D73C(0),0);
        }
        temp2 = (u16)(((((u16)JirachiEntity->pos.x + DungeonRandInt(3)) - 1) << 16) >> 16);
        local_28 &= 0xffff0000;
        local_28 |= temp2;

        temp2 = ((u16)JirachiEntity->pos.y + DungeonRandInt(3) + -1) * 0x10000;
        local_28 &= 0xffff;
        local_28 |= temp2;
        if ((GetTileSafe((s16)local_28, local_28 >> 16)->terrainType & 3) != 0) {
          PlaySoundEffect(400);
          sub_808BB3C((s16 *)&local_28);
          sub_8046860(JirachiEntity,&local_28,itemStack,9);
        }
      }
      JirachiEntity->info->unk15D = 0;
    }

    if (wishChoice == 3)
    {
        // A Friend Area
        friendArea = JirachiFriendAreaSearch();
        if (friendArea == NUM_FRIEND_AREAS)
        {
            // You want a friend area? But you already have many friend areas...
            DisplayDungeonDialogue(&gUnknown_8105A08);
            sub_803E708(10,0x46);
            continue;
        }
        else
        {
        // You want a friend area? As you wish..
          DisplayDungeonDialogue(&gUnknown_8105AD4);
          sub_803E708(10,0x46);
          JirachiWishGrantDialogue(JirachiEntity);
          JirachiEntity->info->unk15D  = 0;
          DisplayDungeonDialogue(&gUnknown_8105B20);
          UnlockFriendArea(friendArea);
          PlaySoundEffect(0xd4);
          LeaderEntity = GetLeader();
          SetMessageArgument(gAvailablePokemonNames,LeaderEntity,0);
          sub_8092578(gUnknown_202DE58,friendArea,0);
          // Obtained the friend area!
          DisplayDungeonDialogue(&gUnknown_8105B68);
        }
    }
    if (wishChoice == 4) {
        // More Strength..
        DisplayDungeonDialogue(&gUnknown_8105BA8);
        sub_803E708(10,0x46);
        JirachiWishGrantDialogue(JirachiEntity);

        for(counter = 0; counter < 5; counter++)
        {

          for(index = 0; index < 4; index++)
          {
            sub_8045C28(&strengthItems[index],gUnknown_81074FC[DungeonRandInt(8)],0);
          }
          temp3 = (u16)(((((u16)JirachiEntity->pos.x + DungeonRandInt(3)) - 1) << 16) >> 16);
          local_24 &= 0xffff0000;
          local_24 |= temp3;

          temp3 = ((u16)JirachiEntity->pos.y + DungeonRandInt(3) + -1) * 0x10000;
          local_24 &= 0xffff;
          local_24 |= temp3;
          if ((GetTileSafe((s16)local_24, local_24 >> 16)->terrainType & 3) != 0) {
            PlaySoundEffect(400);
            sub_808BB3C((s16 *)&local_24);
            sub_8046860(JirachiEntity,&local_24,strengthItems,4);
          }
        }
        JirachiEntity->info->unk15D  = 0;
        DisplayDungeonDialogue(&gUnknown_8105BF4);
        sub_803E708(10,0x46);
    }
    if (wishChoice == 5) {
        // Something Good...
        DisplayDungeonDialogue(&gUnknown_8105D2C);
        sub_803E708(10,0x46);
        JirachiWishGrantDialogue(JirachiEntity);
        JirachiEntity->info->unk15D  = 0;
        DisplayDungeonDialogue(&gUnknown_8105D80);
        sub_803E708(10,0x46);
        LeaderPos = &GetLeader()->pos;
        direction = GetDirectionTowardsPosition(&JirachiEntity->pos,LeaderPos);
        SetFacingDirection(JirachiEntity,direction);
        sub_803E708(10,0x46);
        DisplayDungeonDialogue(&gUnknown_8105D9C);
        sub_803E708(10,0x46);
        gDungeon->unk674 = 1;
    }
    break;
  }

  DisplayDungeonDialogue(&gUnknown_81058E0);
  JirachiSpinEffect(JirachiEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gUnknown_810593C);
  sub_803E708(10,0x46);
  sub_808BD38();
}

void JirachiReFightDialogue(void)
{
    if(HasRecruitedMon(MONSTER_JIRACHI))
    {
        sub_8086448();
        sub_80866C4(&gJirachiReFightDialogue_1);
    }
    else
    {
        JirachiPreFightDialogue();
    }
}

void JirachiWishGrantFlash(void)
{
  s32 iVar1;
  
  PlaySoundEffect(0x2c1);
  gUnknown_202EDC8 = 0x1f;

  for(iVar1 = 0xFA; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 0xFA; iVar1 > 0xC7; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 0xFA; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808BB3C(s16 *param_1)
{
#ifndef NONMATCHING
  register s32 iVar1 asm("r0");
#else
  s32 iVar1;
#endif
  s32 uVar2;
  u32 local_8;
  
  iVar1 = param_1[0] * 0x1800 + 0xc00;
  if (iVar1 < 0) {
    iVar1 += 0xff;
  }

  iVar1 <<= 8;
  iVar1 = (u16)(iVar1 >> 16);

  uVar2 = (local_8 & 0xffff0000) | iVar1;
  local_8 = uVar2;

  iVar1 = param_1[1] * 0x1800 + 0x1000;
  if (iVar1 < 0) {
    iVar1 += 0xff;
  }

  iVar1 <<= 8;
  iVar1 = (u16)(iVar1 >> 0x10);
  iVar1 <<= 0x10;

  local_8 = (iVar1) | (uVar2 & 0x0000ffff);
  sub_8085EC8(100,0,0,&local_8,0);
}

void sub_808BBA8(struct Entity *jirachiEntity)
{
  sub_806BFC0(jirachiEntity->info,0);
}

void JirachiDropInEffect(struct Entity *jirachiEntity)
{
  s32 iVar1;
  s32 iVar2;

  sub_80861F8(0x1b,jirachiEntity,0);
  sub_8086A54(jirachiEntity);
  sub_80861B8(jirachiEntity,0xe,0);
  iVar1 = 0xa000;
  iVar2 = 0x200;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar1 = iVar1 - iVar2;
    if (iVar1 < 0x1800) {
      iVar2 = 0x100;
    }
    if (iVar1 < 0) break;
    jirachiEntity->info->unk174 = iVar1;
    sub_803E46C(0x46);
  }
 jirachiEntity->info->unk174 = 0;
}

void JirachiSpinEffect(struct Entity * jirachiEntity)
{
  s32 uVar1;

  PlaySoundEffect(0x298);
  for(uVar1 = 0; uVar1 < 25; uVar1++){
    SetFacingDirection(jirachiEntity, uVar1 & DIRECTION_MASK);
    sub_803E708(3,0x46);
  }
  jirachiEntity->info->unk15E = 1;
  PlaySoundEffect(0x27f);
  sub_80861F8(99,jirachiEntity,1);
}

void JirachiWishGrantDialogue(struct Entity *jirachiEntity)
{
  u32 uVar2;

  jirachiEntity->info->unk15D = 1;
  // Nnnnnnnnnn!
  DisplayDungeonDialogue(&gUnknown_81058A8);
  PlaySoundEffect(0x375);
  sub_80861F8(0x67,jirachiEntity,1);
  PlaySoundEffect(0x2a8);
  uVar2 = sub_80861F8(0x68,jirachiEntity,0);
  // Taaaaaaaah!
  DisplayDungeonDialogue(&gUnknown_81058C4);
  if (sub_800E9A8(uVar2) != 0) {
    sub_800DC14(uVar2);
  }
  sub_803E708(10,0x46);
  JirachiWishGrantFlash();
}

void sub_808BCE4(void)
{
  struct Tile *puVar1;

  puVar1 = GetTileSafe(gDungeon->unkE23C, gDungeon->unkE23E);
  puVar1->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  puVar1->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
  puVar1->terrainType &= ~TERRAIN_TYPE_STAIRS;
  sub_8049884();
  sub_8049B8C();
  sub_8049ED4();
  sub_8040A84();
}

void sub_808BD38(void)
{
  struct Tile *puVar1;

  puVar1 = GetTileSafe(gDungeon->unkE23C, gDungeon->unkE23E);
  puVar1->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  puVar1->terrainType |= TERRAIN_TYPE_NORMAL;
  puVar1->terrainType &= ~TERRAIN_TYPE_IMPASSABLE_WALL;
  puVar1->terrainType |= TERRAIN_TYPE_STAIRS;
  puVar1->unk8 = 1;
  sub_8049884();
  sub_8049B8C();
  sub_8049ED4();
  sub_8040A84();
}

u8 JirachiFriendAreaSearch(void)
{
  u8 unlockCondition;
  s32 friendAreaCounter;
  s32 numUnlockableAreas;
  u8 friendAreas[NUM_FRIEND_AREAS];
  u32 friendAreaIndex;

  // Build a copy of friend area list and keep track of
  // how many are only Story Unlockable
  numUnlockableAreas = 0;
  for(friendAreaCounter = 1; friendAreaCounter < NUM_FRIEND_AREAS; friendAreaCounter++){
    unlockCondition = GetFriendAreaUnlockCondition(friendAreaCounter);
    if (!(unlockCondition == UNLOCK_LEGENDARY_REQUEST)){
        if (!(unlockCondition == UNLOCK_WONDER_MAIL)){
            if(!gFriendAreas[friendAreaCounter]) {
                friendAreas[numUnlockableAreas] = friendAreaCounter;
                numUnlockableAreas++;
            }
        }
    }
  }

  if (numUnlockableAreas == 0) {
    return NUM_FRIEND_AREAS;
  }
  else {
      // Randomly pick 1
    friendAreaIndex = DungeonRandInt(numUnlockableAreas);
    return friendAreas[friendAreaIndex];
  }
}

void sub_808BDEC(void)
{
  struct Entity * LeaderEntity;
  struct Entity * LugiaEntity;

  LeaderEntity = xxx_call_GetLeader();
  LugiaEntity = GetEntityFromClientType(0x1b);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_LUGIA)) {
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8068FE0(LugiaEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(LugiaEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_LUGIA);
}

void sub_808BE70(u8 param_1,u8 param_2)
{
  if ((param_2 == 0x33) && (param_1 == 0x1B)) {
    gDungeon->unk2 = 1;
  }
}


void LugiaPreFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * LugiaEntity;

  LeaderEntity = xxx_call_GetLeader();
  LugiaEntity = GetEntityFromClientType(0x1b);
  if (HasRecruitedMon(MONSTER_LUGIA)) {
    sub_8086448();
    sub_80866C4(&gLugiaPreFightDialogue_8);
  }
  else {
    DungeonStopBGM();
    sub_8086448();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_1);
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    sub_808C0CC();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_2);
    LugiaScreenFlash();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_3);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_4);
    PlaySoundEffect(0x1f8);
    sub_80861D4(LugiaEntity,0xd,0);
    sub_803E708(0x2b,0x46);
    sub_80861B8(LugiaEntity,0,0);
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_5);
    LugiaScreenFlash();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_6);
    LugiaScreenFlash2();
    SetDungeonBGColorRGB(0xffffff06,0xffffff06,0xffffff06,1,0);
    DungeonStopBGM();
    sub_80861D4(LugiaEntity,7,0);
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_7);
    LugiaScreenFlash();
    SetupBossFightHP(LugiaEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void LugiaScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void LugiaScreenFlash2(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);

  for(iVar1 = 0; iVar1 < 200; iVar1 += 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  sub_803E708(4,0x46);

  for(iVar1 = 0; iVar1 < 200; iVar1 += 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C0CC(void)
{
  gUnknown_202EDC8 = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  sub_803E9D0();
  sub_803E46C(0x46);
  gDungeon->unk7 = 0;
  LugiaScreenFlash();
}

void sub_808C10C(void)
{
  struct Entity * LeaderEntity;
  struct Entity * KyogreEntity;

  u32 XPos;
  s32 YPos;

  LeaderEntity = xxx_call_GetLeader();
  KyogreEntity = GetEntityFromClientType(0x1c);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_KYOGRE)) {
    sub_8068FE0(KyogreEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(KyogreEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + -0x1000);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_KYOGRE);
  // TODO: gUnknown_202E088 doesn't match but gUnknown_202E038 + 0x50 does
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_GROUDON);
}

void sub_808C1A4(u8 param_1,u8 param_2)
{
  if ((param_2 == 0x34) && (param_1 == 0x1C)) {
    gDungeon->unk2 = 1;
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
  }
}

void KyogrePreFightDialogue(void)
{
  struct Entity *LeaderEntity;
  struct Entity *KyogreEntity;

  LeaderEntity = xxx_call_GetLeader();
  KyogreEntity = GetEntityFromClientType(0x1c);
  DungeonStopBGM();
  if (HasRecruitedMon(MONSTER_KYOGRE)) {
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    SpriteLookAroundEffect(LeaderEntity);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_8);
    sub_803E708(10,0x46);
    gDungeon->unk2 = 1;
  }
  else {
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_1);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_2);
    sub_803E708(10,0x46);
    nullsub_99();
    sub_803E708(10,0x46);
    // Gwwwwwooooooooh
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_3);
    sub_803E708(10,0x46);
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    sub_808C360();
    // My duels against {ARG_POKEMON_3} (Groudon) left us both exhausted
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_4);
    KyogreScreenFlash();
    // I am {ARG_POKEMON_2} (Kyogre)!
    // The lord of the sea!
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_5);
    KyogreScreenFlash();
    // Witness the destructive force of my waves!
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_6);
    KyogreScreenFlash();
    // Marvel at my awesome
    // power!
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_7);
    sub_803E708(10,0x46);
    SetupBossFightHP(KyogreEntity,600,MUS_BOSS_BATTLE);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void nullsub_99(void)
{
}

void KyogreScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f8);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C360(void)
{
  gUnknown_202EDC8 = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  sub_803E9D0();
  sub_803E46C(0x46);
  gDungeon->unk7 = 0;
  KyogreScreenFlash();
}

void sub_808C3A0(void)
{
  struct Entity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_DEOXYS_NORMAL)) {
    sub_808563C(sub_808C590);
  }
  else {
    gDungeon->unk7 = 1;
    sub_808563C(SetupDeoxysFacingDirection);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_DEOXYS_NORMAL);
}

void sub_808C414(u8 param_1,u8 param_2)
{
  if ((param_2 == 0x35) && (param_1 == 0x1D)) {
    gDungeon->unk2 = 1;
    DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  }
}

void DeoxysPreFightDialogue(void)
{
  struct Entity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_8086448();
  if (HasRecruitedMon(MONSTER_DEOXYS_NORMAL)) {
    // There appears to be no one here.
    // It's impossible to go any further
    sub_80866C4(&gDeoxysPreFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(&gDeoxysPreFightDialogue_1);
    DungeonFadeInNewBGM(MUS_RAYQUAZAS_DOMAIN, 0x3c);
    sub_808C550();
    DisplayDungeonDialogue(&gDeoxysPreFightDialogue_2);
    DeoxysScreenFlash();
    DisplayDungeonDialogue(&gDeoxysPreFightDialogue_3);
    DeoxysScreenFlash();
    DisplayDungeonDialogue(&gDeoxysPreFightDialogue_4);
    sub_803E708(10,0x46);
    sub_808563C(SetupDeoxysFightHP);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void DeoxysScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x2c1);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,0,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,iVar1,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,0,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C550(void)
{
  gUnknown_202EDC8 = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  sub_803E9D0();
  sub_803E46C(0x46);
  gDungeon->unk7 = 0;
  DeoxysScreenFlash();
}

void sub_808C590(struct Entity *r0)
{
    sub_8068FE0(r0, 0x21C, 0);
}

void SetupDeoxysFacingDirection(struct Entity *deoxysEntity)
{
    SetFacingDirection(deoxysEntity, DIRECTION_SOUTH);
}

void SetupDeoxysFightHP(struct Entity *deoxysEntity)
{
    SetupBossFightHP(deoxysEntity, 950, MUS_BATTLE_WITH_RAYQUAZA);
}

void sub_808C5C0(void)
{
  struct Entity * LeaderEntity;
  struct Entity * CelebiEntity;

  u32 XPos;
  s32 YPos;

  LeaderEntity = xxx_call_GetLeader();
  CelebiEntity = GetEntityFromClientType(0x1e);
  DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(CelebiEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + 0xfffff000);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_CELEBI);
}

// Dummy Celebi Fight Dialogue??
void nullsub_100(u32 r0, u32 r1, u32 r2)
{
}

#ifdef NONMATCHING
void CelebiJoinDialogue(void)
{
  struct Entity *LeaderEntity;
  s32 state;
  s32 menuChoice;
  struct Entity *CelebiEntity;

  LeaderEntity = xxx_call_GetLeader();
  CelebiEntity = GetEntityFromClientType(0x1e);
  if ((HasRecruitedMon(MONSTER_CELEBI)) || (sub_806FD18(CelebiEntity) == '\0'))
  {
    sub_8068FE0(local_1c,0x21c,0);
    SpriteLookAroundEffect(LeaderEntity);
    sub_803E708(10,0x46);
    // .........
    DisplayDungeonDialogue(&gCelebiJoinDialogue_10);
  }
  else
  {
    SpriteLookAroundEffect(LeaderEntity);
    sub_803E708(10,0x46);
    SpriteShockEffect(LeaderEntity);
    sub_803E708(10,0x46);
    // Oh? There's someone there.
    DisplayDungeonDialogue(&gCelebiJoinDialogue_1);
    sub_803E708(10,0x46);
    sub_8086598();
    sub_8086598();
    sub_8086598();
    sub_8086598();
    // The Time-Traveling Pokemon {ARG_POKEMON_2} (Celebi)!
    DisplayDungeonDialogue(&gCelebiJoinDialogue_2);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(CelebiEntity,10,DIRECTION_SOUTH);
    sub_803E708(0x14,0x46);
    sub_806CE68(CelebiEntity, DIRECTION_SOUTH);
    sub_803E708(4,0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(CelebiEntity,10,DIRECTION_SOUTH);
    DisplayDungeonDialogue(&gCelebiJoinDialogue_3);
    sub_803E708(10,0x46);
    state = 0;
    do {
      switch(state)
      {
       case 0:
            do {
                // NOTE: 0 and Load of ptr switch order in compiler but else matches
                menuChoice = sub_8052C68(0,gPtrPurityForestAllowCelebiToJoinText,
                                &gPurityForestAllowCelebiToJoinPrompt,0x701);
            } while (menuChoice < 1);
            sub_803E708(10,0x46);
            if (menuChoice == 1)
            {
                DungeonStopBGM();
                PlaySoundEffect(0xcc);
                while (IsFanfareSEPlaying_2(0xcc) != 0) {
                    sub_803E46C(0x46);
                }
                DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
                PlaySoundEffect(0x1c7);
                sub_80861D4(CelebiEntity,0xd,0);
                sub_803E708(0x37,0x46);
                PlaySoundEffect(0x1d5);
                sub_803E708(0x1a,0x46);
                PlaySoundEffect(0x1d5);
                sub_803E708(0x1c,0x46);
                DisplayDungeonDialogue(&gCelebiJoinDialogue_4);
                sub_803E708(10,0x46);
                sub_806FDF4(LeaderEntity,CelebiEntity,&CelebiEntity);
                DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
                DisplayDungeonDialogue(&gCelebiJoinDialogue_5);
                sub_803E708(10,0x46);
                PlaySoundEffect(0x1c7);
                sub_80861D4(CelebiEntity,0xd,0);
                sub_803E708(0x37,0x46);
                PlaySoundEffect(0x1d5);
                sub_803E708(0x1a,0x46);
                PlaySoundEffect(0x1d5);
                sub_803E708(0x1b,0x46);
                DisplayDungeonDialogue(&gCelebiJoinDialogue_6);
                sub_803E708(10,0x46);
                state = 2;
            }
            else
            {
                state = 1;
            }
            break;
        case 1:
            do {
                // NOTE: 0 and Load of ptr switch order in compiler but else matches
                menuChoice = sub_8052C68(0,gPtrPurityForestRefuseCelebiConfirmText,
                                    &gPurityForestRefuseCelebiConfirmPrompt,0x701);
            } while (menuChoice < 1);
            if (menuChoice == 1)
                state = 0;
            else
            {
                sub_803E708(10,0x46);
                DisplayDungeonDialogue(&gCelebiJoinDialogue_7);
                sub_80861F8(0x3e,CelebiEntity,1);
                sub_803E708(0x18,0x46);
                sub_80861F8(0x3e,CelebiEntity,1);
                sub_803E708(0xe,0x46);
                DisplayDungeonDialogue(&gCelebiJoinDialogue_8);
                sub_803E708(10,0x46);
                sub_808C8E0(CelebiEntity);
                DisplayDungeonDialogue(&gCelebiJoinDialogue_9);
                sub_803E708(10,0x46);
                state = 2;
            }
            break;
      }
    } while (state != 2);
  }
  DungeonFadeOutBGM(0x1e);
  sub_803E708(0x1e,0x46);
  gDungeon->unk2 = 1;
}
#else
NAKED
void CelebiJoinDialogue(void)
{
        asm_unified(
        "\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tsub sp, 0x4\n"
	"\tbl xxx_call_GetLeader\n"
	"\tadds r7, r0, 0\n"
	"\tmovs r0, 0x1E\n"
	"\tbl GetEntityFromClientType\n"
	"\tstr r0, [sp]\n"
	"\tmovs r0, 0x8A\n"
	"\tlsls r0, 1\n"
	"\tbl HasRecruitedMon\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0808C658\n"
	"\tldr r0, [sp]\n"
	"\tbl sub_806FD18\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0808C680\n"
"_0808C658:\n"
	"\tmovs r1, 0x87\n"
	"\tlsls r1, 2\n"
	"\tldr r0, [sp]\n"
	"\tmovs r2, 0\n"
	"\tbl sub_8068FE0\n"
	"\tadds r0, r7, 0\n"
	"\tbl SpriteLookAroundEffect\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C67C\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tb _0808C8AC\n"
	"\t.align 2, 0\n"
"_0808C67C: .4byte gCelebiJoinDialogue_10\n"
"_0808C680:\n"
	"\tadds r0, r7, 0\n"
	"\tbl SpriteLookAroundEffect\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r7, 0\n"
	"\tbl SpriteShockEffect\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C71C\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tbl sub_8086598\n"
	"\tbl sub_8086598\n"
	"\tbl sub_8086598\n"
	"\tbl sub_8086598\n"
	"\tldr r0, _0808C720\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tldr r4, _0808C724\n"
	"\tadds r0, r4, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tldr r0, [sp]\n"
	"\tmovs r1, 0xA\n"
	"\tmovs r2, 0\n"
	"\tbl sub_806CDD4\n"
	"\tmovs r0, 0x14\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, [sp]\n"
	"\tmovs r1, 0\n"
	"\tbl sub_806CE68\n"
	"\tmovs r0, 0x4\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r4, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tldr r0, [sp]\n"
	"\tmovs r1, 0xA\n"
	"\tmovs r2, 0\n"
	"\tbl sub_806CDD4\n"
	"\tldr r0, _0808C728\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tmovs r0, 0\n"
	"\tmov r8, r4\n"
	"\tldr r6, _0808C72C\n"
"_0808C70E:\n"
	"\tcmp r0, 0\n"
	"\tbeq _0808C730\n"
	"\tcmp r0, 0x1\n"
	"\tbne _0808C718\n"
	"\tb _0808C828\n"
"_0808C718:\n"
	"\tb _0808C8A6\n"
	"\t.align 2, 0\n"
"_0808C71C: .4byte gCelebiJoinDialogue_1\n"
"_0808C720: .4byte gCelebiJoinDialogue_2\n"
"_0808C724: .4byte 0x000001c7\n"
"_0808C728: .4byte gCelebiJoinDialogue_3\n"
"_0808C72C: .4byte 0x000001d5\n"
"_0808C730:\n"
	"\tldr r5, _0808C75C\n"
"_0808C732:\n"
	"\tmovs r0, 0\n"
	"\tldr r1, [r5]\n"
	"\tldr r2, _0808C760\n"
	"\tldr r3, _0808C764\n"
	"\tbl sub_8052C68\n"
	"\tadds r4, r0, 0\n"
	"\tcmp r4, 0\n"
	"\tble _0808C732\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tcmp r4, 0x1\n"
	"\tbne _0808C824\n"
	"\tbl DungeonStopBGM\n"
	"\tmovs r0, 0xCC\n"
	"\tbl PlaySoundEffect\n"
	"\tb _0808C76E\n"
	"\t.align 2, 0\n"
"_0808C75C: .4byte gPtrPurityForestAllowCelebiToJoinText\n"
"_0808C760: .4byte gPurityForestAllowCelebiToJoinPrompt\n"
"_0808C764: .4byte 0x00000701\n"
"_0808C768:\n"
	"\tmovs r0, 0x46\n"
	"\tbl sub_803E46C\n"
"_0808C76E:\n"
	"\tmovs r0, 0xCC\n"
	"\tbl IsFanfareSEPlaying_2\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0808C768\n"
	"\tmovs r0, 0x7F\n"
	"\tbl DungeonStartNewBGM\n"
	"\tmov r0, r8\n"
	"\tbl PlaySoundEffect\n"
	"\tldr r0, [sp]\n"
	"\tmovs r1, 0xD\n"
	"\tmovs r2, 0\n"
	"\tbl sub_80861D4\n"
	"\tmovs r0, 0x37\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r6, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r0, 0x1A\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r6, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r0, 0x1C\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C818\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r1, [sp]\n"
	"\tadds r0, r7, 0\n"
	"\tmov r2, sp\n"
	"\tbl sub_806FDF4\n"
	"\tmovs r0, 0x7F\n"
	"\tbl DungeonStartNewBGM\n"
	"\tldr r0, _0808C81C\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tmov r0, r8\n"
	"\tbl PlaySoundEffect\n"
	"\tldr r0, [sp]\n"
	"\tmovs r1, 0xD\n"
	"\tmovs r2, 0\n"
	"\tbl sub_80861D4\n"
	"\tmovs r0, 0x37\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r6, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r0, 0x1A\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r6, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r0, 0x1B\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C820\n"
	"\tb _0808C898\n"
	"\t.align 2, 0\n"
"_0808C818: .4byte gCelebiJoinDialogue_4\n"
"_0808C81C: .4byte gCelebiJoinDialogue_5\n"
"_0808C820: .4byte gCelebiJoinDialogue_6\n"
"_0808C824:\n"
	"movs r0, 0x1\n"
	"b _0808C8A6\n"
"_0808C828:\n"
	"\tldr r5, _0808C844\n"
"_0808C82A:\n"
	"\tmovs r0, 0\n"
	"\tldr r1, [r5]\n"
	"\tldr r2, _0808C848\n"
	"\tldr r3, _0808C84C\n"
	"\tbl sub_8052C68\n"
	"\tadds r4, r0, 0\n"
	"\tcmp r4, 0\n"
	"\tble _0808C82A\n"
	"\tcmp r4, 0x1\n"
	"\tbne _0808C850\n"
	"\tmovs r0, 0\n"
	"\tb _0808C8A6\n"
	"\t.align 2, 0\n"
"_0808C844: .4byte gPtrPurityForestRefuseCelebiConfirmText\n"
"_0808C848: .4byte gPurityForestRefuseCelebiConfirmPrompt\n"
"_0808C84C: .4byte 0x00000701\n"
"_0808C850:\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C8D0\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tldr r1, [sp]\n"
	"\tmovs r0, 0x3E\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_80861F8\n"
	"\tmovs r0, 0x18\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r1, [sp]\n"
	"\tmovs r0, 0x3E\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_80861F8\n"
	"\tmovs r0, 0xE\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C8D4\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, [sp]\n"
	"\tbl sub_808C8E0\n"
	"\tldr r0, _0808C8D8\n"
"_0808C898:\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tmovs r0, 0x2\n"
"_0808C8A6:\n"
	"\tcmp r0, 0x2\n"
	"\tbeq _0808C8AC\n"
	"\tb _0808C70E\n"
"_0808C8AC:\n"
	"\tmovs r0, 0x1E\n"
	"\tbl DungeonFadeOutBGM\n"
	"\tmovs r0, 0x1E\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C8DC\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1, 0x2]\n"
	"\tadd sp, 0x4\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0808C8D0: .4byte gCelebiJoinDialogue_7\n"
"_0808C8D4: .4byte gCelebiJoinDialogue_8\n"
"_0808C8D8: .4byte gCelebiJoinDialogue_9\n"
"_0808C8DC: .4byte gDungeon");
}
#endif

void sub_808C8E0(struct Entity *param_1)
{
  s32 iVar1;

  PlaySoundEffect(0x1a5);
  sub_806CDD4(param_1, 0, DIRECTION_SOUTH);
  for(iVar1 = 0; iVar1 < 16; iVar1++){
    param_1->info->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
  for(iVar1 = 16; iVar1 < 200; iVar1 += 4){
    param_1->info->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
  sub_8086A3C(param_1);
}

void sub_808C938(void)
{
    sub_80855E4(sub_808C9B0);
}

void sub_808C948(struct Entity *param_1, u8 param_2)
{
  bool8 flag;
  s32 index;
  struct Entity *iVar2;

  if (param_2 == 0x37) {
    flag = FALSE;
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++){
      iVar2 = gDungeon->wildPokemon[index];
      if ((iVar2 != param_1) && (EntityExists(iVar2) != 0)) {
        flag = TRUE;
        break;
      }
    }
    if (!flag) {
      gDungeon->unk2 = 1;
    }
  }
}

void sub_808C998(void)
{
    // Defeat the opposing team to win
    // Be careful, your opponents are tough
    DisplayDungeonDialogue(&gUnknown_8106720);
    sub_803E708(0xA, 0x46);
}

void sub_808C9B0(struct Entity *param_1)
{
    param_1->info->action.direction = DIRECTION_NORTH;
    sub_806CE68(param_1, DIRECTION_NORTH);
}

void sub_808C9C4(void)
{
    struct Entity *LeaderEntity;
    struct Entity *MedichamEntity;

    LeaderEntity = xxx_call_GetLeader();
    MedichamEntity = GetEntityFromClientType(7);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(MedichamEntity, DIRECTION_SOUTH);
    sub_8085860(LeaderEntity->pos.x, LeaderEntity->pos.y - 3);
    CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_MEDICHAM);
}

// Medicham Rescue Dialogue?
void MedichamRescueDialogue(void)
{
    struct Entity *MedichamEntity;
    s32 counter;

    MedichamEntity = GetEntityFromClientType(7);
    SpriteLookAroundEffect(MedichamEntity);
    sub_803E708(0xA, 0x46);
    // Oh my I can't seem to find a way out...
    DisplayDungeonDialogue(&gMedichamRescueDialogue_1);
    sub_803E708(0xA, 0x46);
    sub_80869E4(MedichamEntity, 4, 2, 4);
    sub_803E708(0xA, 0x46);
    // What am I to do...?
    DisplayDungeonDialogue(&gMedichamRescueDialogue_2);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    SpriteShockEffect(MedichamEntity);
    sub_803E708(0x20, 0x46);
    sub_80869E4(MedichamEntity, 4, 2, 0);
    DisplayDungeonDialogue(&gMedichamRescueDialogue_3);
    sub_803E708(0xA, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(MedichamEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    sub_806CE68(MedichamEntity, DIRECTION_SOUTH);
    sub_803E708(0x4, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(MedichamEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    // Yes Yes
    // I am so lucky
    //
    // There appears to be no one here
    DisplayDungeonDialogue(&gMedichamRescueDialogue_4);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(MedichamEntity, 0, DIRECTION_SOUTH);
    for(counter = 0x17; counter >= 0; counter--)
    {
        sub_804539C(MedichamEntity, 0, 0x80 << 1);
        sub_803E46C(0x46);
    }
    sub_806CE68(MedichamEntity, DIRECTION_SOUTH);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(MedichamEntity);
    sub_8068FE0(MedichamEntity, 0x21C, 0);
    gDungeon->unk4 = 1;
    gDungeon->unk11 = 4;
}

void sub_808CB5C(void)
{
    struct Entity *LeaderEntity;
    struct Entity *MedichamEntity;

    LeaderEntity = xxx_call_GetLeader();
    MedichamEntity = GetEntityFromClientType(7);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_8068FE0(MedichamEntity, 0x21C, 0);
    sub_8085860(LeaderEntity->pos.x, LeaderEntity->pos.y);
    CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_MEDICHAM);
}

void DummyFightDialogue(void)
{
}

void sub_808CBB0(void)
{
    struct Entity *LeaderEntity;
    struct Entity *SmeargleEntity;

    LeaderEntity = xxx_call_GetLeader();
    SmeargleEntity = GetEntityFromClientType(0x1F);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(SmeargleEntity, DIRECTION_SOUTH);
    sub_8085860(LeaderEntity->pos.x, LeaderEntity->pos.y - 3);
    CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SMEARGLE);
}

// Smeargle Rescue dialogue scene
void SmeargleRescueDialogue(void)
{
    struct Entity *SmeargleEntity;
    s32 counter;

    SmeargleEntity = GetEntityFromClientType(0x1F);
    SpriteLookAroundEffect(SmeargleEntity);
    sub_803E708(0xA, 0x46);
    // Ohhh...
    // I've lost my bearings
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_1);
    sub_803E708(0xA, 0x46);
    sub_80869E4(SmeargleEntity, 4, 2, 4);
    sub_803E708(0xA, 0x46);
    // I can't get out...
    // I'm hungry...
    // I'm in trouble
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_2);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    SpriteShockEffect(SmeargleEntity);
    sub_803E708(0x20, 0x46);
    sub_80869E4(SmeargleEntity, 4, 2, 0);
    // Oh! You are?
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_3);
    sub_803E708(0xA, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(SmeargleEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    sub_806CE68(SmeargleEntity, DIRECTION_SOUTH);
    sub_803E708(0x4, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(SmeargleEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    // Did you maybe come to rescue me?
    // Am I glad to see you
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_4);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(SmeargleEntity, 0, DIRECTION_SOUTH);
    for(counter = 0x17; counter >= 0; counter--)
    {
        sub_804539C(SmeargleEntity, 0, 0x80 << 1);
        sub_803E46C(0x46);
    }
    sub_806CE68(SmeargleEntity, DIRECTION_SOUTH);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(SmeargleEntity);
    sub_8068FE0(SmeargleEntity, 0x21C, 0);
    gDungeon->unk4 = 1;
    gDungeon->unk11 = 4;

}

void sub_808CD44(void)
{
    struct Entity *LeaderEntity;
    struct Entity *SmeargleEntity;

    LeaderEntity = xxx_call_GetLeader();
    SmeargleEntity = GetEntityFromClientType(0x1F);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    sub_8068FE0(SmeargleEntity, 0x21C, 0);
    sub_8085860(LeaderEntity->pos.x, LeaderEntity->pos.y - 3);
    CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SMEARGLE);
}

void sub_808CD9C(u8 r0)
{
    sub_8086448();
    // There appears to be no one here.
    // It's impossible to go any further
    sub_80866C4(&gUnknown_810697C);
}

u64 *sub_808CDB0(u8 r0)
{
    return &gUnknown_8107544[r0];
}
