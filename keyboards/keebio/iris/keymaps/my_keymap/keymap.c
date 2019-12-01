#include QMK_KEYBOARD_H
#include "keymap_french.h"

extern keymap_config_t keymap_config;

// A 'transparent' key code (that falls back to the layers below it).
#define _______ KC_TRNS

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXXXXXX KC_NO

// The most portable copy/paste keys (windows (mostly), linux, and some terminal emulators).
#define MK_CUT    LSFT(KC_DEL)  // shift + delete
#define MK_COPY   LCTL(KC_INS)  // ctrl + insert
#define MK_PASTE  LSFT(KC_INS)  // shift + insert

#define LCTL_H LCTL_T(KC_HOME)
#define LALT_E LALT_T(KC_END)
#define RALT_I RALT_T(KC_INS)

// Layers
#define _AZERTY 0
#define _NUMBERS 1
#define _FN 2
#define _ADJUST 3

uint16_t key_timer;
backlight_config_t backlight_config;

enum custom_keycodes {
    LSFT_LESS = SAFE_RANGE,
    RSFT_GRTR,
    AZERTY,
    NUMBERS,
    FN,
    ADJUST,
};

// // Tap Dance Declarations
// enum {
//     SFT_LCK = 0,
// };

// #define SFTLCK TD(SFT_LCK) // alias for tapdance

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_AZERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  FR_AMP,  FR_EACU, FR_QUOT, FR_APOS, FR_LPRN,                            FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL, FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    FR_M,    KC_ENT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      LSFT_LESS,FR_W,    KC_X,    KC_C,    KC_V,    KC_B,    NUMBERS,          _FN,     KC_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, RSFT_GRTR,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LGUI, KC_SPC,  NUMBERS,                   LALT_E,  FN,      RALT_I
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_NUMBERS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______, FR_1,    FR_2,    FR_3,    FR_4,    FR_5,                               FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    KC_PSCR,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            FR_DOT,  FR_4,    FR_5,    FR_6,    FR_DLR,  KC_DEL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,                            FR_0,    FR_1,    FR_2,    FR_3,    FR_ASTR, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,          FN,      FR_PLUS, FR_MINS, FR_SLSH, FR_EQL,  FR_PERC, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, XXXXXXX,                   _______, FN,      _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_FN] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, XXXXXXX,                            XXXXXXX, KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_F5,   NUMBERS,          XXXXXXX, KC_F11,  KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, RESET,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, NUMBERS,                   _______, XXXXXXX, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_ADJUST] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, _______,                   _______, _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AZERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_AZERTY);
            }
            return false;
            break;
        case NUMBERS:
            if (record->event.pressed) {
                layer_on(_NUMBERS);
                update_tri_layer(_NUMBERS, _FN, _ADJUST);
            } else {
                layer_off(_NUMBERS);
                update_tri_layer(_NUMBERS, _FN, _ADJUST);
            }
            return false;
            break;
        case FN:
            if (record->event.pressed) {
                layer_on(_FN);
                update_tri_layer(_NUMBERS, _FN, _ADJUST);
            } else {
                layer_off(_FN);
                update_tri_layer(_NUMBERS, _FN, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        case LSFT_LESS:
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("<"); // <
                }
            }
            return false;
            break;
        case RSFT_GRTR:
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING(">"); // >
                }
            }
            return false;
            break;
        default:
            layer_on(0);
  }
  return true;
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        clockwise ? rgblight_increase_hue() : rgblight_decrease_hue();
    } else if (index == 1) {
        clockwise ? tap_code(KC_MS_WH_UP) : tap_code(KC_MS_WH_DOWN);
    }
}

// // Shift vs. capslock function. From bbaserdem's Planck keymap.
// void caps_tap (qk_tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         register_code(LSFT_LESS);
//     } else if (state->count == 2) {
//         unregister_code(LSFT_LESS);
//         register_code(KC_CAPS);
//     }
// }
// void caps_tap_end (qk_tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         unregister_code(LSFT_LESS);
//     } else {
//         unregister_code(KC_CAPS);
//     }
// }

// // Tap dance definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     [SFT_LCK] = ACTION_TAP_DANCE_FN_ADVANCED( caps_tap, NULL, caps_tap_end ), // Tap once for Shift, twice for Caps Lock
// };

// Turn on RGB underglow according to active layer
uint32_t layer_state_set_user(uint32_t state){
    switch(biton32(state)) {
        case _AZERTY:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _NUMBERS:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _FN:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case _ADJUST:
            rgblight_sethsv_noeeprom(HSV_ORANGE);
            break;
        default:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 3);
            break;
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
    rgblight_sethsv_noeeprom_red(); // set to red
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // set to breathing
}

void suspend_power_down_user(void){
    backlight_config.enable = false; // disable LED backlight
}

void suspend_wakeup_init_user(void){
    backlight_config.enable = true; // enable LED backlight
}
