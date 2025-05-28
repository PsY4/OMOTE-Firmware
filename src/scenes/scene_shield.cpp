#include <map>
#include "scenes/scene_shield.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
// devices
//#include "devices/TV/device_lgTV/device_lgTV.h"
#include "devices/misc/device_smarthome/device_smarthome.h"
#include "devices/misc/device_smarthome/gui_smarthome.h"
//#include "devices/mediaPlayer/device_shield/device_shield.h"
#include "applicationInternal/commandHandler.h"
// scenes
#include "scenes/scene_allOff.h"

uint16_t SCENE_SHIELD      ; //"Scene_shield"
uint16_t SCENE_SHIELD_FORCE; //"Scene_shield_force"

std::map<char, repeatModes> key_repeatModes_shield;
std::map<char, uint16_t> key_commands_short_shield;
std::map<char, uint16_t> key_commands_long_shield;

void scene_setKeys_shield() {
  key_repeatModes_shield = {
  };
  
  key_commands_short_shield = {
                                     /*                                                                        {KEY_OFF,   SCENE_ALLOFF_FORCE},
   
                                                                                                             {KEY_OFF,   SCENE_ALLOFF_FORCE},
    {KEY_STOP,  SHIELD_STOP},        {KEY_REWI,  SHIELD_REVERSE  },      {KEY_PLAY,  SHIELD_PLAY  },         {KEY_FORW,  SHIELD_FORWARD  }, 
    {KEY_CONF,  SHIELD_SHIELD  },                                                                            {KEY_INFO,  SMARTHOME_MQTT_AMPLI_INFO  }, 
                                                       {KEY_UP,    SHIELD_UP  },  
                      {KEY_LEFT,  SHIELD_LEFT  },      {KEY_OK,    SHIELD_OK  },    {KEY_RIGHT, SHIELD_RIGHT  },
                                                       {KEY_DOWN,  SHIELD_DOWN  },  
    {KEY_BACK,  COMMAND_UNKNOWN  },                                                                           {KEY_SRC,   COMMAND_UNKNOWN  }, 
    {KEY_VOLUP, SMARTHOME_MQTT_AMPLI_VOL_UP  },        {KEY_MUTE,  SMARTHOME_MQTT_AMPLI_MUTE},                {KEY_CHUP,  COMMAND_UNKNOWN  },
    {KEY_VOLDO, SMARTHOME_MQTT_AMPLI_VOL_DOWN },      {KEY_REC,   COMMAND_UNKNOWN  },         {KEY_CHDOW, COMMAND_UNKNOWN  },
    {KEY_RED,   COMMAND_UNKNOWN   },     {KEY_GREEN, COMMAND_UNKNOWN},      {KEY_YELLO, COMMAND_UNKNOWN},     {KEY_BLUE,  COMMAND_UNKNOWN  },*/
  };
  
  key_commands_long_shield = {
  };

}

void scene_start_sequence_shield(void) {
  executeCommand(SMARTHOME_MQTT_TV_POWER_ON);
  delay(1500);
  executeCommand(SMARTHOME_MQTT_AMPLI_POWER_ON);
  delay(2000);
  executeCommand(SMARTHOME_MQTT_AMPLI_INPUT_CBL_SAT);
  delay(3500);
  executeCommand(SMARTHOME_MQTT_TV_INPUT_HDMI_4);
}

void scene_end_sequence_shield(void) {

}

std::string scene_name_shield = "Shield";

void register_scene_shield(void) {
  register_command(&SCENE_SHIELD,       makeCommandData(SCENE, {scene_name_shield}));
  register_command(&SCENE_SHIELD_FORCE, makeCommandData(SCENE, {scene_name_shield, "FORCE"}));

  register_scene(
    scene_name_shield,
    & scene_setKeys_shield,
    & scene_start_sequence_shield,
    & scene_end_sequence_shield,
    & key_repeatModes_shield,
    & key_commands_short_shield,
    & key_commands_long_shield,
    NULL,
    SCENE_SHIELD);
}
