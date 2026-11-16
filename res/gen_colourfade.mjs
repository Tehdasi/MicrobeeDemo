import fs from 'node:fs'


var colorInten = [ 0, 4, 12, 1, 8, 5, 9, 13, 2, 6, 3, 10, 14, 11, 7 ];

function rc( oc, lv )
{
    var c= oc;

    var cp= colorInten.findIndex( (v)=> v == oc );

    if( oc == 15 )
        cp = 14;

    return colorInten[ Math.max( cp-lv, 0 ) ];
}

export async function genColourFade()
{
    var dat= '';
    dat+= '#ifndef __COLOURFADE_H\n';
    dat+= '#define __COLOURFADE_H\n';

    dat+= '\n#include "misc.h"\n\n';
    dat+= 'extern const byte colourFade[16*16];\n';

    dat+= '#endif\n';

    fs.writeFileSync('..\\src\\colourfade.h', dat);

    dat= '#include "colourfade.h"\n\n';
    dat+= 'const byte colourFade[16*16]= {\n';

    for( var y= 0; y< 16; y++ )
    {
        for( var x= 0; x< 16; x++ )
        {
            dat+= `0x${rc( x, y ).toString(16)}, `;
        }

        dat+= '\n';
    }

    dat+= '};\n';

    fs.writeFileSync('..\\src\\colourfade.c', dat);
}