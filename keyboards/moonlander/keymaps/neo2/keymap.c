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
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

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
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  ST_MACRO_0,
  ST_MACRO_1,
  DE_LSPO,
  DE_RSPC,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
};

#define ko_make_shifted(trigger_key_, replacement_key_) \
  ko_make_with_layers(MOD_MASK_SHIFT, trigger_key_, replacement_key_, 1)
#define ko_make_shifted_keep_shift(trigger_key_, replacement_key_) \
  ((const key_override_t){                                                              \
    .trigger_mods                           = MOD_MASK_SHIFT,                           \
    .layers                                 = 1,                                        \
    .suppressed_mods                        = 0,                                        \
    .options                                = ko_options_default,                       \
    .negative_mod_mask                      = 0,                                        \
    .custom_action                          = NULL,                                     \
    .context                                = NULL,                                     \
    .trigger                                = (trigger_key_),                           \
    .replacement                            = (replacement_key_),                       \
    .enabled                                = NULL                                      \
  })
#define ko_make_shifted_unicode(trigger_key_, codepoint) \
  ((const key_override_t){                                                              \
    .trigger_mods                           = MOD_MASK_SHIFT,                           \
    .layers                                 = 1,                                        \
    .suppressed_mods                        = MOD_MASK_SHIFT,                           \
    .options                                = ko_options_default,                       \
    .negative_mod_mask                      = 0,                                        \
    .custom_action                          = &send_override_unicode,                   \
    .context                                = (void*)(codepoint),                       \
    .trigger                                = (trigger_key_),                           \
    .replacement                            = KC_NO,                                    \
    .enabled                                = NULL                                      \
  })

bool send_override_unicode(bool activated, void *context) {
  if (activated) {
    uint32_t codepoint = (uint32_t)context;
    register_unicode(codepoint);
  }

  return true;
}

const key_override_t circ_override = ko_make_shifted_unicode(DE_CIRC, 0x030C); //
const key_override_t s1_override = ko_make_shifted_keep_shift(KC_1, DE_CIRC); // °
const key_override_t s2_override = ko_make_shifted_keep_shift(KC_2, KC_3); // §
const key_override_t s3_override = ko_make_shifted_unicode(KC_3, 0x2113); // ℓ
const key_override_t s4_override = ko_make_shifted_unicode(KC_4, 0x00BB); // »
const key_override_t s5_override = ko_make_shifted_unicode(KC_5, 0x00AB); // «
const key_override_t s6_override = ko_make_shifted_keep_shift(KC_6, KC_4); // $
const key_override_t s7_override = ko_make_shifted(KC_7, ALGR(KC_E)); // €
const key_override_t s8_override = ko_make_shifted_unicode(KC_8, 0x201E); // „
const key_override_t s9_override = ko_make_shifted_unicode(KC_9, 0x201C); // „
const key_override_t s0_override = ko_make_shifted_unicode(KC_0, 0x201D); // ”
const key_override_t sSS_override = ko_make_shifted_unicode(DE_SS, 0x2014); // —
// TODO: ` to ¸ UC(0x327), problematic because the key we're overriding always needs shift to be produced
// TODO: ´ to ~ UC(0x303), problematic because the key we're overriding + shift is used in different situations (i.e. one above)
const key_override_t sComma_override = ko_make_shifted_unicode(KC_COMMA, 0x2013); // –
const key_override_t sDot_override = ko_make_shifted_unicode(RALT_T(KC_DOT), 0x2022); // •

const key_override_t **key_overrides = (const key_override_t *[]){
  &circ_override,
  &s1_override,
  &s2_override,
  &s3_override,
  &s4_override,
  &s5_override,
  &s6_override,
  &s7_override,
  &s8_override,
  &s9_override,
  &s0_override,
  &sSS_override,
  &sComma_override,
  &sDot_override,
  NULL // Must terminate this arra with NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    DE_CIRC,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 TG(5),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           DE_MINS,
    KC_TRANSPARENT, TD(DANCE_0),    TD(DANCE_1),    KC_L,           TD(DANCE_2),    KC_W,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_K,           KC_H,           KC_G,           KC_F,           KC_Q,           DE_SS,
    MO(1),          KC_U,           KC_I,           KC_A,           KC_E,           KC_O,           KC_TAB,                                                                         KC_MEH,         KC_S,           KC_N,           KC_R,           KC_T,           KC_D,           LT(1,DE_Y),
    KC_LSHIFT,      LCTL_T(DE_UE),  LALT_T(DE_OE),  DE_AE,          KC_P,           DE_Z,                                           KC_B,           KC_M,           KC_COMMA,       RALT_T(KC_DOT), RCTL_T(KC_J),   KC_RSHIFT,
    KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        OSL(6),         MO(2),          KC_HYPR,                                                                                                        KC_ESCAPE,      DE_GRV,         DE_ACUT,        KC_RALT,        KC_RCTRL,       KC_TRANSPARENT,
    LSFT_T(KC_SPACE),LT(1,KC_DELETE),KC_LGUI,                        MO(2),          LT(1,KC_ENTER), RSFT_T(KC_BSPACE)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, UC(0x2026), DE_UNDS,        DE_LBRC,        DE_RBRC,        ST_MACRO_0,        KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_EXLM,        DE_LESS,        DE_MORE,        DE_EQL,         DE_AMPR,        KC_TRANSPARENT,
    KC_TRANSPARENT, DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, DE_QST,         DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        DE_AT,
    KC_TRANSPARENT, DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        ST_MACRO_1,                                     DE_PLUS,        DE_PERC,        DE_DQOT,        DE_QUOT,        DE_SCLN,        KC_TRANSPARENT,
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPACE,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DE_SS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_ENTER,                                       KC_TRANSPARENT, DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_UE,
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           DE_OE,          DE_AE,
    KC_TRANSPARENT, DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_TRANSPARENT, KC_DOT,         KC_MINUS,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ESCAPE,                                                                                                      KC_TRANSPARENT, LSFT(DE_ACUT),  DE_ACUT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_SPACE,       KC_DELETE,      KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_BSPACE
  ),
  [6] = LAYOUT_moonlander(
    UC_M_WC       , KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    UC_M_LN       , KC_AUDIO_VOL_UP,KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_MEDIA_PREV_TRACK,KC_TRANSPARENT,                                 KC_TRANSPARENT, RGB_MOD,        RGB_SPD,        RGB_SPI,        RGB_VAD,        RGB_VAI,        KC_F12,
    UC_M_MA       , KC_AUDIO_VOL_DOWN,KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,                                                                 KC_TRANSPARENT, RGB_SLD,        KC_MS_BTN1,     KC_MS_BTN2,     RGB_HUD,        RGB_HUI,        MU_TOG,
    KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,                                RGB_TOG,        TOGGLE_LAYER_COLOR,HSV_0_255_255,  RGB_SAD,        RGB_SAI,        MU_MOD,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, HSV_86_255_128, HSV_172_255_255,AU_ON,          AU_OFF,         RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};



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
  if (rawhid_state.rgb_control) {
      return;
  }
  if (keyboard_config.disable_layer_led) { return; }
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
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(10) SS_TAP(X_SPACE));
    }
    break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    case HSV_0_255_255:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(0,255,255);
        }
        return false;
      case HSV_86_255_128:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(86,255,128);
        }
        return false;
      case HSV_172_255_255:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(172,255,255);
        }
        return false;
    }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[3];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if(state->count > 3) {
        tap_code16(KC_X);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_X); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_X)); break;
        case DOUBLE_TAP: register_code16(KC_X); register_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_X); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_X)); break;
        case DOUBLE_TAP: unregister_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_V)); break;
        case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_V)); break;
        case DOUBLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if(state->count > 3) {
        tap_code16(KC_C);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_C)); break;
        case DOUBLE_TAP: register_code16(KC_C); register_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_C); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_C)); break;
        case DOUBLE_TAP: unregister_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
    }
    dance_state[2].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
