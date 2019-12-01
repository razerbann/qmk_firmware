/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_I2C
#define EE_HANDS

#undef RGBLED_NUM
#define RGBLED_NUM 8
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#undef RGBLED_SPLIT
#define RGBLED_SPLIT { RGBLED_NUM, 0} // defined to sync animations

#define FORCE_NKRO // force NKRO on by default

#undef TAPPING_TERM
#define TAPPING_TERM 200

#define NO_MUSIC_MODE
// Because the Macro and Function features are incompatible with Link Time Optimization, disable those features
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
