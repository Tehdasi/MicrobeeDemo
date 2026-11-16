#include "misc.h"
#include <math.h>

#include "wavetext.h"



#include "staticlines.h"
#include "plasma.h"
#include "wavetext.h"
#include "evlores.h"
#include "sections.h"
#include "colourfade.h"
#include "showpic.h"
#include "skidrow.h"
#include "colourribbons.h"
#include "rotators.h"
#include "compiledsprite.h"
#include "bars.h"
#include "fadelines.h"
#include "textaudio.h"

#include "res.h"

//#define SHOWFPS
#define PLAYAUDIO
//#define SINGLEPART
//#define SKIPPER


typedef void(*effectFunc)(dbyte curFrame, bool init);

typedef struct
{
    effectFunc func;
    dbyte frames;
} EffectPlan;

void clearScreen()
{
    vduColor();
    for( int i= 0; i< 64*15; i++ )
    {
        PIXEL_TABLE_ADDRESS[ i ]= 0;
        TILE_TABLE_ADDRESS[ i ]= 32;
    }
}

void doNoise1(dbyte curFrame, bool init)
{
    if (init)
    {
        initStaticLines();
    }


    for (byte y = 0; y < 15; y++)
    {
//        byte i = zigzag_blunt(y, 8) * 8;

        staticLines_intensity[y] = sine[((curFrame*3) + (y*18))%0xff];;
    }


    staticLines(curFrame);
}


void doNoise2(dbyte curFrame, bool init)
{
    if (init)
    {
        initStaticLines();

        for (byte i = 0; i < 16; i++)
            staticLines_intensity[15 - i] = i * 16;
    }

    staticLines(curFrame);
}

void doNoise3(dbyte curFrame, bool init)
{
    if (init)
    {
        initStaticLines();
    }

    byte anim[] = {
        0xff, 0xff, 0x00, 0xff, 0xff,
        0xff, 0xff, 0x00, 0xff, 0xff,
    };


    byte af = (curFrame / 30) % 2 == 0 ? 0 : 1;

    float cf = (curFrame%200) / 200.0;

    

     for (byte i = 0; i < 15; i++)
     {
         staticLines_intensity[i] = 0xff;
     }

     for (byte i = 0; i < 5; i++)
     {
         staticLines_intensity[i] = anim[af*5 + i];
     }

    staticLines(curFrame);
}


void doEnd(dbyte curFrame, bool init)
{
    const byte xOff = 24;
    vduColor();
    if (init)
    {
        for (int i = 0; i < 64 * 15; i++)
            TILE_TABLE_ADDRESS[i] = 32;
        for (int i = 0; i < 64 * 15; i++)
            PIXEL_TABLE_ADDRESS[i] = 0x00;

        byte* tp = TILE_TABLE_ADDRESS + 64 * 7 + xOff;
        char* msg = "-T-h-e---e-n-d-";

        while (*msg != 0)
        {
            *tp = *msg;
            tp++;
            msg++;
        }
    }


    {
        byte *pp= PIXEL_TABLE_ADDRESS + 64 * 7 + xOff;
        byte bs= (-curFrame/3)&0xff;
        for (byte i = 0; i < 64; i++)
        {
            byte ci = zigzag_sharp((bs+i)&0xff, 15);
            
            *pp = colorInten[ci];
            pp++;
        }
    }
}

void doTest(dbyte curFrame, bool init)
{
    (void)curFrame;
    vduColor();
    TILE_TABLE_ADDRESS[0]= 'a';
    PIXEL_TABLE_ADDRESS[0]= 0x23;
    TILE_TABLE_ADDRESS[1]= 'b';
    PIXEL_TABLE_ADDRESS[1]= 0x23;
    TILE_TABLE_ADDRESS[2]= 'c';
    PIXEL_TABLE_ADDRESS[2]= 0x23;
}

byte FadeForPlasma( dbyte curFrame, dbyte endFrame )
{
    byte fade= 0;
    if (curFrame < 64)
    {
        fade = (63 - curFrame);
    }
    else if (curFrame > (endFrame-64))
    {
        fade = MIN(curFrame - (endFrame - 64), 64);
    }

    return fade;
}

void doPlasma1(dbyte curFrame, bool init)
{
    vduPixels();

    if (init)
        plasmaPrep();

    byte fade = 0; // sine[(curFrame*4)&0xff]>>3;

    plasmaRender01(curFrame, fade);
}


void doPlasma2(dbyte curFrame, bool init)
{
    vduPixels();
    if (init)
        plasmaPrep();

    plasmaRender02(curFrame, FadeForPlasma(curFrame, 300));
}

void doPlasma3(dbyte curFrame, bool init)
{
    vduPixels();
    if (init)
        plasmaPrep();

    plasmaRender03(curFrame, FadeForPlasma(curFrame, 400));
}

void doWaveText1(dbyte curFrame, bool init)
{
    if (init)
    {
        waveTextInit();
    }

    waveTextRender(curFrame);
}



void ShowPicFadeInShared(dbyte curFrame, bool init, byte* data)
{
    if (init)
    {
        evl_setupTiles();
        vduColor();
        for (int i = 0; i < 64 * 15; i++)
            PIXEL_TABLE_ADDRESS[i] = 0;

    }

    const dbyte maxFrame = 400;

    byte fade = 0;

    if (curFrame < 128)
    {
        byte fd = 15 - (curFrame & 0xf);

        byte ln = (curFrame & 0xff) >> 4;

        showPicFade(data, ln, fd);
        showPicFade(data, 15 - ln, fd);
    }

    if (curFrame > (maxFrame - 128))
    {
        byte ff = curFrame - (maxFrame - 128);
        byte fd = ff & 0xf;
        byte ln = (ff & 0xff) >> 4;

        showPicFade(data, ln, fd);
        showPicFade(data, 15 - ln, fd);
    }
}

void doShowPicFadeIn01(dbyte curFrame, bool init)
{
    ShowPicFadeInShared(curFrame, init, skull);
}

void doShowPicFadeIn02(dbyte curFrame, bool init)
{
    ShowPicFadeInShared(curFrame, init, sunset);
}


void doSections1(dbyte curFrame, bool init)
{
    if (init)
    {
        sectionsInit();

        // vduPixels();
        // for( byte y= 0; y< 15; y++ )
        //     PIXEL_TABLE_ADDRESS[y*64]= 0;
    }

    const byte sections = 6;
    for (byte i = 0; i < sections; i++)
    {
        sections_data[i].color = i%2 == 0 ? 7 : 0;
        sections_data[i].length = 255;
    }
    sections_data[sections].color= 1;
    sections_data[sections].length= 255;


    for (byte y = 0; y < 15; y++)
    {
        // for (byte i = 0; i < sections; i++)
        // {
        //     sections_data[i].length = 8 + (sine[((curFrame * (i+2)) + (y * 8)) & 0xff] >> 3);
        // }
        sections_data[0].length = 8 + (sine[((curFrame * 11) + (y * 8)) & 0xff] >> 3);
        sections_data[1].length = 8 + (sine[((curFrame * 10) + (y * 8) + 34) & 0xff] >> 3);
        sections_data[2].length = 8 + (sine[((curFrame * 9) + (y * 8) + 64) & 0xff] >> 3);
        sections_data[3].length = 8 + (sine[((curFrame * 8) + (y * 8) + 44) & 0xff] >> 3);
        sections_data[4].length = 8 + (sine[((curFrame * 7) + (y * 8) + 44) & 0xff] >> 3);
        sections_data[5].length = 8 + (sine[((curFrame * 6) + (y * 8) + 44) & 0xff] >> 3);
//        sections_data[6].length = 8 + (sine[((curFrame * 5) + (y * 8) + 44) & 0xff] >> 3);

        sectionsRenderHalf(y);
    }
}

void doSections2(dbyte curFrame, bool init)
{
    if (init)
    {
        sectionsInit();
    }

    sections_data[0].color = 0;
    //    sections_data[0].length = 2 + (sine[(curFrame+)&0xff]>>3);
    sections_data[0].length = 2;

    sections_data[1].color = 4;
    sections_data[1].length = 10;
    sections_data[2].color = 6;
    sections_data[2].length = 255;
    sections_data[3].color = 4;
    sections_data[3].length = 255;
    sections_data[4].color = 0;
    sections_data[4].length = 255;
    sections_data[5].color = 0;
    sections_data[5].length = 255;

    for (byte y = 0; y < 15; y++)
    {
        sections_data[0].length = 8 + (sine[((curFrame * 8) + (y * 8)) & 0xff] >> 2);
        sections_data[1].length = 8 + (sine[((curFrame * 8) + (y * 8) + 34) & 0xff] >> 2);
        sections_data[2].length = 8 + (sine[((curFrame * 8) + (y * 8) + 64) & 0xff] >> 2);
        sections_data[3].length = 8 + (sine[((curFrame * 8) + (y * 8) + 44) & 0xff] >> 2);
        sectionsRenderHalf(y);
    }
}

void doSections3(dbyte curFrame, bool init)
{
    if (init)
    {
        sectionsInit();
    }

    sections_data[0].color = 0;
    sections_data[0].length = 2;

    sections_data[1].color = 3;
    sections_data[1].length = 10 + (sine[((curFrame * 11)) & 0xff] >> 2);
    sections_data[2].color = 7;
    sections_data[2].length = 255;
    sections_data[3].color = 3;
    sections_data[3].length = 255;
    sections_data[4].color = 0;
    sections_data[4].length = 255;
    sections_data[5].color = 0;
    sections_data[5].length = 255;

    sectionsRenderFull(0);
    sectionsApplyAll();


    // for( byte y= 0; y< 8; y++ )
    // {
    //     sections_data[0].length = 8 + (sine[((curFrame*11)+(y*8))&0xff]>>2);
    //     sections_data[1].length = 18 + (sine[((curFrame*10)+(y*8) + 34)&0xff]>>2);
    //     sections_data[2].length = 18 + (sine[((curFrame * 9) + (y * 8) + 64) & 0xff] >> 2);
    //     sections_data[3].length = 18 + (sine[((curFrame * 8) + (y * 8) + 44) & 0xff] >> 2);

    //     sectionsRenderHalf(y);
    // }
}




char* skidrowTextScreens[] = {
    "\n\n\n\nSo this is the Microbee and it's sole source\n of sound is a CPU driven buzzer.\n\n\n\n\n",
    "\n\n\n\nA sample of what this sounds\nlike will now be played.\n",
    "\n\n\nYeah, nah.\nI'll save you from having to listen to all that.\n\nThis demo implements revolutionary technology\nthat coverts sounds to text.\n" ,
    "\n\n\n\nCheck it out going on down below.\nOkay, starting demo now...\n\n\n\n" ,
};


void doSkidrow(dbyte curFrame, bool init)
{
    if (init)
    {
        skidrowInit();

        skidrowSetText( skidrowTextScreens[0]);


        for (int i = 0; i < sizeof(skidrowTextScreens) / sizeof(char*); i++)
        {
            char* tp = skidrowTextScreens[i];
            int tc= 0;
            while (*tp != 0)
            {
                if( *tp != '\n' && *tp != ' ')
                    tc++;
                tp++;
            }

            // TraceLog( LOG_INFO, "%d: %d", i, tc);
        }
    }

    const int screenMaxTime= 400;

    int p = curFrame%screenMaxTime;


    if (p < 50)
    {
        skidrowChangeText(p, 0);
    }
    else if (p < (screenMaxTime-50))
    {
    }
    else
    {
        skidrowChangeText(50 - (1 + (screenMaxTime - p)), 1);
    }

    if (p == 0)
    {
        int ts = curFrame / screenMaxTime;
        skidrowSetText(skidrowTextScreens[ts]);
    }

#if defined(PLAYAUDIO) && defined(__MBEE)
    if (curFrame == 750)
    {
        playAudio();
    }
#endif
}




void doRotators1(dbyte curFrame, bool init)
{
    if (init)
    {
        for (byte i = 0; i < 64; i++)
            plasmaGenTile(i);


        for (int i = 0; i < 64 * 15; i++)
            TILE_TABLE_ADDRESS[i] = ' ';
    }


    for (byte i = 0; i < 15; i++)
    {
//        rotatorPositions[i] = curFrame % 64; // (curFrame +  i*2)%64;
//        rotatorPositions[i] = (curFrame/4 +  i*2)%64;
        rotatorPositions[i] = 0;
    }

    renderRotators();
}


void doRotators2(dbyte curFrame, bool init)
{
    if (init)
    {
        for (byte i = 0; i < 64; i++)
            plasmaGenTile(i);


        for (int i = 0; i < 64 * 15; i++)
        {
            TILE_TABLE_ADDRESS[i] = ' ';
        }
    }


    for (byte i = 0; i < 5; i++)
    {
        rotatorPositions[i] = (curFrame / 4) % 64;
    }
    for (byte i = 5; i < 10; i++)
    {
        rotatorPositions[i] = ((curFrame / 4)+ 4) % 64;
    }
    for (byte i = 10; i < 15; i++)
    {
        rotatorPositions[i] = ((curFrame / 4) + 8) % 64;
    }

    renderRotators();
}

void doRotators3(dbyte curFrame, bool init)
{
    if (curFrame == 0)
    {
        for (byte i = 0; i < 64; i++)
            plasmaGenTile(i);


        for (int i = 0; i < 64 * 15; i++)
        {
            TILE_TABLE_ADDRESS[i] = ' ';
        }
    }

    for (byte i = 0; i < 7; i++)
    {
        rotatorPositions[i] = (curFrame/4 +i*2)%64;
        rotatorPositions[14-i] = (curFrame/4 + i*2) % 64;
    }

    rotatorPositions[7] = // (curFrame / 4 + 7 * 2) % 64;
        (curFrame / 4 + 13) % 64;

    renderRotators();
}



byte r2_circ[] = {
    2,
    4,
    6,
    7,
    6,
    4,
    2,
    0,
};

void doRibbon2(dbyte curFrame, bool init)
{
    if (init)
    {
        colourRibbonInit();
    }


    dbyte cf = curFrame*3;

    int fi = curFrame % 8;
    int cw = r2_circ[fi];

    colourRibbons[0].start = 32 - cw;
    colourRibbons[0].length = cw*2;
    colourRibbons[0].colour = 0x11;

    colourRibbonRender(1);
}


void doRibbon1(dbyte curFrame, bool init)
{
    if (init)
    {
        colourRibbonInit();
        clearScreen();
    }


    dbyte cf = (curFrame>>1) + curFrame;

    colourRibbons[0].start = 4 + (sine[cf & 0xff] >> 3);
    colourRibbons[0].length = 25;
    colourRibbons[0].colour = 0x11;

    cf += curFrame >> 2;

    colourRibbons[1].start = 4 + (sine[cf & 0xff] >> 3);
    colourRibbons[1].length = 25;
    colourRibbons[1].colour = 0x22;

    cf += curFrame >> 2;
    colourRibbons[2].start = 4 + (sine[cf & 0xff] >> 3);
    colourRibbons[2].length = 25;
    colourRibbons[2].colour = 0x44;


    colourRibbonRender(3);
}

int doColTest(int curFrame)
{
    curFrame;
    vduColor();

    for (byte i = 0; i < 80; i++)
    {
        byte c = (i % 16);
        c = c << 4 | c;

        PIXEL_TABLE_ADDRESS[i] = c;
    }

    PIXEL_TABLE_ADDRESS[0] = 0x45;
    PIXEL_TABLE_ADDRESS[79] = 0x45;
    PIXEL_TABLE_ADDRESS[0 + (80 * 23)] = 0x45;
    PIXEL_TABLE_ADDRESS[79 + (80 * 23)] = 0x45;


    return 0;
}

void doSections4(dbyte curFrame, bool init)
{
    if (init)
    {
        hsectionsInit();
    }

    //    curFrame/=  10;

        //sections_data[0].color = 1;
        //sections_data[0].length = 1;

        //sections_data[1].color = 2;
        //sections_data[1].length = 255;

        //sections_data[2].color = 4;
        //sections_data[2].length = 255;

        //sections_data[3].color = 2;
        //sections_data[3].length = 255;

    sections_data[0].color = 0;
    sections_data[0].length = 9 + (sine[((curFrame * 2)) & 0xff] >> 3);

    for (byte i = 0; i < 10; i++)
    {
        byte si = (i * 2) + 1;

        sections_data[si].length = 9 + (sine[((curFrame * 2) + i * 20) & 0xff] >> 3);
        sections_data[si + 1].length = 9 + (sine[((curFrame * 2) + i * 20) & 0xff] >> 3);
    }

    sections_data[0].color = 0x7;
    sections_data[1].color = 0xc;
    sections_data[2].color = 0x9;
    sections_data[3].color = 0x0;
    sections_data[4].color = 0x1;
    sections_data[5].color = 0x2;
    sections_data[6].color = 0x1;
    sections_data[7].color = 0x2;
    sections_data[8].color = 0x1;
    sections_data[9].color = 0x2;
    sections_data[10].color = 0x1;
    sections_data[11].color = 0x2;
    sections_data[12].color = 0x1;
    sections_data[13].color = 0x2;
    sections_data[14].color = 0x1;
    sections_data[15].color = 0x2;


    hsectionsRenderFull(0);
//    hsectionsApplyAll();

    // for( byte y= 0; y< 8; y++ )
    // {
    //     sections_data[0].length = 8 + (sine[((curFrame*11)+(y*8))&0xff]>>2);
    //     sections_data[1].length = 18 + (sine[((curFrame*10)+(y*8) + 34)&0xff]>>2);
    //     sections_data[2].length = 18 + (sine[((curFrame * 9) + (y * 8) + 64) & 0xff] >> 2);
    //     sections_data[3].length = 18 + (sine[((curFrame * 8) + (y * 8) + 44) & 0xff] >> 2);

    //     sectionsRenderHalf(y);
    // }

//vduColor();
//for (int i = 0; i < 21; i++)
//{
//    TILE_TABLE_ADDRESS[(i*2) + 4] = 128 + i;
//    PIXEL_TABLE_ADDRESS[(i*2) + 4] = 0x12;
//}

//TILE_TABLE_ADDRESS[1 + 80*11] = 'a';
//PIXEL_TABLE_ADDRESS[1 + 80 * 11] = 0x34;
//TILE_TABLE_ADDRESS[1 + 80 * 12] = 'b';
//PIXEL_TABLE_ADDRESS[1 + 80 * 12] = 0x34;
}

void doFadeLines(dbyte curFrame, bool init)
{
    if( init )
        fadelines_init();

    fadelines_doFrame(curFrame);
}

void doRotatingBars(dbyte curFrame, bool init)
{
    if (init)
    {
        initBars();
    }

    byte numBars = MIN(curFrame/50, 6);

    if (curFrame > 400)
    {
        numBars = MAX(MIN(((120-(curFrame - 400)) / 20) + 1, 6), 0);
    }

    dbyte cf = curFrame*3;
    byte o = 256 / 6;

    for (byte i = 0; i < numBars; i++)
    {
        int bp = (cf + o * i);
        byte sv = sine[bp & 0xff];
        byte sv2 = sine[(bp + 64) & 0xff];

        barsData[i].y = 32 + (sv >> 1) + (sv >> 2);
        byte z = (sv2 > 128) ? 0 : 1;
        barsData[i].z = z;
        barsData[i].bright = sv2 >> 5;

    }
    barsData[numBars].bright = 99;

    // barsData[0].y = 180;
    // barsData[0].z = 1;
    // barsData[0].bright = 0;
    // barsData[1].bright = 99;

    renderBars();
}

// completed funcs
// 
// need 6370 total frames
EffectPlan parts[] = {

    
    // working
    { doSkidrow, 1400 },
    // works
     { doRotatingBars, 520 },
    // works, black and white blobby thing with a red background
    { doShowPicFadeIn01, 400 },
    { doSections1, 400 },
    // works, grid of dots
    { doPlasma3, 300 },
    { doFadeLines, 200 },
    // works, two blue expanders
    { doSections2, 200 },
    // works, evolving bands
    { doPlasma1, 300 },
    // working, needs good pic
    { doShowPicFadeIn02, 400 },
    // works, wobbly line
    { doPlasma2, 300 },
    
    // ----------------------------------------- ^^^^^




    // not working, looks like didn't convert from 80x24 well
    // { doSections4, 5000 },

    //  not working, copying top line screwing up
    // { doSections3, 500 },


    // works, but are boring
    // { doNoise2, 600 },
    // { doNoise3, 6000 },

    // works, but slooowwww
    // { doWaveText1, 6000 },




    { doEnd, 64000 },


    // not working, compiled sprites are wrong?
    // { doRotators1, 500 },
};




byte curPart;
int curPartStart;

#ifdef SKIPPER 
int lastPart= -1;
#endif


void doting(void )
{
    TILE_TABLE_ADDRESS[0]= 'a';
    PIXEL_TABLE_ADDRESS[0]= 0x23;
    TILE_TABLE_ADDRESS[1]= 'b';
    PIXEL_TABLE_ADDRESS[1]= 0x23;
    TILE_TABLE_ADDRESS[2]= 'c';
    PIXEL_TABLE_ADDRESS[2]= 0x23;
}


void main(void)
{
    bool partInit = true;
    initSystem(false);
    initMisc();

    curPart = 0;
    curPartStart = 0;



    while(true) 
    {
#ifdef SINGLEPART
        effectFunc func = doTest;
        if (frame == 0)
            func(0, true);
        else
            func(frame, false);


        vBlank();

#else

     #ifdef SKIPPER 
        int tf = frame;
        int p = 0;

        while (tf > parts[p].frames)
        {
            tf -= parts[p].frames;
            p++;
        }


        effectFunc func= parts[p].func;
        bool init = false;

        if (p != lastPart)
            init = true;

        func(tf, init);

        lastPart = p;

        renderHex(64 - 14, 15, tf);


        if (isKeyDown(KEY_A))
        {
            if (frame < 50)
                frame = 0;
            else
                frame -= 50;
        }

        if (isKeyDown(KEY_D))
        {
            frame += 50;
        }

     #else
        EffectPlan ep = parts[curPart];
        dbyte partFrame = frame - curPartStart;
        ep.func(partFrame, partInit);
        partInit = false;

        if (ep.frames == partFrame)
        {
            curPart++;
            curPartStart = frame+1;
            partInit = true;
        }

        textAudioDoFrame();
     #endif

     vBlank();
#endif


#ifdef SHOWFPS
        vduPixels();
        TILE_TABLE_ADDRESS[64 * 15] = 32;
        renderHex(64-4, 15, frame);

        #ifdef __MBEE
        renderHex(64-4, 14, vBlankWaits);
        #endif


        vduColor();
        PIXEL_TABLE_ADDRESS[64 * 15] = (frame % 2 == 0) ? 0xff : 0x0;
#endif
        frame++;
    }
}
