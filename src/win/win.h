#ifndef __WIN_H
#define __WIN_H

#include <raylib.h>
#include <stdbool.h>

extern byte* TILE_TABLE_ADDRESS;
extern byte* PIXEL_TABLE_ADDRESS;


void initSystem(bool col80);

void vBlank();

void vduColor(void);
void vduPixels(void);

int sampleClock(void);

bool isKeyDown(uint8_t key);


void makeSound(void);

#endif

