#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _FN1,
  _NAV
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC,  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    KC_PGUP, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_PGDN, KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
             KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FN1),
             KC_LALT, KC_LGUI, KC_SPC,  MO(_FN1),                        LT(_NAV, KC_SPC),           KC_RALT,          KC_LGUI
  ),

  [_FN1] = LAYOUT(
    RGB_TOG,  VLK_TOG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_DEL,
    RGB_MOD,  _______,  _______, KC_UP,  _______, _______, _______,          RGB_SAI, RGB_HUI, RGB_VAI, _______, _______, _______, _______, _______,
    RGB_RMOD, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          RGB_SAD, RGB_HUD, RGB_VAD, _______, _______, _______,          _______,
              _______, BL_INC,  BL_DEC,  BL_TOGG, BL_BRTG, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
              _______,          _______, _______, _______,                            _______,          _______,          RESET
  ),

  [_NAV] = LAYOUT(
    RGB_TOG,  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_DEL,
    RGB_MOD,  _______,  _______, _______,  _______, _______, _______,        RGB_SAI, RGB_HUI, RGB_VAI, _______, _______, _______, _______, _______,
    RGB_RMOD, _______, _______, _______, _______, _______, _______,          KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,          _______,
              _______, BL_INC,  BL_DEC,  BL_TOGG, BL_BRTG, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
              _______,          _______, _______, _______,                            _______,          _______,          _______
  )
};

#ifdef USE_LEDS_FOR_LAYERS
// example of how to use LEDs as layer indicators
static uint8_t top = 1;
static uint8_t middle = 0;
static uint8_t bottom = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
    top = middle = bottom = 0;
    switch (get_highest_layer(state)) {
    case _BASE:
        top = 1;
        break;
    case _FN1:
        middle = 1;
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
}

// override kb level function
bool led_update_user(led_t usb_led) {
    writePin(B1, !top);
    writePin(B2, !middle);
    writePin(B3, !bottom);
    return false; // we are using LEDs for something else override kb
}
#endif
