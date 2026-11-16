#include "wavetext.h"

#include "misc.h"
#include "res.h"



byte wavetext_text[256];

int wavetext_textPos = 0;

const int renderWidth = 6;


#define SINE  sine[((x + curFrame) * 4) & 0xff] >> 2

#define RENDER_TEXT_WAVE_ODD(n)\
{\
   {\
        byte x= 0;\
        byte o = SINE;\
        const byte* spr = wavetext_font_bitmaps + (tp[0] * 16);\
\
        for (byte y = 0; y < 16; y++)\
        {\
            *pp = spr[(o+y)%16] << n;\
            pp++;\
        }\
    }\
\
    tp++;\
\
    for (int x = 1; x < renderWidth; x++)\
    {\
        byte o = SINE;\
        byte o2 = 0;\
    \
        const byte* spr = (wavetext_font_bitmaps + (tp[0]*16));\
    \
        for (byte y = 0; y < 16; y++)\
        {\
            *pp = (spr[(o+y)%16] >> (8-n)) & 0xff;\
            pp++;\
        }\
\
        for (byte y = 0; y < 16; y++)\
        {\
            * pp = spr[(o+y)%16] << n;\
            pp++; \
        }\
        \
        tp++; \
    }\
\
    {\
        byte x = renderWidth; \
        byte o = SINE; \
        const byte* spr = wavetext_font_bitmaps + (tp[0] * 16); \
        \
        for (byte y = 0; y < 16; y++)\
        {\
            * pp = (spr[(o+y)%16] >> (8-n)) & 0xff; \
            pp++; \
        }\
    }\
    \
    tp++; \
}


#define RENDER_TEXT_WAVE_EVEN(n)\
{\
    for (int x = 0; x < renderWidth; x++)\
    {\
    \
        const byte* spr = (wavetext_font_bitmaps + (tp[0]*16));\
        byte o= SINE;\
    \
        for (byte y = 0; y < 16; y++)\
        {\
            *pp = (spr[(o+y)%16] >> (8-n)) & 0xff;\
            pp++;\
        }\
\
        for (byte y = 0; y < 16; y++)\
        {\
            * pp = (spr[(o+y)%16] << n) & 0xff;\
            pp++; \
        }\
        \
        tp++; \
    }\
}


void waveTextInit(void)
{
    for (int y = 0; y < 15; y++)
    {
        for (int x = 0; x < 6; x++)
        {
            TILE_TABLE_ADDRESS[x + y * 64] = x + 128;
        }

        TILE_TABLE_ADDRESS[8 + y * 64] = 1 + 128;
        TILE_TABLE_ADDRESS[10 + y * 64] = 1 + 128;
        TILE_TABLE_ADDRESS[12 + y * 64] = 1 + 128;
        TILE_TABLE_ADDRESS[14 + y * 64] = 1 + 128;

        //for (int x = 4; x < 8; x++)
        //{
        //    TILE_TABLE_ADDRESS[x + y * 64] = (x-4) + 128;
        //}
    }

    vduColor();
    for (int y = 0; y < 15; y++)
    {
        for (int x = 0; x < 64; x++)
        {
            PIXEL_TABLE_ADDRESS[x + y*64] = 0x07;
        }
    }
    vduPixels();
}

void waveTextRender(int curFrame)
{
    vduPixels();
    wavetext_textPos = curFrame;

    byte* pp = PIXEL_TABLE_ADDRESS;
    const byte* tp = wavetext_font_text + ((wavetext_textPos +8)/ 16);
    byte off = wavetext_textPos % 16;

    // TILE_TABLE_ADDRESS[1] = 'b';
    // TILE_TABLE_ADDRESS[2] = 'a' + off;

//     RENDER_TEXT_WAVE_EVEN(3);

    switch (off)
    {
    case 0: RENDER_TEXT_WAVE_ODD(0); break;
    case 1: RENDER_TEXT_WAVE_ODD(1); break;
    case 2: RENDER_TEXT_WAVE_ODD(2); break;
    case 3: RENDER_TEXT_WAVE_ODD(3); break;
    case 4: RENDER_TEXT_WAVE_ODD(4); break;
    case 5: RENDER_TEXT_WAVE_ODD(5); break;
    case 6: RENDER_TEXT_WAVE_ODD(6); break;
    case 7: RENDER_TEXT_WAVE_ODD(7); break;

    case 8: RENDER_TEXT_WAVE_EVEN(0); break;
    case 9: RENDER_TEXT_WAVE_EVEN(1); break;
    case 10: RENDER_TEXT_WAVE_EVEN(2); break;
    case 11: RENDER_TEXT_WAVE_EVEN(3); break;
    case 12: RENDER_TEXT_WAVE_EVEN(4); break;
    case 13: RENDER_TEXT_WAVE_EVEN(5); break;
    case 14: RENDER_TEXT_WAVE_EVEN(6); break;
    case 15: RENDER_TEXT_WAVE_EVEN(7); break;
    }
}
