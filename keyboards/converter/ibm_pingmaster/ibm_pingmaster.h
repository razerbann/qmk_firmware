/* Copyright 2021 Abdelkafi Ahmed
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#define LAYOUT( \
    K00, K0F, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E,   K44, K45, K46,   K43, K41, K42, K4A, \
    K10,   K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,   K1D,  K1E,   K54, K55, K56,   K50, K51, K52, K5A, \
    K20,    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,  K2D,  K2E,   K64, K65, K66,   K60, K61, K62, K6B, \
    K30,     K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C,    K3D,    K3E,   K74, K75, K76,   K70, K71, K72, K7B, \
    K31,  K47,   K3F,                 K40,                     K4F, K48,       K2F,   K77, K67, K57,   K73, K63, K53, K4E  \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07   }, \
    { K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17   }, \
    { K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   KC_NO }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27   }, \
    { K28,   K29,   K2A,   K2B,   K2C,   K2D,   K2E,   K2F   }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37   }, \
    { K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E,   K3F   }, \
    { K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47   }, \
    { K48,   KC_NO, K4A,   KC_NO, KC_NO, KC_NO, K4E,   K4F   }, \
    { K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57   }, \
    { KC_NO, KC_NO, K5A,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K60,   K61,   K62,   K63,   K64,   K65,   K66,   K67   }, \
    { KC_NO, KC_NO, KC_NO, K6B,   KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K70,   K71,   K72,   K73,   K74,   K75,   K76,   K77   }, \
    { KC_NO, KC_NO, KC_NO, K7B,   KC_NO, KC_NO, KC_NO, KC_NO }  \
}
