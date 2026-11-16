import fs from 'node:fs'
import { genCompiledSpriteLineFuncDecl, genCompiledSpriteLineFuncImpl } from './gen_compsprite.mjs';
import { spinner } from './gen_rotatorsdata.mjs';


function spinner2( ang )
{

}


export function genRotatorsFuncs()
{
    var dat= `
#ifndef __ROTATORSFUNCS_H
#define __ROTATORSFUNCS_H

#include "misc.h"

typedef void (*rotatorRenderLineFunc)(dbyte offset);

extern rotatorRenderLineFunc rotatorFuncs[64];

`;


    for( var i= 0; i< 64; i++ )
    {
        dat+=  genCompiledSpriteLineFuncDecl(`renderRotatorLine${i.toString().padStart(2,'0')}`) + '\n';
    }

    dat+= '#endif';

    fs.writeFileSync('..\\src\\rotatorsfuncs.h', dat);

    dat= `#include "rotatorsfuncs.h"

rotatorRenderLineFunc rotatorFuncs[64]= {
`
    for( var i= 0; i< 64; i++ )
    {
        dat+=  `renderRotatorLine${i.toString().padStart(2,'0')},\n`;
    }

    dat+= '};\n';

    for( var i= 0; i< 64; i++ )
    {
        var [cols,tiles]= spinner( (i/64)*2*Math.PI, 4 );

        dat+= genCompiledSpriteLineFuncImpl( cols, tiles, `renderRotatorLine${i.toString().padStart(2,'0')}` );
        dat+= '\n';
    }

    fs.writeFileSync('..\\src\\rotatorsfuncs.c', dat);
}