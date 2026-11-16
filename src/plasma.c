#include "plasma.h"
#include "plasmatiles.h"

const byte startPlasmaTiles2 = 150;


void plasmaPrep(void)
{
    for (byte i = 0; i < 64; i++)
        TILE_TABLE_ADDRESS[i] = 32;

    vduPixels();
    byte* pb= PIXEL_TABLE_ADDRESS + ((startPlasmaTiles2-128)*16);
    byte* tt= TILE_TABLE_ADDRESS + 64;
    for (int i = 0; i < 64*14; i++)
    {
        *pb= 0xff;
        pb++;

        *tt= 150;
        tt++;
    }

    vduColor();
    pb= PIXEL_TABLE_ADDRESS;
    for (int i = 0; i < 64*15; i++)
    {
        *pb= 0x07;
        pb++;
    }

    vduPixels();
    for (byte i = 0; i < 64; i++)
        plasmaGenTile(i);
}

void plasmaGenTile(byte tile)
{
    byte* pb = PIXEL_TABLE_ADDRESS + (startPlasmaTiles2 - 128 + tile) * 16;
    const byte* ps = plasmaTiles + tile * 16;

    for (byte i = 0; i < 16; i++)
    {
        *pb = *ps;
        pb++;
        ps++;
    }
}

#define PLASMA_PRE \
{ \
    byte* tp = TILE_TABLE_ADDRESS + 64; \
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
    for (byte y = 0; y < 14; y += 2)\
    {\
        for (byte x = 0; x < 64; x += 2)\
        {\
            byte v;

#define PLASMA_POST \
            *tp= v+startPlasmaTiles2;\
            tp+=2;\
        }\
\
        tp += 64;\
    }\
}



void plasmaRender01(int curFrame, byte fade)
{
    PLASMA_PRE
        v = sine[((y * 29) + 50 + curFrame*2 +
            (sine[(x * 7 + 73 ) & 0xff] >> 4)) & 0xff
        ] >>2;
        v = MAX(v - fade, 0);

    PLASMA_POST
}

// wobbly lines
void plasmaRender02(int curFrame, byte fade)
{
    int cf = curFrame * 5 + sine[curFrame & 0xff] >> 2;

    PLASMA_PRE
        v = (sine[(((x+xo) * 4)+(sine[((y+yo)*12 + curFrame*3)&0xff]>>2) + cf) & 0xff] / 4);
        v = MAX(v- fade, 0);

    PLASMA_POST
}


void plasmaRender03(int curFrame, byte fade)
{
    PLASMA_PRE
        byte uy= y + yo;
        byte ux= x + xo;

        //v = ( + (sine[((y + yo) * 12 + curFrame * 3) & 0xff] >> 2) + curFrame) & 0xff] / 4);
        v = (sine[(ux * 8)&0xff] >> 3) + (sine[((uy * 32) + curFrame*4) & 0xff]>>3);
        v = sine[(v+curFrame)&0xff]>> 2;
        v = MAX(v - (fade), 0);
    PLASMA_POST
}


void plasmaRender04(int curFrame, byte fade)
{
    PLASMA_PRE

    if( yo == 0 )
        v= x+xo;
    else
        v = 63- (x + xo);

    PLASMA_POST
}