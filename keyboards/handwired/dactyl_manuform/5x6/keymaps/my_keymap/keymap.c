#include QMK_KEYBOARD_H
#include "keymap_french.h"

// A 'transparent' key code (that falls back to the layers below it).
#define _______   KC_TRNS
// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXXXXXX   KC_NO
// Useful portable shortcuts
// The most portable copy/paste keys
#define COPY      LCTL(KC_INS)
#define CUT       LSFT(KC_DEL)
#define PASTE     LSFT(KC_INS)
// <, >, (, {, [, ], } and ) codes
#define LESS      SS_TAP(X_NONUS_BSLASH)          // <
#define GRTR      SS_LSFT(SS_TAP(X_NONUS_BSLASH)) // >
#define LPRN      "5"                             // (
#define RPRN      "-"                             // )
#define LCBR      SS_ALGR("4")                    // {
#define RCBR      SS_ALGR("=")                    // }
#define LBRC      SS_ALGR("5")                    // [
#define RBRC      SS_ALGR("-")                    // ]

/////////////////////////////
// TAP DANCE CONFIGURATION //
/////////////////////////////
// Tap Dance Declarations
enum {
    LSFT_LESS_TD    = 0,
    RSFT_GRTR_TD,
    LPRN_CBR_BRC_TD,
    RPRN_CBR_BRC_TD,
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

// ( vs { vs [
static tap left_parentheses_tap_state = {
  .is_press_action = true,
  .state = 0
};
void left_parentheses_finished (qk_tap_dance_state_t *state, void *user_data) {
  left_parentheses_tap_state.state = cur_dance(state);
  switch (left_parentheses_tap_state.state) {
    case SINGLE_TAP: SEND_STRING(LPRN); break;
    case DOUBLE_TAP: SEND_STRING(LCBR); break;
    case TRIPLE_TAP: SEND_STRING(LBRC); break;
  }
}
void left_parentheses_reset (qk_tap_dance_state_t *state, void *user_data) {
  left_parentheses_tap_state.state = 0;
}

// ) vs } vs ]
static tap right_parentheses_tap_state = {
  .is_press_action = true,
  .state = 0
};
void right_parentheses_finished (qk_tap_dance_state_t *state, void *user_data) {
  right_parentheses_tap_state.state = cur_dance(state);
  switch (right_parentheses_tap_state.state) {
    case SINGLE_TAP: SEND_STRING(RPRN); break;
    case DOUBLE_TAP: SEND_STRING(RCBR); break;
    case TRIPLE_TAP: SEND_STRING(RBRC); break;
  }
}
void right_parentheses_reset (qk_tap_dance_state_t *state, void *user_data) {
  right_parentheses_tap_state.state = 0;
}

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [LSFT_LESS_TD]    = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, FR_LESS),                                               // Tap once for Shift, twice for less
  [RSFT_GRTR_TD]    = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, FR_GRTR),                                               // Tap once for Shift, twice for greater
  [LPRN_CBR_BRC_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, left_parentheses_finished, left_parentheses_reset),   // Tap once for Shift, twice for greater
  [RPRN_CBR_BRC_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, right_parentheses_finished, right_parentheses_reset), // Tap once for Shift, twice for greater
};

// Aliases for tapdance
#define LSFT_LESS    TD(LSFT_LESS_TD)
#define RSFT_GRTR    TD(RSFT_GRTR_TD)
#define LPRN_CBR_BRC TD(LPRN_CBR_BRC_TD)
#define RPRN_CBR_BRC TD(RPRN_CBR_BRC_TD)

//////////////////////////
// LAYOUT CONFIGURATION //
//////////////////////////

// Layers
#define _AZERTY  0
#define _NUMBERS 1
#define _FN      2

// hold/tap keys
#define NUMBERS  MO(_NUMBERS)
#define FN       MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_AZERTY] = LAYOUT_5x6(
//  ┌────────┬────────┬────────┬────────┬────────┬────────┐                     ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,FR_AMP  ,FR_EACU ,FR_QUOT ,FR_APOS ,LPRN_CBR_BRC,                  FR_MINS ,FR_EGRV ,FR_UNDS ,FR_CCED ,FR_AGRV ,RPRN_CBR_BRC,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,FR_A    ,FR_Z    ,KC_E    ,KC_R    ,KC_T    ,                      KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC ,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
    LSFT_LESS,FR_Q    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                      KC_H    ,KC_J    ,KC_K    ,KC_L    ,FR_M    ,KC_ENT  ,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,FR_W    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                      KC_N    ,FR_COMM ,FR_SCLN ,FR_COLN ,FR_EXLM ,RSFT_GRTR,
//  └────────┴────────┼────────┼────────┼────────┴────────┘                     └────────┴────────┼────────┼────────┼────────┴────────┘
                       KC_LEFT ,KC_RGHT ,                                                          KC_UP   ,KC_DOWN ,
//                    └────────┴────────┤                                                         ├────────┴────────┘
//                                      ├────────┬────────┐                     ┌────────┬────────┤
                                         KC_SPC  ,NUMBERS ,                      FN      ,KC_RALT ,
//                                      └───┬────┴───┬────┴───┐             ┌───┴────┬───┴────┬───┘
                                             KC_TAB  ,KC_HOME ,              KC_END  ,KC_DEL  ,
//                                          ├────────┼────────┤             ├────────┼────────┤
                                             KC_BSPC ,KC_LALT ,              KC_LGUI ,KC_LGUI
//                                          └────────┴────────┘             └────────┴────────┘
  ),

  [_NUMBERS] = LAYOUT_5x6(
//  ┌────────┬────────┬────────┬────────┬────────┬────────┐                     ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,FR_1    ,FR_2    ,FR_3    ,FR_4    ,FR_5    ,                      FR_6    ,FR_7    ,FR_8    ,FR_9    ,FR_0    ,KC_PSCR ,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,KC_UP   ,XXXXXXX , XXXXXXX, XXXXXXX,                      FR_DOT  ,FR_4    ,FR_5    ,FR_6    ,FR_DLR  ,KC_DEL  ,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,XXXXXXX ,                      FR_0    ,FR_1    ,FR_2    ,FR_3    ,FR_ASTR, _______ ,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                      FR_PLUS ,FR_MINS ,FR_CIRC ,FR_EQL  ,FR_PERC ,_______ ,
//  └────────┴────────┼────────┼────────┼────────┴────────┘                     └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______ ,_______ ,                                                          _______ ,_______ ,
//                    └────────┴────────┤                                                         ├────────┴────────┘
//                                      ├────────┬────────┐                     ┌────────┬────────┤
                                         _______ ,XXXXXXX ,                      _______ ,XXXXXXX ,
//                                      └───┬────┴───┬────┴───┐             ┌───┴────┬───┴────┬───┘
                                             _______ ,_______ ,              _______ ,_______ ,
//                                          ├────────┼────────┤             ├────────┼────────┤
                                             _______ ,_______ ,              _______ ,_______
//                                          └────────┴────────┘             └────────┴────────┘
  ),

  [_FN] = LAYOUT_5x6(
//  ┌────────┬────────┬────────┬────────┬────────┬────────┐                     ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6,                         KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , XXXXXXX, XXXXXXX,                      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RESET   ,
//  └────────┴────────┼────────┼────────┼────────┴────────┘                     └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______ ,_______ ,                                                          _______ ,_______ ,
//                    └────────┴────────┤                                                         ├────────┴────────┘
//                                      ├────────┬────────┐                     ┌────────┬────────┤
                                         _______ ,XXXXXXX ,                      _______ ,XXXXXXX ,
//                                      └───┬────┴───┬────┴───┐             ┌───┴────┬───┴────┬───┘
                                             _______ ,_______ ,              _______ ,_______ ,
//                                          ├────────┼────────┤             ├────────┼────────┤
                                             _______ ,_______ ,              _______ ,_______
//                                          └────────┴────────┘             └────────┴────────┘
  ),
};
