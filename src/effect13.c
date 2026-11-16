#include "effect13.h"
#include <math.h>

#include "misc.h"

#include "staticlines.h"



int e13_initFrame= -1;

void e13_do(void)
{
    if (e13_initFrame == -1)
    {
        e13_initFrame = frame;

        initStaticLines();
    }


    vduPixels();
    int curFrame = frame - e13_initFrame;

    staticLines_intensity[0]= 8;
    staticLines_intensity[1]= 16;
    staticLines_intensity[2]= 32;
    staticLines_intensity[3]= 32;
    staticLines_intensity[4]= 64;
    staticLines_intensity[5]= 128;
    staticLines_intensity[6]= 128;
    staticLines_intensity[7]= 200;
    staticLines_intensity[8]= 255;
    staticLines_intensity[9]= 128;
    staticLines_intensity[10]= 128;
    staticLines_intensity[11]= 64;
    staticLines_intensity[12]= 32;
    staticLines_intensity[13]= 32;
    staticLines_intensity[14]= 16;
    staticLines_intensity[15]= 8;

    staticLines(curFrame);
}

