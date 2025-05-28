#include "applicationInternal/commandHandler.h"
#include "device_smarthome.h"

// Ampli Onkyo
uint16_t SMARTHOME_MQTT_AMPLI_POWER_TOGGLE;      
uint16_t SMARTHOME_MQTT_AMPLI_POWER_ON;      
uint16_t SMARTHOME_MQTT_AMPLI_POWER_OFF;      
uint16_t SMARTHOME_MQTT_AMPLI_INPUT_BD_DVD;      
uint16_t SMARTHOME_MQTT_AMPLI_INPUT_CBL_SAT;     
uint16_t SMARTHOME_MQTT_AMPLI_INPUT_STB_DVR;     
uint16_t SMARTHOME_MQTT_AMPLI_INPUT_GAME;        
uint16_t SMARTHOME_MQTT_AMPLI_INPUT_PC;      
uint16_t SMARTHOME_MQTT_AMPLI_INPUT_AUX;     
uint16_t SMARTHOME_MQTT_AMPLI_INPUT_TV_CD;       
uint16_t SMARTHOME_MQTT_AMPLI_VOL_UP;       
uint16_t SMARTHOME_MQTT_AMPLI_VOL_DOWN;        
uint16_t SMARTHOME_MQTT_AMPLI_MUTE;       
uint16_t SMARTHOME_MQTT_AMPLI_BASS_UP;       
uint16_t SMARTHOME_MQTT_AMPLI_BASS_DOWN;     
uint16_t SMARTHOME_MQTT_AMPLI_TREBLE_UP;       
uint16_t SMARTHOME_MQTT_AMPLI_TREBLE_DOWN;          
uint16_t SMARTHOME_MQTT_AMPLI_MODE_MOVIE;       
uint16_t SMARTHOME_MQTT_AMPLI_MODE_MUSIC;       
uint16_t SMARTHOME_MQTT_AMPLI_MODE_GAME;    
uint16_t SMARTHOME_MQTT_AMPLI_INFO;               

// TV LG
uint16_t SMARTHOME_MQTT_TV_POWER_OFF;
uint16_t SMARTHOME_MQTT_TV_POWER_ON;
uint16_t SMARTHOME_MQTT_TV_POWER_TOGGLE;
uint16_t SMARTHOME_MQTT_TV_SOURCE;
uint16_t SMARTHOME_MQTT_TV_CHANNEL_UP;
uint16_t SMARTHOME_MQTT_TV_CHANNEL_DOWN;
uint16_t SMARTHOME_MQTT_TV_MENU;
uint16_t SMARTHOME_MQTT_TV_GUIDE;
uint16_t SMARTHOME_MQTT_TV_SETUP;
uint16_t SMARTHOME_MQTT_TV_INFO;
uint16_t SMARTHOME_MQTT_TV_UP;
uint16_t SMARTHOME_MQTT_TV_DOWN;
uint16_t SMARTHOME_MQTT_TV_LEFT;
uint16_t SMARTHOME_MQTT_TV_RIGHT;
uint16_t SMARTHOME_MQTT_TV_OK;
uint16_t SMARTHOME_MQTT_TV_RETURN;
uint16_t SMARTHOME_MQTT_TV_EXIT;
uint16_t SMARTHOME_MQTT_TV_KEY_A;
uint16_t SMARTHOME_MQTT_TV_KEY_B;
uint16_t SMARTHOME_MQTT_TV_KEY_C;
uint16_t SMARTHOME_MQTT_TV_KEY_D;
uint16_t SMARTHOME_MQTT_TV_INPUT_HDMI_1;
uint16_t SMARTHOME_MQTT_TV_INPUT_HDMI_2;
uint16_t SMARTHOME_MQTT_TV_INPUT_HDMI_3;
uint16_t SMARTHOME_MQTT_TV_INPUT_HDMI_4;
uint16_t SMARTHOME_MQTT_TV_INPUT_TV;
uint16_t SMARTHOME_MQTT_TV_HOME;

// nVIDIA SHIELD
uint16_t SMARTHOME_MQTT_SHIELD_POWER_TOGGLE;
uint16_t SMARTHOME_MQTT_SHIELD_MENU;
uint16_t SMARTHOME_MQTT_SHIELD_EXIT;
uint16_t SMARTHOME_MQTT_SHIELD_STOP;
uint16_t SMARTHOME_MQTT_SHIELD_PLAY;
uint16_t SMARTHOME_MQTT_SHIELD_FORWARD;
uint16_t SMARTHOME_MQTT_SHIELD_REVERSE;
uint16_t SMARTHOME_MQTT_SHIELD_UP;
uint16_t SMARTHOME_MQTT_SHIELD_DOWN;
uint16_t SMARTHOME_MQTT_SHIELD_LEFT;
uint16_t SMARTHOME_MQTT_SHIELD_RIGHT;
uint16_t SMARTHOME_MQTT_SHIELD_OK;
uint16_t SMARTHOME_MQTT_SHIELD_SHIELD;

// HomeAssistant
uint16_t SMARTHOME_MQTT_HA_LABOULE_SET;
uint16_t SMARTHOME_MQTT_HA_LABOULE_BRIGHTNESS_SET;
uint16_t SMARTHOME_MQTT_HA_PLAFOND_SET;
uint16_t SMARTHOME_MQTT_HA_PLAFOND_BRIGHTNESS_SET;
uint16_t SMARTHOME_MQTT_HA_PLAFOND2_SET;
uint16_t SMARTHOME_MQTT_HA_PLAFOND2_BRIGHTNESS_SET;
uint16_t SMARTHOME_MQTT_HA_PIXAR_SET;
uint16_t SMARTHOME_MQTT_HA_PIXAR_BRIGHTNESS_SET;
uint16_t SMARTHOME_MQTT_HA_NANOLEAF_SET;
uint16_t SMARTHOME_MQTT_HA_NANOLEAF_BRIGHTNESS_SET;

void register_device_smarthome() {
  #if (ENABLE_WIFI_AND_MQTT == 1)
  register_command(&SMARTHOME_MQTT_AMPLI_POWER_TOGGLE , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "power_toggle"}));
  register_command(&SMARTHOME_MQTT_AMPLI_POWER_ON     , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "power_on"}));
  register_command(&SMARTHOME_MQTT_AMPLI_POWER_OFF    , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "power_off"}));
  register_command(&SMARTHOME_MQTT_AMPLI_INPUT_BD_DVD , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "bd_dvd"}));
  register_command(&SMARTHOME_MQTT_AMPLI_INPUT_CBL_SAT, makeCommandData(MQTT, {"omote/smarthome/ampli/command", "cbl_sat"}));
  register_command(&SMARTHOME_MQTT_AMPLI_INPUT_STB_DVR, makeCommandData(MQTT, {"omote/smarthome/ampli/command", "stb_dvr"}));
  register_command(&SMARTHOME_MQTT_AMPLI_INPUT_GAME   , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "game"}));
  register_command(&SMARTHOME_MQTT_AMPLI_INPUT_PC     , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "pc"}));
  register_command(&SMARTHOME_MQTT_AMPLI_INPUT_AUX    , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "aux"}));
  register_command(&SMARTHOME_MQTT_AMPLI_INPUT_TV_CD  , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "tv_cd"}));
  register_command(&SMARTHOME_MQTT_AMPLI_VOL_UP       , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "vol_up"}));
  register_command(&SMARTHOME_MQTT_AMPLI_VOL_DOWN     , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "vol_down"}));
  register_command(&SMARTHOME_MQTT_AMPLI_MUTE         , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "mute"}));
  register_command(&SMARTHOME_MQTT_AMPLI_BASS_UP      , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "bass_up"}));
  register_command(&SMARTHOME_MQTT_AMPLI_BASS_DOWN    , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "bass_down"}));
  register_command(&SMARTHOME_MQTT_AMPLI_TREBLE_UP    , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "treble_up"}));
  register_command(&SMARTHOME_MQTT_AMPLI_TREBLE_DOWN  , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "treble_down"}));
  register_command(&SMARTHOME_MQTT_AMPLI_MODE_MOVIE   , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "mode_movie"}));
  register_command(&SMARTHOME_MQTT_AMPLI_MODE_MUSIC   , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "mode_music"}));
  register_command(&SMARTHOME_MQTT_AMPLI_MODE_GAME    , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "mode_game"}));
  register_command(&SMARTHOME_MQTT_AMPLI_INFO         , makeCommandData(MQTT, {"omote/smarthome/ampli/command", "info"}));

  // TV LG
  register_command(&SMARTHOME_MQTT_TV_POWER_OFF         , makeCommandData(MQTT, {"omote/smarthome/tv/command", "power_off"}));
  register_command(&SMARTHOME_MQTT_TV_POWER_ON          , makeCommandData(MQTT, {"omote/smarthome/tv/command", "power_on"}));
  register_command(&SMARTHOME_MQTT_TV_POWER_TOGGLE      , makeCommandData(MQTT, {"omote/smarthome/tv/command", "power_toggle"}));
  register_command(&SMARTHOME_MQTT_TV_SOURCE            , makeCommandData(MQTT, {"omote/smarthome/tv/command", "input"}));
  register_command(&SMARTHOME_MQTT_TV_CHANNEL_UP        , makeCommandData(MQTT, {"omote/smarthome/tv/command", "channel_up"}));
  register_command(&SMARTHOME_MQTT_TV_CHANNEL_DOWN      , makeCommandData(MQTT, {"omote/smarthome/tv/command", "channel_down"}));
  register_command(&SMARTHOME_MQTT_TV_MENU              , makeCommandData(MQTT, {"omote/smarthome/tv/command", "settings"}));
  register_command(&SMARTHOME_MQTT_TV_GUIDE             , makeCommandData(MQTT, {"omote/smarthome/tv/command", "guide"}));
  register_command(&SMARTHOME_MQTT_TV_SETUP             , makeCommandData(MQTT, {"omote/smarthome/tv/command", "setup"}));
  register_command(&SMARTHOME_MQTT_TV_INFO              , makeCommandData(MQTT, {"omote/smarthome/tv/command", "info"}));
  register_command(&SMARTHOME_MQTT_TV_UP                , makeCommandData(MQTT, {"omote/smarthome/tv/command", "up"}));
  register_command(&SMARTHOME_MQTT_TV_DOWN              , makeCommandData(MQTT, {"omote/smarthome/tv/command", "down"}));
  register_command(&SMARTHOME_MQTT_TV_LEFT              , makeCommandData(MQTT, {"omote/smarthome/tv/command", "left"}));
  register_command(&SMARTHOME_MQTT_TV_RIGHT             , makeCommandData(MQTT, {"omote/smarthome/tv/command", "right"}));
  register_command(&SMARTHOME_MQTT_TV_OK                , makeCommandData(MQTT, {"omote/smarthome/tv/command", "ok"}));
  register_command(&SMARTHOME_MQTT_TV_RETURN            , makeCommandData(MQTT, {"omote/smarthome/tv/command", "back"}));
  register_command(&SMARTHOME_MQTT_TV_EXIT              , makeCommandData(MQTT, {"omote/smarthome/tv/command", "exit"}));
  register_command(&SMARTHOME_MQTT_TV_KEY_A             , makeCommandData(MQTT, {"omote/smarthome/tv/command", "dot_one"}));
  register_command(&SMARTHOME_MQTT_TV_KEY_B             , makeCommandData(MQTT, {"omote/smarthome/tv/command", "dot_two"}));
  register_command(&SMARTHOME_MQTT_TV_KEY_C             , makeCommandData(MQTT, {"omote/smarthome/tv/command", "dot_three"}));
  register_command(&SMARTHOME_MQTT_TV_KEY_D             , makeCommandData(MQTT, {"omote/smarthome/tv/command", "dot_four"}));
  register_command(&SMARTHOME_MQTT_TV_INPUT_HDMI_1      , makeCommandData(MQTT, {"omote/smarthome/tv/command", "hdmi_1"}));
  register_command(&SMARTHOME_MQTT_TV_INPUT_HDMI_2      , makeCommandData(MQTT, {"omote/smarthome/tv/command", "hdmi_2"}));
  register_command(&SMARTHOME_MQTT_TV_INPUT_HDMI_3      , makeCommandData(MQTT, {"omote/smarthome/tv/command", "hdmi_3"}));
  register_command(&SMARTHOME_MQTT_TV_INPUT_HDMI_4      , makeCommandData(MQTT, {"omote/smarthome/tv/command", "hdmi_4"}));
  register_command(&SMARTHOME_MQTT_TV_INPUT_TV          , makeCommandData(MQTT, {"omote/smarthome/tv/command", "input_tv"}));
  register_command(&SMARTHOME_MQTT_TV_HOME              , makeCommandData(MQTT, {"omote/smarthome/tv/command", "home"}));

  // nVIDIA SHIELD
  register_command(&SMARTHOME_MQTT_SHIELD_POWER_TOGGLE  , makeCommandData(MQTT, {"omote/smarthome/shield/command", "power_toggle"}));
  register_command(&SMARTHOME_MQTT_SHIELD_MENU          , makeCommandData(MQTT, {"omote/smarthome/shield/command", "menu"}));
  register_command(&SMARTHOME_MQTT_SHIELD_EXIT          , makeCommandData(MQTT, {"omote/smarthome/shield/command", "exit"}));
  register_command(&SMARTHOME_MQTT_SHIELD_STOP          , makeCommandData(MQTT, {"omote/smarthome/shield/command", "stop"}));
  register_command(&SMARTHOME_MQTT_SHIELD_PLAY          , makeCommandData(MQTT, {"omote/smarthome/shield/command", "play"}));
  register_command(&SMARTHOME_MQTT_SHIELD_FORWARD       , makeCommandData(MQTT, {"omote/smarthome/shield/command", "forward"}));
  register_command(&SMARTHOME_MQTT_SHIELD_REVERSE       , makeCommandData(MQTT, {"omote/smarthome/shield/command", "reverse"}));
  register_command(&SMARTHOME_MQTT_SHIELD_UP            , makeCommandData(MQTT, {"omote/smarthome/shield/command", "up"}));
  register_command(&SMARTHOME_MQTT_SHIELD_DOWN          , makeCommandData(MQTT, {"omote/smarthome/shield/command", "down"}));
  register_command(&SMARTHOME_MQTT_SHIELD_LEFT          , makeCommandData(MQTT, {"omote/smarthome/shield/command", "left"}));
  register_command(&SMARTHOME_MQTT_SHIELD_RIGHT         , makeCommandData(MQTT, {"omote/smarthome/shield/command", "right"}));
  register_command(&SMARTHOME_MQTT_SHIELD_OK            , makeCommandData(MQTT, {"omote/smarthome/shield/command", "ok"}));
  register_command(&SMARTHOME_MQTT_SHIELD_SHIELD        , makeCommandData(MQTT, {"omote/smarthome/shield/command", "shield"}));

  // Home assistant
  register_command(&SMARTHOME_MQTT_HA_LABOULE_SET             , makeCommandData(MQTT, {"omote/smarthome/ha/laboule/set"}));
  register_command(&SMARTHOME_MQTT_HA_LABOULE_BRIGHTNESS_SET  , makeCommandData(MQTT, {"omote/smarthome/ha/laboule/brightness"}));
  register_command(&SMARTHOME_MQTT_HA_PLAFOND_SET             , makeCommandData(MQTT, {"omote/smarthome/ha/salon/set"}));
  register_command(&SMARTHOME_MQTT_HA_PLAFOND_BRIGHTNESS_SET  , makeCommandData(MQTT, {"omote/smarthome/ha/salon/brightness"}));

  register_command(&SMARTHOME_MQTT_HA_PLAFOND2_SET             , makeCommandData(MQTT, {"omote/smarthome/ha/salleamanger/set"}));
  register_command(&SMARTHOME_MQTT_HA_PLAFOND2_BRIGHTNESS_SET  , makeCommandData(MQTT, {"omote/smarthome/ha/salleamanger/brightness"}));
  register_command(&SMARTHOME_MQTT_HA_PIXAR_SET                , makeCommandData(MQTT, {"omote/smarthome/ha/pixar/set"}));
  register_command(&SMARTHOME_MQTT_HA_PIXAR_BRIGHTNESS_SET     , makeCommandData(MQTT, {"omote/smarthome/ha/pixar/brightness"}));
  register_command(&SMARTHOME_MQTT_HA_NANOLEAF_SET             , makeCommandData(MQTT, {"omote/smarthome/ha/nanoleaf/set"}));
  register_command(&SMARTHOME_MQTT_HA_NANOLEAF_BRIGHTNESS_SET  , makeCommandData(MQTT, {"omote/smarthome/ha/nanoleaf/brightness"}));
  #endif
}
