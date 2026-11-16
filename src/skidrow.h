#ifndef __SKIDROW_H
#define __SKIDROW_H

#include "misc.h"

#define SKIDROW_MAXSTEPS 25*2

void skidrowInit(void);
void skidrowSetText(byte* tp);

void skidrowChangeText(byte pos, byte on);

void skidrowRender(void);

#endif
