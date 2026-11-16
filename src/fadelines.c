#include "fadelines.h"

byte fadelines_buf[16*15];



void fadelines_init( void )
{
    for( byte x= 0; x< 64; x++ )
    {
        for( byte y= 0; y< 15; y++ )
        {
            TILE_TABLE_ADDRESS[x + y*64]= 
                x < 32 ? 128 + y : 128 + 30 + y;
        }
    }

    vduColor();
    for( byte x= 0; x< 64; x++ )
    {
        for( byte y= 0; y< 15; y++ )
        {
            PIXEL_TABLE_ADDRESS[x + y*64]= x < 32 ? 0x1f : 0x4f;
        }
    }

}

void fadelines_doFrame( dbyte curFrame )
{
    vduPixels();

    for( byte y= 0; y< 16*15; y++ )
        fadelines_buf[y] = 0;

    for( dbyte ln= 0; ln < 16*16; ln+=16 )
    {
        dbyte start= (256 - (curFrame + ln));
        byte y= start&0xff;
        byte h= y/13;

        if( y < 16*15)
        {
             if ((dbyte)(y + h) > 16 * 15)
             {
                 h = 16 * 15 - y;
             }

             for (int i = 0; i < h; i++)
                 fadelines_buf[y + i] = 0xff;
        }
    }


    for( byte y= 0; y< 16*15; y++ )
        PIXEL_TABLE_ADDRESS[y]= fadelines_buf[y];


    for (byte y = 0; y < 16 * 15; y++)
        fadelines_buf[y] = 0;

    for (dbyte ln = 0; ln < 16 * 16; ln += 16)
    {
        dbyte start = curFrame + ln;
        byte y = start & 0xff;
        byte h = y / 13;

        if (y < 16 * 15)
        {
            if ((dbyte)(y + h) > 16 * 15)
            {
                h = 16 * 15 - y;
            }

            for (int i = 0; i < h; i++)
                fadelines_buf[ y + i] = 0xff;
        }
    }


    for (byte y = 0; y < 16 * 15; y++)
        PIXEL_TABLE_ADDRESS[y+16*30] = fadelines_buf[y];
}
