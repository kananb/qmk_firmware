#include QMK_KEYBOARD_H
#include "features/achordion.h"

#define LAYOUT LAYOUT_split_3x6_3

/* Combos */
enum combos {
    COMBO_OSL_FN,
    COMBO_TO_FN,
    COMBO_GUI,
};

const uint16_t PROGMEM osl_fun_combo[] = {OSL(1), KC_SPC, COMBO_END};
const uint16_t PROGMEM to_fun_combo[] = {OSL(2), KC_ENT, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {OSL(2), KC_G, COMBO_END};

combo_t key_combos[] = {
    [COMBO_OSL_FN]  = COMBO(osl_fun_combo, OSL(3)),
    [COMBO_TO_FN] = COMBO(to_fun_combo, TO(3)),
    [COMBO_GUI] = COMBO(gui_combo, KC_LGUI),
};


/* Key mapping */
#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT(KC_NO, KC_NO, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_NO, KC_NO, KC_Q, KC_A, LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G, KC_M, RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), KC_O, KC_QUOT, KC_NO, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, OSL(1), OSL(2), KC_ENT, KC_SPC, KC_NO),
    [_LAYER1] = LAYOUT(KC_NO, KC_NO, KC_ESC, KC_DEL, KC_TAB, LGUI(KC_ESC), KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO, KC_NO, KC_UNDS, KC_1, LALT_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4), KC_5, KC_6, RCTL_T(KC_7), RSFT_T(KC_8), RALT_T(KC_9), KC_0, KC_NO, KC_NO, LCTL(KC_Z), LCTL(KC_Y), LCTL(KC_C), LCTL(KC_V), LGUI(KC_L), CW_TOGG, KC_BSPC, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_NO),
    [_LAYER2] = LAYOUT(KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_GRV, KC_BSLS, KC_PIPE, KC_DQUO, KC_ASTR, KC_SLSH, KC_NO, KC_NO, KC_UNDS, KC_DLR, KC_LPRN, KC_RPRN, LCTL_T(KC_SCLN), KC_AT, KC_AMPR, RCTL_T(KC_EQL), KC_PLUS, KC_MINS, KC_EXLM, KC_TILD, KC_NO, KC_PERC, KC_LCBR, KC_RCBR, KC_COLN, KC_CIRC, KC_HASH, KC_QUOT, KC_LT, KC_GT, KC_QUES, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO),
    [_LAYER3] = LAYOUT(KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_F10, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, TO(0), KC_LEFT, LALT_T(KC_DOWN), LSFT_T(KC_UP), LCTL_T(KC_RGHT), KC_PSCR, KC_F11, RCTL_T(KC_F4), RSFT_T(KC_F5), RALT_T(KC_F6), KC_NO, QK_BOOT, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_F12, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO) 
};


/* QMK functions */

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    return true; // Process all other keycodes normally
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // TODO: Probably want to change this to use the row of the key instead.
        case LGUI_T(KC_Z):
        case RGUI_T(KC_SLSH):
        case LGUI_T(KC_DLR):
        case RGUI_T(KC_PERC):
        case LGUI_T(KC_WBAK):
            return TAPPING_TERM + 70; // Increase tapping term for pinky keys.
        case LALT_T(KC_X):
        case RALT_T(KC_DOT):
        case LALT_T(KC_LCBR):
        // case RALT_T(KC_GT): same key code as KC_DOT
        case LALT_T(KC_D):
        case LALT_T(KC_PGDN):
        case RALT_T(KC_F3):
            return TAPPING_TERM + 40; // Increase tapping term for ring keys.
    }

    return TAPPING_TERM; // Otherwise, force hold and disable key repeating.
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // TODO: Change these when I update the NAV layer.
        case LGUI_T(KC_LEFT):
        case LALT_T(KC_DOWN):
        case LSFT_T(KC_UP):
        case LCTL_T(KC_RGHT):
            return QUICK_TAP_TERM; // Allow quick taps for arrow keys.
        default:
            return 0; // Otherwise disable quick taps.
    }
}


/* Achordion functions */

void matrix_scan_user(void) {
    achordion_task();
}

typedef enum Side {
    NONE,
    LEFT,
    RIGHT,
} Side;

Side side_of_key(keyrecord_t* key_record) {
    // Left alpha coordinates
    const uint8_t left_alpha_start[2] = {0, 1};
    const uint8_t left_alpha_end[2]   = {2, 5};

    if (key_record->event.key.row >= left_alpha_start[0] && key_record->event.key.row <= left_alpha_end[0]) {
        if (key_record->event.key.col >= left_alpha_start[1] && key_record->event.key.col <= left_alpha_end[1]) {
            return LEFT;
        }
    }

    // Right alpha coordinates
    const uint8_t right_alpha_start[2] = {4, 0};
    const uint8_t right_alpha_end[2]   = {6, 5};

    if (key_record->event.key.row >= right_alpha_start[0] && key_record->event.key.row <= right_alpha_end[0]) {
        if (key_record->event.key.col >= right_alpha_start[1] && key_record->event.key.col <= right_alpha_end[1]) {
            return RIGHT;
        }
    }

    return NONE;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    Side tap_hold_side = side_of_key(tap_hold_record);
    Side other_side = side_of_key(other_record);

    return tap_hold_side == NONE || tap_hold_side != other_side;
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LCTL:
        case MOD_RCTL:
            return true; // Eagerly apply shift and control mods.
    }

    return false; // Otherwise, apply mods on release.
}
