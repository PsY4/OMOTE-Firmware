#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/keys.h"
#include "devices/misc/device_smarthome/gui_smarthome.h"
#include "devices/misc/device_smarthome/device_smarthome.h"
#include "scenes/scene__default.h"

// LVGL declarations
LV_IMG_DECLARE(lightbulb);

static lv_obj_t* lightToggleA;
static lv_obj_t* lightToggleB;
static lv_obj_t* lightToggleC;
static lv_obj_t* lightToggleD;
static lv_obj_t* lightToggleE;
static lv_obj_t* sliderA;
static lv_obj_t* sliderB;
static lv_obj_t* sliderC;
static lv_obj_t* sliderD;
static lv_obj_t* sliderE;

static bool lightToggleAstate = false;
static bool lightToggleBstate = false;
static bool lightToggleCstate = false;
static bool lightToggleDstate = false;
static bool lightToggleEstate = false;
static int32_t sliderAvalue = 0;
static int32_t sliderBvalue = 0;
static int32_t sliderCvalue = 0;
static int32_t sliderDvalue = 0;
static int32_t sliderEvalue = 0;

uint16_t GUI_SMARTHOME_ACTIVATE;

std::map<char, repeatModes> key_repeatModes_smarthome = {};
std::map<char, uint16_t> key_commands_short_smarthome = {};
std::map<char, uint16_t> key_commands_long_smarthome = {};

bool smartHomeTabIsInMemory = false;

// Smart Home Toggle Event handler
static void smartHomeToggle_event_cb(lv_event_t* e){
  std::string payload = lv_obj_has_state(lv_event_get_target(e), LV_STATE_CHECKED) ? "true" : "false";
  #if (ENABLE_WIFI_AND_MQTT == 1)
  int user_data = *((int*)(&(e->user_data)));
  if(user_data == 1) executeCommand(SMARTHOME_MQTT_HA_LABOULE_SET, payload);
  if(user_data == 2) executeCommand(SMARTHOME_MQTT_HA_PLAFOND_SET, payload);
  if(user_data == 3) executeCommand(SMARTHOME_MQTT_HA_PLAFOND2_SET, payload);
  if(user_data == 4) executeCommand(SMARTHOME_MQTT_HA_PIXAR_SET, payload);
  if(user_data == 5) executeCommand(SMARTHOME_MQTT_HA_NANOLEAF_SET, payload);
  #endif
}

// Smart Home Slider Event handler
static void smartHomeSlider_event_cb(lv_event_t* e){
  lv_obj_t* slider = lv_event_get_target(e);
  char payload[8];
  sprintf(payload, "%.2f", float(lv_slider_get_value(slider)));
  std::string payload_str(payload);
  #if (ENABLE_WIFI_AND_MQTT == 1)
  int user_data = *((int*)(&(e->user_data)));
  if(user_data == 1) executeCommand(SMARTHOME_MQTT_HA_LABOULE_BRIGHTNESS_SET, payload_str);
  if(user_data == 2) executeCommand(SMARTHOME_MQTT_HA_PLAFOND_BRIGHTNESS_SET, payload_str);
  if(user_data == 3) executeCommand(SMARTHOME_MQTT_HA_PLAFOND2_BRIGHTNESS_SET, payload_str);
  if(user_data == 4) executeCommand(SMARTHOME_MQTT_HA_PIXAR_BRIGHTNESS_SET, payload_str);
  if(user_data == 5) executeCommand(SMARTHOME_MQTT_HA_NANOLEAF_BRIGHTNESS_SET, payload_str);
  #endif
}

static void create_device_control(lv_obj_t* parent, const char* title, int user_id, bool toggle_state, int32_t slider_value, lv_obj_t** toggle_out, lv_obj_t** slider_out) {
  lv_obj_t* menuBox = lv_obj_create(parent);
  lv_obj_set_size(menuBox, lv_pct(100), 79);
  lv_obj_set_style_bg_color(menuBox, color_primary, LV_PART_MAIN);
  lv_obj_set_style_border_width(menuBox, 0, LV_PART_MAIN);

  lv_obj_t* bulbIcon = lv_img_create(menuBox);
  lv_img_set_src(bulbIcon, &lightbulb);
  lv_obj_set_style_img_recolor(bulbIcon, lv_color_white(), LV_PART_MAIN);
  lv_obj_set_style_img_recolor_opa(bulbIcon, LV_OPA_COVER, LV_PART_MAIN);
  lv_obj_align(bulbIcon, LV_ALIGN_TOP_LEFT, 0, 0);

  lv_obj_t* label = lv_label_create(menuBox);
  lv_label_set_text(label, title);
  lv_obj_align(label, LV_ALIGN_TOP_LEFT, 22, 3);

  *toggle_out = lv_switch_create(menuBox);
  if (toggle_state) lv_obj_add_state(*toggle_out, LV_STATE_CHECKED);
  lv_obj_set_size(*toggle_out, 40, 22);
  lv_obj_align(*toggle_out, LV_ALIGN_TOP_RIGHT, 0, 0);
  lv_obj_set_style_bg_color(*toggle_out, lv_color_lighten(color_primary, 50), LV_PART_MAIN);
  lv_obj_set_style_bg_color(*toggle_out, color_primary, LV_PART_INDICATOR);
  lv_obj_add_event_cb(*toggle_out, smartHomeToggle_event_cb, LV_EVENT_VALUE_CHANGED, (void*)(intptr_t)user_id);

  *slider_out = lv_slider_create(menuBox);
  lv_slider_set_range(*slider_out, 0, 100);
  lv_obj_set_style_bg_color(*slider_out, lv_color_lighten(lv_color_black(), 30), LV_PART_INDICATOR);
  lv_obj_set_style_bg_grad_color(*slider_out, lv_color_lighten(lv_palette_main(LV_PALETTE_AMBER), 180), LV_PART_INDICATOR);
  lv_obj_set_style_bg_grad_dir(*slider_out, LV_GRAD_DIR_HOR, LV_PART_INDICATOR);
  lv_obj_set_style_bg_color(*slider_out, lv_color_white(), LV_PART_KNOB);
  lv_obj_set_style_bg_opa(*slider_out, 255, LV_PART_MAIN);
  lv_obj_set_style_bg_color(*slider_out, lv_color_lighten(color_primary, 50), LV_PART_MAIN);
  lv_slider_set_value(*slider_out, slider_value, LV_ANIM_OFF);
  lv_obj_set_size(*slider_out, lv_pct(90), 10);
  lv_obj_align(*slider_out, LV_ALIGN_TOP_MID, 0, 37);
  lv_obj_add_event_cb(*slider_out, smartHomeSlider_event_cb, LV_EVENT_VALUE_CHANGED, (void*)(intptr_t)user_id);
}

void create_tab_content_smarthome(lv_obj_t* tab) {
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_scrollbar_mode(tab, LV_SCROLLBAR_MODE_ACTIVE);

  lv_obj_t* menuLabel = lv_label_create(tab);
  lv_label_set_text(menuLabel, "Salon");

  create_device_control(tab, "La Boule", 1, lightToggleAstate, sliderAvalue, &lightToggleA, &sliderA);
  create_device_control(tab, "Plafond", 2, lightToggleBstate, sliderBvalue, &lightToggleB, &sliderB);

  menuLabel = lv_label_create(tab);
  lv_label_set_text(menuLabel, "Salle a manger");

  create_device_control(tab, "Plafond 2", 3, lightToggleCstate, sliderCvalue, &lightToggleC, &sliderC);
  create_device_control(tab, "Pixar", 4, lightToggleDstate, sliderDvalue, &lightToggleD, &sliderD);
  create_device_control(tab, "Nanoleaf", 5, lightToggleEstate, sliderEvalue, &lightToggleE, &sliderE);

  smartHomeTabIsInMemory = true;

}

void notify_tab_before_delete_smarthome(void) {
  lightToggleAstate = lv_obj_has_state(lightToggleA, LV_STATE_CHECKED);
  lightToggleBstate = lv_obj_has_state(lightToggleB, LV_STATE_CHECKED);
  lightToggleCstate = lv_obj_has_state(lightToggleC, LV_STATE_CHECKED);
  lightToggleDstate = lv_obj_has_state(lightToggleD, LV_STATE_CHECKED);
  lightToggleEstate = lv_obj_has_state(lightToggleE, LV_STATE_CHECKED);
  sliderAvalue = lv_slider_get_value(sliderA);
  sliderBvalue = lv_slider_get_value(sliderB);
  sliderCvalue = lv_slider_get_value(sliderC);
  sliderDvalue = lv_slider_get_value(sliderD);
  sliderEvalue = lv_slider_get_value(sliderE);
  smartHomeTabIsInMemory = false;
}

void gui_setKeys_smarthome() {
  key_commands_short_smarthome = {
    {KEY_STOP, SCENE_SELECTION},
  };
}

void register_gui_smarthome(void){
  register_gui(
    std::string(tabName_smarthome),
    & create_tab_content_smarthome,
    & notify_tab_before_delete_smarthome,
    & gui_setKeys_smarthome,
    & key_repeatModes_smarthome,
    & key_commands_short_smarthome,
    & key_commands_long_smarthome
  );

  register_command(&GUI_SMARTHOME_ACTIVATE, makeCommandData(GUI, {std::to_string(MAIN_GUI_LIST), std::string(tabName_smarthome)}));
}

void updateFromMQTTmessage(std::string topic, std::string payload) {
  if (!smartHomeTabIsInMemory) return;

  if (topic == "omote/remote/return") {
    // Gestion des états ON/OFF
    if (payload == "laboule_set_true")  { lv_obj_add_state(lightToggleA, LV_STATE_CHECKED);   lightToggleAstate = true; }
    if (payload == "laboule_set_false") { lv_obj_clear_state(lightToggleA, LV_STATE_CHECKED); lightToggleAstate = false;}
  
    if (payload == "salon_set_true")  { lv_obj_add_state(lightToggleB, LV_STATE_CHECKED);   lightToggleBstate = true; }
    if (payload == "salon_set_false") { lv_obj_clear_state(lightToggleB, LV_STATE_CHECKED); lightToggleBstate = false;}

    if (payload == "salleamanger_set_true")  { lv_obj_add_state(lightToggleC, LV_STATE_CHECKED);   lightToggleCstate = true; }
    if (payload == "salleamanger_set_false") { lv_obj_clear_state(lightToggleC, LV_STATE_CHECKED); lightToggleCstate = false;} 

    if (payload == "pixar_set_true")  { lv_obj_add_state(lightToggleD, LV_STATE_CHECKED);   lightToggleDstate = true; }
    if (payload == "pixar_set_false") { lv_obj_clear_state(lightToggleD, LV_STATE_CHECKED); lightToggleDstate = false;}
 
    if (payload == "nanoleaf_set_true")  { lv_obj_add_state(lightToggleE, LV_STATE_CHECKED);   lightToggleEstate = true; }
    if (payload == "nanoleaf_set_false") { lv_obj_clear_state(lightToggleE, LV_STATE_CHECKED); lightToggleEstate = false;}  
    
    if (payload.rfind("laboule_brightness_", 0) == 0) {
        std::string valueStr = payload.substr(strlen("laboule_brightness_"));
        int val = std::stoi(valueStr);
        lv_slider_set_value(sliderA, val, LV_ANIM_ON);
        sliderAvalue = val;
    }
    if (payload.rfind("salon_brightness_", 0) == 0) {
        std::string valueStr = payload.substr(strlen("salon_brightness_"));
        int val = std::stoi(valueStr);
        lv_slider_set_value(sliderB, val, LV_ANIM_ON);
        sliderBvalue = val;
    }
    if (payload.rfind("salleamanger_brightness_", 0) == 0) {
        std::string valueStr = payload.substr(strlen("salleamanger_brightness_"));
        int val = std::stoi(valueStr);
        lv_slider_set_value(sliderC, val, LV_ANIM_ON);
        sliderCvalue = val;
    }
    if (payload.rfind("pixar_brightness_", 0) == 0) {
        std::string valueStr = payload.substr(strlen("pixar_brightness_"));
        int val = std::stoi(valueStr);
        lv_slider_set_value(sliderD, val, LV_ANIM_ON);
        sliderDvalue = val;
    }
    if (payload.rfind("nanoleaf_brightness_", 0) == 0) {
        std::string valueStr = payload.substr(strlen("nanoleaf_brightness_"));
        int val = std::stoi(valueStr);
        lv_slider_set_value(sliderE, val, LV_ANIM_ON);
        sliderEvalue = val;
    }
  
  }
}

