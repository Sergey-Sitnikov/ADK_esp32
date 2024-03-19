#pragma once
#include <string>
// #include "nlohmann/json.hpp"
#include <ArduinoJson.h>
// using namespace std;
StaticJsonDocument<10240> doc;
// cJSON docc;
// cJSON *root = cJSON_CreateObject();
//  using json = nlohmann::json;
//  json doc;

int faza = 0;
std::string main_mode_state = "on";
std::string yellow_flashing_state = "off";
std::string os_state = "off";
std::string manual_mode_state = "off";
bool there_config = false; //   файл конфигурации
unsigned char time_circle = 0;
unsigned long last_time = 0;
unsigned long current_time = 0;

esp_err_t ret;
esp_vfs_spiffs_conf_t conf;
// File fsUploadFile;

bool findJson();
void jsonread();
void configureWebServer();
void json_desearelization();
