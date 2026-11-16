#include "colourribbons.h"


ColourRibbon colourRibbons[10];


void colourRibbonInit(void)
{
    vduPixels();


    vduColor();
}

void colourRibbonScroll(void)
{
    vduColor();
#ifdef __MBEE
    __asm

    push bc
    push de
    push hl
    push iy

    ld de, #0xF800
    ld hl, #0xF800 + 64
   
    ld c, #14
scroll_oloop:

    ld b, #64
scroll_iloop:
    ld a, (hl)
    ld (de), a
    inc hl
    inc de
    djnz scroll_iloop

    dec c
    jp nz,scroll_oloop


    ld b, #64
    ld hl, #0xF800 + (14*64)
scroll_clear:
    ld (hl), #0
    inc hl
    djnz scroll_clear

    pop iy
    pop hl
    pop de
    pop bc


    __endasm;
#else 
    for( byte y= 0; y< 14; y++ )
    {
        byte* dp= PIXEL_TABLE_ADDRESS + y*64;
        byte* sp= PIXEL_TABLE_ADDRESS + (y+1)*64;

        for( byte x= 0; x< 64; x++ )
        {
            *dp= *sp;
            dp++;
            sp++;
        }
    }

    {
        byte* p= PIXEL_TABLE_ADDRESS + (14*64);

        for( byte x= 0; x< 64; x++ )
        {
            *p= 0;
            p++;
        }
    }
#endif
}

void colourRibbonRender(byte numRibbons)
{
    vduColor();

    colourRibbonScroll();

    for( byte i= 0; i< numRibbons; i++ )
    {
        byte start= colourRibbons[i].start;
        byte len= colourRibbons[i].length;
        byte col= colourRibbons[i].colour;

        byte* p= PIXEL_TABLE_ADDRESS + (14*64) + start;
        for( byte xx= 0; xx< len; xx++ )
        {
            *p|= col;
            p++;
        }
    }

}
