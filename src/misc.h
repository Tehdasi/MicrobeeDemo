#ifndef __MISC_H
#define __MISC_H

#include <stdint.h>
#include <stdbool.h>

#define byte uint8_t
#define dbyte uint16_t

#ifdef __MBEE
#include "mbee/mbee.h"
#else
#include "win\win.h"
#endif





#define SCREEN_X 64
#define SCREEN_Y 64

extern dbyte frame;


#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

extern const byte colorInten[15];



inline byte zigzag_sharp(byte v, byte max) 
{
	max -= 1;
	int a = (v / max)%2;
	int b = v % max;

	if (a == 0)
		return max - b;
	else
		return b;
}

inline byte zigzag_blunt(byte v, byte max)
{
	int a = (v / max) % 2;
	int b = v % max;

	if (a == 0)
		return (max - b) - 1;
	else
		return b;
}


void clearTiles(void);
void clearColors(void);


void render_colorSprite_fullHeight(byte* spriteData, byte spriteWidth, byte x);



void renderHex( byte x, byte y, dbyte num );

void initMisc(void);


extern byte* scratch[256];

extern byte alignedData[256 + 256 + 256 + 256 + 16];
extern byte* sine;
extern byte* rnd;
extern byte* aligned256Area;
extern byte* e13_fuzz;




extern const byte tunnel6416[32 * 8 * 2];

extern const byte tunnel[32*32*2];

#endif