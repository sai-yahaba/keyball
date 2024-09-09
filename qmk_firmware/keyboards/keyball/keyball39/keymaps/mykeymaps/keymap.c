/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q        , KC_W    , KC_E  , KC_R      , KC_T        ,                               KC_Y          , KC_U       , KC_I      , KC_O   , RCTL_T(KC_P)    ,
    LCTL_T(KC_A), KC_S    , KC_D  , KC_F, KC_G  ,                               KC_H    , KC_J , LT(5,KC_K), KC_L   , KC_ENT          ,
    LSFT_T(KC_Z), KC_X    , KC_C  , LT(2,KC_V)      , LT(3,KC_B)        ,                               LT(3,KC_N)          , LT(2,KC_M)       , KC_COMM   , KC_DOT , RSFT_T(KC_MINS) ,
    KC_LSFT     , KC_LALT , KC_TAB ,KC_LALT      ,LCMD_T(KC_SPC) , LT(1,KC_LNG2), LT(1,KC_LNG1), RCMD_T(KC_SPC)  , _______      , _______     , _______  , KC_RSFT
  ),

  [1] = LAYOUT_universal(
    KC_ESC  , KC_7 , KC_8   , KC_9 , S(KC_EQL) ,                  _______ , KC_HOME , KC_UP   , KC_END  , KC_BSPC ,
    KC_TAB  , KC_4 , KC_5   , KC_6 , KC_MINS   ,                  S(KC_COMM) , KC_LEFT , KC_DOWN , KC_RGHT , KC_DEL  ,
    KC_LSFT , KC_1 , KC_2   , KC_3 , S(KC_8)   ,                  _______ , KC_PGUP , _______   , KC_PGDN , KC_SLSH ,
    KC_LCAP , KC_0 , KC_SLSH, KC_LALT, _______    , LCMD(KC_SPC) , RCMD(KC_SPC) , _______ , _______   , _______   , _______   , KC_BSLS
  ),

  [2] = LAYOUT_universal(
    KC_ESC  , KC_F7 , KC_F8 , KC_F9 , KC_F10 ,                     _______    , _______         , RCTL(KC_UP)   , _______         , RGUI(RALT(KC_4)) ,
    KC_TAB  , KC_F4 , KC_F5 , KC_F6 , KC_F11 ,                     KC_LPAD  , RCTL(KC_LEFT) , RCTL(KC_DOWN) , RCTL(KC_RGHT) , RGUI(RALT(KC_3)) ,
    _______   , KC_F1 , KC_F2 , KC_F3 , KC_F12 ,                     KC_MCTL  , _______         , _______         , _______         ,            _______ ,
    _______   , _______ , _______ , _______ ,_______  , KC_LALT , KC_RALT ,_______    , _______         , _______         , _______         ,            _______
  ),

  [3] = LAYOUT_universal(
    S(KC_1)             , S(KC_2) , S(KC_3) , S(KC_4)     , S(KC_5)     ,                 S(KC_6) , S(KC_7)   , S(KC_8)   , S(KC_MINS) , S(KC_EQL)  ,
    KC_GRV     , KC_BSLS    , KC_LBRC     , KC_RBRC     , KC_SLSH    ,            KC_MINS , S(KC_9)   , S(KC_0)   , KC_SCLN    , KC_QUOT    ,
    S(KC_GRV)   , S(KC_BSLS)    , S(KC_LBRC)  , S(KC_RBRC)  , S(KC_SLSH)  ,              KC_EQL  , S(KC_COMM), S(KC_DOT) , S(KC_SCLN) , S(KC_QUOT) ,
    KC_KB_MUTE          , _______   , _______   , _______       , _______       , _______ , _______ , _______   , _______     , _______     , _______      , _______
  ),

  [4] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , KC_MS_BTN3    , _______    , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                     _______ , KC_MS_BTN1 , MO(5) , KC_MS_BTN2    , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______   , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______    , _______    , _______
  ),

  [5] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                     _______ , KC_MS_BTN1 , _______ , KC_MS_BTN2 , KC_RSFT ,
    _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______   , _______  , KC_RSFT,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 5
    keyball_set_scroll_mode(get_highest_layer(state) == 5);
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    keyball_handle_auto_mouse_layer_change(state);
#endif
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

/*my settings*/
