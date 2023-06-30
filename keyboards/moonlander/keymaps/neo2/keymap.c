#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "os_detection.h"
#include "process_unicode_common.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  ST_CARRET,
  ST_BTCK,
  DE_LSPO,
  DE_RSPC,
};

enum tap_dance_codes {
  DANCE_CUT,
  DANCE_PASTE,
  DANCE_COPY,
  _DANCE_MAX,
};

enum LAYERS {
    LAYER_1_WIN,
    //LAYER_1_MAC,
    // Layer 2 is handled using overrides
    LAYER_3_WIN,
    //LAYER_3_MAC,
    LAYER_4,
    LAYER_5,
    LAYER_6,
    LAYER_QWERTZ,
    LAYER_MEDIA,
};

#define ko_make_shifted(trigger_key_, replacement_key_) \
  ko_make_with_layers(MOD_MASK_SHIFT, trigger_key_, replacement_key_, 1)
#define ko_make_shifted_keep_shift(trigger_key_, replacement_key_) \
  ((const key_override_t){                                                              \
    .trigger_mods                           = MOD_MASK_SHIFT,                           \
    .layers                                 = 1 << LAYER_1_WIN,                         \
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
    .layers                                 = 1 << LAYER_1_WIN,                         \
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

const key_override_t circ_override = ko_make_shifted_unicode(DE_CIRC, 0x030C); // ˇ
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
const key_override_t sGrave_override = ko_make_shifted_unicode(DE_GRV, 0x0327); // ¸
const key_override_t sAcute_override = ko_make_shifted_unicode(DE_ACUT, 0x0303); // ~
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
  &sGrave_override,
  &sAcute_override,
  &sComma_override,
  &sDot_override,
  NULL // Must terminate this arra with NULL
};

const uint16_t PROGMEM caps_combo[] = {KC_LSHIFT, KC_RSHIFT, COMBO_END};
const uint16_t PROGMEM layer5_left_combo[] = {MO(LAYER_3_WIN), KC_LSHIFT, COMBO_END};
const uint16_t PROGMEM layer5_right_combo[] = {LT(LAYER_3_WIN, DE_Y), KC_RSHIFT, COMBO_END};
const uint16_t PROGMEM layer6_left_combo[] = {MO(LAYER_3_WIN), MO(LAYER_4), COMBO_END};
const uint16_t PROGMEM layer6_right_combo[] = {LT(LAYER_3_WIN, DE_Y), MO(LAYER_4), COMBO_END};

combo_t key_combos[] = {
    COMBO(caps_combo, KC_CAPSLOCK),
    COMBO(layer5_left_combo, MO(LAYER_5)),
    COMBO(layer5_right_combo, MO(LAYER_5)),
    COMBO(layer6_left_combo, MO(LAYER_6)),
    COMBO(layer6_right_combo, MO(LAYER_6))
};
uint16_t COMBO_LEN = 5;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Layer 1
  [LAYER_1_WIN] = LAYOUT_moonlander(
    DE_CIRC,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 TG(LAYER_QWERTZ),KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           DE_MINS,
    KC_TRANSPARENT, TD(DANCE_CUT),    TD(DANCE_PASTE),    KC_L,           TD(DANCE_COPY),    KC_W,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_K,           KC_H,           KC_G,           KC_F,           KC_Q,           DE_SS,
    MO(LAYER_3_WIN),KC_U,           KC_I,           KC_A,           KC_E,           KC_O,           KC_TAB,                                                                         KC_MEH,         KC_S,           KC_N,           KC_R,           KC_T,           KC_D,           LT(LAYER_3_WIN,DE_Y),
    KC_LSHIFT,      LCTL_T(DE_UE),  LALT_T(DE_OE),  DE_AE,          KC_P,           DE_Z,                                           KC_B,           KC_M,           KC_COMMA,       RALT_T(KC_DOT), RCTL_T(KC_J),   KC_RSHIFT,
    KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        OSL(LAYER_MEDIA),MO(LAYER_4),    KC_HYPR,                                                                                                        KC_ESCAPE,      DE_GRV,         DE_ACUT,        KC_RALT,        KC_RCTRL,       KC_TRANSPARENT,
    LSFT_T(KC_SPACE),LT(LAYER_3_WIN,KC_DELETE),KC_LGUI,                       MO(LAYER_4),    LT(LAYER_3_WIN,KC_ENTER), RSFT_T(KC_BSPACE)
  ),
// Layer 2 is handled by shift overrides
// Layer 3
  [LAYER_3_WIN] = LAYOUT_moonlander(
    UC(0x21BB),     UC(0x00B9),     UC(0x00B2),     UC(0x00B3),     UC(0x203A),     UC(0x2039),     KC_TRANSPARENT,                                 KC_TRANSPARENT, UC(0x00A2),     UC(0x00A5),     UC(0x201A),     UC(0x2018),     UC(0x2019),     KC_NO,
    KC_TRANSPARENT, UC(0x2026),     DE_UNDS,        DE_LBRC,        DE_RBRC,        ST_CARRET,     KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_EXLM,        DE_LESS,        DE_MORE,        DE_EQL,         DE_AMPR,        UC(0x017F),
    KC_TRANSPARENT, DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_QST,         DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        DE_AT,
    KC_TRANSPARENT, DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        ST_BTCK,                                     DE_PLUS,        DE_PERC,        DE_DQOT,        DE_QUOT,        DE_SCLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, UC(0x030A),     UC(0x0337), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
// Layer 4
  [LAYER_4] = LAYOUT_moonlander(
    UC(0x0307),     UC(0x00AA),     DE_RING,        UC(0x2116),     KC_NO,          UC(0x00B7),     KC_TRANSPARENT,                                 KC_TRANSPARENT, UC(0x00A3),     UC(0x00A4),     KC_TAB,         DE_SLSH,        DE_ASTR,        DE_MINS,
    KC_TRANSPARENT, KC_PGUP,        KC_BSPACE,      KC_UP,          KC_DELETE,      KC_PGDOWN,      KC_TRANSPARENT,                                 KC_TRANSPARENT, UC(0x00A1),		KC_KP_7,        KC_KP_8,        KC_KP_9,        DE_PLUS,        UC(0x2212),
    KC_TRANSPARENT, KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT, UC(0x00BF),		KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_COMMA,       KC_DOT,
    KC_TRANSPARENT, KC_ESCAPE,      KC_TAB,         KC_INSERT,      KC_ENTER,       LCTL(KC_Z),                                     DE_COLN,        KC_KP_1,        KC_KP_2,        KC_KP_3,        DE_SCLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, UC(0x0308),		UC(0x030B),		KC_KP_0,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
// Layer 5
  [LAYER_5] = LAYOUT_moonlander(
    UC(0x02DE),     UC(0x2081),     UC(0x2082),     UC(0x2083),     UC(0x2640),     UC(0x2642),     KC_TRANSPARENT,                                 KC_TRANSPARENT, UC(0x26A5),     UC(0x03F0),     UC(0x27E8),     UC(0x27E9),     UC(0x2080),     UC(0x2011),
    KC_TRANSPARENT, UC(0x03BE),     KC_NO,          UC(0x03BB),     UC(0x03C7),     UC(0x03C9),     KC_TRANSPARENT,                                 KC_TRANSPARENT, UC(0x03BA),     UC(0x03C8),     UC(0x03B3),     UC(0x03C6),     UC(0x03D5),     UC(0x03C2),
    KC_TRANSPARENT, KC_NO,          UC(0x03B9),     UC(0x03B1),     UC(0x03B5),     UC(0x03BF),     KC_TRANSPARENT,                                 KC_TRANSPARENT, UC(0x03C3),     UC(0x03BD),     UC(0x03C1),     UC(0x03C4),     UC(0x03B4),     UC(0x03C5),
    KC_TRANSPARENT, KC_NO,          UC(0x03F5),     UC(0x03B7),     UC(0x03C0),     UC(0x03B6),                                                                     UC(0x03B2),     UC(0x03BC),     UC(0x03F1),     UC(0x03D1),     UC(0x03B8),     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, UC(0x0314),     UC(0x0313),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    UC(0x00A0),     KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
// Layer 6
  [LAYER_6] = LAYOUT_moonlander(
    UC(0x0323),     UC(0x00AC),     UC(0x2228),     UC(0x2227),     UC(0x22A5),     UC(0x2221),     KC_TRANSPARENT,                                 KC_TRANSPARENT, UC(0x2225),     UC(0x2192),     UC(0x221E),     UC(0x221D),     UC(0x2205),     UC(0x2011),
    KC_TRANSPARENT, UC(0x039E),     UC(0x221A),     UC(0x039B),     UC(0x2102),     UC(0x03A9),     KC_TRANSPARENT,                                 KC_TRANSPARENT, UC(0x00D7),     UC(0x03A8),     UC(0x0393),     UC(0x03A6),     UC(0x211A),     UC(0x2218),
    KC_TRANSPARENT, UC(0x2282),     UC(0x222B),     UC(0x2200),     UC(0x2203),     UC(0x2208),     KC_TRANSPARENT,                                 KC_TRANSPARENT, UC(0x03A3),     UC(0x2115),     UC(0x211D),     UC(0x2202),     UC(0x0394),     UC(0x2207),
    KC_TRANSPARENT, UC(0x222A),     UC(0x2229),     UC(0x2135),     UC(0x03A0),     UC(0x2124),                                                                     UC(0x21D0),     UC(0x21D4),     UC(0x21D2),     UC(0x21A6),     UC(0x0398),     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, UC(0x0304),     UC(0x0306),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    UC(0x202F),     KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
// QWERTZ/Gaming
  [LAYER_QWERTZ] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPACE,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DE_SS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_ENTER,                                       KC_TRANSPARENT, DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_UE,
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           DE_OE,          DE_AE,
    KC_TRANSPARENT, DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_TRANSPARENT, KC_DOT,         KC_MINUS,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ESCAPE,                                                                                                      KC_TRANSPARENT, LSFT(DE_ACUT),  DE_ACUT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_SPACE,       KC_DELETE,      KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_BSPACE
  ),
// Function & Media Keys
  [LAYER_MEDIA] = LAYOUT_moonlander(
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
    [LAYER_1_WIN] = { {31,255,255}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,255}, {0,0,255}, {31,255,255}, {0,205,155}, {0,205,155}, {0,183,238}, {0,0,255}, {31,255,255}, {31,255,255}, {0,183,238}, {0,183,238}, {0,0,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,255}, {0,183,238}, {0,205,155}, {0,205,155}, {0,183,238}, {31,255,255} },

    [LAYER_3_WIN] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {31,255,255}, {0,0,0}, {0,0,0}, {0,183,238}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {0,183,238}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {15,166,195}, {15,166,195}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,205,155}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [LAYER_4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,183,238}, {31,255,255}, {0,0,0}, {0,0,0}, {15,166,195}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {0,205,155}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {15,166,195}, {0,205,155}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {0,183,238}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {31,255,255}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {31,255,255}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [LAYER_QWERTZ] = { {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255} },

    [LAYER_MEDIA] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,205,155}, {0,183,238}, {0,205,155}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,205,155}, {0,0,0}, {0,0,0}, {0,205,155}, {0,183,238}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
    case ST_CARRET:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_SPACE));

    }
    break;
    case ST_BTCK:
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

static tap dance_state[_DANCE_MAX];

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

#define DANCE_ACTION(NAME_LC, NAME_UC, KC) \
void on_dance_##NAME_LC(qk_tap_dance_state_t *state, void *user_data) { \
    if(state->count == 3) { \
        tap_code16(KC); \
        tap_code16(KC); \
        tap_code16(KC); \
    } \
    if(state->count > 3) { \
        tap_code16(KC); \
    } \
} \
\
void dance_##NAME_LC##_finished(qk_tap_dance_state_t *state, void *user_data) { \
    dance_state[DANCE_##NAME_UC].step = dance_step(state); \
    switch (dance_state[DANCE_##NAME_UC].step) { \
        case SINGLE_TAP: register_code16(KC); break; \
        case SINGLE_HOLD: register_code16(LCTL(KC)); break; \
        case DOUBLE_TAP: register_code16(KC); register_code16(KC); break; \
        case DOUBLE_SINGLE_TAP: tap_code16(KC); register_code16(KC); \
    } \
} \
\
void dance_##NAME_LC##_reset(qk_tap_dance_state_t *state, void *user_data) { \
    wait_ms(10); \
    switch (dance_state[DANCE_##NAME_UC].step) { \
        case SINGLE_TAP: unregister_code16(KC); break; \
        case SINGLE_HOLD: unregister_code16(LCTL(KC)); break; \
        case DOUBLE_TAP: unregister_code16(KC); break; \
        case DOUBLE_SINGLE_TAP: unregister_code16(KC); break; \
    } \
    dance_state[DANCE_##NAME_UC].step = 0; \
}
DANCE_ACTION(cut, CUT, KC_X)
DANCE_ACTION(paste, PASTE, KC_V)
DANCE_ACTION(copy, COPY, KC_C)

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_cut, dance_cut_finished, dance_cut_reset),
        [DANCE_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_paste, dance_paste_finished, dance_paste_reset),
        [DANCE_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_copy, dance_copy_finished, dance_copy_reset),
};

void process_detected_host_os_user(os_variant_t detected) {
    switch (detected) {
    case OS_LINUX:
        set_unicode_input_mode(UC_LNX, false);
        break;
    case OS_WINDOWS:
        set_unicode_input_mode(UC_WINC, false);
        break;
    case OS_MACOS:
    case OS_IOS:
        set_unicode_input_mode(UC_MAC, false);
        break;
    default:
        break;
    }
}
