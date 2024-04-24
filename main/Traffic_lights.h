#pragma once
#include "esp_log.h"
#include "freertos/FreeRTOS.h"

#include "global.h"
#include <string.h>

static const char *TAG = "traffic";

void Read_controller()
{
  gpio_set_direction(gpio_num_t(in0), GPIO_MODE_INPUT);

  esp_rom_delay_us(5000);
  controller_stat[0] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(20000);
  controller_stat[2] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(10000);
  controller_stat[3] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(10000);
  controller_stat[4] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(10000);
  controller_stat[5] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(10000);
  controller_stat[6] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(40000);
  controller_stat[10] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(15000);

  esp_rom_delay_us(45000);
  controller_phase[4] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(10000);
  controller_phase[5] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(10000);
  controller_phase[6] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(10000);
  controller_phase[7] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(10000);
  controller_phase[8] = gpio_get_level(gpio_num_t(in0));
  esp_rom_delay_us(15000);

  // gpio_set_direction(gpio_num_t(in0), GPIO_MODE_INPUT);
  // //  esp_rom_delay_us(45000);
  // vTaskDelay(pdMS_TO_TICKS(40));
  // controller_phase[4] = gpio_get_level(gpio_num_t(in0));
  // // esp_rom_delay_us(10000);
  // vTaskDelay(pdMS_TO_TICKS(10));
  // controller_phase[5] = gpio_get_level(gpio_num_t(in0));
  // // esp_rom_delay_us(10000);
  // vTaskDelay(pdMS_TO_TICKS(10));
  // controller_phase[6] = gpio_get_level(gpio_num_t(in0));
  // vTaskDelay(pdMS_TO_TICKS(10));
  // // esp_rom_delay_us(10000);
  // controller_phase[7] = gpio_get_level(gpio_num_t(in0));
  // vTaskDelay(pdMS_TO_TICKS(10));
  // // esp_rom_delay_us(10000);
  // controller_phase[8] = gpio_get_level(gpio_num_t(in0));
  // vTaskDelay(pdMS_TO_TICKS(20));
  // // esp_rom_delay_us(15000);
}

void Faza_1()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  // vTaskDelay(pdMS_TO_TICKS(790));
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(20));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  // vTaskDelay(pdMS_TO_TICKS(10));
  vTaskDelay(pdMS_TO_TICKS(110));
}

void Faza_2()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

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
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_3()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(60));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(20));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(20));
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_4()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

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
  vTaskDelay(pdMS_TO_TICKS(10));
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_5()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(50));

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
  vTaskDelay(pdMS_TO_TICKS(20));
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_6()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(50));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(20));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(30));
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_7()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(50));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(30));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_8()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

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
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_9()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

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
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_10()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

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
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_11()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

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
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_12()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(40));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(20));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(40));
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_13()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(500));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(40));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(30));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(30));
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_14()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));

  Read_controller();

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(540));
  // vTaskDelay(pdMS_TO_TICKS(830));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(30));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_15()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));
  Read_controller();
  vTaskDelay(pdMS_TO_TICKS(540));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(40));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(20));
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Phase_selection()
{
  if (faza == 1)
    Faza_1();
  if (faza == 2)
    Faza_2();
  if (faza == 3)
    Faza_3();
  if (faza == 4)
    Faza_4();
  if (faza == 5)
    Faza_5();
  if (faza == 6)
    Faza_6();
  if (faza == 7)
    Faza_7();
  if (faza == 8)
    Faza_8();
  if (faza == 9)
    Faza_9();
  if (faza == 10)
    Faza_10();
  if (faza == 11)
    Faza_11();
  if (faza == 12)
    Faza_12();
}

bool Check_pedastrian(int i)
{
  JsonArray stages = doc["stages"].as<JsonArray>();
  bool cont = false;
  for (const auto &stage : stages)
  {
    JsonArray groups = stage["groups"].as<JsonArray>();
    std::string nam = "Фаза." + std::to_string(i + 1);
    if (stage["name"] == nam)
    {
      for (const auto &group : groups)
      {
        JsonArray items = doc["signalGroups"]["items"].as<JsonArray>();
        std::string item_grupp = "Группа." + std::to_string(group.as<int>());
        for (const auto &item : items)
        {
          if (item_grupp == item["name"])
            if (item["type"] == "pedestrian")
            {
              if (pedastrian == false)
                return false;
              else
              {
                if (doc["plans"][0]["algorithm"]["phases"][i]["recall"] == "none")
                {
                  pedastrian = false;
                  return true;
                }
                else
                  return true;
              }
            }
        }
      }
    }
  }
  return true;
}

void Button_pedastrian(void *pvParameter)
{
  while (1)
  {
    if (gpio_get_level(gpio_num_t(in1)) == 0)
      pedastrian = 1;
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

int i = 0;
time_t t = 0;

void Traffic_lights(void *pvParameter)
{
  if (!there_config)
    json_desearelization();

  while (1)
  {
    // if (gpio_get_level(gpio_num_t(in1)) == 0)
    //   pedastrian = 1;

    if (main_mode_state == std::string("on") && yellow_flashing_state == std::string("off") && os_state == std::string("off") && manual_mode_state == std::string("off"))
    {
      if (there_config)
      {
        get_current_time();
        if (t <= now)
        {
          if (i >= doc["stages"].size())
          {
            i = 0;
          }
          if (doc["plans"][0]["algorithm"]["phases"][i])
          {
            if (Check_pedastrian(i))
            {
              t = now + (time_t)doc["plans"][0]["algorithm"]["phases"][i]["minGreen"] + (time_t)doc["IGM"][0]["items"][0]["time"];

              faza = i + 1;
              //  std::cout << (time_t)doc["plans"][0]["algorithm"]["phases"][i]["minGreen"] << " " << (time_t)doc["IGM"][0]["items"][0]["time"] << " " << faza << std::endl;
            }
            ++i;
          }
        }
        //   std::cout << pedastrian << " " << gpio_get_level(gpio_num_t(in1)) << " " << i << " "
        //            << "фаза:" << faza << std::endl;

        Phase_selection();
      }
      else
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    else if (yellow_flashing_state == std::string("on") && os_state == std::string("off") && manual_mode_state == std::string("off"))
    {
      faza = 14;
      Faza_14();
    }
    else if (os_state == std::string("on") && yellow_flashing_state == std::string("off") && manual_mode_state == std::string("off"))
    {
      faza = 15;
      Faza_15();
    }
    else if (faza > 0)
      if (manual_mode_state == std::string("on"))
      {
        Phase_selection();
      }
    // vTaskDelay(pdMS_TO_TICKS(100));
    // std::cout << "время: " << now << " "
    //           << "t: " << t << " "
    //           << "фаза: " << faza << std::endl;

     std::cout << controller_stat[0] << controller_stat[1] << controller_stat[2] << controller_stat[3] << controller_stat[4] << controller_stat[5]
              << controller_stat[6] << controller_stat[7] << controller_stat[8] << controller_stat[9] << controller_stat[10] << controller_stat[11] << std::endl;

    std::cout << controller_phase[0] << controller_phase[1] << controller_phase[2] << controller_phase[3] << controller_phase[4] << controller_phase[5]
              << controller_phase[6] << controller_phase[7] << controller_phase[8] << controller_phase[9] << " " << faza << std::endl;

    std::fill(&controller_phase[0], &controller_phase[9], 0);
    std::fill(&controller_stat[0], &controller_stat[11], 0);
  }
}