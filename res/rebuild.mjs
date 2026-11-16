import { genBars } from './bars.mjs';
import { genBumpMap } from './gen_bump.mjs';
import { genE12Text } from './gen_e12_text.mjs';
import { genE21 } from './gen_e21.mjs';
import { genColourFade } from './gen_colourfade.mjs';
import { genRotatorsData } from './gen_rotatorsdata.mjs';
import { genCompiledSpriteLine } from './gen_compsprite.mjs';
import { genRotatorsFuncs } from './gen_rotatorsfuncs.mjs';
import { genBarsLogo } from './gen_barslogo.mjs';
import { genSkidrowSteps } from './gen_skidrow.mjs';
import { genPlasmaTiles } from './gen_plasmatiles.mjs';
import { genAudioText } from './gen_audiotext.mjs';

genBumpMap();
genE12Text();
genE21();
genColourFade();
genCompiledSpriteLine();
genRotatorsFuncs();
genBarsLogo();
genSkidrowSteps();
genPlasmaTiles();
genAudioText();

console.log('done!');