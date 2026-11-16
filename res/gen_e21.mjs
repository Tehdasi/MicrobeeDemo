import fs from 'node:fs'


export function genE21()
{
    var offsetBytes= '';
    var bytes= '';

    var tBytes= 0;
    for( var i= 1; i<= 32; i++ )
    {
        var sz= i*2;

        var step= 64/sz;
        var pos= 0;

        for( var x= 0; x< sz; x++ )
        {
            bytes+= '0x' + Math.floor(pos).toString(16) + ',';
            pos+= step;
        }

        bytes+= '\n';

        offsetBytes+= '0x' + tBytes.toString(16) + ',';

        tBytes+= sz;
    }

    var dat= 
        '#ifndef __E21_DATA_H\n' +
        '#define __E21_DATA_H\n' +
        '\n' +
        '#include "misc.h"\n' +
        '\n' +
        'byte e21_linedata_offsets[] = {\n' +
        offsetBytes + 
        '};\n' +
        '\n' +
        'byte e21_linedata[] = {\n' +
        bytes + 
        '};\n' +
        '\n' +
        '#endif\n';

    fs.writeFileSync('..\\src\\e21data.h', dat);
}