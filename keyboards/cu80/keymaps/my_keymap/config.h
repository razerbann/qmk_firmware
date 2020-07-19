/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once

#define FORCE_NKRO // force NKRO on by default

#undef TAPPING_TERM
#define TAPPING_TERM 200

#define NO_MUSIC_MODE
// Because the Macro and Function features are incompatible with Link Time Optimization, disable those features
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#ifdef DEBOUNCE
#undef DEBOUNCE
#define DEBOUNCE 0
#endif // NO_DEBOUNCE

#ifdef LOCKING_SUPPORT_ENABLE
#undef LOCKING_SUPPORT_ENABLE
#ifdef LOCKING_RESYNC_ENABLE
/* Locking resynchronize hack */
#undef LOCKING_RESYNC_ENABLE
#endif // NO_LOCKING_RESYNC_ENABLE
#endif // NO_LOCKING_SUPPORT_ENABLE
