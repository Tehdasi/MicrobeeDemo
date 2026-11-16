#include "rotatorsfuncs.h"

rotatorRenderLineFunc rotatorFuncs[64]= {
renderRotatorLine00,
renderRotatorLine01,
renderRotatorLine02,
renderRotatorLine03,
renderRotatorLine04,
renderRotatorLine05,
renderRotatorLine06,
renderRotatorLine07,
renderRotatorLine08,
renderRotatorLine09,
renderRotatorLine10,
renderRotatorLine11,
renderRotatorLine12,
renderRotatorLine13,
renderRotatorLine14,
renderRotatorLine15,
renderRotatorLine16,
renderRotatorLine17,
renderRotatorLine18,
renderRotatorLine19,
renderRotatorLine20,
renderRotatorLine21,
renderRotatorLine22,
renderRotatorLine23,
renderRotatorLine24,
renderRotatorLine25,
renderRotatorLine26,
renderRotatorLine27,
renderRotatorLine28,
renderRotatorLine29,
renderRotatorLine30,
renderRotatorLine31,
renderRotatorLine32,
renderRotatorLine33,
renderRotatorLine34,
renderRotatorLine35,
renderRotatorLine36,
renderRotatorLine37,
renderRotatorLine38,
renderRotatorLine39,
renderRotatorLine40,
renderRotatorLine41,
renderRotatorLine42,
renderRotatorLine43,
renderRotatorLine44,
renderRotatorLine45,
renderRotatorLine46,
renderRotatorLine47,
renderRotatorLine48,
renderRotatorLine49,
renderRotatorLine50,
renderRotatorLine51,
renderRotatorLine52,
renderRotatorLine53,
renderRotatorLine54,
renderRotatorLine55,
renderRotatorLine56,
renderRotatorLine57,
renderRotatorLine58,
renderRotatorLine59,
renderRotatorLine60,
renderRotatorLine61,
renderRotatorLine62,
renderRotatorLine63,
};

void renderRotatorLine00(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xc3c3
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
    
#endif
}

void renderRotatorLine01(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xc7c7
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xc7be
    push hl
    ld hl, #0xbebe
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
    
#endif
}

void renderRotatorLine02(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xcbcb
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb9b9
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
    
#endif
}

void renderRotatorLine03(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x1
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x400
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xce
    push hl
    ld hl, #0xcece
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb4b4
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb400
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine04(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xd1d1
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd1ae
    push hl
    ld hl, #0xaeae
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine05(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x1
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x400
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xd3
    push hl
    ld hl, #0xd3d3
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd3a8
    push hl
    ld hl, #0xa8a8
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa800
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine06(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0xd4d4
    push hl
    push hl
    push hl
    ld hl, #0xd4a2
    push hl
    ld hl, #0xa2a2
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine07(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x101
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0xd5d5
    push hl
    ld hl, #0xd59c
    push hl
    ld hl, #0x9c9c
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine08(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x4
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x400
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x96
    push hl
    ld hl, #0x9696
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x9600
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine09(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x9c9c
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x9cd5
    push hl
    ld hl, #0xd5d5
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine10(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0xa2a2
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa2d4
    push hl
    ld hl, #0xd4d4
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine11(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x4
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x300
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xa8
    push hl
    ld hl, #0xa8a8
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa8d3
    push hl
    ld hl, #0xd3d3
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd300
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine12(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xaeae
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xaed1
    push hl
    ld hl, #0xd1d1
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine13(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x4
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x300
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xb4
    push hl
    ld hl, #0xb4b4
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xcece
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xce00
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine14(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xb9b9
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xcbcb
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
    
#endif
}

void renderRotatorLine15(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xbebe
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xbec7
    push hl
    ld hl, #0xc7c7
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
    
#endif
}

void renderRotatorLine16(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xc3c3
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
    
#endif
}

void renderRotatorLine17(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xc7c7
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xc7be
    push hl
    ld hl, #0xbebe
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
    
#endif
}

void renderRotatorLine18(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xcbcb
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb9b9
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
    
#endif
}

void renderRotatorLine19(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x4
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x300
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xce
    push hl
    ld hl, #0xcece
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb4b4
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb400
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine20(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xd1d1
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd1ae
    push hl
    ld hl, #0xaeae
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine21(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x4
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x300
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xd3
    push hl
    ld hl, #0xd3d3
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd3a8
    push hl
    ld hl, #0xa8a8
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa800
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine22(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0xd4d4
    push hl
    push hl
    push hl
    ld hl, #0xd4a2
    push hl
    ld hl, #0xa2a2
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine23(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x404
    push hl
    ld hl, #0x403
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0xd5d5
    push hl
    ld hl, #0xd59c
    push hl
    ld hl, #0x9c9c
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine24(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x3
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x300
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x96
    push hl
    ld hl, #0x9696
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x9600
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine25(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x9c9c
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x9cd5
    push hl
    ld hl, #0xd5d5
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine26(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0xa2a2
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa2d4
    push hl
    ld hl, #0xd4d4
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine27(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x3
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x200
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xa8
    push hl
    ld hl, #0xa8a8
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa8d3
    push hl
    ld hl, #0xd3d3
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd300
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine28(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xaeae
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xaed1
    push hl
    ld hl, #0xd1d1
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine29(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x3
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x200
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xb4
    push hl
    ld hl, #0xb4b4
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xcece
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xce00
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine30(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xb9b9
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xcbcb
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
    
#endif
}

void renderRotatorLine31(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xbebe
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xbec7
    push hl
    ld hl, #0xc7c7
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
    
#endif
}

void renderRotatorLine32(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xc3c3
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
    
#endif
}

void renderRotatorLine33(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xc7c7
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xc7be
    push hl
    ld hl, #0xbebe
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
    
#endif
}

void renderRotatorLine34(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xcbcb
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb9b9
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
    
#endif
}

void renderRotatorLine35(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x3
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x200
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xce
    push hl
    ld hl, #0xcece
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb4b4
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb400
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine36(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xd1d1
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd1ae
    push hl
    ld hl, #0xaeae
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine37(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x3
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x200
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xd3
    push hl
    ld hl, #0xd3d3
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd3a8
    push hl
    ld hl, #0xa8a8
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa800
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine38(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0x303
    push hl
    push hl
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0xd4d4
    push hl
    push hl
    push hl
    ld hl, #0xd4a2
    push hl
    ld hl, #0xa2a2
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine39(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x303
    push hl
    ld hl, #0x302
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0xd5d5
    push hl
    ld hl, #0xd59c
    push hl
    ld hl, #0x9c9c
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 3;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine40(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x2
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x200
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x96
    push hl
    ld hl, #0x9696
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x9600
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine41(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x9c9c
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x9cd5
    push hl
    ld hl, #0xd5d5
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine42(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0xa2a2
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa2d4
    push hl
    ld hl, #0xd4d4
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine43(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x2
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x100
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xa8
    push hl
    ld hl, #0xa8a8
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa8d3
    push hl
    ld hl, #0xd3d3
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd300
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine44(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xaeae
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xaed1
    push hl
    ld hl, #0xd1d1
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine45(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x2
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x100
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xb4
    push hl
    ld hl, #0xb4b4
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xcece
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xce00
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine46(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xb9b9
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xcbcb
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
    
#endif
}

void renderRotatorLine47(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xbebe
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xbec7
    push hl
    ld hl, #0xc7c7
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
    
#endif
}

void renderRotatorLine48(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xc3c3
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
*tp= 195;
tp--;
    
#endif
}

void renderRotatorLine49(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xc7c7
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xc7be
    push hl
    ld hl, #0xbebe
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
    
#endif
}

void renderRotatorLine50(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xcbcb
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb9b9
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
    
#endif
}

void renderRotatorLine51(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x2
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x100
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xce
    push hl
    ld hl, #0xcece
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb4b4
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xb400
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine52(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xd1d1
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd1ae
    push hl
    ld hl, #0xaeae
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine53(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x2
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x100
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xd3
    push hl
    ld hl, #0xd3d3
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd3a8
    push hl
    ld hl, #0xa8a8
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa800
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine54(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0x202
    push hl
    push hl
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0xd4d4
    push hl
    push hl
    push hl
    ld hl, #0xd4a2
    push hl
    ld hl, #0xa2a2
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine55(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x202
    push hl
    ld hl, #0x201
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0xd5d5
    push hl
    ld hl, #0xd59c
    push hl
    ld hl, #0x9c9c
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 2;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine56(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x1
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x100
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x96
    push hl
    ld hl, #0x9696
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x9600
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 150;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine57(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    push hl
    ld hl, #0x9c9c
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x9cd5
    push hl
    ld hl, #0xd5d5
    push hl
    ld hl, #0x0
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 156;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 213;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine58(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    push hl
    ld hl, #0xa2a2
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa2d4
    push hl
    ld hl, #0xd4d4
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 162;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 212;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine59(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x1
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x400
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xa8
    push hl
    ld hl, #0xa8a8
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xa8d3
    push hl
    ld hl, #0xd3d3
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xd300
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 168;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 211;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine60(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    push hl
    ld hl, #0xaeae
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xaed1
    push hl
    ld hl, #0xd1d1
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x0
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 0;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 174;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 209;
tp--;
*tp= 0;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine61(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x1
    push hl
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x400
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xb4
    push hl
    ld hl, #0xb4b4
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xcece
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xce00
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 0;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 0;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 0;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 180;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 206;
tp--;
*tp= 0;
tp--;
    
#endif
}

void renderRotatorLine62(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xb9b9
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xcbcb
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 185;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
*tp= 203;
tp--;
    
#endif
}

void renderRotatorLine63(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0x101
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0x104
    push hl
    ld hl, #0x404
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl

    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
    ld hl, #0xbebe
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    ld hl, #0xbec7
    push hl
    ld hl, #0xc7c7
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 1;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
*pp= 4;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 190;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
*tp= 199;
tp--;
    
#endif
}
