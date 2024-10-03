#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "features/layer_lock.h"

#define LAYOUT LAYOUT_split_3x6_3


#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

#define ALPHA _LAYER0
#define SYM _LAYER1
#define NUM _LAYER2
#define NAV _LAYER3


/* Custom keycodes */

enum custom_keycodes {
    LLOCK = SAFE_RANGE,
};

enum td_keycodes {
    ESC_LOCK,
};

#define LL_LAYER SYM
#define LTHUMB LT(NUM, KC_SPC)
#define RTHUMB OSL(SYM)


/* Tap dance definitions */

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);
void el_finished(tap_dance_state_t *state, void *user_data);
void el_reset(tap_dance_state_t *state, void *user_data);


/* Combos */

enum combos {
    COMBO_J,
    COMBO_Q,
    COMBO_X,
    COMBO_Z,

    COMBO_UNDS,
    COMBO_ASTR,
    COMBO_F12,
    // COMBO_ESC,

    COMBO_OSL_FN,
    COMBO_GUI,
    COMBO_BOOT,

    COMBO_LLEAD,
    COMBO_RLEAD,

    COMBO_OSM_LCTL,
    COMBO_OSM_LSHFT_A,
    COMBO_OSM_LSHFT_S,
    COMBO_OSM_LALT,
    COMBO_OSM_RCTL,
    COMBO_OSM_RSHFT_A,
    COMBO_OSM_RSHFT_S,
    COMBO_OSM_RALT,

    COMBO_BSPC_LHS,
    COMBO_ENT_LHS,
};

const uint16_t PROGMEM j_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM x_combo[] = {KC_V, KC_C, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_C, KC_D, COMBO_END};

const uint16_t PROGMEM unds_combo[] = {KC_H, KC_BSPC, COMBO_END};
const uint16_t PROGMEM astr_combo[] = {KC_PLUS, KC_MINS, COMBO_END};
const uint16_t PROGMEM f12_combo[] = {KC_F1, KC_F2, COMBO_END};
// const uint16_t PROGMEM esc_combo[] = {KC_W, KC_F, KC_P, COMBO_END};

const uint16_t PROGMEM osl_fun_combo[] = {LTHUMB, RTHUMB, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {LTHUMB, KC_G, COMBO_END};
const uint16_t PROGMEM boot_combo[] = {KC_V, KC_D, KC_H, KC_ENT, COMBO_END};

const uint16_t PROGMEM llead_combo[] = {LCTL_T(KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM rlead_combo[] = {RCTL_T(KC_N), KC_M, COMBO_END};

const uint16_t PROGMEM osm_lctl_combo[] = {LCTL_T(KC_T), KC_P, COMBO_END};
const uint16_t PROGMEM osm_lshfta_combo[] = {LSFT_T(KC_S), KC_F, COMBO_END};
const uint16_t PROGMEM osm_lshfts_combo[] = {KC_RBRC, KC_RPRN, COMBO_END};
const uint16_t PROGMEM osm_lalt_combo[] = {LALT_T(KC_R), KC_W, COMBO_END};
const uint16_t PROGMEM osm_rctl_combo[] = {RCTL_T(KC_N), KC_L, COMBO_END};
const uint16_t PROGMEM osm_rshfta_combo[] = {RSFT_T(KC_E), KC_U, COMBO_END};
const uint16_t PROGMEM osm_rshfts_combo[] = {KC_ASTR, KC_PLUS, COMBO_END};
const uint16_t PROGMEM osm_ralt_combo[] = {RALT_T(KC_I), KC_Y, COMBO_END};

const uint16_t PROGMEM bspc_lhs_combo[] = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM ent_lhs_combo[] = {KC_V, KC_D, COMBO_END};

combo_t key_combos[] = {
    [COMBO_J] = COMBO(j_combo, KC_J),
    [COMBO_Q] = COMBO(q_combo, KC_Q),
    [COMBO_X] = COMBO(x_combo, KC_X),
    [COMBO_Z] = COMBO(z_combo, KC_Z),

    [COMBO_UNDS] = COMBO(unds_combo, KC_UNDS),
    [COMBO_ASTR] = COMBO(astr_combo, KC_ASTR),
    [COMBO_F12] = COMBO(f12_combo, KC_F12),
    // [COMBO_ESC] = COMBO(esc_combo, KC_ESC),
    
    [COMBO_OSL_FN]  = COMBO(osl_fun_combo, OSL(NAV)),
    [COMBO_GUI] = COMBO(gui_combo, KC_LGUI),
    [COMBO_BOOT] = COMBO(boot_combo, QK_BOOT),

    [COMBO_LLEAD] = COMBO(llead_combo, QK_LEAD),
    [COMBO_RLEAD] = COMBO(rlead_combo, QK_LEAD),

    [COMBO_OSM_LCTL] = COMBO(osm_lctl_combo, OSM(MOD_LCTL)),
    [COMBO_OSM_LSHFT_A] = COMBO(osm_lshfta_combo, OSM(MOD_LSFT)),
    [COMBO_OSM_LSHFT_S] = COMBO(osm_lshfts_combo, OSM(MOD_LSFT)),
    [COMBO_OSM_LALT] = COMBO(osm_lalt_combo, OSM(MOD_LALT)),
    [COMBO_OSM_RCTL] = COMBO(osm_rctl_combo, OSM(MOD_RCTL)),
    [COMBO_OSM_RSHFT_A] = COMBO(osm_rshfta_combo, OSM(MOD_RSFT)),
    [COMBO_OSM_RSHFT_S] = COMBO(osm_rshfts_combo, OSM(MOD_RSFT)),
    [COMBO_OSM_RALT] = COMBO(osm_ralt_combo, OSM(MOD_RALT)),

    [COMBO_BSPC_LHS] = COMBO(bspc_lhs_combo, KC_BSPC),
    [COMBO_ENT_LHS] = COMBO(ent_lhs_combo, KC_ENT),
};


/* Key mapping */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT(KC_NO, KC_NO, KC_W, KC_F, KC_P, KC_NO, KC_NO, KC_L, KC_U, KC_Y, KC_NO, KC_NO, KC_NO, KC_A, LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G, KC_M, RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), KC_O, KC_NO, KC_NO, KC_NO, KC_V, KC_C, KC_D, KC_B, KC_K, KC_H, KC_BSPC, KC_ENT, KC_NO, KC_NO, KC_NO, LTHUMB, KC_NO, KC_NO, RTHUMB, KC_NO),
    [_LAYER1] = LAYOUT(KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_GRV, KC_NO, KC_NO, KC_DQUO, KC_ASTR, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_QUES, KC_LPRN, KC_RPRN, LCTL_T(KC_SCLN), KC_AT, KC_AMPR, RCTL_T(KC_EQL), KC_PLUS, KC_MINS, KC_EXLM, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_COLN, KC_HASH, KC_BSLS, KC_QUOT, KC_COMM, KC_DOT, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO),
    [_LAYER2] = LAYOUT(KC_NO, KC_NO, TD(ESC_LOCK), KC_DEL, KC_TAB, KC_NO, KC_NO, KC_PLUS, KC_MINS, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_1, LALT_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4), KC_5, KC_6, RCTL_T(KC_7), RSFT_T(KC_8), RALT_T(KC_9), KC_0, KC_NO, KC_NO, KC_NO, LCTL(KC_Z), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Y), KC_DLR, KC_SPC, KC_BSPC, KC_DOT, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO),
    [_LAYER3] = LAYOUT(KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_MPLY, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, KC_LEFT, LALT_T(KC_DOWN), LSFT_T(KC_UP), LCTL_T(KC_RGHT), KC_PSCR, KC_F10, RCTL_T(KC_F4), RSFT_T(KC_F5), RALT_T(KC_F6), LLOCK, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP, DM_PLY1, DM_REC1, KC_F11, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO)    
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
    else if (row == 3) return NONE;
    else if (row <= 6) return RIGHT;
    else return NONE;
}

bool is_thumb_key(keyrecord_t* key_record) {
    uint8_t row = key_record->event.key.row;
    return row == 7 || row == 3;
}


/* Tap dance functions */

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (!state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    }
    else return TD_UNKNOWN;
}

static td_tap_t el_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void el_finished(tap_dance_state_t *state, void *user_data) {
    el_tap_state.state = cur_dance(state);
    switch (el_tap_state.state) {
        case TD_SINGLE_HOLD:
            tap_code16(LGUI(KC_L));
            break;
        case TD_DOUBLE_HOLD:
            tap_code16(LGUI(KC_ESC));
            break;
        default:
            break; 
    }
}
void el_reset(tap_dance_state_t *state, void *user_data) {
    el_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [ESC_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, el_finished, el_reset),
};


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

/* QMK functions */

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) return false;
    if (!process_layer_lock(keycode, record, LLOCK)) return false;

    if (keycode == TD(ESC_LOCK)) {
        if (record->event.pressed) tap_code(KC_ESC);
    }

    return true; // Process all other keycodes normally
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (combo->keycode) {
        case KC_X:
        case KC_Q:
            return COMBO_TERM + 20; // Increase combo term for ring keys.
    }

    return COMBO_TERM;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    Side side = side_of_key(record);
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;

    if ((side == LEFT && col <= 1) || (side == RIGHT && col >= 4))
        return TAPPING_TERM + 150; // Increase tapping term for pinky keys.
    else if ((side == LEFT && col == 2) || (side == RIGHT && col == 3))
        if (row == 0) return TAPPING_TERM - 85; // Decrease tapping term for esc_lock tap dance.
        else return TAPPING_TERM + 70; // Increase tapping term for ring keys.
    else if (is_thumb_key(record))
        return TAPPING_TERM + 30; // Increase tapping term for thumb keys.
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

bool get_retro_tapping(uint16_t keycode, keyrecord_t* record) {
    return !is_thumb_key(record) && keycode != LSFT_T(KC_S);
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case QK_LEAD:
            return true;

        default:
            return false;  // Deactivate Caps Word.
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

    return false;
}
