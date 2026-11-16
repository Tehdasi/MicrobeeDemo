#include "textaudio.h"
#include "textaudiodata.h"

#include "misc.h"

char* textAudioNames[] = {
    "", //0
    "Thud", //1
    "Tish", //2
    "Faw", //3
    "Squige",
    "Scuush",
    "Buzz",
    "Bewww",
    "Herzzz",
    "Bmmm",
    "Click",
    "Zuuk", //11
    "Wack", //12
    "Waooh", //13
    "Dum", //14
    "Weer", //15
    "Drrr" //16
    "Zzzt", //17
    "zzt", //18
    "Tap", //19
    "Koor", //20
    "ZZZ", //21
    "Bizzle", //22
    "Oohh", //23
    "18", //23
};

const int textAudioStartFrame= 1250;


void textAudioUnrender()
{
    byte* tp = TILE_TABLE_ADDRESS + 64*15;
    for (int x = 0; x < 64; x++)
    {
        *tp = 32;
        tp++;
    }
}

void textAudioRender( byte px, char* text )
{
    byte* tp = TILE_TABLE_ADDRESS + px + 15 * 64;
    char* txp= text;

    while( *txp != 0 )
    {
        *tp= *txp;

        txp++;
        tp++;
    }
}

void renderChannel(byte x, byte o)
{
    dbyte uf = (frame- textAudioStartFrame) / 5;
    byte v = textAudioData[uf * 4 + o];

    byte* tp = TILE_TABLE_ADDRESS + 64 * 15 + x;
    byte* cp = PIXEL_TABLE_ADDRESS + 64 * 15 + x;
    char* nm = textAudioNames[v];
    byte i = 0;
    while (*nm != 0)
    {
        *tp = *nm;
        *cp = 0x07;
        cp++;
        tp++;
        nm++;
        i++;
    }

    while (i < 10)
    {
        switch (*cp)
        {
        case 0x07: *cp = 0x0e; break;
        case 0x0e: *cp = 0x0c; break;
        case 0x0c: *cp = 0x04; break;
        case 0x04: *cp = 0x00; break;
        }
        cp++;
        i++;
    }
}

void textAudioDoFrame(void)
{

    if ( frame < textAudioStartFrame || frame >= (1024 * 5 + textAudioStartFrame))
        return;

    vduColor();

    byte xb = 15;
    renderChannel( xb, 0 );
    renderChannel(xb+10, 1);
    renderChannel(xb+20, 2);
    renderChannel(xb+30, 3);
}
