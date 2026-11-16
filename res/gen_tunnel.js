var ou= "";
var i= 0;
var maxD= Math.sqrt(32*32 + 32*32);

for( var y= 31; y>= 0; y-- )
{
    for( var x= 31; x>= 0; x-- )
    {
        if( i%16 == 0)
            ou+= "<br>";

        var pi= 3.14159265359;
        var d= Math.floor(255*Math.sqrt(x*x + y*y)/maxD);

        var ang= Math.floor((Math.atan2(y, x)*255)/(2*pi));


        ou+=`0x${d.toString(16).padStart(2, '0')},0x${ang.toString(16).padStart(2, '0')}, `;
        i++;
    }
}
log(ou);