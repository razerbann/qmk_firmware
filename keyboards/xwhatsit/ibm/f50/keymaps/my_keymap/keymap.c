#include QMK_KEYBOARD_H
#include "layer_names.h"
#include "custom_keycodes.h"
#include "tap_dance.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,   KC_PSLS, KC_PAST,    KC_MINS, KC_EQL,   KC_DEL,     KC_PSCR, KC_COMM, KC_DOT,  KC_BSPC,
        KC_Q,     KC_W,    KC_E,       KC_R,    KC_T,     KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,     KC_S,    KC_D,       KC_F,    KC_G,     KC_H,       KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT,  KC_Z,    KC_X,       KC_C,    KC_V,     KC_B,       KC_N,    KC_M,    KC_SCLN, KC_NUHS,
        KC_LCTRL, MO(_FN), KC_LALT,    KC_TAB,  KC_QUOT,  KC_SPC,     KC_BSLS, KC_COMM, KC_DOT,  KC_SLSH
    ),
    [_FN] = LAYOUT(
        _______,  _______, _______,    _______, _______,  _______,    _______, _______, _______, _______,
        _______,  _______, _______,    _______, _______,  _______,    _______, _______, _______, _______,
        _______,  _______, _______,    _______, _______,  _______,    _______, _______, _______, _______,
        _______,  _______, _______,    _______, _______,  _______,    _______, _______, _______, _______,
        _______,  _______, _______,    _______, _______,  MO(_FN2),   _______, _______, _______, _______
    ),
    [_FN2] = LAYOUT(
        _______,  _______, _______,    _______, _______,  _______,    _______, _______, _______, _______,
        _______,  _______, EEPROM_RESET, RESET, _______,  _______,    _______, _______, _______, _______,
        _______,  _______, DEBUG,      _______, _______,  _______,    _______, _______, _______, _______,
        _______,  _______, _______,    _______, _______,  _______,    _______, _______, _______, _______,
        _______,  _______, _______,    _______, _______,  _______,    _______, _______, _______, _______
    )
};
