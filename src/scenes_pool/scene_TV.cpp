#include <map>
#include "scenes_pool/scene_TV.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
// devices
//#include "devices/TV/device_lgTV/device_lgTV.h"
//#include "devices/AVreceiver/device_onkyoAmp/device_onkyoAmp.h"
#include "applicationInternal/commandHandler.h"
// guis
#include "guis/gui_numpad.h"

uint16_t SCENE_TV         ; //"Scene_tv"
uint16_t SCENE_TV_FORCE   ; //"Scene_tv_force"

std::map<char, repeatModes> key_repeatModes_TV;
std::map<char, uint16_t> key_commands_short_TV;
std::map<char, uint16_t> key_commands_long_TV;

void scene_setKeys_TV() {
  key_repeatModes_TV = {
  
    {KEY_STOP,  SHORT_REPEATED   },    {KEY_REWI,  SHORT            },    {KEY_PLAY,  SHORT            },    {KEY_FORW,  SHORT_REPEATED   },
    {KEY_CONF,  SHORT            },                                                                          {KEY_INFO,  SHORT            },
                                                         {KEY_UP,    SHORT_REPEATED   },
                      {KEY_LEFT,  SHORT_REPEATED   },    {KEY_OK,    SHORT            },    {KEY_RIGHT, SHORT_REPEATED  },
                                                         {KEY_DOWN,  SHORT_REPEATED   },
                                                                                                             {KEY_SRC,   SHORT            },
                                                                                                             {KEY_CHUP,  SHORT            },
                                                                                                             {KEY_CHDOW, SHORT            },
  
  };
  
  key_commands_short_TV = {
  
    {KEY_STOP,  COMMAND_UNKNOWN    },    {KEY_REWI,  COMMAND_UNKNOWN   },    {KEY_PLAY,  COMMAND_UNKNOWN     },    {KEY_FORW,  COMMAND_UNKNOWN},
    {KEY_CONF,  COMMAND_UNKNOWN    },                                                                          {KEY_INFO,  COMMAND_UNKNOWN     },
                                                         {KEY_UP,    COMMAND_UNKNOWN       },
                      {KEY_LEFT,  COMMAND_UNKNOWN    },     {KEY_OK,    COMMAND_UNKNOWN   },    {KEY_RIGHT, COMMAND_UNKNOWN    },
                                                         {KEY_DOWN,  COMMAND_UNKNOWN     },
                                                                                                             {KEY_SRC,   COMMAND_UNKNOWN     },
                                                                                                             {KEY_CHUP,  COMMAND_UNKNOWN},
                                                                                                             {KEY_CHDOW, COMMAND_UNKNOWN},
  
  };
  
  key_commands_long_TV = {
  
  
  };

}

void scene_start_sequence_TV(void) {
  //executeCommand(SAMSUNG_POWER_ON);
  delay(500);
  //executeCommand(ONKYO_POWER_ON);
  delay(1500);
  //executeCommand(ONKYO_INPUT_DVD);
  delay(3000);
  //executeCommand(SAMSUNG_INPUT_TV);

}

void scene_end_sequence_TV(void) {

}

std::string scene_name_TV = "TV";
t_gui_list scene_TV_gui_list = {tabName_numpad};

void register_scene_TV(void) {
  register_command(&SCENE_TV,       makeCommandData(SCENE, {scene_name_TV}));
  register_command(&SCENE_TV_FORCE, makeCommandData(SCENE, {scene_name_TV, "FORCE"}));

  register_scene(
    scene_name_TV,
    & scene_setKeys_TV,
    & scene_start_sequence_TV,
    & scene_end_sequence_TV,
    & key_repeatModes_TV,
    & key_commands_short_TV,
    & key_commands_long_TV,
    & scene_TV_gui_list,
    SCENE_TV);
}
