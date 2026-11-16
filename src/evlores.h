#ifndef __EVLORES_H
#define __EVLORES_H

#include "misc.h"


#define EVL_WIDTH 64
#define EVL_HEIGHT 32
#define EVL_STRIDE 16


void evl_setupTiles(void);
void evl_clear(void);

extern byte evl_chunkyBuffer[EVL_WIDTH * EVL_HEIGHT];
void evl_chunkyToScreen(void);

void evl_setPixel(byte x, byte y, byte col);
void evl_setPixelClipped(int8_t x, int8_t y, byte col);



#endif