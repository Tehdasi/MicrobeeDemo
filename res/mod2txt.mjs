// mod2txt.mjs - dump a ProTracker .mod as text: samples, the order list
// (which pattern plays at each song position), then every pattern row by row.
//
// Usage: node mod2txt.mjs song.mod [out.txt]

import fs from 'node:fs'
import path from 'node:path'
import { fileURLToPath } from 'node:url'


const NOTE_NAMES = [ 'C-', 'C#', 'D-', 'D#', 'E-', 'F-', 'F#', 'G-', 'G#', 'A-', 'A#', 'B-' ];

// Finetune-0 periods. ProTracker itself uses octaves 1-3; 0 and 4 are the
// extended range some trackers write.
const PERIODS = [
    [ 1712, 1616, 1525, 1440, 1357, 1281, 1209, 1141, 1077, 1017, 961, 907 ],
    [ 856, 808, 762, 720, 678, 640, 604, 570, 538, 508, 480, 453 ],
    [ 428, 404, 381, 360, 340, 320, 302, 285, 269, 254, 240, 226 ],
    [ 214, 202, 190, 180, 170, 160, 151, 143, 135, 127, 120, 113 ],
    [ 107, 101, 95, 90, 85, 80, 76, 71, 67, 64, 60, 57 ],
];

var inexactNotes= 0;

function noteName( period )
{
    if( period == 0 )
        return '---';

    var best= null, bestDiff= Infinity;

    for( var oct= 0; oct< PERIODS.length; oct++ )
    {
        for( var n= 0; n< 12; n++ )
        {
            var diff= Math.abs( PERIODS[oct][n] - period );

            if( diff < bestDiff )
            {
                bestDiff= diff;
                best= NOTE_NAMES[n] + oct;
            }
        }
    }

    if( bestDiff != 0 )
        inexactNotes++;

    return best;
}

function channelsFor( sig )
{
    if( [ 'M.K.', 'M!K!', 'M&K!', 'FLT4', '4CHN', 'N.T.' ].includes(sig) )
        return 4;
    if( [ 'FLT8', 'CD81', 'OKTA', 'OCTA' ].includes(sig) )
        return 8;

    var m= sig.match(/^(\d)CHN$/) || sig.match(/^(\d\d)CH$/) || sig.match(/^TDZ(\d)$/);

    return m ? parseInt(m[1]) : 0;   // 0: no signature, a 15-sample Soundtracker module
}

function text( buf, start, len )
{
    var s= '';

    for( var i= start; i< start + len && buf[i] != 0; i++ )
        s+= (buf[i] >= 32 && buf[i] < 127) ? String.fromCharCode(buf[i]) : ' ';

    return s.trimEnd();
}

function hex( v, digits )
{
    return v.toString(16).toUpperCase().padStart(digits, '0');
}

function cellText( b, o )
{
    var sample= (b[o] & 0xf0) | (b[o+2] >> 4);
    var period= ((b[o] & 0x0f) << 8) | b[o+1];
    var effect= b[o+2] & 0x0f;
    var param= b[o+3];

    return noteName(period) + ' ' +
        (sample ? hex(sample, 2) : '..') + ' ' +
        ((effect || param) ? hex(effect, 1) + hex(param, 2) : '...');
}

export function modToText( buf )
{
    var sig= buf.toString('latin1', 1080, 1084);
    var channels= channelsFor(sig);
    var numSamples= 31;

    if( channels == 0 )
    {
        channels= 4;
        numSamples= 15;
        sig= '(none - 15 samples)';
    }

    var songPos= 20 + numSamples * 30;
    var songLength= buf[songPos];
    var order= Array.from( buf.subarray(songPos + 2, songPos + 2 + 128) );
    var patternStart= songPos + 2 + 128 + (numSamples == 31 ? 4 : 0);
    var patternSize= 64 * channels * 4;
    var numPatterns= Math.max(...order) + 1;

    if( patternStart + numPatterns * patternSize > buf.length )
        throw new Error(`file too short for ${numPatterns} patterns`);

    var out= [];

    out.push( text(buf, 0, 20) );
    out.push( `signature ${sig}, ${channels} channels, ${numSamples} samples, ` +
        `${songLength} song positions, ${numPatterns} patterns` );
    out.push( 'cells are: note sample effect (C-1 = period 856); "--- .. ..." is an empty cell' );
    out.push( '' );

    out.push( 'samples' );
    out.push( ' nr  name                    length  volume  finetune  loop start  loop length' );

    for( var s= 0; s< numSamples; s++ )
    {
        var o= 20 + s * 30;
        var fine= buf[o+24] & 0x0f;

        out.push( ' ' + hex(s + 1, 2) + '  ' +
            text(buf, o, 22).padEnd(22) + '  ' +
            String(buf.readUInt16BE(o+22) * 2).padStart(6) + '  ' +
            String(buf[o+25]).padStart(6) + '  ' +
            String(fine > 7 ? fine - 16 : fine).padStart(8) + '  ' +
            String(buf.readUInt16BE(o+26) * 2).padStart(10) + '  ' +
            String(buf.readUInt16BE(o+28) * 2).padStart(11) );
    }
    out.push( '' );

    out.push( 'order (song position: pattern)' );
    for( var p= 0; p< songLength; p+= 16 )
    {
        out.push( order.slice(p, Math.min(p + 16, songLength))
            .map( (pat, i)=> hex(p + i, 2) + ':' + hex(pat, 2) ).join('  ') );
    }
    out.push( '' );

    var header= 'row';
    for( var c= 0; c< channels; c++ )
        header+= ' | ' + `channel ${c + 1}`.padEnd(10);
    header= header.trimEnd();

    for( var pat= 0; pat< numPatterns; pat++ )
    {
        var used= order.slice(0, songLength).includes(pat);

        out.push( `pattern ${hex(pat, 2)}` + (used ? '' : '  (not in the song)') );
        out.push( header );

        for( var row= 0; row< 64; row++ )
        {
            var line= ' ' + hex(row, 2);

            for( var c= 0; c< channels; c++ )
                line+= ' | ' + cellText( buf, patternStart + pat * patternSize + (row * channels + c) * 4 );

            out.push( line );
        }
        out.push( '' );
    }

    return out.join('\r\n');
}

// run from the command line (rather than imported)
if( process.argv[1] && path.resolve(process.argv[1]) == fileURLToPath(import.meta.url) )
{
    var inFile= process.argv[2];

    if( !inFile )
    {
        console.log('usage: node mod2txt.mjs song.mod [out.txt]');
        process.exit(1);
    }

    var outFile= process.argv[3] || path.basename(inFile).replace(/\.[^.]*$/, '') + '.txt';

    fs.writeFileSync( outFile, modToText( fs.readFileSync(inFile) ) );
    console.log(`${outFile} written` + (inexactNotes ? `, ${inexactNotes} notes not on the period table` : ''));
}
