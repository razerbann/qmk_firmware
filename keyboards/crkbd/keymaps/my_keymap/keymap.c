#include QMK_KEYBOARD_H
#include "keymap_french.h"

#ifdef SSD1306OLED
extern uint8_t is_master;
#endif // SSD1306OLED

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif // RGBLIGHT_ENABLE

// A 'transparent' key code (that falls back to the layers below it).
#define _______ KC_TRNS

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXXXXXX KC_NO

// Useful portable shortcuts
// The most portable copy/paste keys
#define MK_COPY   LCTL(KC_INS)  // ctrl + insert
#define MK_CUT    LSFT(KC_DEL)  // shift + delete
#define MK_PASTE  LSFT(KC_INS)  // shift + insert
// CTRL
#define MK_CTL_A LCTL(FR_A) // Begin of line terminal
#define MK_CTL_E LCTL(KC_E) // End of line terminal
#define MK_CTL_F LCTL(KC_F)
#define MK_CTL_N LCTL(KC_N)
#define MK_CTL_P LCTL(KC_P)
#define MK_CTL_R LCTL(KC_R)
#define MK_CTL_S LCTL(KC_S)
#define MK_CTL_T LCTL(KC_T)
#define MK_CTL_Z LCTL(FR_Z)
// CTRL + SHIFT
#define MK_CTLSFT_N LCTL(LSFT(KC_N))
#define MK_CTLSFT_T LCTL(LSFT(KC_T))
#define MK_CTLSFT_Z LCTL(LSFT(KC_Z))

// <, >, (, {, [, ], } and ) codes
#define X__LESS    SS_TAP(X_NONUS_BSLASH) // <
#define X__GRTR    SS_LSFT(SS_TAP(X_NONUS_BSLASH)) // >
#define X__LPRN   "5" // (
#define X__RPRN   "-" // )
#define X__LCBR   SS_ALGR("4") // {
#define X__RCBR   SS_ALGR("=") // }
#define X__LBRC   SS_ALGR("5") // [
#define X__RBRC   SS_ALGR("-") // ]

///////////////////////////
// TAP DANCE CONFIGURATION
///////////////////////////
// Tap Dance Declarations
enum {
    LSFT_LESS_TD    = 0,
    RSFT_GRTR_TD,
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
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
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
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return UNKNOWN_TAP; // At some point this method will expand to work for more presses
}

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [LSFT_LESS_TD]    = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, FR_LESS), // Tap once for Shift, twice for less
    [RSFT_GRTR_TD]    = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, FR_GRTR), // Tap once for Shift, twice for greater
};

// Aliases for tapdance
#define LSFT_LESS    TD(LSFT_LESS_TD)
#define RSFT_GRTR    TD(RSFT_GRTR_TD)

///////////////////////////
//  LAYOUT CONFIGURATION
///////////////////////////

// Layers
#define _AZERTY  0
#define _NUMBERS 1
#define _FN      2

enum custom_keycodes {
    RGBRST  = SAFE_RANGE,
};

// hold/tap keys
#define LCTL_H   LCTL_T(KC_HOME)
#define LALT_E   LALT_T(KC_END)
#define RALT_I   RALT_T(KC_INS)
#define LGUI_SPC LGUI_T(KC_SPC)
#define NUM_SPC  LT(_NUMBERS, KC_SPC)
#define FN_DEL   LT(_FN, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AZERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LCTL_H,    FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    FR_M,  KC_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LSFT_LESS,    FR_W,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N, FR_COMM, FR_SCLN, FR_COLN, FR_EXLM,RSFT_GRTR,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         LGUI_SPC,  KC_SPC, NUM_SPC,     LALT_E,  FN_DEL,  RALT_I \
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUMBERS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    FR_1,    FR_2,    FR_3,    FR_4,    FR_5,                         FR_6,    FR_7,    FR_8,    FR_9,    FR_0,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME,   KC_UP,  KC_END, RGB_TOG,  FR_DLR,                      FR_PLUS,    FR_4,    FR_5,    FR_6, FR_PERC, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, FR_ASTR,                         FR_0,    FR_1,    FR_2,    FR_3,  FR_EQL, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, XXXXXXX,    _______, XXXXXXX, _______ \
                                      //`--------------------------'  `--------------------------'
    ),

  [_FN] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,  RGBRST,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, XXXXXXX,    _______, XXXXXXX, _______ \
                                      //`--------------------------'  `--------------------------'
  ),
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif // RGBLIGHT_ENABLE

    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  #ifdef SSD1306OLED
    iota_gfx_init(!has_usb());   // turns on the display
  #endif // SSD1306OLED
}

#ifdef SSD1306OLED // SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif //SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef SSD1306OLED
      set_keylog(keycode, record);
    #endif // SSD1306OLED
  }

  switch (keycode) {
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif // RGBLIGHT_ENABLE
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif // RGBLIGHT_ENABLE
      break;
  }
  return true;
}
