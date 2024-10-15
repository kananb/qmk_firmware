#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/flow.h"

#define LAYOUT LAYOUT_split_3x6_3


#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4
#define _LAYER5 5
#define _LAYER6 6

#define ALPHA _LAYER0
#define SYM_BRC _LAYER1
#define SYM_OPS _LAYER2
#define NUM _LAYER3
#define FUN _LAYER4
#define NAV _LAYER5
#define MOD _LAYER6


/* Custom keycodes */

enum custom_keycodes {
    LLOCK = SAFE_RANGE,

    OSL_NAV,
    OSL_SYM_BRC,
    OSL_SYM_OPS,
    OSL_NUM,
    OSL_FUN,
    OSL_MOD,

    CK_QU,
};


/* Flow configuration */

const uint16_t flow_config[FLOW_COUNT][2] = {
    {OSL_MOD, KC_LCTL},
    {OSL_MOD, KC_LSFT},
    {OSL_MOD, KC_LALT},
    {OSL_MOD, KC_LGUI},
    {OSL_MOD, KC_RCTL},
    {OSL_MOD, KC_RSFT},
    {OSL_MOD, KC_RALT},
    {OSL_MOD, KC_RGUI},

    {OSL_NAV, KC_RCTL},
    {OSL_NAV, KC_RSFT},
    {OSL_NAV, KC_RALT},
    {OSL_NAV, KC_RGUI},
};

const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OSL_NAV, NAV},
    {OSL_SYM_BRC, SYM_BRC},
    {OSL_SYM_OPS, SYM_OPS},
    {OSL_NUM, NUM},
    {OSL_FUN, FUN},
    {OSL_MOD, MOD},
};

#define LTHUMB OSL_MOD
#define RTHUMB KC_SPC


/* Combos */

enum combos {
    COMBO_J,
    COMBO_Q,
    COMBO_QU,
    COMBO_X,
    COMBO_Z,
    COMBO_UNDS,
    COMBO_QUOT,
    COMBO_CARET,

    COMBO_OSL_NAV,
    COMBO_OSL_SYM_BRC,
    COMBO_OSL_SYM_OPS,
    COMBO_OSL_NUM,
    COMBO_OSL_FUN,

    COMBO_BOOT,

    COMBO_BSPC_LHS,
    COMBO_ENT_LHS,
};

const uint16_t PROGMEM j_combo[] = {KC_G, KC_K, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_W, KC_D, COMBO_END};
const uint16_t PROGMEM qu_combo[] = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM x_combo[] = {KC_M, KC_B, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_V, KC_D, COMBO_END};
const uint16_t PROGMEM unds_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM caret_combo[] = {KC_W, KC_V, KC_D, COMBO_END};

const uint16_t PROGMEM osl_nav_combo[] = {LTHUMB, RTHUMB, COMBO_END};
const uint16_t PROGMEM osl_sym_brc_combo[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM osl_sym_ops_combo[] = {KC_E, KC_COMM, COMBO_END};
const uint16_t PROGMEM osl_num_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM osl_fun_combo[] = {KC_S, KC_V, COMBO_END};

const uint16_t PROGMEM boot_combo[] = {KC_W, KC_D, KC_H, KC_DOT, COMBO_END};

const uint16_t PROGMEM bspc_lhs_combo[] = {KC_Y, KC_S, COMBO_END};
const uint16_t PROGMEM ent_lhs_combo[] = {KC_T, KC_P, COMBO_END};

combo_t key_combos[] = {
    [COMBO_J] = COMBO(j_combo, KC_J),
    [COMBO_Q] = COMBO(q_combo, KC_Q),
    [COMBO_QU] = COMBO(qu_combo, CK_QU),
    [COMBO_X] = COMBO(x_combo, KC_X),
    [COMBO_Z] = COMBO(z_combo, KC_Z),
    [COMBO_UNDS] = COMBO(unds_combo, KC_UNDS),
    [COMBO_QUOT] = COMBO(quot_combo, KC_QUOT),
    [COMBO_CARET] = COMBO(caret_combo, KC_CIRC),
    
    [COMBO_OSL_NAV]  = COMBO(osl_nav_combo, OSL_NAV),
    [COMBO_OSL_SYM_BRC] = COMBO(osl_sym_brc_combo, OSL_SYM_BRC),
    [COMBO_OSL_SYM_OPS] = COMBO(osl_sym_ops_combo, OSL_SYM_OPS),
    [COMBO_OSL_NUM] = COMBO(osl_num_combo, OSL_NUM),
    [COMBO_OSL_FUN] = COMBO(osl_fun_combo, OSL_FUN),
    
    [COMBO_BOOT] = COMBO(boot_combo, QK_BOOT),

    [COMBO_BSPC_LHS] = COMBO(bspc_lhs_combo, KC_BSPC),
    [COMBO_ENT_LHS] = COMBO(ent_lhs_combo, KC_ENT),
};


/* Key mapping */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT(KC_NO, KC_NO, KC_L, KC_Y, KC_P, KC_NO, KC_NO, KC_F, KC_O, KC_U, KC_NO, KC_NO, KC_NO, KC_C, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_A, KC_NO, KC_NO, KC_NO, KC_W, KC_V, KC_D, KC_K, KC_B, KC_H, KC_COMM, KC_DOT, KC_NO, KC_NO, KC_NO, LTHUMB, KC_NO, KC_NO, RTHUMB, KC_NO),
    [_LAYER1] = LAYOUT(KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_DQUO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_QUES, KC_LPRN, KC_RPRN, KC_SCLN, KC_DLR, KC_NO, KC_TRNS, KC_GRV, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_COLN, KC_AT, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO),
    [_LAYER2] = LAYOUT(KC_NO, KC_NO, KC_SLSH, KC_ASTR, KC_AMPR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL, KC_HASH, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LT, KC_GT, KC_PIPE, KC_PERC, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO),
    [_LAYER3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_NO, KC_EQL, KC_ASTR, KC_PLUS, KC_TRNS, KC_NO, KC_0, KC_4, KC_5, KC_6, KC_DOT, KC_NO, KC_NO, KC_NO, KC_SLSH, KC_MINS, KC_TRNS, KC_NO, KC_COLN, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO),
    [_LAYER4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_F10, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_F12, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO),
    [_LAYER5] = LAYOUT(KC_NO, KC_NO, KC_END, KC_HOME, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_VOLU, KC_VOLD, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PSCR, LLOCK, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_ENT, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO),
    [_LAYER6] = LAYOUT(KC_NO, KC_NO, KC_ESC, KC_DEL, KC_TAB, KC_NO, KC_NO, KC_NO, CW_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, LCTL(KC_A), QK_REP, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, KC_NO, KC_NO, KC_NO, LCTL(KC_Z), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Y), QK_AREP, KC_BSPC, QK_LEAD, KC_ENT, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO) 
};


/* QMK functions */

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_layer_lock(keycode, record, LLOCK)) return false;
    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;

    if (keycode == CK_QU) {
        if (record->event.pressed) {
            register_code(KC_Q);
            register_code(KC_U);
        } else {
            unregister_code(KC_Q);
            unregister_code(KC_U);
        }
    }

    return true; // Process all other keycodes normally
}

void matrix_scan_user(void) {
    flow_matrix_scan();
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    uint16_t layer = get_highest_layer(layer_state|default_layer_state);
    switch (combo_index) {
        case COMBO_J:
        case COMBO_QU:
        case COMBO_X:
        case COMBO_Z:
        case COMBO_UNDS:
        case COMBO_QUOT:
            return layer == ALPHA;
        case COMBO_CARET:
            return layer == SYM_OPS;
        case COMBO_BSPC_LHS:
        case COMBO_ENT_LHS:
            return layer == MOD;
    }

    return true;
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (combo->keycode) {
        case CK_QU:
            return COMBO_TERM + 20; // Increase combo term for ring keys.
    }

    return COMBO_TERM;
}


/* Leader key functions */

void leader_start_user(void) {
    // Do nothing
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_W)) {
        tap_code(KC_ESC);
        tap_code16(KC_COLN);
        tap_code(KC_W);
        tap_code(KC_ENT);
    }
}
