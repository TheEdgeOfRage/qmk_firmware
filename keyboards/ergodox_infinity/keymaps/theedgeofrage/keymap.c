#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "version.h"

#define _____ KC_TRNS
#define XXXXX KC_NO

enum layers {
    COLEMAK,
    QWERTY,
    FUNCTION,
    NUMPAD,
};

enum custom_keycodes {
	M_EMAIL = SAFE_RANGE,
	M_USER,
	M_HOST,
};

enum unicode_names {
	USH,
	LSH,
	UDJ,
	LDJ,
	UCJ,
	LCJ,
	UCH,
	LCH,
	UZH,
	LZH,
};

const uint32_t PROGMEM unicode_map[] = {
	[USH] = 0x160, // Š
	[LSH] = 0x161, // š
	[UDJ] = 0x110, // Đ
	[LDJ] = 0x111, // đ
	[UCJ] = 0x106, // Ć
	[LCJ] = 0x107, // ć
	[UCH] = 0x10C, // Č
	[LCH] = 0x10D, // č
	[UZH] = 0x17D, // Ž
	[LZH] = 0x17E, // ž
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Layer 0: Colemak
	* ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
	* │   `   │  1  │  2  │  3  │  4  │  5  │  =  │     │  =  │  6  │  7  │  8  │  9  │  0  │   -   │
	* ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
	* │  TAB  │  Q  │  W  │  F  │  P  │  G  │  (  │     │  [  │  J  │  L  │  U  │  Y  │  ;  │   '   │
	* ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
	* │ LCTRL │  A  │  R  │  S  │  T  │  D  ├─────┤     ├─────┤  H  │  N  │  E  │  I  │  O  │  ENT  │
	* ├───────┼─────┼─────┼─────╄─────╃─────┤  )  │     │  ]  ├─────╄─────╃─────┼─────┼─────┼───────┤
	* │ LSHFT │  Z  │  X  │  C  │  V  │  B  │     │     │     │  K  │  M  │  ,  │  .  │  \  │ RSHFT │
	* └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
	*   │     │     │     │ LALT│ SPC │                             │  /  │     │     │ APP │     │
	*   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
	*                                   │ ESC │     │ │     │ NUM │
	*                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
	*                             │     │     │ QWER│ │ QWER│     │     │
	*                             │ SPC │ LGUI├─────┤ ├─────┤  FN │ BSPC│
	*                             │     │     │ CAPS│ │ PSCR│     │     │
	*                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
	*/
	[COLEMAK] = LAYOUT_ergodox(
		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_EQL,
		KC_TAB,		KC_Q,		KC_W,		KC_F,		KC_P,		KC_G,		KC_LPRN,
		KC_LCTL,	KC_A,		KC_R,		KC_S,		KC_T,		KC_D,
		KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_RPRN,
		XXXXX,		KC_ESC,		XXXXX,		KC_LALT,	KC_SPC,
																	KC_ESC,		XXXXX,
																				TG(QWERTY),
														KC_SPC,		KC_LGUI,	KC_CAPS,

		KC_EQL,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,
		KC_LBRC,	KC_J,		KC_L,		KC_U,		KC_Y,		KC_SCLN,	KC_QUOT,
					KC_H,		KC_N,		KC_E,		KC_I,		KC_O,		KC_ENT,
		KC_RBRC,	KC_K,		KC_M,		KC_COMM,	KC_DOT,		KC_BSLS,	KC_RSFT,
								KC_SLSH,	XXXXX,		XXXXX,		KC_APP,		XXXXX,
		XXXXX,		TG(NUMPAD),
		TG(QWERTY),
		KC_PSCR,	MO(FUNCTION),KC_BSPC
	),

	/* Layer 1: QWERTY
	* ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
	* │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
	* ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
	* │       │  Q  │  W  │  E  │  R  │  T  │     │     │     │  Y  │  U  │  I  │  O  │  P  │       │
	* ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
	* │       │  A  │  S  │  D  │  F  │  G  ├─────┤     ├─────┤  H  │  J  │  K  │  L  │  ;  │       │
	* ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
	* │       │  Z  │  X  │  C  │  V  │  B  │     │     │     │  N  │  M  │     │     │     │       │
	* └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
	*   │     │     │     │     │     │                             │     │     │     │     │     │
	*   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
	*                                   │     │     │ │     │     │
	*                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
	*                             │     │     │ COL │ │ COL │     │     │
	*                             │     │     ├─────┤ ├─────┤     │     │
	*                             │     │     │     │ │     │     │     │
	*                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
	*/
	[QWERTY] = LAYOUT_ergodox(
		_____,		_____,		_____,		_____,		_____,		_____,		_____,
		_____,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		_____,
		_____,		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,
		_____,		KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		_____,
		_____,		_____,		_____,		_____,		_____,
																	_____,		_____,
																				_____,
														_____,		_____,		_____,

		_____,		_____,		_____,		_____,		_____,		_____,		_____,
		_____,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		_____,
					KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	_____,
		_____,		KC_N,		KC_M,		_____,		_____,		_____,		_____,
								_____,		_____,		_____,		_____,		_____,
		_____,		_____,
		_____,
		_____,		_____,		_____
	),

	/* Layer 2: Function
	* ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
	* │ RESET │  F1 │  F2 │  F3 │  F4 │  F5 │  F6 │     │  F7 │  F8 │  F9 │ F10 │ F11 │ F12 │ RESET │
	* ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
	* │       │ MUTE│ VOLD│ VOLU│     │     │     │     │  Š  │     │     │     │     │  Č  │   Ć   │
	* ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
	* │       │ PLAY│ PREV│ NEXT│ USER│ HOST├─────┤     ├─────┤  ←  │  ↓  │  ↑  │  →  │     │       │
	* ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │  Đ  ├─────╄─────╃─────┼─────┼─────┼───────┤
	* │       │EMAIL│     │     │     │     │     │     │     │ HOME│ PGUP│ PGDN│ END │  Ž  │       │
	* └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
	*   │     │     │     │     │     │                             │     │     │     │     │     │
	*   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
	*                                   │     │     │ │     │     │
	*                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
	*                             │     │     │     │ │     │     │     │
	*                             │ DEL │     ├─────┤ ├─────┤     │     │
	*                             │     │     │     │ │     │     │     │
	*                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
	*/
	[FUNCTION] = LAYOUT_ergodox(
		RESET,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,
		_____,		KC_MUTE,	KC_VOLD,	KC_VOLU,	XXXXX,		XXXXX,		XXXXX,
		_____,		KC_MPLY,	KC_MPRV,	KC_MNXT,	M_USER,		M_HOST,
		_____,		M_EMAIL,	XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		_____,		_____,		_____,		_____,		_____,
																	_____,		_____,
																				XXXXX,
														KC_DEL,		_____,		_____,

		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		RESET,
		XP(LSH, USH),XXXXX,		XXXXX,		XXXXX,		XXXXX,		XP(LCH, UCH),XP(LCJ, UCJ),
					KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT,	XXXXX,		XXXXX,
		XP(LDJ, UDJ),KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,		XP(LZH, UZH),_____,
								XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		XXXXX,		XXXXX,
		XXXXX,
		_____,		_____,		_____
	),

	/* Layer 3: Numpad
	* ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
	* │       │     │     │     │     │     │     │     │     │     │ NLCK│  /  │  *  │  -  │       │
	* ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
	* │       │     │     │     │     │     │     │     │     │     │  7  │  8  │  9  │  +  │       │
	* ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
	* │       │     │     │     │     │     ├─────┤     ├─────┤     │  4  │  5  │  6  │  +  │       │
	* ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
	* │       │     │     │     │     │     │     │     │     │     │  1  │  2  │  3  │ ENT │       │
	* └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
	*   │     │     │     │     │     │                             │  0  │  0  │  .  │ ENT │     │
	*   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
	*                                   │     │     │ │     │     │
	*                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
	*                             │     │     │     │ │     │     │     │
	*                             │     │     ├─────┤ ├─────┤     │     │
	*                             │     │     │     │ │     │     │     │
	*                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
	*/
	[NUMPAD] = LAYOUT_ergodox(
		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
																	XXXXX,		XXXXX,
																				XXXXX,
														XXXXX,		XXXXX,		XXXXX,

		XXXXX,		XXXXX,		KC_NLCK,	KC_PSLS,	KC_PAST,	KC_PMNS,	XXXXX,
		XXXXX,		XXXXX,		KC_P7,		KC_P8,		KC_P9,		KC_PPLS,	XXXXX,
					XXXXX,		KC_P4,		KC_P5,		KC_P6,		KC_PPLS,	XXXXX,
		XXXXX,		XXXXX,		KC_P1,		KC_P2,		KC_P3,		KC_ENT,		XXXXX,
								KC_P0,		KC_P0,		KC_PDOT,	KC_ENT,		XXXXX,
		XXXXX,		_____,
		XXXXX,
		XXXXX,		XXXXX,		XXXXX
	),
};

void matrix_init_user(void) {
	set_unicode_input_mode(UC_LNX);
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case M_EMAIL:
				SEND_STRING("pavle.portic@tilda.center");
				return false;
			case M_USER:
				SEND_STRING("TheEdgeOfRage");
				return false;
			case M_HOST:
				SEND_STRING("theedgeofrage.com");
				return false;
		}
	}

	return true;
}
