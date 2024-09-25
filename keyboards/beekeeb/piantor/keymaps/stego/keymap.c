#include QMK_KEYBOARD_H
#include "features/achordion.h"

#define LAYOUT LAYOUT_split_3x6_3


/* Combos */

enum combos {
    COMBO_OSL_FN,
    COMBO_GUI,
    COMBO_LLEAD,
    COMBO_RLEAD,

    COMBO_OSM_LCTL,
    COMBO_OSM_LSHFT,
    COMBO_OSM_LALT,
    COMBO_OSM_RCTL,
    COMBO_OSM_RSHFT,
    COMBO_OSM_RALT,
};

const uint16_t PROGMEM osl_fun_combo[] = {OSL(1), LT(2,KC_SPC), COMBO_END};
const uint16_t PROGMEM gui_combo[] = {OSL(1), KC_G, COMBO_END};
const uint16_t PROGMEM llead_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM rlead_combo[] = {KC_N, KC_M, COMBO_END};

const uint16_t PROGMEM osm_lctl_combo[] = {LCTL_T(KC_T), KC_P, COMBO_END};
const uint16_t PROGMEM osm_lshft_combo[] = {LSFT_T(KC_S), KC_F, COMBO_END};
const uint16_t PROGMEM osm_lalt_combo[] = {LALT_T(KC_R), KC_W, COMBO_END};
const uint16_t PROGMEM osm_rctl_combo[] = {RCTL_T(KC_N), KC_L, COMBO_END};
const uint16_t PROGMEM osm_rshft_combo[] = {RSFT_T(KC_E), KC_U, COMBO_END};
const uint16_t PROGMEM osm_ralt_combo[] = {RALT_T(KC_I), KC_Y, COMBO_END};

combo_t key_combos[] = {
    [COMBO_OSL_FN]  = COMBO(osl_fun_combo, OSL(3)),
    [COMBO_GUI] = COMBO(gui_combo, KC_LGUI),
    [COMBO_LLEAD] = COMBO(llead_combo, QK_LEAD),
    [COMBO_RLEAD] = COMBO(rlead_combo, QK_LEAD),

    [COMBO_OSM_LCTL] = COMBO(osm_lctl_combo, OSM(MOD_LCTL)),
    [COMBO_OSM_LSHFT] = COMBO(osm_lshft_combo, OSM(MOD_LSFT)),
    [COMBO_OSM_LALT] = COMBO(osm_lalt_combo, OSM(MOD_LALT)),
    [COMBO_OSM_RCTL] = COMBO(osm_rctl_combo, OSM(MOD_RCTL)),
    [COMBO_OSM_RSHFT] = COMBO(osm_rshft_combo, OSM(MOD_RSFT)),
    [COMBO_OSM_RALT] = COMBO(osm_ralt_combo, OSM(MOD_RALT)),
};


/* Key mapping */

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT(KC_NO, KC_NO, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_NO, KC_NO, KC_Q, KC_A, LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G, KC_M, RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), KC_O, KC_QUOT, KC_NO, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, OSL(1), KC_NO, KC_NO, LT(2,KC_SPC), KC_NO),
    [_LAYER1] = LAYOUT(KC_NO, KC_NO, KC_ESC, KC_DEL, KC_TAB, LGUI(KC_ESC), KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO, KC_NO, KC_UNDS, KC_1, LALT_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4), KC_5, KC_6, RCTL_T(KC_7), RSFT_T(KC_8), RALT_T(KC_9), KC_0, CW_TOGG, KC_NO, LCTL(KC_Z), KC_ENT, LCTL(KC_C), LCTL(KC_V), LCTL(KC_Y), QK_LEAD, KC_BSPC, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO),
    [_LAYER2] = LAYOUT(KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_GRV, KC_BSLS, KC_PIPE, KC_DQUO, KC_ASTR, KC_SLSH, KC_NO, KC_NO, KC_UNDS, KC_DLR, KC_LPRN, KC_RPRN, LCTL_T(KC_SCLN), KC_AT, KC_AMPR, RCTL_T(KC_EQL), KC_PLUS, KC_MINS, KC_EXLM, KC_TILD, KC_NO, KC_PERC, KC_LCBR, KC_RCBR, KC_COLN, KC_CIRC, KC_HASH, KC_QUOT, KC_LT, KC_GT, KC_QUES, KC_NO, KC_NO, KC_SPC, KC_NO, KC_NO, KC_TRNS, KC_NO),
    [_LAYER3] = LAYOUT(KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_F10, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, TO(0), KC_LEFT, LALT_T(KC_DOWN), LSFT_T(KC_UP), LCTL_T(KC_RGHT), KC_PSCR, KC_F11, RCTL_T(KC_F4), RSFT_T(KC_F5), RALT_T(KC_F6), KC_NO, QK_BOOT, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_F12, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO)
};


/* Helper functions */

typedef enum Side {
    NONE,
    LEFT,
    RIGHT,
} Side;

Side side_of_key(keyrecord_t* key_record) {
    uint8_t row = key_record->event.key.row;

    if (row <= 2) return LEFT;
    else if (row <= 6) return RIGHT;
    else return NONE;
}


/* QMK functions */

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    return true; // Process all other keycodes normally
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    Side side = side_of_key(record);
    uint8_t col = record->event.key.col;

    if ((side == LEFT && col <= 1) || (side == RIGHT && col >= 4))
        return TAPPING_TERM + 70; // Increase tapping term for pinky keys.
    else if ((side == LEFT && col == 2) || (side == RIGHT && col == 3))
        return TAPPING_TERM + 40; // Increase tapping term for ring keys.
    else return TAPPING_TERM; // Otherwise, force hold and disable key repeating.
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

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    Side tap_hold_side = side_of_key(tap_hold_record);
    Side other_side = side_of_key(other_record);
    uint8_t tap_hold_row = tap_hold_record->event.key.row;
    uint8_t other_row = other_record->event.key.row;

    if (layer_state_is(_LAYER1) && tap_hold_side == LEFT && tap_hold_row != other_row)
        return true; // Allow chords between rows on the left side of layer 1

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
