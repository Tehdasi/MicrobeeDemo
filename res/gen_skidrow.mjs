import fs from 'node:fs'




export async function genSkidrowSteps()
{
    var dat= `#ifndef __SKIDROWSTEPS_H
#define __SKIDROWSTEPS_H
#include "misc.h"

const extern dbyte skidrowSteps[100];

#endif`;

    fs.writeFileSync('..\\src\\skidrowsteps.h', dat);


    dat= `#include "skidrowsteps.h"
    
const dbyte skidrowSteps[100] = {
`;

    var steps= [];

    for( var y= 0; y< 5; y++ )
    {
        for( var x= 0; x< 5; x++ )
        {
            var a= Math.atan2( y,x);

            steps.push({a: a, x: x, y: y});
        }
    }

    steps.sort( (a,b)=> a.a-b.a );

    var allSteps= [];

    // bl
    for( var i= 0; i< steps.length; i++ )
    {
        var pg= steps[i];
        var x= pg.x, y= pg.y;
        var ux= 32 + x*5, uy= y+8;

        var addr= 0xf800 + ux + (uy*64);
        allSteps.push(addr);
    }

    // br
    for( var i= 0; i< steps.length; i++ )
    {
        var pg= steps[steps.length-1-i];
        var x= pg.x, y= pg.y;
        var ux= 32 - (5+ x*5), uy= y+8;

        var addr= 0xf800 + ux + (uy*64);
        allSteps.push(addr);
    }

    // tl
    for( var i= 0; i< steps.length; i++ )
    {
        var pg= steps[i];
        var x= pg.x, y= pg.y;
        var ux= 32 - (5+ x*5), uy= 7-y;

        var addr= 0xf800 + ux + (uy*64);
        allSteps.push(addr);
    }

    // tr
    for( var i= 0; i< steps.length; i++ )
    {
        var pg= steps[steps.length-1-i];
        var x= pg.x, y= pg.y;
        var ux= 32 + x*5, uy= 7-y;

        var addr= 0xf800 + ux + (uy*64);
        allSteps.push(addr);
    }

    for( var v of allSteps.slice(12) )
        dat+= `0x${v.toString(16).padStart(4, '0')}, `;

    for( var v of allSteps.slice(0,12) )
        dat+= `0x${v.toString(16).padStart(4, '0')}, `;

    
    dat+= '};\n';

    fs.writeFileSync('..\\src\\skidrowsteps.c', dat);
}