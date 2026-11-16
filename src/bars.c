#include "bars.h"

#include "barslogo.h"


BarDesc barsData[20];
byte bars_tmpBuff[16*16];

byte bars_logoBuff[2];


struct {
    byte y;
    byte bright;
} bars_funcargs;



///< bars_tmpBuff[y .. y+9] = 0xff >> bright, same as the C version below
void bars_renderBar(void)
{
#ifdef __MBEE
    __asm
    ld      hl, #_bars_tmpBuff
    ld      a, (_bars_funcargs)         ; y
    add     a, l
    ld      l, a
    jr      nc, 1$
    inc     h
1$:
    ld      a, (_bars_funcargs + 1)     ; bright
    ld      b, a
    ld      a, #0xff
    inc     b                           ; shift right 'bright' times
    jr      3$
2$:
    srl     a
3$:
    djnz    2$

    ld      b, #10
4$:
    ld      (hl), a
    inc     hl
    djnz    4$
    __endasm;
#else


    byte* pp = bars_tmpBuff + bars_funcargs.y;

    byte v = 0xff >> bars_funcargs.bright;

    for (int i = 0; i < 10; i++)
    {
        *pp = v;
        pp++;
    }



#endif
}

byte withlogo_pre;
byte withlogo_bar;
byte withlogo_post;

void bars_renderInternal(void )
{
#ifdef __MBEE
    __asm
    ld de, #0xf800 + 16*16
    ld hl, #_apiaryLogoData

    ld c, #(APIARY_LOGO_WIDTH / 8)

column_loop:

    ld a, (_withlogo_pre)
    cp #0
    jp z, pre_loop_end
    ld b, a
pre_loop:
    ld a, (hl)
    ld (de), a
    inc de
    inc hl
    djnz pre_loop


pre_loop_end:
    ld a, (_withlogo_bar)
    cp #0
    jp z, bar_loop_end
    
    ld b, a
    ld a, #0xff
bar_loop:
    ld (de), a
    inc de
    inc hl
    djnz bar_loop    

bar_loop_end:
    ld a, (_withlogo_post)
    cp #0
    jp z, post_loop_end

    ld b, a
post_loop:
    ld a, (hl)
    ld (de), a
    inc de
    inc hl
    djnz post_loop    
post_loop_end:

    dec c
    jp nz, column_loop

    __endasm;
#else
    byte* pp = PIXEL_TABLE_ADDRESS + 16 * 16;
    const byte* lp = apiaryLogoData;

    for (byte x = 0; x < APIARY_LOGO_WIDTH / 8; x++)
    {
        for (byte y = 0; y < withlogo_pre; y++)
        {
            *pp = *lp;
            pp++;
            lp++;
        }

        for (byte y = 0; y < withlogo_bar; y++)
        {
            *pp = 0xff;
            pp++;
        }
        lp+= withlogo_bar;

        for (byte y = 0; y < withlogo_post; y++)
        {
            *pp = *lp;
            pp++;
            lp++;
        }
    }
#endif    
}


void barsRenderWithLogo(int overBarY )
{
    int obo = overBarY - 16*6;



    withlogo_pre = 14;
    withlogo_bar = 10;
    withlogo_post = 64-(withlogo_pre+withlogo_bar);


    if (obo <= -10 )
    {
        withlogo_pre = 0;
        withlogo_bar = 0;
        withlogo_post = 64;
    }
    else if (obo > -10 && obo < 0)
    {
        withlogo_pre = 0;
        withlogo_bar = 10 + obo;
        withlogo_post = 64 - (withlogo_pre + withlogo_bar);
    }
    else if (obo > 0 && obo < (64-10))
    {
        withlogo_pre = obo;
        withlogo_bar = 10;
        withlogo_post = 64 - (withlogo_pre + withlogo_bar);
    }
    else if (obo >= (64-10) && obo < 65 )
    {
        withlogo_pre = obo;
        withlogo_bar = 64-obo;
        withlogo_post = 0;
    }

    bars_renderInternal();
}



void initBars(void)
{
    vduColor();
    for (int x = 0; x < 64; x++)
        for (int y = 0; y < 15; y++)
        {
            TILE_TABLE_ADDRESS[x + y * 64] = y + 128;
            PIXEL_TABLE_ADDRESS[x + y * 64] = 0x07;
        }


    byte tp= 0;

    int xs = 28,  ys= 4;

    for( int x= 0; x< xs; x++ )
    {
        for (int y = 0; y < ys; y++)
        {
            TILE_TABLE_ADDRESS[ (x + (64-xs)/2) + (y+(16-ys)/2)*64 ]= 128+16+ tp;


            tp++;
        }
    }
}




void renderBars(void)
{
    vduPixels();

    for (int i = 0; i < 16 * 16; i++)
        bars_tmpBuff[i]= 0;


    int overBarPos = -12;
    int i= 0;

    while( barsData[i].bright < 16 )
    {
        if (barsData[i].z == 0)
        {
            bars_funcargs.y = barsData[i].y;
            bars_funcargs.bright = barsData[i].bright;
            bars_renderBar();
        }
        i++;
    }

    i = 0;
    while (barsData[i].bright < 16)
    {
        if (barsData[i].z == 1)
        {
            bars_funcargs.y = barsData[i].y;
            bars_funcargs.bright = barsData[i].bright;
            bars_renderBar();

            if (bars_funcargs.y >= 16*5 && bars_funcargs.y < 16*(5+5))
                overBarPos = bars_funcargs.y;
        }
        i++;
    }

    barsRenderWithLogo(overBarPos);

    /*

    for( int i= 0; i< numBars; i++ )
    {
        int a = (curFrame) + (i * 80);

        bars[i].z = sine[(a + 64) & 0xff] >> 3;
        bars[i].y = 50 + (sine[a & 0xff] >> 1) + (bars[i].z - 16);
    }


    for (int i = 0; i < numBars; i++)
    {
        if (bars[i].z <= 16)
        {
            e18_funcargs.y = bars[i].y;
            e18_funcargs.h = 1 + bars[i].z;
            e18_funcargs.data = bd_ptr[bars[i].z];

            e18_renderBar();
        }
    }
    for (int i = 0; i < numBars; i++)
    {
        if (bars[i].z > 16)
        {
            e18_funcargs.y = bars[i].y;
            e18_funcargs.h = 1 + bars[i].z;
            e18_funcargs.data = bd_ptr[bars[i].z];

            e18_renderBar();
        }
    }
*/


    for (int i = 0; i < 16 * 16; i++)
        PIXEL_TABLE_ADDRESS[i] = bars_tmpBuff[i];
}
