# MCU name
MCU                     = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER              = caterina

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE        = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE         = yes      # Mouse keys(+4700)
EXTRAKEY_ENABLE         = yes      # Audio control and System control(+450)
CONSOLE_ENABLE          = no       # Console for debug(+400)
COMMAND_ENABLE          = no       # Commands for debug and configuration
NKRO_ENABLE             = yes      # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE        = yes      # Enable keyboard backlight functionality
MIDI_ENABLE             = no       # MIDI controls
AUDIO_ENABLE            = no       # Audio output on port C6
UNICODE_ENABLE          = no       # Unicode
BLUETOOTH_ENABLE        = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE         = yes      # Enable WS2812 RGB underlight.
VELOCIKEY_ENABLE        = yes      # I like RGB

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE        = no       # Breathing sleep LED during USB suspend

CUSTOM_MATRIX           = yes
QUANTUM_LIB_SRC        += i2c.c \
				    	  serial.c
SRC                    += ssd1306.c

TAP_DANCE_ENABLE        = yes       # Enable tap dance feature
LINK_TIME_OPTIMIZATION  = yes       # Enable link time optimization
EXTRAFLAGS             += -flto     # Use the optimiser during linking

DEFAULT_FOLDER          = crkbd/rev1

# If you want to change the display of OLED, you need to change here
SRC                    += ./lib/glcdfont.c \
                          ./lib/rgb_state_reader.c \
                          ./lib/layer_state_reader.c \
                          ./lib/logo_reader.c \
                          ./lib/keylogger.c \
                          # ./lib/mode_icon_reader.c \
                          # ./lib/host_led_state_reader.c \
                          # ./lib/timelogger.c \
