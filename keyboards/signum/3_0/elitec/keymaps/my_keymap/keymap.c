#include QMK_KEYBOARD_H
#include "keymap_french.h"

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO

// The most portable copy/paste keys (windows (mostly), linux, and some terminal emulators).
#define MK_CUT    LSFT(KC_DEL)  // shift + delete
#define MK_COPY   LCTL(KC_INS)  // ctrl + insert
#define MK_PASTE  LSFT(KC_INS)  // shift + insert

enum custom_keycodes {
    L_SFT_LESS = SAFE_RANGE,
    R_SFT_GRTR,
    L1_LPRN,
    L2_RPRN,
    L3_LCBR,
    L6_RCBR,
    L4_LBRC,
    L5_RBRC
};

uint16_t key_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_SFT_LESS:
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
        case R_SFT_GRTR:
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
        case L1_LPRN:
            if (record->event.pressed) {
                key_timer = timer_read();
                layer_on(1);
            } else {
                layer_off(1);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("("); // (
                }
            }
            return false;
            break;
        case L2_RPRN:
            if (record->event.pressed) {
                key_timer = timer_read();
                layer_on(2);
            } else {
                layer_off(2);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING(")"); // )
                }
            }
            return false;
            break;
        case L3_LCBR:
            if (record->event.pressed) {
                key_timer = timer_read();
                layer_on(3);
            } else {
                layer_off(3);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("{"); // {
                }
            }
            return false;
            break;
        case L6_RCBR:
            if (record->event.pressed) {
                key_timer = timer_read();
                layer_on(6);
            } else {
                layer_off(6);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("}");  // }
                }
            }
            return false;
            break;
        case L4_LBRC:
            if (record->event.pressed) {
                key_timer = timer_read();
                layer_on(4);
            } else {
                layer_off(4);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("["); // [
                }
            }
            return false;
            break;
        case L5_RBRC:
            if (record->event.pressed) {
                key_timer = timer_read();
                layer_on(5);
            } else {
                layer_off(5);
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    SEND_STRING("]"); // ]
                }
            }
            return false;
            break;
        default:
            layer_on(0);
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Layer 0
 * -------------------------------------------------               -------------------------------------------------
 * |  ESC  |   a   |   z   |   e   |   r   |   t   |               |   y   |   u   |   i   |   o   |   p   |  BSP  |
 * -------------------------------------------------               -------------------------------------------------
 * |  TAB  |   q   |   s   |   d   |   f   |   g   |               |   h   |   j   |   k   |   l   |   m   | ENTER |
 * -------------------------------------------------               -------------------------------------------------
 * |L_SFT_<|   w   |   x   |   c   |   v   |   b   |               |   n   |   ,   |   ;   |   :   |   !   |R_SFT_>|
 * -----------------------------------------------------------------------------------------------------------------
 *   LT1_(   LT3_{   LT4_[         |  WIN  | SPACE |L_CTL_H|R_ALT_E|  DEL  |L_ALT_I|         LT5_]   LT6_}   LT2_)
 *                                 -------------------------------------------------
 */
	[0] = LAYOUT_ortho_4x12(
		KC_ESC, FR_A, FR_Z, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
		KC_TAB, FR_Q, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, FR_M, KC_ENT,
		L_SFT_LESS, FR_W, KC_X, KC_C, KC_V, KC_B, KC_N, FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, R_SFT_GRTR,
		L1_LPRN, L3_LCBR, L4_LBRC, KC_LGUI, KC_SPC, LCTL_T(KC_HOME), RALT_T(KC_END), KC_DEL, LALT_T(KC_INS), L5_RBRC, L6_RCBR, L2_RPRN
	),

/*
 * Layer 1
 * -------------------------------------------------               -------------------------------------------------
 * |  ESC  |   &   |   é   |   "   |   '   |       |               |   -   |   è   |   _   |   ç   |   à   |  BSP  |
 * -------------------------------------------------               -------------------------------------------------
 * |  TAB  |       |       |       |       |       |               |       |       |   °   |   =   |   +   | ENTER |
 * -------------------------------------------------               -------------------------------------------------
 * |L_SFT_<|       |       |       |       |       |               |       |   ?   |   .   |   /   |   ù   |R_SFT_>|
 * -----------------------------------------------------------------------------------------------------------------
 *           HOME     END        |  WIN  | SPACE |L_CTL_H|R_ALT_E|  DEL  |L_ALT_I|        Pg_DOWN  Pg_UP
 *                                 -------------------------------------------------
 */
	[1] = LAYOUT_ortho_4x12(
		KC_ESC, FR_AMP, FR_EACU, FR_QUOT, FR_APOS, KC_NO, FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, KC_BSPC,
		KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, FR_OVRR, FR_EQL, FR_PLUS, KC_ENT,
		L_SFT_LESS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, FR_QUES, FR_DOT, FR_SLSH, FR_MU, R_SFT_GRTR,
		KC_NO, KC_HOME, KC_END, KC_LGUI, KC_SPC, LCTL_T(KC_HOME), RALT_T(KC_END), KC_DEL, LALT_T(KC_INS), KC_PGUP, KC_PGDN, KC_NO
	),

/*
 * Layer 2
 * -------------------------------------------------               -------------------------------------------------
 * |  ESC  |       |   ~   |   #   |       |       |               |   |   |   `   |   \   |   ^   |   @   |  BSP  |
 * -------------------------------------------------               -------------------------------------------------
 * |  TAB  |       |   ↑   |       |       |       |               |       |   €   |   ¨   |   ^   |   $   | ENTER |
 * -------------------------------------------------               -------------------------------------------------
 * |L_SFT_<|   ←   |   ↓   |   →   |       |       |               |       |       |   ù   |   %   |   *   |R_SFT_>|
 * -----------------------------------------------------------------------------------------------------------------
 *           HOME     END          |  WIN  | SPACE |L_CTL_H|R_ALT_E|  DEL  |L_ALT_I|        Pg_DOWN  Pg_UP
 *                                 -------------------------------------------------
 */
	[2] = LAYOUT_ortho_4x12(
		KC_ESC, KC_NO, FR_TILD, FR_HASH, KC_NO, KC_NO, FR_PIPE, FR_GRV, FR_BSLS, FR_CCIRC, FR_AT, KC_BSPC,
		KC_TAB, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, FR_EURO, FR_UMLT, FR_CIRC, FR_DLR, KC_ENT,
		L_SFT_LESS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, FR_UGRV, FR_PERC, FR_ASTR, R_SFT_GRTR,
		KC_NO, KC_HOME, KC_END, KC_LGUI, KC_SPC, LCTL_T(KC_HOME), RALT_T(KC_END), KC_DEL, LALT_T(KC_INS), KC_PGUP, KC_PGDN, KC_NO
	),

/*
 * Layer 3
 * -------------------------------------------------               -------------------------------------------------
 * |  ESC  |   1   |   2   |   3   |   4   |   5   |               |   6   |   7   |   8   |   9   |   0   |  BSP  |
 * -------------------------------------------------               -------------------------------------------------
 * |  TAB  |       |       |       |       |       |               |       |   4   |   5   |   6   | Pg_UP | ENTER |
 * -------------------------------------------------               -------------------------------------------------
 * |L_SFT_<|       |       |       |       |       |               |   0   |   1   |   2   |   3   |Pg_DOWN|R_SFT_>|
 * -----------------------------------------------------------------------------------------------------------------
 *                                 |  WIN  | SPACE |L_CTL_H|R_ALT_E|  DEL  |L_ALT_0|        Pg_DOWN  Pg_UP
 *                                 -------------------------------------------------
 */
	[3] = LAYOUT_ortho_4x12(
		KC_ESC, FR_1, FR_2, FR_3, FR_4, FR_5, FR_6, FR_7, FR_8, FR_9, FR_0, KC_BSPC,
		KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, FR_4, FR_5, FR_6, KC_PGUP, KC_ENT,
		L_SFT_LESS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, FR_0, FR_1, FR_2, FR_3, KC_PGDN, R_SFT_GRTR,
		KC_NO, KC_NO, KC_NO, KC_LGUI, KC_SPC, LCTL_T(KC_HOME), RALT_T(KC_END), KC_DEL, LALT_T(FR_0), KC_PGUP, KC_PGDN, KC_NO
	),

/*
 * Layer 4
 * -------------------------------------------------               -------------------------------------------------
 * |  Fn1  |  Fn2  |  Fn3  |  Fn4  |  Fn5  |  Fn6  |               |  Fn7  |  Fn8  |  Fn9  |  F10  |  F11  |  F12  |
 * -------------------------------------------------               -------------------------------------------------
 * |       |       |       |       |       |       |               |       |   ←   |   ↓   |   ↑   |   →   |       |
 * -------------------------------------------------               -------------------------------------------------
 * |       |       |       |       |       |  Fn5  |               |  Fn9  |  F10  |  F11  |  F12  |       |PRT_SCR|
 * -----------------------------------------------------------------------------------------------------------------
 *                                 |  WIN  | SPACE |L_CTL_H|R_ALT_E|  DEL  |L_ALT_I|        Pg_DOWN  Pg_UP
 *                                 -------------------------------------------------
 */
	[4] = LAYOUT_ortho_4x12(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F5, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_PSCR,
		KC_NO, KC_NO, KC_NO, KC_LGUI, KC_SPC, LCTL_T(KC_HOME), RALT_T(KC_END), KC_DEL, LALT_T(KC_INS), KC_PGUP, KC_PGDN, KC_NO
	),

/*
 * Layer 5
 * -------------------------------------------------               -------------------------------------------------
 * |       |M_BTN_5|M_BTN_4|M_BTN_3|M_BTN_2|M_BTN_1|               |       | M_W_← | M_W_↓ | M_W_↑ | M_W_→ |       |
 * -------------------------------------------------               -------------------------------------------------
 * |       |M_BTN_5|M_BTN_4|M_BTN_3|M_BTN_2|M_BTN_1|               |       |  M_←  |  M_↓  |  M_↑  |  M_→  |       |
 * -------------------------------------------------               -------------------------------------------------
 * |       |M_BTN_5|M_BTN_4|M_BTN_3|M_BTN_2|M_BTN_1|               |       |  M_←  |  M_↓  |  M_↑  |  M_→  |       |
 * -----------------------------------------------------------------------------------------------------------------
 *           HOME     END          |       |       |       |       |       |       |
 *                                 -------------------------------------------------
 */
	[5] = LAYOUT_ortho_4x12(
        KC_NO, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
        KC_NO, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
        KC_NO, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
        KC_NO, KC_HOME, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	),

/*
 * Layer 6
 * -------------------------------------------------               -------------------------------------------------
 * |       |       |       |       |       | RESET |               | RESET |       |       |       |       | Vol_↑ |
 * -------------------------------------------------               -------------------------------------------------
 * |       |       |       |       |       |       |               |       |       |       |       |       | Vol_↓ |
 * -------------------------------------------------               -------------------------------------------------
 * |       |       |       |       |       |       |               |       |       |       |       |       | Vol_0 |
 * -----------------------------------------------------------------------------------------------------------------
 *           HOME     END          |       |       |       |       |       |       |
 *                                 -------------------------------------------------
 */
	[6] = LAYOUT_ortho_4x12(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE,
        KC_NO, KC_HOME, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	)
};

/* vi: ft=c:tw=80:sw=2:ts=2:sts=2:et */

