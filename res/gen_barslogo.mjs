import fs from 'node:fs'
import { createCanvas, loadImage } from '@napi-rs/canvas'


// apiary.png -> apiaryLogoData: the image cut into stripes 8 pixels wide,
// left to right. Each stripe is one byte per row, top to bottom, with the
// leftmost pixel in bit 7 (white = 1, black = 0) - the same layout as PCG
// characters, so a stripe can be copied straight into PCG RAM.

function isWhite( data, i )
{
    return data[i+3] >= 128 && (data[i] + data[i+1] + data[i+2]) / 3 >= 128;
}

export async function genBarsLogo()
{
    var img= await loadImage('logo2.png');

    var canvas= createCanvas(img.width, img.height);
    var ctx= canvas.getContext('2d');
    ctx.drawImage(img, 0, 0);
    var {data}= ctx.getImageData(0, 0, img.width, img.height);

    var stripes= Math.ceil(img.width / 8);
    var bytes= [];

    for( var s= 0; s< stripes; s++ )
    {
        for( var y= 0; y< img.height; y++ )
        {
            var b= 0;

            for( var bit= 0; bit< 8; bit++ )
            {
                var x= s*8 + bit;

                b<<= 1;
                if( x < img.width && isWhite(data, (y*img.width + x)*4) )
                    b|= 1;
            }

            bytes.push(b);
        }
    }

    var dat= '';
    dat+= '#ifndef __BARSLOGO_H\n';
    dat+= '#define __BARSLOGO_H\n';

    dat+= '\n#include "misc.h"\n\n';
    dat+= `#define APIARY_LOGO_WIDTH ${img.width}\n`;
    dat+= `#define APIARY_LOGO_HEIGHT ${img.height}\n`;
    dat+= `#define APIARY_LOGO_STRIPES ${stripes}\n\n`;
    dat+= `extern const byte apiaryLogoData[${bytes.length}];\n`;

    dat+= '#endif\n';

    fs.writeFileSync('..\\src\\barslogo.h', dat);

    dat= '#include "barslogo.h"\n\n';
    dat+= `const byte apiaryLogoData[${bytes.length}]= {\n`;

    for( var s= 0; s< stripes; s++ )
    {
        dat+= `// stripe ${s}: x ${s*8}-${s*8 + 7}\n`;

        for( var y= 0; y< img.height; y+= 16 )
        {
            var row= bytes.slice( s*img.height + y, s*img.height + Math.min(y + 16, img.height) );

            dat+= row.map( (v)=> `0x${v.toString(16).padStart(2, '0')}, ` ).join('') + '\n';
        }
    }

    dat+= '};\n';

    fs.writeFileSync('..\\src\\barslogo.c', dat);
}
