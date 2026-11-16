import fs from 'node:fs'


export function genBars()
{
    var bytes= '';
    var pointers= '';
    var bu= 0;

    for( var i= 1; i<= 32; i++ )
    {
        if( i == 1 )
        {
            bytes+= '0xff,\n';
        }
        else if( i == 2 )
        {
            bytes+= '0xff,0xff,\n';
        }
        else
        {
            var fss= i-2;

            var vb= '0xff,';
            for( var j= 0; j< fss; j++ )
            {
                var u= j/fss;
                var b= '';
                if( u < 0.25)
                    b= `ff`;
                else if( u < 0.5 || u > 0.75)
                {
                    if( j%2 == 0)
                        b= '55';
                    else
                        b= 'aa';
                }
                else
                    b= '00';

                vb+= `0x${b},`;
            }
            vb+= '0xff,';

            bytes+= vb + '\n';
        }

        pointers+= `bd_data+${bu},\n`
        bu+= i;
    }

    var dat= 
        '#ifndef __BARSDATA_H\n' +
        '#define __BARSDATA_H\n' +
        '\n' +
        '#include "misc.h"\n' +
        '\n' +
        'byte bd_data[] = {\n' +
        bytes + 
        '};\n' +
        '\n' +
        'byte* bd_ptr[] = {\n' +
        pointers + 
        '};\n' +
        '\n' +
        '#endif\n';

    fs.writeFileSync('..\\src\\barsdata.h', dat);
}