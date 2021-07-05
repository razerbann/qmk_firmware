/* Copyright 2021 Ahmed Abdelkafi
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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xABDE
#define PRODUCT_ID      0x4803
#define DEVICE_VER      0x4803
#define MANUFACTURER    IBM
#define PRODUCT         5140

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

/*
 * Keyboard Matrix Assignments
 */
#define MATRIX_ROW_PINS { B0, B1, B2, B3, B7, D0 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, B6, B5, B4, D7, D6, D4, D5, C7, C6 }

#define DIODE_DIRECTION ROW2COL
