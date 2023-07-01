/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 300000

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"L4nZ0/vvVjK"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61

#define RGB_MATRIX_STARTUP_SPD 60
#define PERMISSIVE_HOLD

#define UNICODE_SELECTED_MODES UC_WINC, UC_LNX, UC_MAC
#define UNICODE_SONG_MAC {AUDIO_ON_SOUND}
#define UNICODE_SONG_WINC {UNICODE_WINDOWS}
#define UNICODE_SONG_LNX {UNICODE_LINUX}
#define UNICODE_MAC_PREFIX SS_LCTL(" ")
#define UNICODE_MAC_SUFFIX SS_LCTL(SS_LALT(" "))

#define LAYER_STATE_16BIT
