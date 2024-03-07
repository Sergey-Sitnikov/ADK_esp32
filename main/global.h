#pragma once
#include <string>
//using namespace std;

//StaticJsonDocument<10240> doc;

int faza = 0;
std::string main_mode_state = "on";
std::string yellow_flashing_state = "off";
std::string os_state = "off";
std::string manual_mode_state = "off";
bool there_config = false;            //   файл конфигурации
unsigned  char time_circle = 0;
unsigned long last_time = 0;
unsigned long current_time = 0;
//File fsUploadFile;


//string findJson();
void jsonread();
void configureWebServer();

