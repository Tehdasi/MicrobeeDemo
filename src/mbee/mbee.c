#include <stdbool.h>
#include <string.h>
#include "..\misc.h"
#include "mbee.h"

#define VDU_VSYNC_MASK ( 1 << crtStatusVSync )
#define SOUND_MASK 0x60


#define TILES_WIDTH 80

// From the R6545 crt display controller manual

///< crt/vdu status byte
enum {

    crtStatusVSync = 5,                 // Video in vsync
    crtStatusLightPen,                  // Keyboard hit
    crtStatusUpdateReady,               // Wrote to reg 31
};

///< Crt registers
enum {

    crtHorizontalTotalChars = 0,
    crtHorizontalDisplayedChars = 1,
    crtHorizontalSyncPosition = 2,
    crtHorizontalVerticalSyncWidths = 3,
    crtVerticalTotalRows = 4,
    crtVerticalTotalLineAdjust = 5,
    crtVerticalDisplayedRows = 6,
    crtVerticalSyncPosition = 7,
    crtModeControl = 8,
    crtRowScanLines = 9,
    crtCursorStartLine = 10,
    crtCursorEndLine = 11,
    crtDisplayStartAddressHigh = 12,
    crtDisplayStartAddressLow = 13,
    crtCursorPositionHigh = 14,
    crtCursorPositionLow = 15,
    crtLightPenHigh = 16,
    crtLightPenLow = 17,
    crtUpdateAddressHigh = 18,
    crtUpdateAddressLow = 19,
};

static volatile __sfr __at 0x02 SoundPort;
static volatile __sfr __at 0x0C CrtRegPort;
static volatile __sfr __at 0x0D CrtDataPort;
static volatile __sfr __at 0x08 VduBankPort;

int vBlankWaits;
bool cols80;

///< Set crt register value
void vdu_reg_set( unsigned char reg, unsigned char value ) {

    CrtRegPort = reg;
    CrtDataPort = value;
}

///< Setup crt to 64x16 tiles and hide the cursor
///< There's a fixed set combination of values that will work at each resolution
///< Changing individual values will often result in a blank screen on real hardware
void vdu_crt_setup(void) {
    vdu_reg_set( crtHorizontalTotalChars, 108 - 1 );    // horizontal sync timing constant
    vdu_reg_set( crtHorizontalDisplayedChars, 64 );     // number of displayed characters per line
    vdu_reg_set( crtHorizontalSyncPosition, 81 );       // horizontal sync position
    vdu_reg_set( crtHorizontalVerticalSyncWidths, 55 ); // horizontal and vertical sync width
    vdu_reg_set( crtVerticalTotalRows, 19 - 1 );        // vertical sync width
    vdu_reg_set( crtVerticalTotalLineAdjust, 9 );       // vertical sync timing constant
    vdu_reg_set( crtVerticalDisplayedRows, 16 );        // number of displayed rows per screen
    vdu_reg_set( crtVerticalSyncPosition, 17 );         // vertical sync position
    vdu_reg_set( crtModeControl, 72 );                  // mode control constant
    vdu_reg_set( crtRowScanLines, 16-1 );               // number of scan lines per character
    vdu_reg_set( crtCursorStartLine, 0x20+15 );         // cursor mode and start line
    vdu_reg_set( crtCursorEndLine, 15 );                // cursor end line
    vdu_reg_set( crtDisplayStartAddressHigh, 0 );       // display start address relative to 0F000h
    vdu_reg_set( crtDisplayStartAddressLow, 0 );
    vdu_reg_set( crtCursorPositionHigh, 0 );            // cursor position
    vdu_reg_set( crtCursorPositionLow, 0 );

/*
    vdu_reg_set( crtHorizontalTotalChars, 113 );
    vdu_reg_set( crtHorizontalDisplayedChars, 80 );
    vdu_reg_set( crtHorizontalSyncPosition, 86 );
    vdu_reg_set( crtHorizontalVerticalSyncWidths, 44 );
    vdu_reg_set( crtVerticalTotalRows, 38 );
    vdu_reg_set( crtVerticalTotalLineAdjust, 0 );
    vdu_reg_set( crtVerticalDisplayedRows, 24 );
    vdu_reg_set( crtVerticalSyncPosition, 31 );
    vdu_reg_set( crtModeControl, 0 );
    vdu_reg_set( crtRowScanLines, 9 );
    vdu_reg_set( crtCursorStartLine, 32 );
    vdu_reg_set( crtCursorEndLine, 0 );
    vdu_reg_set( crtDisplayStartAddressHigh, 0x20 );
    vdu_reg_set( crtDisplayStartAddressLow, 0 );
    vdu_reg_set( crtCursorPositionHigh, 0 );
    vdu_reg_set( crtCursorPositionLow, 0 );
*/
}

///< Switch in vdu PCG or colour data at 0xF8000
void vdu_bank( int colour ) {

    VduBankPort = colour ? 0x47 : 0x07;
}

///< Clear screen
void vdu_screen_clear(void) {
    memset( TILE_TABLE_ADDRESS, 32, 4096 );
}

///< Setup vdu
void vdu_init(void) {

    vdu_screen_clear();
    vdu_crt_setup();
}



void vBlank(void) __naked
{
    __asm
    push de
    ld de, #0

wait: 
    inc de
    in a, (0x0c)
    cp #0xa0
    jr z, wait

 wait2:
    inc de
    in a, (0x0c)
    cp #0xa0
    jr nz, wait2

    ld (_vBlankWaits), de

    pop de
    ret
    __endasm;
}



byte getPort(void) __naked
{
    __asm 
        in a,(0x50)
        ret
    __endasm;
}

void initBlocks(void)
{
    vdu_bank(0);

    for( byte i= 0; i< 16; i++)
    {
        for( byte y= 0; y< 16; y++)
        {
            byte y4= y/4;
            byte c= ((i>>y4)&1 == 1) ? 0xff : 0x0;

            PIXEL_TABLE_ADDRESS[(i*16)+y]= c;
        }
    }
}


bool isKeyDown(uint8_t key) __naked {

    key;
    __asm
    ld    a, l

        ; write the loword to register 0x12 (18)
        ld      b, a
        ld      a, #0x12
        out(#0x0c), a
        ld      a, b
        rrca
        rrca
        rrca
        rrca
        and #0x03
        out(#0x0d), a

        ; write the hiword to register 0x13 (19)
        ld      a, #0x13
        out(#0x0c), a
        ld      a, b
        rlca
        rlca
        rlca
        rlca
        out(#0x0d), a

        ; enable latch rom(to disable key scan)
        ld      a, #0x01
        out(#0x0b), a


        ; read register 0x10 (16) (light pen address to clear light pen flag)
        ld      a, #0x10
        out(#0x0c), a
        in      a, (#0x0d)

        ; write to port 31 to scan the key
        ld      a, #0x1f
        out(#0x0c), a
        out(#0x0d), a

        ; wait for update strobe bit to be set
        00001$:     in      a, (#0x0c)
        bit     #7, a
        jr      z, 00001$

        ; read status register and check lpen bit
        in      a, (#0x0c)
        bit     #6, a

        ; turn off latch rom
        ld      a, #0x00
        out(#0x0b), a

        ; setup return value
        ld      l, #1
        jr      nz, 00002$
        ld      l, #0
        00002$:

    ;; Clear keyboard set flag
        ld c, #0x0c
        in a, (c)

        ret
        __endasm;
}


void initSystem(bool col80)
{
    col80;
    vdu_init();

    //initBlocks();
}   

void vduColor()
{
    VduBankPort = 0x47;
}

void vduPixels(void)
{
    VduBankPort = 0x07;
}

void playSound(byte* soundData, int samples)
{
    (void)soundData;
    (void)samples;
    for (int i = 0; i < 200; i++) { 

        SoundPort = SOUND_MASK;
        for (int delay = 0; delay < 2; delay++);
        SoundPort = 0;
        for (int delay = 0; delay < 200; delay++);
    }
}

int lastClockSample = 0;

int getClockVal(void) __naked
{

    __asm
    ld a, #0
    out (#0x42), a
    in a, (#0x43)
    ld e, a
    ld d, #0
    ret
    __endasm;
}

int sampleClock(void)
{
    //time_t t = time(NULL);
    //struct tm* t2 = localtime(&t);
    //int nt = t2->tm_sec + t2->tm_min * 60 + t2->tm_hour * 60 * 60;
    int nt = getClockVal();

    return nt;
    /*
    if (lastClockSample == 0)
    {
        lastClockSample = nt;
        return 0;
    }
    else
    {
        int t = nt - lastClockSample;
        lastClockSample = nt;
        return t;
    }
    */
}

void makeSound(int cycles, byte on)
{
    for (int i = 0; i < cycles; i++)
    {
        SoundPort = SOUND_MASK;
        for (int delay = 0; delay < on; delay++);
        SoundPort = 0;
        for (int delay = 0; delay < (200-on); delay++);
    }
} 

byte adsr[]= 
{
/*
    100,
    110,
    120,
    130,

    140,
    150,
    160,
    170,

    180,
    190,
    200
    */    


    100,
    200,
    150,
    100,
};

byte adsrLength= sizeof(adsr)/sizeof(byte);

void makeSound3(int low)
{
    for (byte i = 0; i < adsrLength; i++)
    {
        int jj= adsr[i]+low;

        for( byte j= 0; j< 5; j++ )
        {
            SoundPort = SOUND_MASK;
            for (int delay = 0; delay < jj; delay++);
            SoundPort = 0;
            for (int delay = 0; delay < jj; delay++);
        }
    }
} 

void makeSound32(void)
{
    for (byte i = 0; i < adsrLength; i++)
    {
        int jj= adsr[i]/2;

        for( byte j= 0; j< 5; j++ )
        {
            SoundPort = SOUND_MASK;
            for (int delay = 0; delay < jj; delay++);
            SoundPort = 0;
            for (int delay = 0; delay < jj; delay++);
        }
    }
} 

void makeSound2(void)
{
    for (int i = 100; i < 200; i++)
    {
        SoundPort = SOUND_MASK;
        for (int delay = 0; delay < i; delay++);
        SoundPort = 0;
        for (int delay = 0; delay < i; delay++);
    }
} 

void makeSound11(void)
{
    for (int i = 0; i < 2000; i++)
    {
        SoundPort = SOUND_MASK;
        for (int delay = 0; delay < 10; delay++);
        SoundPort = 0;
        for (int delay = 0; delay < 30; delay++);
    }
} 


void makeSound4( int pitch, int length )
{
    int i= length;
    while( i > 0 )
    {
        SoundPort = SOUND_MASK;
        for (int delay = 0; delay < pitch; delay++);
        SoundPort = 0;
        for (int delay = 0; delay < pitch; delay++);
        i-= pitch*2;
    }
}

void pause(int msecs)
{
    for (int i = 0; i < msecs; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            SoundPort = 0;
        }
    }
}


void playAudio(void)
{   

    // for( byte i= 0; i< 10; i++ )           
    // {
    //     makeSound3(); 
    //     makeSound3(); 
    //     makeSound32(); 
    //     pause(100);
    // }

    for( byte j= 0; j< 4; j++ )
    {
        for( byte i= 0; i< 3; i++ )           
        {
            makeSound4(50, 1000); 
            pause(50);
            makeSound4(100, 1000); 
            pause(50);
            makeSound4(150, 1000); 
            pause(50);
        }


        makeSound4(150, 1000); 
        pause(50);
        makeSound4(200, 1000); 
        pause(50);
        makeSound4(250, 1000); 
        pause(50);

    }

    pause(1000);

    // makeSound(100,30);
    // makeSound(100,55);
    // makeSound(100,100);
    // makeSound(100,30);
    // makeSound(100,55);
    // makeSound(100,30);
}
 
