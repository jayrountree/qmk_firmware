/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

// Macros
enum custom_keycodes {
    CLIP = SAFE_RANGE,
    LOCK,
	SPOT, /*
	QC1,
	QC2,
	QC3,
	QC4,
	*/
};

// Macro Definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CLIP: //takes a clip
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_F10)SS_UP(X_LALT)SS_UP(X_F10));
		}
        break;
		
    case LOCK: //locks the screen
        if (record->event.pressed) {
			SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_L)SS_UP(X_LGUI)SS_UP(X_L));
		}
        break;
	
	case SPOT: //opens spotify
        if (record->event.pressed) {
			SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_3)SS_UP(X_LGUI)SS_UP(X_3));
		}
        break;
		
	//Quickchats 
	/*
    case QC1: 
        if (record->event.pressed) {
           SEND_STRING("tSheesh!"SS_TAP(X_ENT));
        }
        break;
	case QC2: 
        if (record->event.pressed) {
           SEND_STRING("tJust like coach drew it up!"SS_TAP(X_ENT));
        }
        break;
	case QC3: 
        if (record->event.pressed) {
           SEND_STRING("tYou're throwing!"SS_TAP(X_ENT));
        }
        break;
	case QC4: 
        if (record->event.pressed) {
           SEND_STRING("tYou better scramble like an egg before you get folded like a omelet!"SS_TAP(X_ENT));
        }
	*/
        break;
    }
    return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_MPRV, KC_MNXT, KC_MPLY, SPOT,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        TO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   TO(2),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, RGB_TOG, RGB_VAI, RGB_VAD, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        TO(0),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, KC_END,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD,RGB_SPI
    ),
	
	[2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS,          _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, LOCK,    _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, KC_N,    _______, _______, _______, CLIP,             _______, KC_UP,   KC_END,
        _______, _______, _______,                            _______,                            _______, TO(0),   _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch(biton32(layer_state)){
        case 1:
            if (clockwise){
                tap_code16(KC_MNXT);
            } else {
                tap_code16(KC_MPRV);
            }
            break;
        default:
            if (clockwise) {
                tap_code16(KC_VOLU);
            } else {
                tap_code16(KC_VOLD);
            }
            break;
        }
    }
    return true;
}
#endif // ENCODER_ENABLE

// RGB LED layout

// led number, function of the key

//  67, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      69, Prt       Rotary(Mute)   68, Side led 12
//  70, Side led 02    1, ~        7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       78, (=+)     85, BackSpc   72, Del        71, Side led 13
//  73, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       89, ]}       93, \|        75, PgUp       74, Side led 14
//  76, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"                    96, Enter     86, PgDn       77, Side led 15
//  80, Side led 05    4, Sh_L     10, Z       16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?                    90, Sh_R     94, Up        82, End        81, Side led 16
//  83, Side led 06    5, Ct_L     11,Win_L    17, Alt_L                              33, SPACE                              49, Alt_R    55, FN                    65, Ct_R     95, Left     97, Down      79, Right      84, Side led 17
//  87, Side led 07                                                                                                                                                                                                        88, Side led 18
//  91, Side led 08


void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	switch(get_highest_layer(layer_state)) {  // special handling per layer
		case 1:  //layer 1
			RGB_MATRIX_INDICATOR_SET_COLOR(3, 100, 100, 100);
			break;
		case 2:  //layer 2
			RGB_MATRIX_INDICATOR_SET_COLOR(55, 100, 100, 100);
			break;
		default: //layer 0
			// rgb_matrix_set_color_all(0, 0, 0); //turn off rgb as default
			break;
		break;
	}
}

