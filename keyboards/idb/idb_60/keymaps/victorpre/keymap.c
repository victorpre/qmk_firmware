#include QMK_KEYBOARD_H
#define _______ KC_TRNS

enum keyboard_layers {
  _BL = 0, // Base Layer
  _FL,      // Function Layer
  _CL      // Control Layer
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BL] = LAYOUT(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    LT(_CL, KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FL),
    KC_LALT, _______, KC_LGUI,                                     KC_SPC,                             KC_RALT, KC_MENU, KC_RCTL
  ),
  [_FL] = LAYOUT(
	RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______,                                     _______,                            _______, _______, _______
  ),
  [_CL] = LAYOUT(
	KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, _______, _______,          _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______,                                     _______,                            _______, _______, _______
  )

};

// Layer LED indicators

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, 1)) {
        _idb_60_esc_led_on();
    } else {
        _idb_60_esc_led_off();
    }
	
	return state;
}
