//const { createCanvas, loadImage } = require('canvas');
import { createCanvas, loadImage } from '@napi-rs/canvas'


export async function genBumpMap()
{
    // loadImage returns a Promise
    var img= await loadImage('bump.png');

    var canvas= createCanvas(img.width, img.height);
    var ctx= canvas.getContext('2d');
    ctx.drawImage(img, 0,0);
    var imgData= ctx.getImageData(0,0,img.width, img.height);
    var {data} = imgData;

//    console.log(data);

    for( var y= 0; y<img.height-1; y++ )
    {
        for( var x= 0; x<img.width-1; x++ )
        {
            
        }
    }

//    var pd= getPixels(img, { x:0, y:0, width: img.width, height: img.height });


        // const canvas = createCanvas(image.width, image.height);
        // const ctx = canvas.getContext('2d');
        
        // // Draw the loaded image onto the canvas
        // ctx.drawImage(image, 0, 0);
        // console.log('Image successfully loaded onto canvas!');
}


