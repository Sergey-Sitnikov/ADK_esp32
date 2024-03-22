#pragma once
#include "esp_log.h"
#include "freertos/FreeRTOS.h"

#include "global.h"
#include <string.h>

static const char *TAG = "traffic";

void Faza_1()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(790));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(70));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 1);
  vTaskDelay(pdMS_TO_TICKS(20));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));
  vTaskDelay(pdMS_TO_TICKS(100));
}

void Faza_2()
{
  gpio_set_level(gpio_num_t(S1), 0);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(10));

  gpio_set_level(gpio_num_t(S1), 1);
  gpio_set_level(gpio_num_t(S0), 0);
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(790));

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
  vTaskDelay(pdMS_TO_TICKS(830));

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
  vTaskDelay(pdMS_TO_TICKS(830));

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
                  pedastrian = false;
                return true;
              }
            }
        }
      }
    }
  }
  return true;
}

int i = 0;
time_t t = 0;

void Traffic_lights(void *pvParameter)
{
  // std::cout << main_mode_state << " " << yellow_flashing_state << " " << os_state << " " << manual_mode_state << " " << std::endl;
  // uint promtact = doc["IGM"]["items"][1]["time"];
  if (!there_config)
    json_desearelization();

  while (1)
  {
    //   std::cout << there_config << std::endl;
    if (gpio_get_level(gpio_num_t(in1)) == 0)
      pedastrian = 1;

    if (main_mode_state == std::string("on") && yellow_flashing_state == std::string("off") && os_state == std::string("off") && manual_mode_state == std::string("off"))
    {
      if (there_config)
      {
        get_current_time();
        //    pedastrian = gpio_get_level(gpio_num_t(in1));
        if (t <= now)
        {
          if (doc["plans"][0]["algorithm"]["phases"][i])
          {
            if (Check_pedastrian(i))
            {
              t = now + (time_t)doc["plans"][0]["algorithm"]["phases"][i]["minGreen"] + (time_t)doc["IGM"][0]["items"][0]["time"];
              faza = i + 1;
              std::cout << (time_t)doc["plans"][0]["algorithm"]["phases"][i]["minGreen"] << " " << (time_t)doc["IGM"][0]["items"][0]["time"] << " " << faza << std::endl;
              ++i;
              //  }
            }
            else
            {
              faza = i + 2;
              i = +2;
            }
          }
          else
            i = 0;
          if (i >= doc["stages"].size())
            i = 0;
        }
        //  std::cout << i << std::endl;
        //    }
        std::cout << pedastrian << " " << gpio_get_level(gpio_num_t(in1)) << " " << i << std::endl;
        Phase_selection();

        //     std::cout << faza << " " << now << " " << t << std::endl;
      }
      else
        vTaskDelay(pdMS_TO_TICKS(100));
    }

    if (yellow_flashing_state == std::string("on") && os_state == std::string("off") && manual_mode_state == std::string("off"))
    {
      Faza_14();
    }

    if (os_state == std::string("on") && yellow_flashing_state == std::string("off") && manual_mode_state == std::string("off"))
    {
      Faza_15();
    }

    if (faza > 0)
      if (manual_mode_state == std::string("on"))
      {
        Phase_selection();
      }
    // vTaskDelay(pdMS_TO_TICKS(100));
    // std::cout << "время: " << now << " "
    //           << "t: " << t << " "
    //           << "фаза: " << faza << std::endl;
  }
}