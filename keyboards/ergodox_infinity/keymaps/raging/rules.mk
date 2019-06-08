#
# rules.mk
# pavle, 2017-03-24 15:39
#
BOOTMAGIC_ENABLE ?= no  # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  ?= yes # Mouse keys(+4700)
EXTRAKEY_ENABLE  ?= yes # Audio control and System control(+450)
CONSOLE_ENABLE   ?= no  # Console for debug(+400)
COMMAND_ENABLE   ?= no # Commands for debug and configuration
CUSTOM_MATRIX    ?= no # Custom matrix file for the ErgoDox EZ
SLEEP_LED_ENABLE ?= no # Breathing sleep LED during USB suspend
NKRO_ENABLE      ?= yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
UNICODE_ENABLE   ?= yes # Unicode
ONEHAND_ENABLE   ?= no # Allow swapping hands of keyboard
