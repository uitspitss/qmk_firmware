#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define KC_SCSTFL LGUI(KC_PERC)
#define KC_SCSTCB LCTL(LGUI(KC_DLR))
#define KC_WNHLFL LALT(LGUI(KC_LEFT))
#define KC_WNHLFR LALT(LGUI(KC_RIGHT))
#define KC_WNFLSC LALT(LGUI(LSFT(KC_F)))
#define KC_WNTHDL LALT(LCTL(KC_LEFT))
#define KC_WNTHDR LALT(LCTL(KC_RIGHT))
#define KC_WNUNDO LALT(LGUI(KC_Z))
#define KC_SFTSPC LSFT(KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER|Cmd/Esc| Sft/ |    | Alt/ |Ctr/Ent|RAISE|
 *                  `-------------| Spc  |    | Tab  |-------------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
       LOWER, GUI_T(KC_ESC), SFT_T(KC_SPC),         ALT_T(KC_TAB), CTL_T(KC_ENT), RAISE          \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   `  |      |      |      |   [  |           |   ]  |      |      |   \  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |   =  |           |   -  |      |      |      | Bspc |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER|Cmd/Esc| Sft/ |    | Alt/ |Ctr/Ent|RAISE|
 *                  `-------------| Spc  |    | Tab  |-------------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_GRV,  _______, _______, _______, KC_LBRC,      KC_RBRC,KC_LANG1,KC_LANG2, KC_BSLS, KC_QUOT, \
  _______, _______, _______, _______, KC_EQL,       KC_MINS, _______, _______, _______, KC_BSPC, \
                    _______, _______,KC_SFTSPC,      _______, _______, _______                   \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   ~  |      |      |      |   {  |           |   }  |      |      |   |  |   "  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |   +  |           |   _  | Left | Down |  Up  |Right |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER|Cmd/Esc| Sft/ |    | Alt/ |Ctr/Ent|RAISE|
 *                  `-------------| Spc  |    | Tab  |-------------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_TILD,KC_WNFLSC,KC_WNHLFL,KC_WNHLFR,KC_LCBR,    KC_RCBR, _______, _______, KC_PIPE, KC_DQT,  \
  KC_LALT,KC_WNUNDO,KC_WNTHDL,KC_WNTHDR,KC_PLUS,    KC_UNDS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
                    _______, _______, _______,      _______, _______, _______                    \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |SCRSHT|      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|RGBTOG|RGBMOD|RGBHUI|RGBHUD|           |RGBVAI|RGBVAD|RGBSAI|RGBSAD|      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |LOWER|Cmd/Esc| Sft/ |    | Alt/ |Ctr/Ent|RAISE|
 *                  `-------------| Spc  |    | Tab  |-------------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
  KC_F11,  KC_F12,KC_SCSTCB,KC_SCSTFL,_______,      _______, _______, _______, _______, _______, \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,      RGB_VAI, RGB_VAD, RGB_SAI, RGB_SAD, _______, \
                    _______, _______, _______,      _______, _______, _______                    \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
