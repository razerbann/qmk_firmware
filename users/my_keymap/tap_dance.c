#include "quantum.h"
#include "tap_dance.h"

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Alt, twice for Alt Gr
    [LALT_RALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
    // Tap once for Ctrl, twice for ESC
    [LCTRL_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, KC_ESC),
};
