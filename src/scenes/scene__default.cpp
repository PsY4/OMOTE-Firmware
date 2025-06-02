#include <map>
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
// devices
//#include "devices/AVreceiver/device_onkyoAmp/device_onkyoAmp.h"
//#include "devices/mediaPlayer/device_shield/device_shield.h"
#include "devices/misc/device_smarthome/device_smarthome.h"
#include "devices/misc/device_smarthome/gui_smarthome.h"
// scenes
#include "scene__default.h"
#include "scenes/scene_allOff.h"
#include "scenes/scene_shield.h"

uint16_t SCENE_SELECTION;
std::string scene_name_selection = "sceneSelection";
uint16_t SCENE_BACK_TO_PREVIOUS_GUI_LIST;
std::string scene_back_to_previous_gui_list = "backToPreviousList";
uint16_t GUI_PREV;
std::string scene_gui_prev = "GUI_prev";
uint16_t GUI_NEXT;
std::string scene_gui_next = "GUI_next";

std::map<char, repeatModes> key_repeatModes_default;
std::map<char, uint16_t> key_commands_short_default;
std::map<char, uint16_t> key_commands_long_default;

// This is the main list of guis we want to be shown when swiping. Need not to be all the guis that have been registered, can be only a subset.
// You can swipe through these guis. Will be in the order you place them here in the vector.
// By default, it is a list of the guis that have been registered in main.cpp
// If a scene defines a scene specific gui list, this will be used instead as long as the scene is active and we don't explicitely navigate back to main_gui_list
t_gui_list main_gui_list;

void register_scene_defaultKeys(void) {
  key_repeatModes_default = {
                                                                                                             {KEY_OFF,   SHORT            },
    {KEY_STOP,  SHORT            },    {KEY_REWI,  SHORT_REPEATED   },    {KEY_PLAY,  SHORT            },    {KEY_FORW,  SHORT_REPEATED   },
    {KEY_CONF,  SHORT            },                                                                          {KEY_INFO,  SHORT            },
                                                         {KEY_UP,    SHORT_REPEATED},
                      {KEY_LEFT, SHORT_REPEATED    },    {KEY_OK,    SHORT         },     {KEY_RIGHT, SHORT_REPEATED},
                                                         {KEY_DOWN,  SHORT_REPEATED},
    {KEY_BACK,  SHORT            },                                                                          {KEY_SRC,   SHORT            },
    {KEY_VOLUP, SHORT_REPEATED   },                      {KEY_MUTE,  SHORT            },                     {KEY_CHUP,  SHORT            },
    {KEY_VOLDO, SHORT_REPEATED   },                      {KEY_REC,   SHORT            },                     {KEY_CHDOW, SHORT            },
    {KEY_RED,   SHORT            },    {KEY_GREEN, SHORT            },    {KEY_YELLO, SHORT            },    {KEY_BLUE,  SHORT            },
  };
  
  key_commands_short_default = {
                                                                                                                                   {KEY_OFF, SCENE_ALLOFF_FORCE},
    {KEY_STOP,  SMARTHOME_MQTT_SHIELD_STOP}, {KEY_REWI,  SMARTHOME_MQTT_SHIELD_REVERSE }, {KEY_PLAY, SMARTHOME_MQTT_SHIELD_PLAY }, {KEY_FORW, SMARTHOME_MQTT_SHIELD_FORWARD }, 
    {KEY_CONF,  SMARTHOME_MQTT_SHIELD_SHIELD  },                                                                                   {KEY_INFO, SMARTHOME_MQTT_AMPLI_INFO  }, 
                                                                    {KEY_UP, SMARTHOME_MQTT_SHIELD_UP },  
                          {KEY_LEFT,  SMARTHOME_MQTT_SHIELD_LEFT }, {KEY_OK, SMARTHOME_MQTT_SHIELD_OK }, {KEY_RIGHT, SMARTHOME_MQTT_SHIELD_RIGHT },
                                                                    {KEY_DOWN, SMARTHOME_MQTT_SHIELD_DOWN },  
    {KEY_BACK,  SMARTHOME_MQTT_SHIELD_EXIT  },                                                                                      {KEY_SRC, COMMAND_UNKNOWN }, 
    {KEY_VOLUP, SMARTHOME_MQTT_AMPLI_VOL_UP  },                     {KEY_MUTE,  SMARTHOME_MQTT_AMPLI_MUTE},                         {KEY_CHUP,  COMMAND_UNKNOWN  },
    {KEY_VOLDO, SMARTHOME_MQTT_AMPLI_VOL_DOWN },                    {KEY_REC,   SCENE_BACK_TO_PREVIOUS_GUI_LIST  },                 {KEY_CHDOW, COMMAND_UNKNOWN  },
    {KEY_RED, SMARTHOME_MQTT_TV_OK },              {KEY_GREEN, COMMAND_UNKNOWN},               {KEY_YELLO, SMARTHOME_MQTT_HA_PLAFOND_TOGGLE},             {KEY_BLUE,  SMARTHOME_MQTT_HA_LABOULE_TOGGLE  },
  };
  
  key_commands_long_default = {
  
  
  };

  register_command(&SCENE_SELECTION                , makeCommandData(SCENE, {scene_name_selection}));
  register_command(&SCENE_BACK_TO_PREVIOUS_GUI_LIST, makeCommandData(SCENE, {scene_back_to_previous_gui_list}));
  register_command(&GUI_PREV                       , makeCommandData(SCENE, {scene_gui_prev}));
  register_command(&GUI_NEXT                       , makeCommandData(SCENE, {scene_gui_next}));

}
