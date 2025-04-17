#include QMK_KEYBOARD_H


enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

bool set_scrolling = false;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 8.0
#define SCROLL_DIVISOR_V 8.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            // Toggle set_scrolling when DRAG_SCROLL key is pressed or released
            set_scrolling = record->event.pressed;
            break;
        default:
            break;
    }
    return true;
}

/*// Function to handle layer changes and disable drag scrolling when not in AUTO_MOUSE_DEFAULT_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    if (get_highest_layer(state) != AUTO_MOUSE_DEFAULT_LAYER) {
        set_scrolling = false;
    }
    return state;
}*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,                                 KC_U, KC_I, KC_O, KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,       KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
        KC_Z, KC_X, KC_C, KC_V, KC_B,                                       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                    MO(5), LT(1,KC_TAB), KC_ENT,                          KC_SPC, LT(2,KC_BSPC), MO(4)
    ),

    [1] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,              KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
        KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_TRNS,    KC_GRAVE, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
                      KC_TRNS, KC_TRNS, KC_ENT,         KC_SPC, MO(3), KC_RALT
    ),

    [2] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_ESC, KC_NO, KC_TRNS, KC_NO, KC_TRNS,          KC_VOLU, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_VOLD, KC_MPRV, KC_MNXT, KC_TRNS, KC_MPLY,
                      KC_LGUI, MO(3), KC_BSPC,          KC_SPC, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT(
        QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                      KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO
    ),

    [4] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOTE,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_ENT,
                      KC_LGUI, KC_LCTL, KC_NO,          KC_NO, KC_NO, KC_TRNS
    ),

    [5] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              MS_BTN1, MS_BTN2, MS_BTN3, KC_NO, KC_NO,
        KC_NO, DRAG_SCROLL, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		      KC_TRNS, KC_TRNS, KC_TRNS,	MS_BTN1, MS_BTN2, MS_BTN3

   ),
};

