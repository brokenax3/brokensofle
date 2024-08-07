#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ  // if you remove this it causes issues - needs better
                           // guarding

#define TAPPING_FORCE_HOLD
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#define TAPPING_TERM 200
#endif
// #define ENCODER_DIRECTION_FLIP
#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4
#define ENCODER_RESOLUTION_RIGHT 2
// #define ENCODER_RESOLUTIONS {4, 2}

#define RGBLIGHT_SLEEP
//
#define RGBLIGHT_LAYERS

/* ws2812 RGB LED */
#define WS2812_DI_PIN D3

// #ifdef RGB_MATRIX_ENABLE
// #define RGBLED_NUM 36  // Number of LEDs
// #define RGB_MATRIX_LED_COUNT RGBLED_NUM
// #endif

#ifdef RGBLIGHT_ENABLE
// #undef RGBLED_NUM

// #define RGBLIGHT_EFFECT_PLAIN
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE

// #define RGBLED_NUM 70
#undef RGBLED_SPLIT
#define RGBLED_SPLIT { 35, 35 }  // haven't figured out how to use this yet

// #define RGBLED_NUM 30
#define RGBLIGHT_LIMIT_VAL 100
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_KEYPRESSES  // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of
// keypresses)
#define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 //
// limits the number of LEDs to process in an animation per task run (increases
// keyboard responsiveness) #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits
// in milliseconds how frequently an animation will update the LEDs. 16 (16ms)
// is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS \
    120  // limits maximum brightness of LEDs to 150 out of 255. Higher may
         // cause the controller to crash.

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT

#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10

#endif
