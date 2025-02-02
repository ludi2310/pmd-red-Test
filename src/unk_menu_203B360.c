#include "global.h"
#include "input.h"
#include "main_menu.h"
#include "memory.h"
#include "menu.h"
#include "text.h"
#include "menu_input.h"

struct unkSprite
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
};

struct unkStruct_203B360
{
    // size: 0x1b4
    u32 currMenu;
    u32 unk4; // state
    struct MenuStruct unk8[4];
    struct UnkTextStruct2 unk148[4];
    struct unkSprite unk1A8;
    u32 unk1B0; // sprite count?
};

extern struct unkStruct_203B360 *gUnknown_203B360;
extern struct UnkTextStruct2 gUnknown_80E6E7C;
extern struct UnkTextStruct2 gUnknown_80E6E94;
extern struct MenuItem gUnknown_80E6EAC[];

extern void AddSprite(struct unkSprite *, u32, u32, u32);
extern void sub_8038440();
extern void sub_8035CF4(struct MenuStruct *, u32, u32);
extern void SetMenuItems(struct MenuStruct *, struct UnkTextStruct2 *, u32, struct UnkTextStruct2 *, struct MenuItem *, u32, u32, u32);
extern void sub_80384D0();

void sub_80382E4(s32 param_1)
{
  s32 iVar4;
  
  if (gUnknown_203B360 == NULL) {
    gUnknown_203B360 = MemoryAlloc(sizeof(struct unkStruct_203B360), 8);
    MemoryFill8((u8 *)gUnknown_203B360, 0, sizeof(struct unkStruct_203B360));
  }
  for(iVar4 = 0; iVar4 < 4; iVar4++){
    gUnknown_203B360->unk148[iVar4] = gUnknown_80E6E7C;
  } 
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B360->unk148,1,1);
  if (param_1 == 0x25) {
      // Caution!
      // The storage space is empty!
      // Please check again.
    SetMenuItems(gUnknown_203B360->unk8,gUnknown_203B360->unk148,0,&gUnknown_80E6E94,gUnknown_80E6EAC,
                 0,4,0);
  }
  sub_8035CF4(gUnknown_203B360->unk8,0,1);
  gUnknown_203B360->currMenu = param_1;
  gUnknown_203B360->unk4 = 0;
  sub_8038440();
}

void sub_80383A8(void)
{
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  if (gUnknown_203B360 != 0) {
    MemoryFree(gUnknown_203B360);
    gUnknown_203B360 = 0;
  }
}

u32 sub_80383D4(void)
{
  u32 nextMenu;
  u32 menuAction;
  
  menuAction = 2;
  nextMenu = MENU_NO_SCREEN_CHANGE;

  if (gUnknown_203B360->unk4 == 0){
    if (sub_80130A8(&gUnknown_203B360->unk8[0]) == '\0') {
        sub_8013114(&gUnknown_203B360->unk8[0], &menuAction);
    }
    switch(menuAction)
    {
        case 3:
        case 1:
            gUnknown_203B360->unk4  = 0;
            nextMenu = MENU_MAIN_SCREEN;
            break;
        case 2:
            gUnknown_203B360->unk4  = 0;
        default:
            break;
    }
    sub_80384D0();
  }

  return nextMenu;
}

void sub_8038440(void)
{
#ifdef NONMATCHING
    u32 r0;
    u32 r2;
#else
    register u32 r0 asm("r0");
    register u32 r2 asm("r2");
#endif
    u32 r1;
    u32 r4;
    u32 r5;
    struct unkSprite *sprite;
    
    r5 = 0;
    sprite = &gUnknown_203B360->unk1A8;

    r1 = sprite->unk0;
    r0 = 0xfeff;
    r0 &= r1;
    r0 &= 0xfdff;
    r0 &= 0xf3ff;
    r0 &= 0xefff;
    r0 &= 0xdfff;
    r2 = 0x4000;
    r0 &= 0x3fff;
    r0 |= r2;
    sprite->unk0 = r0;

    r2 = 0x3F0;
    r1 = sprite->unk4;
    r0 = 0xFC00;
    r0 &= r1;
    r0 |= r2;
    r0 &= 0xf3ff;
    r2 = 0xF;
    r4 = 0xF000;
    r0 &= 0xfff;
    r0 |= r4;

    sprite->unk4 = r0;
    
    sprite->unk2 = 0x70;
    
    r1 = 0x700;
    r2 &= sprite->unk6;
    r2 |= r1;
    sprite->unk6 = r2;
    
    gUnknown_203B360->unk1B0 = r5;
}


void sub_80384D0(void)
{
  if ((gUnknown_203B360->unk1B0 & 8) != 0) {
    AddSprite(&gUnknown_203B360->unk1A8, 0x100, 0, 0);
  }
  gUnknown_203B360->unk1B0++;
}

