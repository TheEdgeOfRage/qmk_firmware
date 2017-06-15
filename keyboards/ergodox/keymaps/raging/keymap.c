#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define QWER 1 // qwerty layout
#define FN 2 // function
#define NUM 3 // numpad
#define RPN 4 // numpad

#define C_INIT M(10) // Reset calculator to zero
#define C_0 M(0) // Append number 0 to buffer
#define C_1 M(1) // Append number 1 to buffer
#define C_2 M(2) // Append number 2 to buffer
#define C_3 M(3) // Append number 3 to buffer
#define C_4 M(4) // Append number 4 to buffer
#define C_5 M(5) // Append number 5 to buffer
#define C_6 M(6) // Append number 6 to buffer
#define C_7 M(7) // Append number 7 to buffer
#define C_8 M(8) // Append number 8 to buffer
#define C_9 M(9) // Append number 9 to buffer
#define C_DOT M(11) // Add decimal point
#define C_PUSH M(12) // Push buffer to stack
#define C_POP M(13) // Pop stack to buffer
#define C_ADD M(14) // Add buffer and stack
#define C_SUB M(15) // Subtract buffer from stack
#define C_MUL M(16) // Multiply buffer and stack
#define C_DIV M(17) // Divide stack and buffer

#define _____ KC_TRNS
#define XXXXX KC_NO

const uint16_t max = 5000;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Keymap 1: Basic layer
	 *
	 * ,--------------------------------------------------.           ,--------------------------------------------------.
	 * |   `    |   1  |   2  |   3  |   4  |   5  |   =  |           |  NUM |   6  |   7  |   8  |   9  |   0  |   -    |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * | Del    |   Q  |   W  |   F  |   P  |   G  |   (  |           |   [  |   J  |   L  |   U  |   Y  |   ;  |   '    |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |Esc/Ctrl|   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |  Enter |
	 * |--------+------+------+------+------+------|   )  |           |   ]  |------+------+------+------+------+--------|
	 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   \  | RShift |
	 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	 *   |      |      |      |      | LGUI |                                       |   /  |      |      |      |      |
	 *   `----------------------------------'                                       `----------------------------------'
	 *                                        ,-------------.       ,--------------.
	 *                                        |      |      |       |      |       |
	 *                                 ,------|------|------|       |------+-------+------.
	 *                                 |      |      | Slck |       | QWER |       |      |
	 *                                 | Space| LAlt |------|       |------|   FN  | Enter|
	 *                                 |      |      | Caps |       | Pscr |       |      |
	 *                                 `--------------------'       `---------------------'
	 */
	[BASE] = KEYMAP(  // layer 0 : default
		// left hand
		KC_GRV,			KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_EQL,
		KC_TAB,			KC_Q,		KC_W,		KC_F,		KC_P,		KC_G,		KC_LPRN,
		KC_LCTL,		KC_A,		KC_R,		KC_S,		KC_T,		KC_D,
		KC_LSFT,		KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_RPRN,
		TG(FN),			XXXXX,		XXXXX,		XXXXX,		KC_LGUI,
																		KC_ESC,		TG(QWER),
																					KC_SLCK,
															KC_SPC,		KC_LALT,	KC_CAPS,

		// right hand
		TG(NUM),		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,
		KC_LBRC,		KC_J,		KC_L,		KC_U,		KC_Y,		KC_SCLN,	KC_QUOT,
						KC_H,		KC_N,		KC_E,		KC_I,		KC_O,		KC_ENT,
		KC_RBRC,		KC_K,		KC_M,		KC_COMM,	KC_DOT,		KC_BSLS,	KC_RSFT,
									KC_SLSH,	XXXXX,		XXXXX,		XXXXX,		XXXXX,
		TG(RPN),		XXXXX,
		TG(QWER),
		KC_PSCR,		MO(FN),		KC_BSPC
			),
	/* Keymap 0: Basic layer
	 *
	 * ,--------------------------------------------------.           ,--------------------------------------------------.
	 * |   `    |   1  |   2  |   3  |   4  |   5  |   =  |           |  NUM |   6  |   7  |   8  |   9  |   0  |   -    |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * | Del    |   Q  |   W  |   E  |   R  |   T  |   (  |           |   [  |   Y  |   U  |   I  |   O  |   P  |   '    |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |Esc/Ctrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  Enter |
	 * |--------+------+------+------+------+------|   )  |           |   ]  |------+------+------+------+------+--------|
	 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   \  | RShift |
	 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	 *   |      |      |      |      | LGUI |                                       |   /  |      |      |      |      |
	 *   `----------------------------------'                                       `----------------------------------'
	 *                                        ,-------------.       ,--------------.
	 *                                        |      |      |       |      |       |
	 *                                 ,------|------|------|       |------+-------+------.
	 *                                 |      |      | Slck |       | QWER |       |      |
	 *                                 | Space| LAlt |------|       |------|   FN  | Enter|
	 *                                 |      |      | Caps |       | Pscr |       |      |
	 *                                 `--------------------'       `---------------------'
	 */
	// QWERTY layer
	[QWER] = KEYMAP(  // layer 1 : qwerty
		// left hand
		_____,			_____,		_____,		_____,		_____,		_____,		_____,
		_____,			KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		_____,
		_____,			KC_A,		KC_S,		KC_D,		KC_F,		KC_G,
		_____,			KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		_____,
		_____,			_____,		_____,		_____,		KC_SPC,
																		_____,		_____,
																					_____,
															_____,		_____,		_____,

		// right hand
		_____,			_____,		_____,		_____,		_____,		_____,		_____,
		_____,			KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_QUOT,
						KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_ENT,
		_____,			KC_N,		KC_M,		_____,		_____,		_____,		_____,
									KC_SLSH,	_____,		_____,		_____,		_____,
		_____,			_____,
		_____,
		_____,			_____,		_____
	),
	/* Keymap 2: Function Layer
	 *
	 * ,--------------------------------------------------.           ,--------------------------------------------------.
	 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * |        | Mute | Vol- | Vol+ |      |      |      |           |      |      |      |      |      |      |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        | Play | Prev | Next |      |      |------|           |------|   ←  |   ↓  |   ↑  |   →  |      |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        |      |      |      |      |      |      |           |      | Home | PgUp | PgDn |  End |      |        |
	 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	 *   |      |      |      |      |      |                                       |      |      |      |      |      |
	 *   `----------------------------------'                                       `----------------------------------'
	 *                                        ,-------------.       ,-------------.
	 *                                        |      |      |       |      |      |
	 *                                 ,------|------|------|       |------+------+------.
	 *                                 |      |      |      |       |      |      |      |
	 *                                 |  Del |      |------|       |------|      |      |
	 *                                 |      |      |      |       |      |      |      |
	 *                                 `--------------------'       `--------------------'
	 */
	// Function layer
	[FN] = KEYMAP(  // layer 2 : function
		// left hand
		RESET,			KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,
		_____,			KC_MUTE,	KC_VOLD,	KC_VOLU,	XXXXX,		XXXXX,		_____,
		_____,			KC_MPLY,	KC_MPRV,	KC_MNXT,	XXXXX,		XXXXX,
		_____,			XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		_____,
		_____,			_____,		XXXXX,		XXXXX,		XXXXX,
																		_____,		_____,
																					_____,
															KC_DEL,		_____,		_____,

		// right hand
		KC_F7,			KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		RESET,
		XXXXX,			XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		DEBUG,
						KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT,	XXXXX,		XXXXX,
		XXXXX,			KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,		XXXXX,		XXXXX,
									XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		XXXXX,			XXXXX,
		XXXXX,
		_____,			_____,		_____
	),
	/* Keymap 3: Numpad Layer
	 *
	 * ,--------------------------------------------------.           ,--------------------------------------------------.
	 * |        |      |      |      |      |      |      |           |      |      | NLCK |   /  |   *  |   -  |        |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   +  |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |  ENT |        |
	 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	 *   |      |      |      |      |      |                                       |   0  |   0  |   .  |  ENT |      |
	 *   `----------------------------------'                                       `----------------------------------'
	 *                                        ,-------------.       ,-------------.
	 *                                        |      |      |       |      |      |
	 *                                 ,------|------|------|       |------+------+------.
	 *                                 |      |      |      |       |      |      |      |
	 *                                 |      |      |------|       |------|      |      |
	 *                                 |      |      |      |       |      |      |      |
	 *                                 `--------------------'       `--------------------'
	 */
	[NUM] = KEYMAP(  // layer 3 : numpad
		// left hand
		_____,			XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		_____,			XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		_____,
		_____,			XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		_____,			XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		_____,
		_____,			_____,		XXXXX,		XXXXX,		XXXXX,
																		_____,		_____,
																					_____,
															_____,		_____,		_____,

		// right hand
		_____,			XXXXX,		KC_NLCK,	KC_PSLS,	KC_PAST,	KC_PMNS,	XXXXX,
		XXXXX,			XXXXX,		KC_P7,		KC_P8,		KC_P9,		KC_PPLS,	XXXXX,
						XXXXX,		KC_P4,		KC_P5,		KC_P6,		KC_PPLS,	XXXXX,
		XXXXX,			XXXXX,		KC_P1,		KC_P2,		KC_P3,		KC_ENT,		XXXXX,
									KC_P0,		KC_P0,		KC_PDOT,	KC_ENT,		XXXXX,
		XXXXX,			XXXXX,
		XXXXX,
		_____,			_____,		_____
	),
	[RPN] = KEYMAP(  // layer 4 : RPN calculator
		// left hand
		_____,			XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		_____,			XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		_____,
		_____,			XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
		_____,			XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		_____,
		_____,			_____,		XXXXX,		XXXXX,		XXXXX,
																		_____,		_____,
																					_____,
															_____,		_____,		_____,

		// right hand
		_____,			XXXXX,		C_INIT,		C_DIV,		C_MUL,		C_SUB,	XXXXX,
		XXXXX,			XXXXX,		C_7,		C_8,		C_9,		C_ADD,	XXXXX,
						XXXXX,		C_4,		C_5,		C_6,		C_ADD,	XXXXX,
		XXXXX,			XXXXX,		C_1,		C_2,		C_3,		C_PUSH,		XXXXX,
									C_0,		C_0,		C_DOT,		C_PUSH,		XXXXX,
		_____,			_____,
		_____,
		_____,			_____,		C_POP
	),
};

/*const uint16_t PROGMEM fn_actions[] = {*/
	/*[1] = ACTION_LAYER_TAP_TOGGLE(FN)                // FN1 - Momentary Layer 1 (Symbols)*/
/*};*/

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch(id) {
		case 0:
			if (record->event.pressed)
				ergodox_calc_append_number(0);
			break;
		case 1:
			if (record->event.pressed)
				ergodox_calc_append_number(1);
			break;
		case 2:
			if (record->event.pressed)
				ergodox_calc_append_number(2);
			break;
		case 3:
			if (record->event.pressed)
				ergodox_calc_append_number(3);
			break;
		case 4:
			if (record->event.pressed)
				ergodox_calc_append_number(4);
			break;
		case 5:
			if (record->event.pressed)
				ergodox_calc_append_number(5);
			break;
		case 6:
			if (record->event.pressed)
				ergodox_calc_append_number(6);
			break;
		case 7:
			if (record->event.pressed)
				ergodox_calc_append_number(7);
			break;
		case 8:
			if (record->event.pressed)
				ergodox_calc_append_number(8);
			break;
		case 9:
			if (record->event.pressed)
				ergodox_calc_append_number(9);
			break;
		case 10:
			if (record->event.pressed)
				ergodox_calc_init();
			break;
		case 11:
			if (record->event.pressed)
				ergodox_calc_dot();
			break;
		case 12:
			if (record->event.pressed)
				ergodox_calc_push();
			break;
		case 13:
			if (record->event.pressed)
				ergodox_calc_pop();
			break;
		case 14:
			if (record->event.pressed)
				ergodox_calc_add();
			break;
		case 15:
			if (record->event.pressed)
				ergodox_calc_sub();
			break;
		case 16:
			if (record->event.pressed)
				ergodox_calc_mul();
			break;
		case 17:
			if (record->event.pressed)
				ergodox_calc_div();
			break;
	}
	return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
	/* ergodox_calc_init(); */
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
	uint8_t layer = biton32(layer_state);

	switch (layer) {
		case 0:
			/* ergodox_led_all_on(); */
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			// none
			break;
	}
};

