
#include "compiledsprite.h"

int compiledSpriteScratchSp;
int compiledSpriteScratchOffset;

void undefined(dbyte offset) 
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
    ld hl, #0x3333
    push hl
    ld hl, #0x2222
    push hl
    ld hl, #0x1111
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
    push hl
    push hl
    push hl
ld sp, (_compiledSpriteScratchSp)
    __endasm
      ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
*pp= 51;
pp--;
*pp= 51;
pp--;
*pp= 34;
pp--;
*pp= 34;
pp--;
*pp= 17;
pp--;
*pp= 17;
pp--;
byte *tp= TILE_TABLE_ADDRESS + offset;*tp= e;
tp--;
*tp= t;
tp--;
*tp= i;
tp--;
*tp= r;
tp--;
*tp= p;
tp--;
*tp= S;
tp--;
*tp= r;
tp--;
*tp= e;
tp--;
*tp= d;
tp--;
*tp= n;
tp--;
*tp= e;
tp--;
*tp= r;
tp--;
    
#endif
}