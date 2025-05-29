#pragma once

#define EE_HANDS // Store which side I am in EEPROM

/* Keyboard matrix assignments */
#define MATRIX_ROW_PINS { GP28, GP27, GP26, GP15 }
#define MATRIX_COL_PINS { GP4, GP5, GP6, GP7, GP8 }

/* Encoders */
//#define ENCODERS_PAD_A { GP21, GP20 }
//#define ENCODERS_PAD_B { GP18, GP19 }

/* Homerow Modifiers */
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
//#define IGNORE_MOD_TAP_INTERRUPT
#define QUICK_TAP_TERM 60 
//#define TAPPING_TERM_PER_KEY

/* Reset */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
// This LED blinks when entering bootloader
