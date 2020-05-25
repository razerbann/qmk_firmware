#pragma once


#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2


#define RGB_DI_PIN          F7 // pin the DI on the WS2812B is hooked-up to
#define RGBLIGHT_ANIMATIONS    // run RGB animations
#define RGBLED_NUM          11 // number of LEDs
#define RGBLIGHT_HUE_STEP   12 // units to step when in/decreasing hue
#define RGBLIGHT_SAT_STEP   25 // units to step when in/decresing saturation
#define RGBLIGHT_VAL_STEP   12 // units to step when in/decreasing value (brightness)
