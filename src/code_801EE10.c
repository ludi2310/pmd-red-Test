#include "global.h"
#include "pokemon.h"
#include "text.h"
#include "memory.h"
#include "input.h"

struct unkStruct_203B270
{
    // size 0xBC
    u32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    /* 0x8 */ struct PokemonStruct *pokeStruct;
    /* 0xC */ u8 isTeamLeader;
    /* 0x10 */ struct Move *moves;
    u8 fill14[0x1C - 0x14];
    u32 unk1C;
    u8 fill20[0x50 - 0x20];
    u32 unk50;
    u32 unk54;
    struct UnkTextStruct2 unk58[4];
    u32 unkB8;
};

extern struct unkStruct_203B270 *gUnknown_203B270;
extern struct UnkTextStruct2 gUnknown_80DC25C;
extern struct UnkTextStruct2 gUnknown_80DC274;

extern void sub_8012D08(void *, u32);
extern void sub_8013818(void *, u32, u32, u32);
u32 sub_8006544(u32 index);
s32 sub_801F3F8(void);
void sub_8013780(u32 *, u32);
void sub_801F280(u32);

u8 sub_801EE10(u32 param_1,s16 species,struct Move *moves,u32 param_4,u32 param_5,u32 param_6)
{
  s32 iVar5;
  s32 iVar8;
  s32 species_s32;
  u8 param_4_u8;
  s32 four;
    
  species_s32 = species; 
  param_4_u8 = param_4;
  gUnknown_203B270 = MemoryAlloc(sizeof(struct unkStruct_203B270), 8);
  gUnknown_203B270->unk4 = param_4_u8;
  gUnknown_203B270->unk5 = 1;
  gUnknown_203B270->unk6 = 1;
  gUnknown_203B270->unk7 = 1;
  gUnknown_203B270->unk0 = param_1;
  switch(param_1)
  {
      case 2:
      case 3:
        gUnknown_203B270->unk5 = 0;
        gUnknown_203B270->unk6 = 0;
        gUnknown_203B270->unk7 = 0;
        break;
      case 0:
      case 1:
          break;
  }
  gUnknown_203B270->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
  gUnknown_203B270->isTeamLeader = gUnknown_203B270->pokeStruct->isTeamLeader;
  gUnknown_203B270->moves = moves;
  gUnknown_203B270->unkB8 = param_5;
  iVar8 = iVar5 = sub_801F3F8();
  four = 4;
  if (iVar8 < four) {
    iVar8 = 4;
  }
  sub_8006518(gUnknown_203B270->unk58);
  gUnknown_203B270->unk50 = param_6;
  gUnknown_203B270->unk58[param_6] = gUnknown_80DC25C;
  if (gUnknown_203B270->unkB8 != 0) {
    gUnknown_203B270->unk54 = sub_8006544(param_6);
    gUnknown_203B270->unk58[gUnknown_203B270->unk54] = gUnknown_80DC274;
  }
  sub_8012D08(&gUnknown_203B270->unk58[gUnknown_203B270->unk50],iVar8);
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B270->unk58,1,1);
  sub_8013818(&gUnknown_203B270->unk1C,iVar5,iVar5,param_6);
  sub_8013780(&gUnknown_203B270->unk1C,0);
  sub_801F280(1);
  return 1;
}
