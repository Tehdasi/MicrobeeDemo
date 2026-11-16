#ifndef __MBEE_H
#define __MBEE_H

#include <stdint.h>
#include <stdbool.h>

#define TILE_TABLE_ADDRESS ((uint8_t*)0xF000)
#define PIXEL_TABLE_ADDRESS ((uint8_t*)0xF800)



void initSystem(bool cols80);

extern int vBlankWaits;
void vBlank(void);
// void render( byte *  screen );

void playAudio(void);

void vduColor(void);
void vduPixels(void);

int sampleClock(void);


bool isKeyDown(uint8_t key);

void playSound(uint8_t* soundData, int samples);


#endif
