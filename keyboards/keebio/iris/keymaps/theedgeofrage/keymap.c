#include QMK_KEYBOARD_H

enum my_layers {
    _BASE,
    _QWERTY,
    _FN
};

#define XXXXXXX KC_NO
#define QWERTY  TG(_QWERTY)
#define FN      MO(_FN)
#define CTRL    LCTL_T(KC_ESC)

#define XSH UP(LSH, USH)
#define XDJ UP(LDJ, UDJ)
#define XCJ UP(LCJ, UCJ)
#define XCH UP(LCH, UCH)
#define XZH UP(LZH, UZH)

enum custom_keycodes {
    M_EMAIL = SAFE_RANGE,
    M_USER,
    M_HOST,
    M_ALTC,
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

  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,           KC_PSCR, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_BSLS, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LGUI, KC_SPC,                    KC_BSPC, FN,      KC_SLSH
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    _______, _______,  _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, QK_BOOT,                            KC_EQL,  KC_LBRC, KC_RBRC, XDJ,     XCH,     XCJ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPLY, KC_MPRV, KC_MNXT, M_USER,  M_HOST,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XSH,     XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, M_EMAIL, RGB_TOG, M_ALTC,  QWERTY,  UC_NEXT, _______,          _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XZH,     _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};
// Runs just one time when the keyboard initializes.
// void matrix_init_user(void) {
// };

// Runs constantly in the background, in a loop.
// void matrix_scan_user(void) {
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool capitalize;
    static bool alternate;
    if (record->event.pressed) {
        switch(keycode) {
            case M_EMAIL:
                SEND_STRING("pavle.portic@theedgeofrage.com");
                return false;
            case M_USER:
                SEND_STRING("TheEdgeOfRage");
                return false;
            case M_HOST:
                SEND_STRING("theedgeofrage.com");
                return false;
            case M_ALTC:
                capitalize = false;
                alternate = !alternate;
                return false;
        }

        if (alternate && keycode >= KC_A && keycode <= KC_Z) {
            if (capitalize)
                register_code(KC_LSFT);

            register_code(keycode);
            unregister_code(keycode);

            if (capitalize)
                unregister_code(KC_LSFT);

            capitalize = !capitalize;
            return false;
        }
    }

    return true;
}
