#ifndef __SECTIONS_H
#define __SECTIONS_H

#include "misc.h"

typedef struct 
{
    byte color;
    byte length;
} Section;

#define SECTIONS_MAX 80

extern Section sections_data[SECTIONS_MAX];

void sectionsInit(void);
void hsectionsInit(void);




void sectionsRenderFull( byte y );
void sectionsRenderHalf( byte y );
void sectionsApplyAll(void);

void hsectionsRenderFull( byte x );
void hsectionsRenderHalf( byte x );
void hsectionsApplyAll(void);



#endif