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

enum encoder_names {
    _LEFT,
    _RIGHT,
    _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Scroll Up/Dn  | Knob 2: Volume    | Knob 3: Scroll Le/Ri |
        | Press: Previous Media | Press: Play/Pause | Press: Next Media    |
        | Mute Spotify          | Mute all          | RGB Mode             |
        | Discord Mute          | Discord Deafen    | _blank_              |
     */
    [0] = LAYOUT(KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_F14, KC_MUTE, RGB_MOD, KC_F15, KC_F16, ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case _LEFT:
            if (clockwise) {
                tap_code(KC_MS_WH_UP);
            } else {
                tap_code(KC_MS_WH_DOWN);
            }
            break;
        case _MIDDLE:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case _RIGHT:
            if (clockwise) {
                tap_code(KC_MS_WH_RIGHT);
            } else {
                tap_code(KC_MS_WH_LEFT);
            }
            break;
    }
    return true;
}