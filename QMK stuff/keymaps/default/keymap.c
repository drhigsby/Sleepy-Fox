/* Copyright 2021 drhigsby
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

enum layers{
  _BASE,
  _NUM,
  _FN
};

#define NUM MO(_NUM)
#define FN MO(_FN)
#define ZZZ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T,              KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,               KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B,              KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
                        KC_LALT, KC_LCTL, NUM,   KC_CAPS,   KC_SPC, KC_RGUI, FN
  ),


    [_NUM] = LAYOUT(
       ZZZ, KC_1, KC_2, KC_3, KC_4, KC_5,                            KC_6, KC_7, KC_8, KC_9, KC_0, ZZZ,
       ZZZ, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL, ZZZ,
       ZZZ, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_HOME,               KC_END, KC_PIPE, KC_BSLS, KC_DQUO, KC_QUOT, ZZZ,
                     KC_PGUP, KC_PGDN, ZZZ,             ZZZ,         ZZZ, KC_PGUP, KC_PGDN
  ),

    [_FN] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, 
        ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, 
        ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ, ZZZ
  )

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    return true;
}
