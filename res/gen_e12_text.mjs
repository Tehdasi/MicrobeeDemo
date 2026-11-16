import fs from 'node:fs'


var text= [
    [
        "lorem",
        "ipsum"
    ],

    [
        "yada",
        "yoyo"
    ]
];

function dumpLine( txt )
{
    var dat= '';

    var ll= txt.length;
    var pre=  Math.floor((60-ll)/2);
    var post= 60 - (ll + pre);

    for( var i= 0; i< pre; i++ )
        dat+= '0x32,';

    for( var i= 0; i< txt.length; i++ )
    {
        var c= txt.codePointAt(i);

        dat+= `0x${c.toString(16)},`;
    }

    for( var i= 0; i< post; i++ )
        dat+= '0x32,';

    dat+= "\n";

    return dat;
}

export async function genE12Text()
{
    var dat= '';
    dat+= '#ifndef __E12_TEXT_H\n';
    dat+= '#define __E12_TEXT_H\n';

    dat+= '\n#include "misc.h"\n\n';
    dat+= 'const byte e12_text[]= {\n';
    for( var pg of text)
    {
        dat+= '\n';
        
        var pgl= pg.length;
        var prePage=  Math.floor((10-pgl)/2);
        var postPage= 10 - (pgl + prePage);

        for( var i = 0; i< prePage; i++ )
        {
            dat+= dumpLine('');
        }

        for( var ln of pg )
        {
            dat+= dumpLine(ln);
        }

        for( var i = 0; i< postPage; i++ )
        {
            dat+= dumpLine('');
        }


    }
    dat+= '};\n';

    dat+= '#endif\n';

    fs.writeFileSync('..\\src\\e12_text.h', dat);
}