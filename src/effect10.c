#include "effect10.h"
#include <math.h>

#include "misc.h"


int e10_initFrame= 0;
const int startPlasmaTiles = 150;


byte e10_freq = 2;
byte e10_audioCur = 5;
bool e10_audioOn = false;


#ifdef __MBEE
static volatile __sfr __at 0x02 SoundPort;
#define SOUND_MASK 0x60
#endif


void e10_audio(void)
{
#ifdef __MBEE
    e10_audioCur--;

    if (e10_audioCur == 0)
    {
        SoundPort = e10_audioOn ? SOUND_MASK : 0;
        e10_audioOn = !e10_audioOn;
        e10_audioCur = e10_freq;
    }
#endif
}



void e10_init(void)
{
}





void e10_doPlasmaC( int curFrame)
{
    byte* tp = TILE_TABLE_ADDRESS;
    byte xo=0, yo=0;

    if ((frame & 1) == 0)
    {
        tp ++;
        xo++;
    }

    if ((frame & 2) == 0)
    {
        tp += 64;
        yo+= 1;
    }


    for (byte y = 0; y < 16; y+=2)
    {
        for (byte x = 0; x < 64; x+=2)
        {
//            e10_audio();

            // TILE_TABLE_ADDRESS[x + y * 64] = ((((sine[x]<<1)+(sine[y]<<4) + curFrame*2)&0xff)>>2) + startPlasmaTiles;

            //TILE_TABLE_ADDRESS[x + y * 64] = (((
            //    sine[(x*2)&0xff] +
            //    sine[(y*2)&0xff] +
            //    (curFrame*17&0xff)  )&0xff)>>3) + startPlasmaTiles;


            // vertical bars
            // TILE_TABLE_ADDRESS[x + y * 64] = sine[(x * 16) & 0xff]/4 + startPlasmaTiles;

            // horizontal bars
            // TILE_TABLE_ADDRESS[x + y * 64] = sine[(y * 16*4) & 0xff]/4 + startPlasmaTiles;


            {
                //                int v = sine[(y * 8 * 4) & 0xff] + sine[(x * 8 + curFrame*4) & 0xff];
                int v = sine[((y + yo) * 12 + 45) & 0xff] + sine[((x+xo) * 2 + 156) & 0xff];
                v = sine[(v + curFrame * 2) & 0xff];

                *tp = (v / 4) + startPlasmaTiles;
                tp+= 2;
            }
        }

        tp+= 64;
    }
}

void e10_doPlasmaAsm(int curFrame)
{
    #ifdef __MBEE
    __asm

    push ix
    push bc

    ld e,l // curFrame

    ld ix, #0xF000
    ld hl, (#_sine)

    // bc loop vars
    // d, total

    ld c,#16
oloop:
    ld b,#64
iloop:
    ld a, b
    add a,a
    add a,a
    add a,a
//    add a,a
    add a,e

    ld l, a

    ld a, (hl) // sin(x*8 + curFrame)
    srl a
    srl a
    srl a
    ld d,a


    ld a, c
    add a
    add a
    add a
    add a
    ld l,a
    ld a,(hl)

    add a,d
    srl a
    srl a
    srl a

    add a, #150

    ld (ix), a
    inc ix
    djnz iloop

    dec c
    jr nz, oloop

    pop bc
    pop ix

    __endasm;
    #endif
}



#define PLASMA_PRE \
{ \
    byte* tp = TILE_TABLE_ADDRESS; \
    byte xo = 0, yo = 0; \
\
    if ((frame & 1) == 0) \
    {\
        tp++;\
        xo++;\
    }\
\
    if ((frame & 2) == 0)\
    {\
        tp += 64;\
        yo += 1;\
    }\
\
    for (byte y = 0; y < 16; y += 2)\
    {\
        for (byte x = 0; x < 64; x += 2)\
        {\
            byte v;

#define PLASMA_POST \
            *tp= v+startPlasmaTiles;\
            tp+=2;\
        }\
\
        tp += 64;\
    }\
}



void e10_plas01(int curFrame)
{
    PLASMA_PRE
        // v = sine[(x * 16) & 0xff] / 4;
        // v = ((((sine[x] << 1) + (sine[y] << 4) + curFrame * 2) & 0xff) >> 2);

        v = sine[((y + yo) * 6 + 45) & 0xff] + sine[((x + xo) * 2 + 156) & 0xff];
        v = sine[(v + curFrame * 2) & 0xff]>>2;

    PLASMA_POST
}

void e10_plas02(int curFrame)
{
    PLASMA_PRE
        v = sine[((x * 4)+(sine[(y*22 + curFrame*3)&0xff]>>2) + curFrame) & 0xff] / 4;

//        v = sine[((y * 14) + (sine[(x * 22 + curFrame * 3) & 0xff] >> 2) + curFrame) & 0xff] / 8;
//        v = sine[((y * 7) + (sine[(x * 7 + curFrame * 3) & 0xff] >> 2) + curFrame) & 0xff] / 4;

//         v = ((((sine[x] << 1) + (sine[y] << 4) + curFrame * 2) & 0xff) >> 2);

    //    v = sine[((y + yo) * 6 + 45) & 0xff] + sine[((x + xo) * 2 + 156) & 0xff];
//    v = sine[(v + curFrame * 2) & 0xff] >> 2;

    PLASMA_POST
}

void genTile(byte tn)
{
    byte rl2= (tn*7)&0xff;

    byte* pb = PIXEL_TABLE_ADDRESS + (startPlasmaTiles - 128 + tn) * 16;
    byte rl= rnd[rl2];

    for (byte j = 0; j < 16; j++)
    {
        byte b = 0;

        for (byte k = 0; k < 8; k++)
        {
            b <<= 1;
            if (rnd[rl] > (tn << 2))
                b = b | 1;

            rl++;
        }

        pb[j] = b;
    }

}

void e10_do(void)
{
    vduPixels();

    if (e10_initFrame == 0)
    {
        e10_initFrame = frame;
//        vl_setupTiles();

        byte rl2 = 0;



        byte* pb= PIXEL_TABLE_ADDRESS + ((startPlasmaTiles-128)*16);
        byte* tt= TILE_TABLE_ADDRESS;
        for (int i = 0; i < 64*16; i++)
        {
            *pb= 0xff;
            pb++;

            *tt= 150;
            tt++;
        }

        /*
        for (int i = 0; i < 64; i++)
        {
            byte rl = rnd[rl2];

            byte* pb = PIXEL_TABLE_ADDRESS + (startPlasmaTiles - 128 + i) * 16;
            for (byte j = 0; j < 16; j++)
            {
                byte b = 0;

                for (byte k = 0; k < 8; k++)
                {
                    b <<= 1;
                    if (rnd[rl] > (i << 2))
                        b = b | 1;

                    rl++;
                }

                pb[j] = b;
            }

            rl2 += 7;
        }
          */  

        clearColors();
    }

    vduPixels();
    int curFrame = frame - e10_initFrame;

    if( curFrame < 16 )
    {
        genTile(curFrame*4);
        genTile((curFrame*4)+1);
        genTile((curFrame*4)+2);
        genTile((curFrame*4)+3);
    }

    //if ((curFrame / 20)%2 == 0)
    //{
    //    e10_plas01(curFrame);
    //}
    //else
    //{
        e10_plas02(curFrame);
    // s}
    // e10_doPlasmaC(curFrame);
//    e10_doPlasmaAsm(curFrame);
}

