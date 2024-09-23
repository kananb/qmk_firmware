#include QMK_KEYBOARD_H

#define LAYOUT LAYOUT_split_3x6_3

/* Custom Keys */
enum custom_keycods {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,

    /// Homerow mods
    // Alpha layer
    CKC_R, // Alt
    CKC_S, // Shift
    CKC_T, // Ctrl
    CKC_N, // Ctrl
    CKC_E, // Shift
    CKC_I, // Alt

    // Num layer
    CKC_2, // Alt
    CKC_3, // Shift
    CKC_4, // Ctrl
    CKC_7, // Ctrl
    CKC_8, // Shift
    CKC_9, // Alt

    // Symbol layer
    CKC_SCLN, // Ctrl
    CKC_EQL, // Ctrl

    // Nav layer
    CKC_DOWN, // Alt
    CKC_UP, // Shift
    CKC_RGHT, // Ctrl
    CKC_F4, // Ctrl
    CKC_F5, // Shift
    CKC_F6, // Alt

    SMTD_KEYCODES_END,
};

#include "sm_td.h"


/* Combos */
enum combos {
    COMBO_OSL_FN,
    COMBO_GUI,
};

const uint16_t PROGMEM osl_fun_combo[] = {OSL(1), KC_SPC, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {OSL(2), KC_G, COMBO_END};

combo_t key_combos[] = {
    [COMBO_OSL_FN]  = COMBO(osl_fun_combo, OSL(3)),
    [COMBO_GUI] = COMBO(gui_combo, KC_LGUI),
};


/* Key mapping */

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT(KC_NO, KC_NO, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_NO, KC_NO, KC_Q, KC_A, CKC_R, CKC_S, CKC_T, KC_G, KC_M, CKC_N, CKC_E, CKC_I, KC_O, KC_QUOT, KC_NO, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, OSL(1), OSL(2), QK_LEAD, KC_SPC, KC_NO),
    [_LAYER1] = LAYOUT(KC_NO, KC_NO, KC_ESC, KC_DEL, KC_TAB, LGUI(KC_ESC), KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO, KC_NO, CW_TOGG, KC_1, CKC_2, CKC_3, CKC_4, KC_5, KC_6, CKC_7, CKC_8, CKC_9, KC_0, KC_NO, KC_NO, LCTL(KC_Z), LGUI(KC_L), LCTL(KC_C), LCTL(KC_V), LGUI(KC_V), KC_NO, KC_BSPC, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_NO),
    [_LAYER2] = LAYOUT(KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_GRV, KC_BSLS, KC_PIPE, KC_DQUO, KC_ASTR, KC_SLSH, KC_NO, KC_NO, KC_UNDS, KC_DLR, KC_LPRN, KC_RPRN, CKC_SCLN, KC_AT, KC_AMPR, CKC_EQL, KC_PLUS, KC_UNDS, KC_EXLM, KC_TILD, KC_NO, KC_PERC, KC_LCBR, KC_RCBR, KC_COLN, KC_CIRC, KC_HASH, KC_QUOT, KC_LT, KC_GT, KC_QUES, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO),
    [_LAYER3] = LAYOUT(KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_F10, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, TG(3), KC_LEFT, CKC_DOWN, CKC_UP, CKC_RGHT, KC_PSCR, KC_F11, CKC_F4, CKC_F5, CKC_F6, KC_NO, QK_BOOT, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_F12, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO) 
};

/* QMK functions */

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    return true; // Process all other keycodes normally
}

/* SM_TD functions */
void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_R, KC_R, KC_LALT, 2)
        SMTD_MTE(CKC_S, KC_S, KC_LSFT, 2)
        SMTD_MT(CKC_T, KC_T, KC_LCTL, 2)
        SMTD_MT(CKC_N, KC_N, KC_RCTL, 2)
        SMTD_MTE(CKC_E, KC_E, KC_RSFT, 2)
        SMTD_MT(CKC_I, KC_I, KC_RALT, 2)

        SMTD_MT(CKC_2, KC_2, KC_LALT, 2)
        SMTD_MT(CKC_3, KC_3, KC_LSFT, 2)
        SMTD_MT(CKC_4, KC_4, KC_LCTL, 2)
        SMTD_MT(CKC_7, KC_7, KC_RCTL, 2)
        SMTD_MT(CKC_8, KC_8, KC_RSFT, 2)
        SMTD_MT(CKC_9, KC_9, KC_RALT, 2)

        SMTD_MT(CKC_SCLN, KC_SCLN, KC_LCTL, 2)
        SMTD_MT(CKC_EQL, KC_EQL, KC_RCTL, 2)

        SMTD_MT(CKC_DOWN, KC_DOWN, KC_LALT, 2)
        SMTD_MT(CKC_UP, KC_UP, KC_LSFT, 2)
        SMTD_MT(CKC_RGHT, KC_RGHT, KC_LCTL, 2)
        SMTD_MT(CKC_F4, KC_F4, KC_RCTL, 2)
        SMTD_MT(CKC_F5, KC_F5, KC_RSFT, 2)
        SMTD_MT(CKC_F6, KC_F6, KC_RALT, 2)
    }
}
