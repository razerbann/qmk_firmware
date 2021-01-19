#include QMK_KEYBOARD_H
#include "layer_names.h"
#include "custom_keycodes.h"
#include "tap_dance.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_WIN] = LAYOUT_all(
        TG(_MAC),  KC_ESC,                  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS, KC_BSPC,     TG(_MAC)  , KC_PSLS, KC_PAST, KC_PMNS,
        PREV_TAB, NEXT_TAB,                 KC_TAB ,     KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,          KC_P7  , KC_P8  , KC_P9  , KC_PPLS,
        PREV_WINDOW_WIN, NEXT_WINDOW_WIN,   KC_LCTL,      KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT ,         KC_P4  , KC_P5  , KC_P6  , KC_PPLS,
        _______, _______,                   KC_LSFT,    KC_NUBS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_RSFT,           KC_P1  , KC_P2  , KC_P3  , KC_PENT,
        _______, _______,                   KC_LGUI,           KC_LALT,                 KC_SPC ,                                              KC_RALT,            MO(_FN),             KC_P0  , KC_P0  , KC_PDOT, KC_PENT
    ),
    [_MAC] = LAYOUT_all(
        _______, _______,                   KC_NUBS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______,
        _______, _______,                   _______,     _______,_______,EEPROM_RESET,RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        PREV_WINDOW_MAC, NEXT_WINDOW_MAC,   _______,      _______, _______, DEBUG  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______,
        OPEN_ALFRED, OPEN_ALFRED,           _______,    KC_GRV, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______,
        PREV_WORKSPACE, NEXT_WORKSPACE,     KC_LALT,           KC_LGUI,                 _______,                                              KC_RALT,            MO(_FN),             _______, _______, _______, _______
    ),
    [_FN] = LAYOUT_all(
        _______, _______,   KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 , _______, KC_DEL,      _______, _______, _______, _______,
        _______, _______,   _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______,   _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______,
        _______, _______,   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______,
        _______, _______,   _______,           _______,                   MO(_FN2),                                           _______,              _______,           _______, _______, _______, _______
    ),
    [_FN2] = LAYOUT_all(
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______,
        _______, _______,   _______,     _______,_______,EEPROM_RESET,RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______,   _______,      _______, _______, DEBUG  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______,
        _______, _______,   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______,
        _______, _______,   _______,           _______,                 _______,                                              _______,              _______,           _______, _______, _______, _______
    )
};
