#include "ergomini.h"

#define _BASE 0 // default layer
#define _QWER 1 // qwerty layout
#define _FN 2 // function
#define _NUM 3 // numpad
#define _RGB 4 // RGB

#define _____ KC_TRNS
#define XXXXX KC_NO

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
    /* Keymap 1: Base layer
     *
     * ,-----------------------------------------------------------------------------------.
     * |   `    |  1  |  2  |  3  |  4  |  5  |  =  |  6  |  7  |  8  |  9  |  0  |   -    |
     * |--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------|
     * |  Tab   |  Q  |  W  |  F  |  P  |  G  |  (  |  J  |  L  |  U  |  Y  |  ;  |   '    |
     * |--------+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+--------|
     * |  Ctrl  |  A  |  R  |  S  |  T  |  D  |-----|  H  |  N  |  E  |  I  |  O  |  Enter |
     * |--------+-----+-----+-----+-----+-----|  )  |-----+-----+-----+-----+-----+--------|
     * | LShift |  Z  |  X  |  C  |  V  |  B  |     |  K  |  M  |  ,  |  .  |  \  | RShift |
     * |--------+-----+-----+-----+-----------+-----+-----------+-----+-----+-----+--------|
     * | QWERTY | Esc | LAlt| i3  |   Space   | Fn  | Backspace |  /  |PtScr|Menu |        |
     * `-----------------------------------------------------------------------------------'
     *
     */
    [_BASE] = LAYOUT_ergomini(
        KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_EQL,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,
        KC_TAB,		KC_Q,		KC_W,		KC_F,		KC_P,		KC_G,		KC_LPRN,	KC_J,		KC_L,		KC_U,		KC_Y,		KC_SCLN,	KC_QUOT,
        KC_LCTL,	KC_A,		KC_R,		KC_S,		KC_T,		KC_D,					KC_H,		KC_N,		KC_E,		KC_I,		KC_O,		KC_ENT,
        KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_RPRN,	KC_K,		KC_M,		KC_COMM,	KC_DOT,		KC_BSLS,	KC_RSFT,
        TG(_QWER),	KC_ESC,		KC_LALT,	KC_LGUI,		KC_SPC,				MO(_FN),		KC_BSPC,			KC_SLSH,	KC_PSCR,	KC_APP,		TG(_NUM)
    ),

    /* Keymap 1: QWERTY layer
     *
     * ,-----------------------------------------------------------------------------------.
     * |        |     |     |     |     |     |     |     |     |     |     |     |        |
     * |--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------|
     * |        |  Q  |  W  |  E  |  R  |  T  |  (  |  Y  |  U  |  I  |  O  |  P  |        |
     * |--------+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+--------|
     * |        |  A  |  S  |  D  |  F  |  G  |-----|  H  |  J  |  K  |  L  |  ;  |        |
     * |--------+-----+-----+-----+-----+-----|  )  |-----+-----+-----+-----+-----+--------|
     * |        |  Z  |  X  |  C  |  V  |  B  |     |  N  |  M  |  ,  |  .  |  \  |        |
     * |--------+-----+-----+-----+-----------+-----+-----------+-----+-----+-----+--------|
     * |        |     |     |     |           |     |           |     |     |     |        |
     * `-----------------------------------------------------------------------------------'
     *
     */
    [_QWER] = LAYOUT_ergomini(
        _____,		_____,		_____,		_____,		_____,		_____,		_____,		_____,		_____,		_____,		_____,		_____,		_____,
        _____,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		_____,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		_____,
        _____,		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,					KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	_____,
        _____,		KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		_____,		KC_N,		KC_M,		_____,		_____,		_____,		_____,
        _____,		_____,		_____,		_____,			_____,				_____,			_____,				_____,		_____,		_____,		_____
    ),

    /* Keymap 2: Function Layer
     *
     * ,-----------------------------------------------------------------------------------.
     * |        | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 |  F12   |
     * |--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------|
     * |        |Mute |Vol- |Vol+ |     |     |  [  |  š  |     |     |     |  č  |   ć    |
     * |--------+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+--------|
     * |        |Play |Prev |Next |User |Domai|-----|  ←  |  ↓  |  ↑  |  →  |  đ  |        |
     * |--------+-----+-----+-----+-----+-----|  ]  |-----+-----+-----+-----+-----+--------|
     * |        |Email|     |     |     |     |     |Home |PgUp |PgDn | End |  ž  |        |
     * |--------+-----+-----+-----+-----------+-----+-----------+-----+-----+-----+--------|
     * |        |     |     |     |  Delete   |     |           |     |     | RGB |        |
     * `-----------------------------------------------------------------------------------'
     *
     */
    [_FN] = LAYOUT_ergomini(
        RESET,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,
        _____,		KC_MUTE,	KC_VOLD,	KC_VOLU,	XXXXX,		XXXXX,		KC_LBRC,	XP(LSH, USH),XXXXX,		XXXXX,		XXXXX,		XP(LCH, UCH),XP(LCJ, UCJ),
        _____,		KC_MPLY,	KC_MPRV,	KC_MNXT,	M_USER,		M_HOST,					KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT,	XP(LDJ, UDJ),_____,
        _____,		M_EMAIL,	XXXXX,		XXXXX,		XXXXX,		XXXXX,		KC_RBRC,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,		XP(LZH, UZH),_____,
        XXXXX,		_____,		_____,		_____,			KC_DEL,				_____,			_____,				_____,		_____,		TG(_RGB),	XXXXX
    ),

    /* Keymap 3: Numpad Layer
     *
     * ,-----------------------------------------------------------------------------------.
     * |        |     |     |     |     |     |     |     |NumLk|  /  |  *  |  -  |        |
     * |--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------|
     * |        |     |     |     |     |     |     |     |  7  |  8  |  9  |  +  |        |
     * |--------+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+--------|
     * |        |     |     |     |     |     |-----|     |  4  |  5  |  6  |  +  |        |
     * |--------+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+--------|
     * |        |     |     |     |     |     |     |     |  1  |  2  |  3  | ENT |        |
     * |--------+-----+-----+-----+-----------+-----+-----------+-----+-----+-----+--------|
     * |        |     |     |     |           |     |     0     |  0  |  .  | ENT |        |
     * `-----------------------------------------------------------------------------------'
     *
     */
    [_NUM] = LAYOUT_ergomini(
        _____,		_____,		_____,		_____,		_____,		_____,		_____,		_____,		KC_NLCK,	KC_PSLS,	KC_PAST,	KC_PMNS,	_____,
        _____,		_____,		_____,		_____,		_____,		_____,		_____,		_____,		KC_P7,		KC_P8,		KC_P9,		KC_PPLS,	_____,
        _____,		_____,		_____,		_____,		_____,		_____,					_____,		KC_P4,		KC_P5,		KC_P6,		KC_PPLS,	_____,
        _____,		_____,		_____,		_____,		_____,		_____,		_____,		_____,		KC_P1,		KC_P2,		KC_P3,		KC_ENT,		_____,
        _____,		_____,		_____,		_____,			_____,				_____,			KC_P0,				KC_P0,		KC_PDOT,	KC_ENT,		_____
    ),

    /* Keymap 4: RGB Layer */
    [_RGB] = LAYOUT_ergomini(
        XXXXX,		RGB_HUI,	RGB_SAI,	RGB_VAI,	XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
        XXXXX,		RGB_HUD,	RGB_SAD,	RGB_VAD,	XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
        XXXXX,		RGB_TOG,	RGB_MOD,	XXXXX,		XXXXX,		XXXXX,					XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
        XXXXX,		RGB_M_P,	RGB_M_B,	RGB_M_R,	XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,		XXXXX,
        XXXXX,		RGB_M_SW,	RGB_M_K,	RGB_M_G,		XXXXX,			    _____,			XXXXX,				XXXXX,		XXXXX,		_____,		XXXXX
    ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

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
