#pragma once
#include <string>
// #include "nlohmann/json.hpp"
#include <ArduinoJson.h>
#include "esp_sntp.h"
#include "time.h"
#include <driver/gpio.h>
#include <array>

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
std::array<int, 10> controller_phase = {0};
std::array<int, 12> controller_stat = {0};
time_t now;
bool pedastrian = true;
const int S0 = 26;
const int S1 = 27;
const int in0 = 25;
const int in1 = 16; // кнопка 1
const int in2 = 17; // кнопка 2

const std::array<int, 10> first      = {0, 0, 0, 0, 0, 0, 0, 1, 1, 0};
const std::array<int, 10> second     = {0, 0, 0, 0, 0, 0, 1, 0, 1, 0};
const std::array<int, 10> third      = {0, 0, 0, 0, 0, 0, 1, 1, 0, 0};
const std::array<int, 10> fourth     = {0, 0, 0, 0, 0, 1, 0, 0, 1, 0};
const std::array<int, 10> fifth      = {0, 0, 0, 0, 0, 1, 0, 1, 0, 0};
const std::array<int, 10> sixth      = {0, 0, 0, 0, 0, 1, 1, 0, 0, 0};
const std::array<int, 10> seventh    = {0, 0, 0, 0, 0, 1, 1, 1, 1, 0};
const std::array<int, 10> eighth     = {0, 0, 0, 0, 1, 0, 0, 0, 1, 0};
const std::array<int, 10> ninth      = {0, 0, 0, 0, 1, 0, 0, 1, 0, 0};
const std::array<int, 10> tenth      = {0, 0, 0, 0, 1, 0, 1, 0, 0, 0};
const std::array<int, 10> eleventh   = {0, 0, 0, 0, 1, 0, 1, 1, 1, 0};
const std::array<int, 10> twelfth    = {0, 0, 0, 0, 1, 1, 0, 0, 0, 0};
const std::array<int, 10> thirteenth = {0, 0, 0, 0, 1, 1, 0, 1, 1, 0};
const std::array<int, 10> fourteenth = {0, 0, 0, 0, 1, 1, 1, 0, 1, 0};
const std::array<int, 10> fifteenth  = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0};

// struct tm timeinfo;
// time_t promtact = 0;

esp_err_t ret;
esp_vfs_spiffs_conf_t conf;
// File fsUploadFile;

bool findJson();
void jsonread();
void configureWebServer();
void json_desearelization();

static const char *TAG_T = "SET_TIME";
static void initialize_sntp(void)
{
    ESP_LOGI(TAG_T, "Инициализация SNTP");

    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_init();
}

void obtain_time(void)
{
    initialize_sntp();
    // time_t now = 0;
    struct tm timeinfo = {0};

    while (timeinfo.tm_year < (2020 - 1900))
    {
        ESP_LOGI(TAG_T, "Ожидание синхронизации времени...");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        time(&now);
        localtime_r(&now, &timeinfo);
    }
}

void get_current_time()
{
    // now;
    time(&now);
    //    ESP_LOGI(TAG_T, "Текущее время в секундах: %lld", now);
}