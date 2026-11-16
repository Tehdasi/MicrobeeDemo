import fs from 'node:fs'



export function genAudioText()
{
    var dat= `#ifndef __TEXTAUDIODATA_H
#define __TEXTAUDIODATA_H

#include "misc.h"
extern const byte textAudioData[];

#endif`;

    fs.writeFileSync('..\\src\\textaudiodata.h', dat);

    var txt= fs.readFileSync('song.txt', 'utf8');

    var lns= txt.split('\r\n');



    dat= `#include "textaudiodata.h"
    
const byte textAudioData[]= {`;

    var ttt= (nt) => {
        var samp= nt.slice(4,6);

        if( samp== '..')
            samp= 0;
        else
            samp= parseInt( samp, 16 );

        dat+= `0x${samp.toString(16).padStart(2, '0')}, `;

    };

    for( var i= 0; i< lns.length; i++ )
    {
        var ln= lns[i];

        if( ln.length == 55 )
        {
            ttt( ln.slice(6,16) );
            ttt( ln.slice(19,29));
            ttt( ln.slice(32,42));
            ttt( ln.slice(45,55));

            dat+= '\n';
        }
    }

/*



    for( var i= 0; i< lns.length; i++ )
    {
        var ln= lns[i];
        var b= ln.split(',');

        if( b[0] == 'p' )
        {

        }
        
    }
*/
    dat+= '};';

    fs.writeFileSync('..\\src\\textaudiodata.c', dat);

}