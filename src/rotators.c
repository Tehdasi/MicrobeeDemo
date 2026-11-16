#include "rotators.h"

#include "rotatorsfuncs.h"

byte rotatorPositions[80];




void renderRotators(void)
{
    vduColor();

   

#ifdef __MBEE
    for (byte y = 0; y < 15; y++)
    {
        rotatorFuncs[rotatorPositions[y]]( y*64 );
    }


#else
    for (byte y = 0; y < 15; y++)
    {
        rotatorFuncs[rotatorPositions[y]]( y*64 + 56 );
    }
#endif
}