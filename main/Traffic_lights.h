#pragma once
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "global.h"
#include <string.h>

static const char *TAG = "traffic";

const int S0 = 26;
const int S1 = 27;
const int in = 25;

void Traffic_lights(void *pvParameter)
{
  while (1)
  {
    // Serial.println(time);
    // Serial.println(current_time);
    // Serial.println(time_circle);

    /* if (yellow_flashing_state == "on" && os_state == "off" && manual_mode_state == "off") {
      //  if (yellow_flashing_state == "on") {
      if (time_circle == 0) {
        gpio_set_level(gpio_num_t(S1), 0);
        gpio_set_level(gpio_num_t(S0), 0);
      }
      if (time_circle == 1) {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
      }
      if (time_circle == 84) {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
      }
      if (time_circle == 87) {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
      }
      if (time_circle == 88) {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
      }
      if (time_circle == 89) {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
      }

    }*/
    if (yellow_flashing_state == std::string("on") && os_state == std::string("off") && manual_mode_state == std::string("off"))
    {
      //  if (yellow_flashing_state == "on") {
      gpio_set_level(gpio_num_t(S1), 0);
      gpio_set_level(gpio_num_t(S0), 0);
      // vTaskDelay(pdMS_TO_TICKS(10);
      vTaskDelay(pdMS_TO_TICKS(10));
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 0);
      // vTaskDelay(pdMS_TO_TICKS(830);
      vTaskDelay(pdMS_TO_TICKS(830));
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 1);
      // vTaskDelay(pdMS_TO_TICKS(30);
      vTaskDelay(pdMS_TO_TICKS(30));
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 0);
      // vTaskDelay(pdMS_TO_TICKS(10);
      vTaskDelay(pdMS_TO_TICKS(10));
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 1);
      // vTaskDelay(pdMS_TO_TICKS(10);
      vTaskDelay(pdMS_TO_TICKS(10));
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 0);
      // vTaskDelay(pdMS_TO_TICKS(110);
      vTaskDelay(pdMS_TO_TICKS(10));
      // ESP_LOGI(TAG, "YF");
    }
    
    if (os_state == std::string("on") && yellow_flashing_state == std::string("off") && manual_mode_state == std::string("off"))
    {
      gpio_set_level(gpio_num_t(S1), 0);
      gpio_set_level(gpio_num_t(S0), 0);
      vTaskDelay(pdMS_TO_TICKS(10));

      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 0);

      vTaskDelay(pdMS_TO_TICKS(830));
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 1);
      vTaskDelay(pdMS_TO_TICKS(40));
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 0);
      vTaskDelay(pdMS_TO_TICKS(20));
      //   ESP_LOGI(TAG, "OS");
    }
    // Serial.println(faza);

    if (manual_mode_state == std::string("on") && faza > 0)
    {
      // ESP_LOGI(TAG, "MM");
      gpio_set_level(gpio_num_t(S1), 0);
      gpio_set_level(gpio_num_t(S0), 0);
      vTaskDelay(pdMS_TO_TICKS(10));

      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 0);
      vTaskDelay(pdMS_TO_TICKS(790));

      if (faza == 1)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(70));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(20));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(10));
      }

      if (faza == 2)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(60));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(10));
      }
      if (faza == 3)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(60));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(20));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(20));
      }
      if (faza == 4)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(50));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(20));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(110));
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(20));
      }
      if (faza == 6)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(50));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(20));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(30));
      }
      if (faza == 7)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(50));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(40));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(10));
      }
      if (faza == 8)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(40));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(30));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(10));
      }
      if (faza == 8)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(40));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(20));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(20));
      }
      if (faza == 10)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(40));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(30));
      }
      if (faza == 11)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(40));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(30));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(10));
      }
      if (faza == 12)
      {
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(40));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 1);
        vTaskDelay(pdMS_TO_TICKS(20));
        gpio_set_level(gpio_num_t(S1), 1);
        gpio_set_level(gpio_num_t(S0), 0);
        vTaskDelay(pdMS_TO_TICKS(40));
      }
      
    }
    
    /*if (yellow_flashing_state == "on" && os_state == "off" && all_red_state == "off") {
      //  if (yellow_flashing_state == "on") {

      gpio_set_level(gpio_num_t(S1), 0);
      gpio_set_level(gpio_num_t(S0), 0);
      vTaskDelay(pdMS_TO_TICKS(10);

      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 0);

      vTaskDelay(pdMS_TO_TICKS(830);
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 1);
      vTaskDelay(pdMS_TO_TICKS(30);
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 0);
      vTaskDelay(pdMS_TO_TICKS(10);
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 1);
      vTaskDelay(pdMS_TO_TICKS(10);
      gpio_set_level(gpio_num_t(S1), 1);
      gpio_set_level(gpio_num_t(S0), 0);
      vTaskDelay(pdMS_TO_TICKS(110);
    }*/
    //  ++time_circle;
    //   if (time_circle == 100)
    //     time_circle = 0;

     vTaskDelay(pdMS_TO_TICKS(100));
  }
}