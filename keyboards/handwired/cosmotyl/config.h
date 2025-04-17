#pragma once

#define EE_HANDS // Store which side I am in EEPROM

/* Keyboard matrix assignments */
#define MATRIX_ROW_PINS { GP29, GP28, GP27, GP26 }
#define MATRIX_COL_PINS { GP4, GP5, GP6, GP7, GP8 }

/* Encoders */
//#define ENCODERS_PAD_A { GP21, GP20 }
//#define ENCODERS_PAD_B { GP18, GP19 }

/* Homerow Modifiers */
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
//#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM_PER_KEY

/* Trackball */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP14
#define SPI_MISO_PIN GP12
#define SPI_MOSI_PIN GP11
#define POINTING_DEVICE_CS_PIN GP10
#define ROTATIONAL_TRANSFORM_ANGLE -80 // Optional: Rotates the trackball
#define POINTING_DEVICE_TASK_THROTTLE_MS 1 // Limits the frequency that the sensor is polled for motion.
#define POINTING_DEVICE_INVERT_X // Optional: Inverts trackball X
#define PMW33XX_CPI 900
#define PMW33XX_LIFTOFF_DISTANCE 0x03

/* Reset */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
// This LED blinks when entering bootloader
