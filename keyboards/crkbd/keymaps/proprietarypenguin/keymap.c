/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

//extern uint8_t is_master;

enum crkbd_layers {
    _QWERTY,
    _QWERTYHR,
    _LOWER,
    _RAISE,
    _ADJUST,
    _VIM,
    _MOUSE,
};

/*enum custom_keycodes {
    CAFF_ON = SAFE_RANGE,
    CAFF_OFF,
};*/

/*bool caffeine_mode = false;
uint16_t caffeine_timer = 0;*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LCTL_T(KC_ESC), KC_A, KC_S, KC_D, LT(6,KC_F), KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT), KC_LALT, LT(2,KC_TAB), LGUI_T(KC_ENT), KC_SPC, LT(3,KC_BSPC), MO(5)),
	[_QWERTYHR] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LCTL_T(KC_ESC), LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT), KC_LALT, LT(2,KC_TAB), KC_ENT, KC_SPC, LT(3,KC_BSPC), MO(5)),
	[_LOWER] = LAYOUT_split_3x6_3(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_INS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_END, KC_PSCR, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_SPC, MO(4), KC_RALT),
	[_RAISE] = LAYOUT_split_3x6_3(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_TRNS, KC_ESC, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_VOLU, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_MPRV, KC_MNXT, KC_HOME, KC_END, KC_MPLY, KC_LGUI, MO(4), KC_BSPC, KC_SPC, KC_TRNS, KC_TRNS),
	[_ADJUST] = LAYOUT_split_3x6_3(RGB_MOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, AG_SWAP, AG_NORM, KC_NO, KC_NO, KC_NO, KC_NO, TG(1), RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(0), KC_LGUI, KC_TRNS, KC_ENT, KC_SPC, KC_TRNS, KC_TRNS),
	[_VIM] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(6), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_NO, KC_TRNS, KC_LGUI, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_TRNS),
    [_MOUSE] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_WH_U, KC_BTN3, KC_NO, KC_ACL0, KC_NO, KC_ESC, KC_NO, KC_NO, KC_BTN4, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL1, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_D, KC_BTN5, KC_NO, KC_ACL2, KC_NO, KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN4)
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
   return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define _QWERTY 0
#define _QWERTYHR 1
#define _RAISE 2
#define _LOWER 3
#define _ADJUST 4
#define _VIM 5
#define _MOUSE 6

void oled_print_layer_state(void) {
    // Print current layer
    oled_write_P(PSTR("Layer:"), false);
    switch (layer_state) {
        case _QWERTY:
            oled_write_P(PSTR("Base"), false);
            break;
        case _QWERTYHR:
            oled_write_P(PSTR("HRMods"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj"), false);
            break;
        case _VIM:
            oled_write_P(PSTR("Vim"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
}

void oled_print_os_state(void) {
    oled_write_P(PSTR("\nMODE:"), false);
    //oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lalt_lgui) {
        oled_write_P(PSTR("macOS"), false);
    } else {
        oled_write_P(PSTR("Linux"), false);
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name);
}

void oled_render_keylog(void) {
    oled_write_P(PSTR("\n"), false);
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_print_layer_state();
        oled_print_os_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE

