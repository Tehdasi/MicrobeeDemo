import fs from 'node:fs'


const width= 50;
const halfWidth= width/2;
const tilesStart= 150;

export function spinner( angle, numFaces )
{
    var verts= [];
    var faces= [];



    for( var i= 0; i< numFaces; i++ )
    {
        var a= ((i/numFaces)*Math.PI*2.0) + angle;
        verts.push( {x: Math.sin(a),y: Math.cos(a) } );
    }

    for( var i= 0; i< numFaces; i++ )
    {
        var n= (((i+0.5)/numFaces)*Math.PI*2.0) + angle;

        if( Math.cos(n) >= 0 )
        {
            var sn= Math.abs(Math.sin(n));
            var s= Math.floor(sn*64);

            faces.push( { start: (verts[i].x)*halfWidth + halfWidth, end: (verts[(i+1)%numFaces].x)*halfWidth + halfWidth, shade: s + 150, color: i+1 } );
        }
    }

    var al= (((i+0.5)/numFaces)*Math.PI*2.0) + angle;

    // verts= verts.filter( v=> v.y >= 0 );
    //   verts= verts.sort( (a,b) =>  );

    var colours= [];
    var tiles= [];
    for( var i= 0; i< width; i++ )
    {
        colours.push(0);
        tiles.push(0);
    }

    for( var f of faces )
    {
        for( var x= Math.floor(f.start+0.5); x< Math.floor(f.end+0.5); x++  )
        {
            colours[ x ]= f.color;
            tiles[ x ]= f.shade;
        }
    }
    
    return [colours,tiles];
}

export async function genRotatorsData()
{
    var dat= '';
    dat+= '#ifndef __ROTATORSDATA_H\n';
    dat+= '#define __ROTATORSDATA_H\n';

    dat+= '\n#include "misc.h"\n\n';
    dat+= `const extern byte rotatorsData[${48*64}];\n`;


    dat+= '#endif\n';

    fs.writeFileSync('..\\src\\rotatorsdata.h', dat);

    dat= '#include "rotatorsdata.h"\n';
    dat+= '\n';

    dat+= 'byte rotatorsData[]= {\n';

    for( var i= 0; i< 64; i++ )
    {
        var [cols,tiles]= spinner( (i/64)*2*Math.PI, 4 );

        for( var t of tiles )
            dat+= `0x${(t+tilesStart).toString(16).padStart(2,'0')},`;
        dat+= '\n';

        for( var c of cols )
            dat+= `0x${c.toString(16).padStart(2,'0')},`;

        dat+= '\n';
        dat+= '\n';
    }
    dat+= '};\n';

    fs.writeFileSync('..\\src\\rotatorsdata.c', dat);
}


