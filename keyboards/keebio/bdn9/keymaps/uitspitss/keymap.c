/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines for task manager and such
#define KC_CHRM    KC_F21  // open Google Chrome
#define KC_SHFT    KC_F22  // open Shift
#define KC_ITRM    KC_F23  // open iTerm
#define KC_VSCD    KC_F24  // open VSCode
#define KC_SPRV    LALT(LGUI(KC_UP))  // Previous Account/App in Shift
#define KC_SNXT    LALT(LGUI(KC_DOWN))  // Next Account/App in Shift
#define KC_SPTB    LGUI(LSFT(KC_GRV)) // Previous Tab
#define KC_SNTB    LGUI(KC_GRV)  // Next Tab
#define KC_SEML    LGUI(KC_1)
#define KC_SCAL    LGUI(KC_2)
#define KC_SDRV    LGUI(KC_3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
        KC_MUTE, LT(1,KC_CHRM), KC_MPLY,
        KC_SEML, KC_SCAL, KC_SDRV,
        KC_SPRV, KC_SHFT, KC_SNXT
    ),
    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        _______, _______, _______,
        KC_SPTB, RGB_MOD, KC_SNTB,
        KC_ITRM, KC_VSCD, KC_CHRM
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
}
