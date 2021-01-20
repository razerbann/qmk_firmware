# Build Options
#   change yes to no to disable

BOOTMAGIC_ENABLE  = no                      # Virtual DIP switch configuration
MOUSEKEY_ENABLE   = no                      # Mouse keys
EXTRAKEY_ENABLE   = no                      # Audio control and System control
CONSOLE_ENABLE    = no                      # Console for debug
COMMAND_ENABLE    = no                      # Commands for debug and configuration

TAP_DANCE_ENABLE  = yes

SRC += custom_keycodes.c tap_dance.c

ifeq ($(strip $(NOT_IBM_BOARD)), yes)
    RAW_ENABLE    = yes                     # Enable RAW_HID capabilities
    SRC          += comm_protocol.c
endif
