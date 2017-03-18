#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_french_osx.h"

/* Layers */
enum {
    BASE = 0, // default layer
    SYMB     // symbols
};

enum {
    GM_2 = 1,
    GM_5,
    GM_6,
    GM_7,
    GM_8,
    GM_9,
    GM_0,
    GM_PC_MAC,
    GM_OP,
    GM_DOL,
    GM_CP,
    GM_STAR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |  1/& | 2/\  | 3/"  |  4/' |  5/` |  F3  |           |  F4  |  6/- |  7/~ | 8/_  |  9/# |  0/| | PC/MAC |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   A  |   Z  |   E  |   R  |   T  |   [  |           |  ]   |   Y  |   U  |   I  |   O  |   P  |  +/=   |
 * |--------+------+------+------+------+------|   (  |           |  )   |------+------+------+------+------+--------|
 * | Ctrl   |   Q  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   M  |  Ctrl  |
 * |--------+------+------+------+------+------|  {   |           |  }   |------+------+------+------+------+--------|
 * | LShift |   W  |   X  |   C  |   V  |   B  |      |           |      |   N  |  ?/, | ./;  |  //: |   Up | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Symb | >/<  | €/$  | Alt  | Hyper|                                       | Hyper| %/ * |Left  | Down | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------| Super  |Enter |
 *                                 |      |ace   |  End |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
         KC_ESC,           KC_1,        M(GM_2),    KC_3,    KC_4,   M(GM_5),          KC_F3,
         KC_TAB,           FR_A,           FR_Z,    KC_E,    KC_R,      KC_T,       M(GM_OP),
       KC_LCTRL,           FR_Q,           KC_S,    KC_D,    KC_F,      KC_G,
        KC_LSFT,           FR_W,           KC_X,    KC_C,    KC_V,      KC_B,        FR_LCBR,
         TG(SYMB),        FR_AT,      M(GM_DOL), KC_LALT, ALL_T(KC_NO),

                                                                           KC_DELT,    KC_NO,
                                                                                     KC_HOME,
                                                                  KC_SPC,  KC_BSPC,   KC_END,

        // right hand
         KC_F4,        M(GM_6),         M(GM_7), M(GM_8), M(GM_9),   M(GM_0),   M(GM_PC_MAC),
      M(GM_CP),           KC_Y,            KC_U,    KC_I,    KC_O,      KC_P,         FR_EQL,
                          KC_H,            KC_J,    KC_K,    KC_L,      FR_M,        KC_LCTL,
       FR_RCBR,           KC_N,         FR_COMM, FR_SCLN, FR_COLN,     KC_UP,        KC_RSFT,
                          ALL_T(KC_NO),  M(GM_STAR), KC_LEFT,        KC_DOWN,        KC_RGHT,

         KC_NO,   KC_NO,
         KC_PGUP,
         KC_PGDN, KC_LGUI, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,FR_EXLM,FR_AT,  FR_LCBR,FR_RCBR,FR_PIPE,KC_TRNS,
       KC_TRNS,FR_HASH,FR_DLR, FR_LPRN,FR_RPRN,FR_GRV,
       KC_TRNS,FR_PERC,FR_CIRC,FR_LBRC,FR_RBRC,FR_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   FR_7,   FR_8,    FR_9,    FR_ASTR, KC_F12,
                KC_DOWN, FR_4,   FR_5,    FR_6,    FR_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, FR_1,   FR_2,    FR_3,    FR_BSLS, KC_TRNS,
                    KC_TRNS,FR_DOT,  FR_0,    FR_EQL,         RESET,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [SYMB] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{

    static bool mac_mode = true;

  // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;

        case GM_2:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    register_code (KC_2);
                    unregister_code (KC_2);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_LALT);
                    register_code(FR_COLN);
                    unregister_code(FR_COLN);
                    unregister_code(KC_LALT);
                    unregister_code(KC_LSFT);
                }
            }
            break;

        case GM_5:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    register_code (KC_5);
                    unregister_code (KC_5);
                } else {
                    register_code(FR_GRV);
                    unregister_code(FR_GRV);

                }
            }
            break;

        case GM_6:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    register_code (KC_6);
                    unregister_code (KC_6);
                } else {
                    register_code(FR_MINS);
                    unregister_code(FR_MINS);

                }
            }
            break;

        case GM_7:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    register_code (KC_7);
                    unregister_code (KC_7);
                } else {
                    register_code(KC_LALT);
                    register_code(KC_N);
                    unregister_code(KC_N);
                    unregister_code(KC_LALT);

                }
            }
            break;

        case GM_8:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    register_code (KC_8);
                    unregister_code (KC_8);
                } else {
                    register_code(KC_LSFT);
                    register_code(FR_MINS);
                    unregister_code(FR_MINS);
                    unregister_code(KC_LSFT);

                }
            }
            break;

        case GM_9:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    register_code (KC_9);
                    unregister_code (KC_9);
                } else {
                    if (mac_mode) {
                        register_code(KC_LSFT);
                        register_code(FR_LESS);
                        unregister_code(FR_LESS);
                        unregister_code(KC_LSFT);
                    } else {
                        register_code(KC_RALT);
                        register_code(KC_3);
                        unregister_code(KC_3);
                        unregister_code(KC_RALT);
                    }
                }
            }
            break;

        case GM_0:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    register_code (KC_0);
                    unregister_code (KC_0);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_LALT);
                    register_code(KC_L);
                    unregister_code(KC_L);
                    unregister_code(KC_LALT);
                    unregister_code(KC_LSFT);

                }
            }
            break;

        case GM_PC_MAC:
            if (record->event.pressed) {
                mac_mode = !mac_mode;
            }
            break;

        case GM_OP:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    // [
                    register_code(KC_LALT);
                    register_code(KC_5);
                    unregister_code(KC_5);
                    unregister_code(KC_LALT);
                } else {
                    // (
                    register_code(KC_5);
                    unregister_code(KC_5);
                }
            }
            break;

        case GM_CP:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    // ]
                    register_code(KC_LALT);
                    register_code(KC_MINS);
                    unregister_code(KC_MINS);
                    unregister_code(KC_LALT);
                } else {
                    // )
                    register_code(KC_MINS);
                    unregister_code(KC_MINS);
                }
            }
            break;

        case GM_DOL:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    // €
                    unregister_code(KC_LSFT);
                    register_code (KC_RALT);
                    register_code(FR_DLR);
                    unregister_code(FR_DLR);
                    unregister_code (KC_RALT);
                    register_code(KC_LSFT);
                } else {
                    // $
                    register_code(FR_DLR);
                    unregister_code(FR_DLR);

                }
            }
            break;

        case GM_STAR:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    // %
                    register_code (KC_LSFT);
                    register_code(KC_QUOT);
                    unregister_code (KC_QUOT);
                    unregister_code(KC_LSFT);
                } else {
                    // *
                    register_code(KC_LSFT);
                    register_code(FR_DLR);
                    unregister_code(FR_DLR);
                    unregister_code(KC_LSFT);

                }
            }
            break;
    }

    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
