#include "sections.h"

Section sections_data[SECTIONS_MAX];

void sectionsInit(void)
{
    vduPixels();

    byte *pp = PIXEL_TABLE_ADDRESS;

//    byte v= 0;
    byte v= 0xff;

    for (byte i = 0; i < 8; i++)
    {
        for (byte y = 0; y < 16; y++)
        {
            *pp = v;
            pp++;
        }

        v >>= 1;
    }

    // inverse tiles
    v= 0xff;
    for (byte x = 0; x < 8; x++)
    {
        for (byte y = 0; y < 16; y++)
        {
            *pp = v;
            pp++;
        }

        v<<= 1;
        v&= 0xfe;
    }
}


void hsectionsInit(void)
{
    vduPixels();

    byte* pp = PIXEL_TABLE_ADDRESS;

    //    byte v= 0;
    for (byte i = 0; i < 11; i++)
    {
        for (byte y = 0; y < 10; y++)
        {
            if (y<i)
                *pp = 0x00;
            else
                *pp = 0xff;
            pp++;
        }
        pp += 6;
    }

    for (byte y = 0; y < 10; y++)
    {
        *pp = 0xff;
        pp++;
    }
    pp += 6;

    // inverse tiles
    for (byte i = 0; i < 11; i++)
    {
        for (int y = 9; y >= 0; y--)
        {
            if (i < y)
                *pp = 0xff;
            else
                *pp = 0x0;
            pp++;
        }
        pp += 6;
    }

}


void sectionsRenderFull(byte y)
{
    vduColor();

    byte *tp = TILE_TABLE_ADDRESS + (y * 64);
    byte *cp = PIXEL_TABLE_ADDRESS + (y*64);
    Section* sp= sections_data;

    byte rl = sp->length;
    byte cc = sp->color;


    for (byte x = 0; x < 64; x++)
    {
        if (rl == 0)
        {
            sp++;
            rl = sp->length;
            cc = sp->color;
        }

        if (rl >= 8)
        {
            rl -= 8;

            *tp= (byte)(128 + 0);
            *cp= cc;
        }
        else
        {
            byte orl = rl;
            byte oc = cc;

            sp++;
            rl= sp->length - (8-orl);
            cc= sp->color;
            
            *tp = 128 + orl;
            *cp = (oc << 4) | cc;

        }

        tp++;
        cp++;
    }
}

void sectionsRenderHalfCopy(byte y)
{
    y;
#ifdef __MBEE
    __asm

    ld h, #0
    ld l, a
    add hl,hl
    add hl,hl
    add hl,hl
    add hl,hl
    add hl,hl
    add hl,hl
    ld b, h
    ld c, l

    push bc

    ld hl, #0xf000 + 32
    add hl, bc

    push hl
    
    ld hl, #0xf000 + 31
    add hl, bc

    ld d, h
    ld e, l
    pop hl


    exx

    pop bc


    ld hl, #0xf800 + 32
    add hl, bc

    push hl
    
    ld hl, #0xf800 + 31
    add hl, bc

    ld d, h
    ld e, l
    pop hl

    exx

    ld b, #32
srhc_loop:
    ld a,(hl)
    add a,#8
    ld (de),a
    inc hl
    dec de
    exx

    ld a,(hl)
    ld (de),a
    inc hl
    dec de
    exx

    djnz srhc_loop

    __endasm;
#else
    byte *tps = TILE_TABLE_ADDRESS + (y * 64) + 32;
    byte *cps = PIXEL_TABLE_ADDRESS + (y*64) + 32;
    
    byte *tpd = TILE_TABLE_ADDRESS + (y * 64) + 31;
    byte *cpd = PIXEL_TABLE_ADDRESS + (y * 64) + 31;

    for (byte x = 0; x < 32; x++)
    {
        *tpd= (*tps)+8;
        *cpd= *cps;

        tpd--;
        tps++;
        cpd--;
        cps++;
    }   
#endif
}

void sectionsRenderHalf(byte y)
{
    vduColor();

    byte *tp = TILE_TABLE_ADDRESS + (y * 64) + 32;
    byte *cp = PIXEL_TABLE_ADDRESS + (y*64) + 32;
    Section* sp= sections_data;

    byte rl = sp->length;
    byte cc = sp->color;

    for (byte x = 0; x < 32; x++)
    {
        if (rl == 0)
        {
            sp++;
            rl = sp->length;
            cc = sp->color;
        }

        if (rl >= 8)
        {
            rl -= 8;

            *tp= (byte)(128 + 0);
            *cp= (cc << 4) | cc;
        }
        else
        {
            byte orl = rl;
            byte oc = cc;

            sp++;
            rl= sp->length - (8-orl);
            cc= sp->color;
            
            *tp = 128 + orl;
            *cp = (oc << 4) | cc;
        }

        tp++;
        cp++;
    }

    sectionsRenderHalfCopy(y);
}

void hsectionsRenderHalf(byte x)
{
    vduColor();

    byte* tp = TILE_TABLE_ADDRESS + x + (12*80);
    byte* cp = PIXEL_TABLE_ADDRESS + x + (12*80);
    Section* sp = sections_data;

    byte rl = sp->length;
    byte cc = sp->color;

    for (byte x = 0; x < 12; x++)
    {
        if (rl == 0)
        {
            sp++;
            rl = sp->length;
            cc = sp->color;
        }

        if (rl >= 10)
        {
            rl -= 10;

            *tp = (byte)(128 + 0);
            *cp = cc;
        }
        else
        {
            byte orl = rl;
            byte oc = cc;

            sp++;
            rl = sp->length - (10 - orl);
            cc = sp->color;

            *tp = 128 + orl;
            *cp = (oc << 4) | cc;
        }

        tp+= 80;
        cp+= 80;
    }

    
    byte* tps = TILE_TABLE_ADDRESS + x + 12*80;
    byte* cps = PIXEL_TABLE_ADDRESS + x + 12*80;

    byte* tpd = TILE_TABLE_ADDRESS + x + 11*80;
    byte* cpd = PIXEL_TABLE_ADDRESS + x + 11*80;

    for (byte x = 0; x < 12; x++)
    {
        *tpd = (*tps) + 11;
        *cpd = *cps;

        tpd-= 80;
        tps+= 80;
        cpd-= 80;
        cps+= 80;
    }
    
}

void hsectionsRenderFull(byte x)
{
    vduColor();

    byte* tp = TILE_TABLE_ADDRESS + x;
    byte* cp = PIXEL_TABLE_ADDRESS + x;
    Section* sp = sections_data;

    byte rl = sp->length;
    byte cc = sp->color;

    for (byte x = 0; x < 15; x++)
    {
        if (rl == 0)
        {
            sp++;
            rl = sp->length;
            cc = sp->color;
        }

        if (rl >= 16)
        {
            rl -= 16;

            *tp = (byte)(128 + 0);
            *cp = cc;
        }
        else
        {
            byte orl = rl;
            byte oc = cc;

            sp++;
            rl = sp->length - (16 - orl);
            cc = sp->color;

            *tp = 128 + orl;
            *cp = (oc << 4) | cc;
        }

        tp += 64;
        cp += 64;
    }
}


void sectionsApplyAll(void)
{
    vduColor();
    #ifdef __MBEE
    __asm

    push bc
    push ix
    push iy

    // ld ix, #0xf000       
    ld iy, #0xf800

    ld c, #10
aa_yloop:

    ld b, #64


aa_xloop:
    // ld a, (ix)
    // ld (ix+80), a

    ld a, (iy)
    ld (iy+64), a

//    inc ix
    inc iy

    djnz aa_xloop 

    dec c
    jp nz, aa_yloop

    pop iy
    pop ix
    pop bc


    __endasm;

    #else
    byte* tps = TILE_TABLE_ADDRESS;
    byte* cps = PIXEL_TABLE_ADDRESS;


    for (byte x = 0; x < 64; x++)
    {
        byte t = *tps;
        byte c = *cps;

        byte* tpd = tps + 64;
        byte* cpd = cps + 64;

        for (byte y = 1; y < 15; y++)
        {
            *tpd = t;
            *cpd = c;

            tpd += 64;
            cpd += 64;
        }

        tps++;
        cps++;
    }
    #endif
}

int aaStoreSp;
int aaStorePtr;

void hsectionsApplyAll(void)
{
    vduColor();

    #ifdef __MBEE

    __asm
    push bc
    push de
    push hl
    push ix
    push iy

    // save sp
    ld (_aaStoreSp), sp

    // point hl to colours
    ld hl, #0xf800
    ld (_aaStorePtr), hl

    ld b, #15

aa_lineLoop:
    ld hl, (_aaStorePtr)

    // get the colour on the first left into d&e
    // save the colour to the second pos
    ld a, (hl)
    inc hl
    ld (hl), a
    ld d, a
    ld e, a

    // point sp to the last pos
    push de
    ld de, #63
    add hl, de
    pop de
    ld sp, hl


    push de
    push de
    push de
    push de
    push de
    push de
    push de
    push de
    
    push de
    push de
    push de
    push de
    push de
    push de
    push de
    push de

    push de
    push de
    push de
    push de
    push de
    push de
    push de
    push de

    push de
    push de
    push de
    push de
    push de
    push de
    push de

    // setup colour ptr for the next go around

    ld d, #0
    ld e, #64
    ld hl, (_aaStorePtr)
    add hl, de
    ld (_aaStorePtr), hl

    djnz aa_lineLoop

    // restore sp
    ld sp, (_aaStoreSp)

    pop iy
    pop ix
    pop hl
    pop de
    pop bc
    __endasm;

    /*
    __asm
    push bc
    push ix
    push iy

    ld ix, #0xf000
    ld iy, #0xf800

    ld c, #24

haa_yloop:

    ld d, (ix)
    ld e, (iy)
    inc ix
    inc iy

    ld b, #79
haa_xloop:
    ld (ix), d
    ld (iy), e

    inc ix
    inc iy
    djnz haa_xloop

    dec c
    jp nz, haa_yloop

    pop iy
    pop ix
    pop bc
    __endasm;
*/
    #else


    for (byte y = 0; y < 24; y++)
    {
        byte* tps = TILE_TABLE_ADDRESS + y*80;
        byte* cps = PIXEL_TABLE_ADDRESS + y*80;
        byte t = *tps;
        byte c = *cps;


        for (byte x = 1; x < 80; x++)
        {
            *tps = t;
            *cps = c;

            tps ++;
            cps ++;
        }
    }
    #endif
}
