#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |  T   |  (   |   |  )   |  Y   |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | LCtrl|   A  |   S  |   D  |   F  |  G   |  [   |   |  ]   |  H   |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | LSft |   Z  |   X  |   C  |   V  |  B   |  =   |   |  -   |  N   |   M  |   ,  |   .  |   /  | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      | Muhen| META | LGUI | S&S  |   | A&T  | RCtrl| SYMB |  Hen |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    S(KC_9),               S(KC_0),    KC_Y,     KC_U,    KC_I,    KC_O,   KC_P,  KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_LBRC,               KC_RBRC,    KC_H,     KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_EQL,                KC_MINS,    KC_N,     KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LANG2,MO(META), LGUI_T(KC_ESC), SFT_T(KC_SPC),  RALT_T(KC_TAB), RCTL_T(KC_ENT), MO(SYMB), KC_LANG1, XXXXXXX, XXXXXXX, XXXXXXX \
  ),


  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  ~   |   1  |   2  |   3  |   4  |   5  |  (   |   |  )   |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | LCtrl|      | Home | PgDn | PgUp | End  |  [   |   |  ]   | Left | Down |  Up  | Right|      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | LSft |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   |  F7  |  F8  |  F9  | F10  | F11  | F12  | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      | META | LGUI | S&S  |   | RAlt | RCtrl| SYMB |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   S(KC_9),    S(KC_0),     KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, \
    _______, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______,    _______,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,        KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_RSFT, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,   _______,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |   !  |   @  |   #  |   $  |   %  |  (   |   |  )   |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | LCtrl|   ~  | Home | PgDn | PgUp | End  |  [   |   |  ]   | Left | Down |  Up  | Right|      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | LSft |  F1  |  F2  |  F3  |  F4  |   +  |  F6  |   |  F7  |   _  |  F9  | F10  | F11  | F12  | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      | META | LGUI | S&S  |   | RAlt | RCtrl| SYMB |      |      |      |Reset |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    XXXXXXX, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_9),   S(KC_0),  S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_BSPC), \
    _______, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,   _______,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_RSFT, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,   _______,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  ),
};
