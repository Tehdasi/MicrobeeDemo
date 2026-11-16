#ifndef __COLOURRIBBONS_H
#define __COLOURRIBBONS_H

#include "misc.h"

typedef struct {
    byte start;
    byte length;
    byte colour;
} ColourRibbon;

extern ColourRibbon colourRibbons[10];

void colourRibbonInit(void);
void colourRibbonRender(byte numRibbons);

#endif
