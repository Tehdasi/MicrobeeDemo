import fs from 'node:fs'

export function genPlasmaTiles()
{
    var dat= `#ifndef __PLASMATILES_H
#define __PLASMATILES_H

#include "misc.h"
extern const byte plasmaTiles[64*16];

#endif`;
    fs.writeFileSync('..\\src\\plasmatiles.h', dat);

    dat= `#include "plasmatiles.h"
    
const byte plasmaTiles[64*16] = {
`;

    var a= 0;

    var bits= [];

    for( var x= 0; x< 8; x++ )
    {
        for( var y= 0; y< 16; y++ )
        {
            bits.push( { x: x, y: y } );
        }
    }

    while( bits.length > 0 )
    {

        // if( bits.length == 20 )
        // {
        //     rb= Math.floor(Math.random()*bits.length);
        //     bits.splice(rb, 1);
        // }

        var v= [
            0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
            0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        ];
        for( var b of bits )
        {
            var uv= v[b.y];
            uv= uv & ~(1<<b.x);
            v[b.y]= uv;
        }

        for( var vl of v )
        {
            dat+= `0x${vl.toString(16).padStart(2,'0')},`;
        }


        var rb= Math.floor(Math.random()*bits.length);
        bits.splice(rb, 1);

        rb= Math.floor(Math.random()*bits.length);
        bits.splice(rb, 1);

        if( bits.length== 40 || bits.length == 21 )
        {
            rb= Math.floor(Math.random()*bits.length);
            bits.splice(rb, 1);
        }

        dat+= '\n';
        a++;
    }

    for( var i= 0; i< 16; i++ )
    {
        dat+= `0xff,`;
    }


dat+= `};`;

    fs.writeFileSync('..\\src\\plasmatiles.c', dat);
}