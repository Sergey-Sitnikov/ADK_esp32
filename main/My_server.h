#pragma once
//#include <std::string>
#include "global.h"
//using namespace std;


std::string web()
{
  // if (findJson() != "NONE")
  // {
  //   if (there_config == false)
  //   {
  //     jsonread();
  //   }
  // }

  std::string index_html =
      "<!DOCTYPE html><html lang=\"ru\">"
      "<head>"
      "<meta charset=\"utf-8\" name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
      "<title> CDI устройство управления светофором </title>"
      "<link rel=\"icon\" href=\"data:,\">"
      "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}"
      ".button { background-color: GREY; border: none; color: white; padding: 16px 40px;"
      "text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}"
      ".button2 {background-color: GREEN;}"
      "</style>"
      "</head> "
      "<body><h1>CDI устройство управления светофором</h1>";

  std::string name_position;
  // if (there_config == true)
  //   name_position = doc["description"].as<std::string>();
  // else
  name_position = "null";
  index_html += name_position;

  index_html +=
      "<p>основной режим</p>";

  if (main_mode_state == "off")
  {
    index_html += "<p><a href=\"/main_mode/on\"><button class=\"button\">ВЫКЛ</button></a></p>";
  }
  else
  {
    index_html += "<p><a href=\"/main_mode/off\"><button class=\"button button2\">ВКЛ</button></a></p>";
  }
  index_html += "<p>мигающий жёлтый</p>";
  if (yellow_flashing_state == "off")
  {
    index_html += "<p><a href=\"/yellow_flashing/on\"><button class=\"button\">ВЫКЛ</button></a></p>";
  }
  else
  {
    index_html += "<p><a href=\"/yellow_flashing/off\"><button class=\"button button2\">ВКЛ</button></a></p>";
  }
  index_html +=
      "<p>ОС</p>";
  if (os_state == "off")
  {
    index_html +=
        "<p><a href=\"/os/on\"><button class=\"button\">ВЫКЛ</button></a></p>";
  }
  else
  {
    index_html += "<p><a href=\"/os/off\"><button class=\"button button2\">ВКЛ</button></a></p>";
  }

  index_html +=
      "<p>ручной режим</p>";
  if (there_config == true)
  {
    if (manual_mode_state == "on" && there_config == true)
    {
      index_html +=
          "<p><a href=\"/manual_mode/off\"><button class=\"button button2\">ВКЛ</button></a></p>"
          "<form method=\"POST\" action=\"/manual\">";
      // int j = doc["stages"].size();

      // for (int i = 0; i < j; ++i)
      // {
      //   std::string name = doc["stages"][i]["name"];
      //   index_html += "<input type=\"radio\" name=\"faza\" value=" + std::string(i) + ">";
      //   index_html += "Фаза " + std::string(i + 1);
      //   if (faza - 1 == i)
      //     index_html += "  v";
      //   index_html += "<br>";
      // }
      index_html += "<br>";
      index_html += "<input type=\"submit\" value=\"выбрать\">";
      index_html += "<br><br></form>";
    }
    else
    {
      index_html +=
          "<p><a href=\"/manual_mode/on\"><button class=\"button\">ВЫКЛ</button></a></p>";
    }
  }
  else
  {
    index_html += "<p>конфигурация не загружена</p>";
  }
  index_html +=
      "<form method=\"POST\" action=\"/upload\" enctype=\"multipart/form-data\">загрузить конфигурацию: <input type=\"file\" name=\"data\"/><input type=\"submit\" value=\"загрузить\"></form>";

  index_html +=
      "<form action=\"/download\"  method='POST' >"
      "<p>скачать конфигурацию: <input type=\"submit\" value=\"Скачать\"></p></form>";
  index_html +=
      "</body></html>";
  return index_html;
}