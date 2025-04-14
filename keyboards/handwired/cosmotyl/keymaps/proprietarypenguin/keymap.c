#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,                                 KC_U, KC_I, KC_O, KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,       KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
        KC_Z, KC_X, KC_C, KC_V, KC_B,                                       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                    KC_LALT, LT(1,KC_TAB), KC_ENT,                          KC_SPC, LT(2,KC_BSPC), MO(4)
    ),

    [_LOWER] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,              KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,            KC_F12, KC_END, KC_PSCR, KC_PGUP, KC_PGDN,
                      KC_TRNS, KC_TRNS, KC_ENT,         KC_SPC, MO(3), KC_RALT
    ),

    [_RAISE] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS,          KC_VOLU, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_VOLD, KC_MPRV, KC_MNXT, KC_HOME, KC_END,
                      KC_LGUI, MO(3), KC_BSPC,          KC_SPC, KC_TRNS, KC_TRNS
    ),

    [_ADJUST] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                      KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO
    ),


	[_VIM] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_NO,
                      KC_LGUI, KC_LCTL, KC_NO,          KC_NO, KC_NO, KC_TRNS
    ),

};

#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3
#define _VIM 4
//#define _MOUSE 5

