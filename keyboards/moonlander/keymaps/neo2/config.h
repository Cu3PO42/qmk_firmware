/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define PERMISSIVE_HOLD

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 300000

#define USB_SUSPEND_WAKEUP_DELAY 0
#define RGB_MATRIX_STARTUP_SPD 60
#define PERMISSIVE_HOLD

#define UNICODE_SELECTED_MODES UC_WINC, UC_LNX, UC_MAC
#define UNICODE_SONG_MAC {AUDIO_ON_SOUND}
#define UNICODE_SONG_WINC {UNICODE_WINDOWS}
#define UNICODE_SONG_LNX {UNICODE_LINUX}