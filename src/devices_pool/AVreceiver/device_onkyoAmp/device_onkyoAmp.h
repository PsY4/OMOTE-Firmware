#pragma once

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
extern uint16_t ONKYO_INPUT_DVD;
extern uint16_t ONKYO_INPUT_DTV;
// extern uint16_t ONKYO_INPUT_VCR;
// extern uint16_t ONKYO_POWER_TOGGLE;
// extern uint16_t ONKYO_INPUT_CD;
// extern uint16_t ONKYO_INPUT_MD;
// extern uint16_t ONKYO_INPUT_VAUX;
// extern uint16_t ONKYO_MULTICHANNEL;
// extern uint16_t ONKYO_INPUT_TUNER;
// extern uint16_t ONKYO_PRESETGROUP;
// extern uint16_t ONKYO_PRESETSTATION_MINUS;
// extern uint16_t ONKYO_PRESETSTATION_PLUS;
extern uint16_t ONKYO_STANDARD;
// extern uint16_t ONKYO_5CHSTEREO;
// extern uint16_t ONKYO_NIGHT;
// extern uint16_t ONKYO_SLEEP;
// extern uint16_t ONKYO_TEST;
// extern uint16_t ONKYO_STRAIGHT;
extern uint16_t ONKYO_VOL_MINUS;
extern uint16_t ONKYO_VOL_PLUS;
// extern uint16_t ONKYO_PROG_MINUS;
// extern uint16_t ONKYO_PROG_PLUS;
extern uint16_t ONKYO_MUTE_TOGGLE;
// extern uint16_t ONKYO_LEVEL;
// extern uint16_t ONKYO_SETMENU;
// extern uint16_t ONKYO_SETMENU_UP;
// extern uint16_t ONKYO_SETMENU_DOWN;
// extern uint16_t ONKYO_SETMENU_MINUS;
// extern uint16_t ONKYO_SETMENU_PLUS;
extern uint16_t ONKYO_POWER_OFF;
extern uint16_t ONKYO_POWER_ON;

void register_device_onkyoAmp();
