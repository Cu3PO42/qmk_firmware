#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  DE_LSPO,
  DE_RSPC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    DE_CIRC,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 TG(5),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           DE_MINS,        
    KC_TRANSPARENT, KC_X,           KC_V,           KC_L,           KC_C,           KC_W,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_K,           KC_H,           KC_G,           KC_F,           KC_Q,           DE_SS,          
    MO(1),          KC_U,           KC_I,           KC_A,           KC_E,           KC_O,           KC_TAB,                                                                         KC_MEH,         KC_S,           KC_N,           KC_R,           KC_T,           KC_D,           LT(1,DE_Y),     
    KC_LSHIFT,      LCTL_T(DE_UE),  LALT_T(DE_OE),  DE_AE,          KC_P,           DE_Z,                                           KC_B,           KC_M,           KC_COMMA,       RALT_T(KC_DOT), RCTL_T(KC_J),   KC_RSHIFT,      
    KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        OSL(6),         MO(2),          KC_TRANSPARENT,                                                                                                 KC_ESCAPE,      LSFT(DE_GRV),   DE_GRV,         KC_RALT,        KC_RCTRL,       KC_TRANSPARENT, 
    LSFT_T(KC_SPACE),LT(1,KC_DELETE),KC_LGUI,                        MO(2),          LT(1,KC_BSPACE),RSFT_T(KC_ENTER)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, DE_UNDS,        DE_LBRC,        DE_RBRC,        DE_CIRC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_EXLM,        DE_LESS,        DE_MORE,        DE_EQL,         DE_AMPR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, DE_QST,         DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        DE_GRV,                                         DE_PLUS,        DE_PERC,        DE_DQOT,        DE_QUOT,        DE_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, DE_RING,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DE_SLSH,        DE_ASTR,        DE_MINS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PGUP,        KC_BSPACE,      KC_UP,          KC_DELETE,      KC_PGDOWN,      KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_7,        KC_KP_8,        KC_KP_9,        DE_PLUS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_COMMA,       KC_DOT,         
    KC_TRANSPARENT, KC_ESCAPE,      KC_TAB,         KC_INSERT,      KC_ENTER,       LCTL(KC_Z),                                     DE_COLN,        KC_KP_1,        KC_KP_2,        KC_KP_3,        DE_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_0,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_UE,          
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           DE_OE,          DE_AE,          
    KC_TRANSPARENT, DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         RESET,          
    KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_MEDIA_PREV_TRACK,KC_TRANSPARENT,                                 KC_TRANSPARENT, RGB_MOD,        RGB_SPD,        RGB_SPI,        RGB_VAD,        RGB_VAI,        AU_TOG,         
    KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,                                                                 KC_TRANSPARENT, RGB_SLD,        KC_MS_BTN1,     KC_MS_BTN2,     RGB_HUD,        RGB_HUI,        MU_TOG,         
    KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,                                RGB_TOG,        TOGGLE_LAYER_COLOR,HSV_0_255_255,  RGB_SAD,        RGB_SAI,        MU_MOD,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, HSV_86_255_128, HSV_172_255_255,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {31,255,255}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,255}, {0,0,255}, {31,255,255}, {0,205,155}, {0,205,155}, {0,183,238}, {0,0,255}, {31,255,255}, {31,255,255}, {0,183,238}, {0,183,238}, {0,0,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,255}, {0,183,238}, {0,205,155}, {0,205,155}, {0,183,238}, {31,255,255} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {31,255,255}, {0,0,0}, {0,0,0}, {0,183,238}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {0,183,238}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {15,166,195}, {15,166,195}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,205,155}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,183,238}, {31,255,255}, {0,0,0}, {0,0,0}, {15,166,195}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {0,205,155}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {15,166,195}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {0,183,238}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {31,255,255}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {31,255,255}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,205,155}, {0,183,238}, {0,205,155}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,205,155}, {0,0,0}, {0,0,0}, {0,205,155}, {0,183,238}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DE_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case DE_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
  }
  return true;
}
