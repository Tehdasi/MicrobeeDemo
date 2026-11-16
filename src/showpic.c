#include "showpic.h"

#include "colourFade.h"

void showPicFade( const byte* picData, byte ln, byte fade )
{
    vduColor();

//    byte curLine= fade>>4;

    
    byte* pp = PIXEL_TABLE_ADDRESS + ln*64;
    const byte* dp = picData + ln*64;

    const byte* cf= colourFade + (fade*16);


    for (byte x = 0; x < 64; x++)
    {
        byte v= *dp;

        byte v1 = v & 0xf;
        byte v2 = (v>>4) & 0xf;

        v1= cf[v1];
        v2 = cf[v2];

        *pp = (v2<<4) | v1;
            pp++;
            dp++;
    }
}