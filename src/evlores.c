#include "evlores.h"

#ifdef __MBEE
#include "mbee/mbee.h"
#else
#include "win\win.h"
#endif

byte evl_chunkyBuffer[64 * 32];


void evl_setupTiles(void)
{
    vduPixels();
    
    for (byte i = 0; i < 8; i++)
    {
        PIXEL_TABLE_ADDRESS[i] = 0;
        PIXEL_TABLE_ADDRESS[i+8] = 0xff;
    }

    for (int i = 0; i < 64 * 32; i++)
        TILE_TABLE_ADDRESS[i] = 128;
}


void evl_setPixel(byte x, byte y, byte col )
{
    vduColor();
    byte* pt = PIXEL_TABLE_ADDRESS + x + ((y / 2) * 64);
    byte b = *pt;

    if (y % 2 == 0)
        b = (b & 0xf) | (col << 4);
    else
        b = (b & 0xf0) | col;
    
    *pt = b;
}

void evl_setPixelClipped(int8_t x, int8_t y, byte col)
{
    if (x < 0 || x >= EVL_WIDTH || y < 0 || y >= EVL_HEIGHT)
        return;

}

void evl_clear(void)
{
    vduColor();

    for (int i = 0; i < EVL_WIDTH * EVL_STRIDE; i++)
        PIXEL_TABLE_ADDRESS[i] = 0;
}


void evl_chunkyToScreen()
{
    vduColor();
#ifdef __MBEE
    __asm

    push ix
        push iy
        push de

        ld l, #16
        ld ix, #0xF800
        ld iy, #_evl_chunkyBuffer


        cts_oloop :
    ld b, #64
        ld de, #1

        cts_iloop:
    ld a, (iy)
        add	a, a
        add	a, a
        add	a, a
        add	a, a
        ld c, a
        ld a, 64 (iy)
        add a, c
        ld(ix), a

        add ix, de
        add iy, de

        djnz cts_iloop

        ld de, #64
        add iy, de

        dec l
        jp nz, cts_oloop

        pop de
        pop iy
        pop ix


        __endasm;
#else
    {
        byte* pt = PIXEL_TABLE_ADDRESS;

        byte* bp = evl_chunkyBuffer;

        for (byte y = 0; y < 16; y++)
        {
            for (byte x = 0; x < 64; x++)
            {
                byte b1 = *bp;
                byte b2 = bp[64];

                *pt = ((b1 & 0xf) << 4) | b2 & 0xf;


                bp++;
                pt++;
            }

            bp += 64;
        }
    }
#endif
}
