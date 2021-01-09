#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _WIN,
    _MAC,
    _FN,
    _FN2
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    PREV_TAB = SAFE_RANGE,
    NEXT_TAB,
    OPEN_ALFRED,
    PREV_WORKSPACE,
    NEXT_WORKSPACE,
    PREV_WINDOW_WIN,
    NEXT_WINDOW_WIN,
    PREV_WINDOW_MAC,
    NEXT_WINDOW_MAC
};

bool is_alt_tab_active = false;
bool is_cmd_tab_active = false;
uint16_t alt_tab_timer = 0;
uint16_t cmd_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT_122key(
                                          KC_ESC , KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MRWD, KC_MFFD, KC_MSTP, KC_BRID, KC_BRIU, KC_F11,  KC_PSCR,
                                          KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,

        KC_ESC,  KC_ESC,                  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,         KC_BSPC,    KC_INS , KC_HOME, KC_PGUP,    TG(_MAC),KC_PSLS, KC_PAST, KC_PMNS,
        PREV_TAB, NEXT_TAB,                 KC_TAB ,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_ENT ,      KC_DEL , KC_END , KC_PGDN,    KC_P7  , KC_P8  , KC_P9  , KC_PPLS,
        PREV_WINDOW_WIN, NEXT_WINDOW_WIN,   KC_LCTRL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,                         KC_UP  ,             KC_P4  , KC_P5  , KC_P6  , KC_PPLS,
        _______, _______,                  KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH,         KC_RSFT,         KC_LEFT, KC_DOWN, KC_RGHT,    KC_P1  , KC_P2  , KC_P3  , KC_PENT,
        _______, _______,                   KC_LGUI,         KC_LALT,                     KC_SPC ,                                           KC_RALT,         MO(_FN),                      KC_DOWN,                      KC_P0  , KC_PDOT
    ),
    [_MAC] = LAYOUT_122key(
                                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______,                 KC_NUBS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,    _______, _______, _______,    _______, _______, _______, _______,
        _______, _______,                   _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,      _______, _______, _______,    _______, _______, _______, _______,
        PREV_WINDOW_MAC, NEXT_WINDOW_MAC,   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                         _______,             _______, _______, _______, _______,
        OPEN_ALFRED, OPEN_ALFRED,          _______, KC_GRV, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,          _______, _______, _______,    _______, _______, _______, _______,
        PREV_WORKSPACE, NEXT_WORKSPACE,     KC_LALT,          KC_LGUI,                     _______,                                           KC_RALT,         MO(_FN),                     _______,                      _______, _______
    ),
    [_FN] = LAYOUT_122key(
                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,    _______, _______, _______,    _______, _______, _______, _______,
        _______, _______,    _______,   _______,_______,_______,_______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,         _______, _______, _______,    _______, _______, _______, _______,
        _______, _______,    _______,    _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______, _______,                        _______,             _______, _______, _______, _______,
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,         _______, _______, _______,    _______, _______, _______, _______,
        _______, _______,    _______,          _______,                     MO(_FN2),                                         _______,         _______,                       _______,                      _______, _______
    ),
    [_FN2] = LAYOUT_122key(
                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,    _______, _______, _______,    _______, _______, _______, _______,
        _______, _______,    _______,   _______,_______,EEPROM_RESET,RESET, _______, _______, _______, _______, _______, _______, _______, _______,   _______,      _______, _______, _______,    _______, _______, _______, _______,
        _______, _______,    _______,    _______, HPT_TOG, DEBUG  , _______, _______, _______, _______, _______, _______, _______, _______, _______,                         HPT_DWLI,            _______, _______, _______, _______,
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,         HPT_BUZ, HPT_DWLD, HPT_RST,   _______, _______, _______, _______,
        _______, _______,    _______,          _______,                     _______,                                           _______,         _______,                     HPT_DWLD,                     _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PREV_TAB:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_LCTRL);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_LCTRL);
        unregister_code(KC_LSFT);
      }
      break;
    case NEXT_TAB:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_LCTRL);
      }
      break;
    case OPEN_ALFRED:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_SPC);
      } else {
        unregister_code(KC_SPC);
        unregister_code(KC_LGUI);
      }
      break;
    case PREV_WORKSPACE:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        register_code(KC_LEFT);
      } else {
        unregister_code(KC_LEFT);
        unregister_code(KC_LCTRL);
      }
      break;
    case NEXT_WORKSPACE:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        register_code(KC_RIGHT);
      } else {
        unregister_code(KC_RGHT);
        unregister_code(KC_LCTRL);
      }
      break;
    case PREV_WINDOW_WIN:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_LSFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
      break;
    case NEXT_WINDOW_WIN:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case PREV_WINDOW_MAC:
      if (record->event.pressed) {
        if (!is_cmd_tab_active) {
          is_cmd_tab_active = true;
          register_code(KC_LGUI);
        }
        cmd_tab_timer = timer_read();
        register_code(KC_LSFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
      break;
    case NEXT_WINDOW_MAC:
      if (record->event.pressed) {
        if (!is_cmd_tab_active) {
          is_cmd_tab_active = true;
          register_code(KC_LGUI);
        }
        cmd_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 1000) {
      unregister_code(KC_LGUI);
      is_cmd_tab_active = false;
    }
  }
}
