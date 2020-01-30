#include QMK_KEYBOARD_H
#include "keymap_french.h"

extern keymap_config_t keymap_config;

// A 'transparent' key code (that falls back to the layers below it).
#define _______   KC_TRNS
// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXXXXXX   KC_NO
// Useful portable shortcuts
// The most portable copy/paste keys
#define COPY      LCTL(KC_INS)
#define CUT       LSFT(KC_DEL)
#define PASTE     LSFT(KC_INS)

/////////////////////////////
// TAP DANCE CONFIGURATION //
/////////////////////////////
#ifdef TAP_DANCE_ENABLE
// Tap Dance Declarations
enum {
    _TD = 0,
};

typedef struct {
  bool is_press_action;
  int  state;
} tap;

enum {
  SINGLE_TAP        = 1,
  SINGLE_HOLD       = 2,
  DOUBLE_TAP        = 3,
  DOUBLE_HOLD       = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP        = 6,
  TRIPLE_HOLD       = 7,
  UNKNOWN_TAP       = 8,
};

// Return an integer that corresponds to what kind of tap dance should be executed.
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    // key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  // Assumes no one is trying to type the same letter three times (at least not quickly).
  // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed) return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return UNKNOWN_TAP; // At some point this method will expand to work for more presses
}
#endif

//////////////////////////
// LAYOUT CONFIGURATION //
//////////////////////////
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _AZERTY  0
#define _FN      1
#define TO_FN    MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AZERTY] = LAYOUT_65_with_macro(
    // ┌────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┬────────┐
        XXXXXXX ,XXXXXXX ,   KC_ESC  ,FR_AMP  ,FR_EACU ,FR_QUOT ,FR_APOS ,FR_LPRN ,FR_MINS ,         FR_EGRV ,FR_UNDS ,FR_CCED ,FR_AGRV ,FR_RPRN ,KC_EQL  ,XXXXXXX ,KC_BSPC ,KC_HOME , \
    // ├────────┼────────┤  ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬────────────┼────────┤
        XXXXXXX ,XXXXXXX ,   KC_TAB       ,FR_A    ,FR_Z    ,KC_E    ,KC_R    ,KC_T    ,         KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,FR_CIRC ,FR_DLR  ,KC_ENT      ,KC_END  , \
    // ├────────┼────────┤  ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
        FR_LESS ,FR_GRTR ,   KC_CAPS        ,FR_Q    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,         KC_H    ,KC_J    ,KC_K    ,KC_L    ,FR_M    ,FR_UGRV ,FR_ASTR            ,KC_PGUP , \
    // ├────────┼────────┤  ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴──────────┬────────┼────────┤
        COPY    , PASTE  ,   KC_LSFT              ,FR_W    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,         KC_N    ,FR_COMM ,FR_SCLN ,FR_COLN ,FR_EXLM ,KC_RSFT      ,KC_UP   ,KC_PGDN , \
    // ├────────┼────────┤  ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┬────────┼────────┤
        CUT     ,CUT     ,   KC_LCTL   ,KC_LALT    ,KC_LGUI   ,TO_FN      ,KC_SPC              ,         KC_SPC, XXXXXXX       ,KC_RALT ,KC_RGUI , KC_RCTL,KC_LEFT ,KC_DOWN ,KC_RGHT
    // └────────┴────────┘  └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └──────────────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT_65_with_macro(
    // ┌────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┬────────┐
        _______ ,_______ ,   _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,         KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_EQL  ,_______ ,KC_DEL  ,_______ , \
    // ├────────┼────────┤  ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬────────────┼────────┤
        _______ ,_______ ,   RGB_TOG      ,RGB_MOD ,_______ ,KC_UP   ,_______ ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______     ,_______,  \
    // ├────────┼────────┤  ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
        _______ ,_______ ,   _______        ,_______, KC_LEFT ,KC_DOWN ,KC_RGHT ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______            ,_______ , \
    // ├────────┼────────┤  ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴──────────┬────────┼────────┤
        _______ ,_______ ,   _______              ,_______ ,_______ ,_______ ,_______ ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______      ,_______ ,_______ , \
    // ├────────┼────────┤  ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┬────────┼────────┤
        _______ ,_______ ,   _______   ,_______    ,_______   ,_______    ,_______             ,         _______, _______      ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
    // └────────┴────────┘  └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └──────────────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  )
};

#ifdef RGBLIGHT_ENABLE
// Turn on RGB underglow according to active layer
uint32_t layer_state_set_user(uint32_t state){
  switch(biton32(state)) {
    case _AZERTY: rgblight_sethsv_noeeprom(HSV_BLUE); break;
    case _FN: rgblight_sethsv_noeeprom(HSV_CORAL); break;
    default: rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 3); break;
  }
  return state;
}

void keyboard_pre_init_user(void) {
  // Make sure the red LEDs don't light
  setPinOutput(D5);
  writePinHigh(D5);
  setPinOutput(B0);
  writePinHigh(B0);
}

void keyboard_post_init_user(void){
  rgblight_enable_noeeprom(); // enable the RGBs
  rgblight_sethsv_noeeprom(HSV_BLUE); // set to red
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // set to breathing
}
#endif  // RGBLIGHT_ENABLE
