#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_UNDERGLOW(hsv) \
    {1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_LAYER_ID(hsv) \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {1, 6, hsv}, \
    {35+1, 6, hsv}, \
    {7, 4, hsv}, \
    {35+ 7, 4, hsv}, \
    {25, 2, hsv}, \
    {35+ 25, 2, hsv}

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _DEFAULTS = 0,
    _COLEMAK,
    _QWERTY,
    _UPPER,
    _LOWER,
    _FUNCTION,
    _MOUSE,
};

// enum custom_keycodes {
//     KC_COLEMAK,
//     KC_QWERTY,
//     KC_PRVWD,
//     KC_NXTWD,
//     KC_LSTRT,
//     KC_LEND,
//     KC_DLINE
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAK] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_DEL, KC_LSFT, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_MUTE, KC_TAB, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LALT, KC_LGUI, KC_SPC, MO(2), KC_ESC, KC_ENT, MO(3), KC_RCTL, KC_RSFT, MO(5)),
	[_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_TAB, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LALT, KC_LGUI, KC_SPC, MO(2), KC_ESC, KC_ENT, MO(3), KC_RCTL, KC_RALT, MO(5)),
	[_UPPER] = LAYOUT(KC_TRNS, LGUI(KC_F1), LGUI(KC_F2), LGUI(KC_F3), LGUI(KC_F4), LGUI(KC_F5), LGUI(KC_F6), LGUI(KC_F7), LGUI(KC_F8), LGUI(KC_F9), LGUI(KC_F10), LGUI(KC_F11), KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_SCLN, LGUI(KC_F12), KC_TRNS, KC_PIPE, KC_UNDS, KC_MINS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_GRV, KC_EQL, KC_BSLS, KC_PIPE, KC_TRNS, KC_NUBS, KC_EQL, KC_PLUS, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_INS, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS),
	[_LOWER] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_CAPS, KC_PMNS, KC_P7, KC_P8, KC_P9, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_PPLS, KC_P4, KC_P5, KC_P6, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_CUT, KC_COPY, KC_NO, KC_PSTE, KC_TRNS, KC_TRNS, KC_P0, KC_P1, KC_P2, KC_P3, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[_FUNCTION] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_NO, DF(0), DF(1), KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO, QK_BOOT, KC_F12, KC_NO, BL_DEC, BL_INC, BL_TOGG, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[_MOUSE] = LAYOUT(KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_MS_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_NO, KC_NO, KC_ACL0, KC_TRNS, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_BTN4, KC_BTN1, KC_BTN3, KC_BTN5, KC_NO, KC_ACL1, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL2, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS)
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_UNDERGLOW(HSV_RED)
);

const rgblight_segment_t PROGMEM layer_colemak_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_UNDERGLOW(HSV_PINK)
);

// _UPPER,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_upper_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_TEAL)

);
// _LOWER,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_lower_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_BLUE)

    );
// _FUNCTION,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_function_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_PURPLE)
);

// _MOUSE   // light up top row
const rgblight_segment_t PROGMEM layer_mouse_lights[] =   RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_GREEN),
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    layer_colemak_lights,
    layer_qwerty_lights,
    layer_upper_lights,
    layer_lower_lights,
    layer_function_lights,
    layer_mouse_lights,
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAK));
    rgblight_set_layer_state(1, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));

    rgblight_set_layer_state(2, layer_state_cmp(state, _UPPER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(4, layer_state_cmp(state, _FUNCTION));
    rgblight_set_layer_state(5, layer_state_cmp(state, _MOUSE));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_mode(10);// haven't found a way to set this in a more useful way
}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    // if (keymap_config.swap_lctl_lgui) {
    //     oled_write_ln_P(PSTR("MAC"), false);
    // } else {
    //     oled_write_ln_P(PSTR("WIN"), false);
    // }
    //
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Function"), false);
            break;
        case _UPPER:
            oled_write_P(PSTR("Upper"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _UPPER, _MOUSE);
}


#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    return true;
}

#endif
