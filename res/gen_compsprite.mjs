import fs from 'node:fs'


export function genCompiledSpriteLineFuncImpl( cols, tiles, funcName )
{
    var dat=`
void ${funcName}(dbyte offset) 
{
    offset;
#ifdef __MBEE
    __asm
    ld (_compiledSpriteScratchSp), sp
    ld (_compiledSpriteScratchOffset), hl

    ld e, l
    ld d, h
    ld hl, #0xf800
    add hl, de

    ld sp, hl
    ld hl, #0
`;
    var lastBlock= 0;
    for( var i= cols.length-2; i >= 0; i-= 2 )
    {
        var curBlock= (cols[i+1]<<8) | cols[i+0];

        if( curBlock!= lastBlock )
            dat+= `    ld hl, #0x${curBlock.toString(16).padStart('0')}\n`;
        dat+= '    push hl\n';
        lastBlock= curBlock;
    }

    dat+= `
    ld hl,(_compiledSpriteScratchOffset)
    ld e, l
    ld d, h
    ld hl, #0xf000
    add hl, de

    ld sp, hl
    ld hl, #0
`;

    lastBlock= 0;
    for( var i= tiles.length-2; i >= 0; i-= 2 )
    {
        var curBlock= (tiles[i+1]<<8) | tiles[i+0];

        if( curBlock != lastBlock )
            dat+= `    ld hl, #0x${curBlock.toString(16).padStart('0')}\n`;
        dat+= '    push hl\n';
        lastBlock= curBlock;
    }


    dat+= `ld sp, (_compiledSpriteScratchSp)
    __endasm
    `;

    dat+= `  ;
#else
    byte *pp= PIXEL_TABLE_ADDRESS + offset;
`;

    for( var i= 0; i < cols.length; i++ )
    {
        dat+= `*pp= ${cols[ cols.length-(1+i) ]};\n`;
        dat+= `pp--;\n`;
    }

    dat+= 'byte *tp= TILE_TABLE_ADDRESS + offset;';

     for( var i= 0; i < tiles.length; i++ )
    {
        dat+= `*tp= ${tiles[ tiles.length-(1+i) ]};\n`;
        dat+= `tp--;\n`;
    }

dat+= `    
#endif
}`;

    return dat;
}

export function genCompiledSpriteLineFuncDecl(funcName)
{
    return `extern void ${funcName}(dbyte offset);`;
}

export function genCompiledSpriteLine()
{
    var dat= '';
    var sd= [0x11,0x11,0x22,0x22,0x33,0x33];
    var fn= 'renderSprite';

    dat+= `
#include "compiledsprite.h"

int compiledSpriteScratchSp;
int compiledSpriteScratchOffset;
`;
    dat+= genCompiledSpriteLineFuncImpl(sd, fn );

    fs.writeFileSync('..\\src\\compiledsprite.c', dat);

    dat= `#ifndef __COMPILEDSPRITE_H
#define __COMPILEDSPRITE_H
#include "misc.h"

${ genCompiledSpriteLineFuncDecl(fn) }

#endif`;

    fs.writeFileSync('..\\src\\compiledsprite.h', dat);
}