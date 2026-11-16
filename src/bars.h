#ifndef __BARS_H
#define __BARS_H

#include "misc.h"



typedef struct {
    byte y;
    byte z;
    byte bright;
} BarDesc; 

extern BarDesc barsData[20];


void initBars(void);

void renderBars(void);


#endif