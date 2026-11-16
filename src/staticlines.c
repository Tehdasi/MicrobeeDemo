#include "staticlines.h"

byte staticLines_intensity[15];


void initStaticLines(void)
{
    vduColor();

    for (int x = 0; x < 64; x++)
        for (int y = 0; y < 15; y++)
        {
            PIXEL_TABLE_ADDRESS[x + y * 64]= 0x07;
            TILE_TABLE_ADDRESS[x + y * 64] = y + 128;
        }
}


#ifdef __MBEE
void staticLines(int curFrame)
{
    vduPixels();

    __asm

    push ix
    push iy
    push de
    push hl
    push bc


    // get a lookup rnd based on cur frame, 
    // use that seed rnd
    // hl now has a pointer to cur rnd val
    ld c, l
    ld de,(_rnd)
    ld h, d
    ld l, c
    ld a,(hl)
    ld l, a

    ld iy, #0xF800
    ld ix, #_staticLines_intensity
    ld e, #16

    // hl - rnd ptr
    // ix - row intensity ptr
    // iy - screen/pixel ptr
    // b - inner loop index
    // e - outer loop index
    // c - intensity of cur row
    // d - flex



// loop
    ld c, (ix)
stloop2:
    ld b,#16 
loop012: 
    ld a,(hl)
    ld d, #0xff 
    cp c 
    jp c, move012
    ld d, #0 
move012: 
    ld (iy),d 
    inc l 
    inc iy 
    djnz loop012

    inc ix
    ld c, (ix)

    dec e
    jr nz, stloop2


    pop bc
    pop hl
    pop de
    pop iy
    pop ix



    __endasm;
}
#else

void staticLines(int curFrame)
{
    byte rndInd = rnd[curFrame & 0xff];

    vduPixels();
    byte* pp = PIXEL_TABLE_ADDRESS;
    for (int rw = 0; rw < 15; rw++)
    {
        byte prob = staticLines_intensity[rw];
        for (int y = 0; y < 16; y++)
        {
            if (rnd[rndInd] < prob)
                *pp = 0x00;
            else
                *pp = 0xff;
            pp++;
            rndInd = (rndInd + 1) & 0xff;
        }

    }
}

#endif