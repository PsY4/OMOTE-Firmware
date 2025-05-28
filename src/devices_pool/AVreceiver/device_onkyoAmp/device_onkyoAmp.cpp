#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_onkyoAmp.h"

  // Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
  uint16_t ONKYO_INPUT_DVD           ; //"Yamaha_input_dvd";
  uint16_t ONKYO_INPUT_DTV           ; //"Yamaha_input_dtv";
  // uint16_t ONKYO_INPUT_VCR           ; //"Yamaha_input_vcr";
  // uint16_t ONKYO_POWER_TOGGLE        ; //"Yamaha_power_toggle";
  // uint16_t ONKYO_INPUT_CD            ; //"Yamaha_input_cd";
  // uint16_t ONKYO_INPUT_MD            ; //"Yamaha_input_md";
  // uint16_t ONKYO_INPUT_VAUX          ; //"Yamaha_input_vaux";
  // uint16_t ONKYO_MULTICHANNEL        ; //"Yamaha_multichannel";
  // uint16_t ONKYO_INPUT_TUNER         ; //"Yamaha_input_tuner";
  // uint16_t ONKYO_PRESETGROUP         ; //"Yamaha_presetgroup";
  // uint16_t ONKYO_PRESETSTATION_MINUS ; //"Yamaha_presetstation-";
  // uint16_t ONKYO_PRESETSTATION_PLUS  ; //"Yamaha_presetstation+";
  uint16_t ONKYO_STANDARD            ; //"Yamaha_standard";
  // uint16_t ONKYO_5CHSTEREO           ; //"Yamaha_5chstereo";
  // uint16_t ONKYO_NIGHT               ; //"Yamaha_night";
  // uint16_t ONKYO_SLEEP               ; //"Yamaha_sleep";
  // uint16_t ONKYO_TEST                ; //"Yamaha_test";
  // uint16_t ONKYO_STRAIGHT            ; //"Yamaha_straight";
  uint16_t ONKYO_VOL_MINUS           ; //"Yamaha_vol-";
  uint16_t ONKYO_VOL_PLUS            ; //"Yamaha_vol+";
  // uint16_t ONKYO_PROG_MINUS          ; //"Yamaha_prog-";
  // uint16_t ONKYO_PROG_PLUS           ; //"Yamaha_prog+";
  uint16_t ONKYO_MUTE_TOGGLE         ; //"Yamaha_mute_toggle";
  // uint16_t ONKYO_LEVEL               ; //"Yamaha_level";
  // uint16_t ONKYO_SETMENU             ; //"Yamaha_setmenu";
  // uint16_t ONKYO_SETMENU_UP          ; //"Yamaha_setmenu_up";
  // uint16_t ONKYO_SETMENU_DOWN        ; //"Yamaha_setmenu_down";
  // uint16_t ONKYO_SETMENU_MINUS       ; //"Yamaha_setmenu_-";
  // uint16_t ONKYO_SETMENU_PLUS        ; //"Yamaha_setmenu_+";
  uint16_t ONKYO_POWER_OFF           ; //"Yamaha_power_off";
  uint16_t ONKYO_POWER_ON            ; //"Yamaha_power_on";

void register_device_onkyoAmp() {
  // tested with Onkyo TX-NR656, works also with others

  // Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
  register_command(&ONKYO_INPUT_DVD           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1837C"}));
  register_command(&ONKYO_INPUT_DTV           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA12AD5"}));
  // register_command(&ONKYO_INPUT_VCR           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1F00F"}));
  // register_command(&ONKYO_POWER_TOGGLE        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1F807"}));
  // register_command(&ONKYO_INPUT_CD            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1A857"}));
  // register_command(&ONKYO_INPUT_MD            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1936C"}));
  // register_command(&ONKYO_INPUT_VAUX          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1AA55"}));
  // register_command(&ONKYO_MULTICHANNEL        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1E11E"}));
  // register_command(&ONKYO_INPUT_TUNER         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA16897"}));
  // register_command(&ONKYO_PRESETGROUP         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA148B7"}));
  // register_command(&ONKYO_PRESETSTATION_MINUS , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA18877"}));
  // register_command(&ONKYO_PRESETSTATION_PLUS  , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA108F7"}));
  register_command(&ONKYO_STANDARD            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA109F6"}));
  // register_command(&ONKYO_5CHSTEREO           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1E916"}));
  // register_command(&ONKYO_NIGHT               , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1A956"}));
  // register_command(&ONKYO_SLEEP               , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1EA15"}));
  // register_command(&ONKYO_TEST                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1A15E"}));
  // register_command(&ONKYO_STRAIGHT            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA16A95"}));
  register_command(&ONKYO_VOL_MINUS           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1D827"}));
  register_command(&ONKYO_VOL_PLUS            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA158A7"}));
  // register_command(&ONKYO_PROG_MINUS          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA19A65"}));
  // register_command(&ONKYO_PROG_PLUS           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA11AE5"}));
  register_command(&ONKYO_MUTE_TOGGLE         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA138C7"}));
  // register_command(&ONKYO_LEVEL               , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1619E"}));
  // register_command(&ONKYO_SETMENU             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA139C6"}));
  // register_command(&ONKYO_SETMENU_UP          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA119E6"}));
  // register_command(&ONKYO_SETMENU_DOWN        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA19966"}));
  // register_command(&ONKYO_SETMENU_MINUS       , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1CA35"}));
  // register_command(&ONKYO_SETMENU_PLUS        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA14AB5"}));
  register_command(&ONKYO_POWER_OFF           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA17887"}));
  register_command(&ONKYO_POWER_ON            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x5EA1B847"}));

  // GC seems not to work
  //register_command(&ONKYO_POWER_TOGGLE       , makeCommandData(IR, {std::to_string(IR_PROTOCOL_GLOBALCACHE), "38000,1,69,341,170,21,21,21,64,21,64,21,64,21,64,21,64,21,64,21,21,21,64,21,21,21,21,21,21,21,21,21,21,21,21,21,64,21,21,21,64,21,21,21,64,21,21,21,64,21,21,21,21,21,64,21,21,21,64,21,21,21,64,21,21,21,64,21,64,21,1517,341,85,21,3655"}));
  //register_command(&ONKYO_POWER_OFF          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_GLOBALCACHE), "38000,1,69,341,170,21,21,21,64,21,64,21,64,21,64,21,64,21,64,21,21,21,64,21,21,21,21,21,21,21,21,21,21,21,21,21,64,21,64,21,64,21,64,21,64,21,64,21,64,21,64,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,64,21,1517,341,85,21,3655"}));
  //register_command(&ONKYO_POWER_ON           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_GLOBALCACHE), "38000,1,69,341,170,21,21,21,64,21,64,21,64,21,64,21,64,21,64,21,21,21,64,21,21,21,21,21,21,21,21,21,21,21,21,21,64,21,21,21,64,21,64,21,64,21,64,21,64,21,64,21,21,21,64,21,21,21,21,21,21,21,21,21,21,21,21,21,64,21,1517,341,85,21,3655"}));
  //register_command(&ONKYO_INPUT_DVD          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_GLOBALCACHE), "38000,1,69,341,170,21,21,21,64,21,21,21,64,21,64,21,64,21,64,21,21,21,64,21,21,21,64,21,21,21,21,21,21,21,21,21,64,21,64,21,21,21,21,21,21,21,21,21,21,21,64,21,64,21,21,21,64,21,64,21,64,21,64,21,64,21,21,21,21,21,1517,341,85,21,3655"}));
  //register_command(&ONKYO_INPUT_DTV          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_GLOBALCACHE), "38000,1,69,341,170,21,21,21,64,21,21,21,64,21,64,21,64,21,64,21,21,21,64,21,21,21,64,21,21,21,21,21,21,21,21,21,64,21,21,21,21,21,64,21,21,21,64,21,21,21,64,21,21,21,64,21,64,21,21,21,64,21,21,21,64,21,21,21,64,21,1517,341,85,21,3655"}));
  //register_command(&ONKYO_STANDARD           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_GLOBALCACHE), "38000,1,69,341,170,21,21,21,64,21,64,21,64,21,64,21,64,21,64,21,21,21,64,21,21,21,21,21,21,21,21,21,21,21,21,21,64,21,21,21,64,21,64,21,64,21,64,21,64,21,64,21,64,21,64,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,1517,341,85,21,3655"}));
}
