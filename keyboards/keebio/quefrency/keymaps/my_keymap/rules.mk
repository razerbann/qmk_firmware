BOOTMAGIC_ENABLE         = no        # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE          = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE          = yes       # Audio control and System control(+450)
CONSOLE_ENABLE           = no        # Console for debug(+400)
COMMAND_ENABLE           = no        # Commands for debug and configuration
NKRO_ENABLE              = yes       # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE         = no        # Enable keyboard backlight b
MIDI_ENABLE              = no        # MIDI controls
AUDIO_ENABLE             = no        # Audio output on port C6
UNICODE_ENABLE           = no        # Unicode
BLUETOOTH_ENABLE         = no        # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE          = yes       # Enable WS2812 RGB underlight.
VELOCIKEY_ENABLE         = yes       # I like RGB

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE         = no        # Breathing sleep LED during USB suspend

SPLIT_KEYBOARD           = yes
ENCODER_ENABLE           = no

#TAP_DANCE_ENABLE         = yes       # Enable tap dance feature
LINK_TIME_OPTIMIZATION   = yes       # Enable link time optimization
EXTRAFLAGS              += -flto     # Use the optimiser during linking

# MOUSEKEY_WHEEL_MAX_SPEED = 1        # Maximum number of scroll steps per scroll action
# MOUSEKEY_WHEEL_MAX_SPEED = 0         # Time until maximum scroll speed is reached. Set to 0 will disable acceleration for the scrolling
