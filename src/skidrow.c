#include "skidrow.h"
#include "skidrowsteps.h"

void skidrowInit(void)
{
    vduPixels();

    for (byte i = 0; i < 16; i++)
    {
        byte i2 = 15 - i;
        byte c = 0;
        if (i == 0)
            c = 0xff;

        PIXEL_TABLE_ADDRESS[i] = c;
        PIXEL_TABLE_ADDRESS[16 + i2] = c;
    }

    for (byte x = 0; x < 64; x++)
    {
        TILE_TABLE_ADDRESS[x + 64] = 129;
        TILE_TABLE_ADDRESS[x + (64 * 14)] = 128;
    }

    vduColor();
    for (byte i = 0; i < 64; i++)
    {
        PIXEL_TABLE_ADDRESS[i+64] = 0x07;
        PIXEL_TABLE_ADDRESS[i + 64*14] = 0x07;
    }

    for (int i = 0; i < 64 * 12; i++)
    {
        PIXEL_TABLE_ADDRESS[i + 64*2] = 0x44;
    }
}


void skidrowChangeTextBlock(byte *pp, byte c)
{
#ifndef __MBEE
    pp -= 0xf800;
    pp = PIXEL_TABLE_ADDRESS + (dbyte)pp;
#endif

//     byte* pp = PIXEL_TABLE_ADDRESS + x + y * 64;

    pp[0] = c;
    pp[1] = c;
    pp[2] = c;
    pp[3] = c;
    pp[4] = c;
}

void skidrowChangeText(byte pos, byte on)
{
    vduColor();

    byte col = on == 0 ? 0x47 : 0x44;

    skidrowChangeTextBlock( (byte*)skidrowSteps[pos], col );

    pos += 50;

    if (pos > 100)
        pos -= 100;

    skidrowChangeTextBlock((byte*)skidrowSteps[pos], col);
}



void skidrowSetText(byte* tp)
{
    byte *p= tp;


    for( byte ln= 0; ln< 10; ln++ )
    {
        byte* sl= p;
        byte ll= 0;

        if (*p == 0)
            break;


        while( *p!= '\n')
        {
            ll++;
            p++;
        }


        p++;

        byte* srb= TILE_TABLE_ADDRESS + (ln+3)*64;
        byte excess= 64-ll;
        byte eh= excess/2;


        for( byte i= 0; i< eh; i++ )
        {
            *srb= 32;
            srb++;
        }

        for( byte i= 0; i< ll; i++ )
        {
            *srb= *sl;
            srb++;
            sl++;
        }

        for( byte i= 0; i< (64-(ll+eh)); i++ )
        {
            *srb= 32;
            srb++;
        }
    }
}

