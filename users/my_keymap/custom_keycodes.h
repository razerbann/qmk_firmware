#pragma once

#include "quantum.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _WIN = _BASE,
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

// Defines the keycodes for Tap Dance
enum tap_dance {
    TD_LALT_RALT,
    TD_LCTRL_ESC,
};
