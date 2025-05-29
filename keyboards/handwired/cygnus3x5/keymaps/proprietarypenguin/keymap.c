#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_caps[] = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_apos[] = {RALT_T(KC_L), RGUI_T(KC_SCLN), COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_caps, CW_TOGG),
    COMBO(combo_apos, KC_QUOTE), 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,                                 KC_U, KC_I, KC_O, KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,       KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
        KC_Z, KC_X, KC_C, KC_V, KC_B,                                       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                    MO(5), LT(1,KC_TAB), KC_ENT,                            KC_SPC, LT(2,KC_BSPC), MO(4)
    ),

    [1] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,              KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
        KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_TRNS,    KC_GRAVE, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
                      KC_TRNS, KC_TRNS, KC_ENT,         KC_SPC, MO(3), KC_RALT
    ),

    [2] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_ESC, KC_NO, KC_TRNS, KC_NO, KC_TRNS,         KC_VOLU, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_VOLD, KC_MPRV, KC_MNXT, KC_TRNS, KC_MPLY,
                      KC_LGUI, MO(3), KC_BSPC,          KC_SPC, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT(
        QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO,            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                      KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO
    ),

    [4] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOTE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_ENT,
                      KC_TRNS, KC_TRNS, KC_NO,          KC_NO, KC_NO, KC_TRNS
    ),

    [5] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_ACL0,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,  	MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, MS_ACL1,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, MS_ACL2,
		      KC_TRNS, KC_TRNS, KC_TRNS,	MS_BTN1, MS_BTN2, MS_BTN3

   ),
};

