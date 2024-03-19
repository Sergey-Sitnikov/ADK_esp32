cmake_minimum_required(VERSION 3.11)

#project(ADK CXX)
set(CMAKE_CXX_STANDARD 17)

set(srcs "enc28j60_example_main.cpp" "My_server.h" "global.h" "Traffic_lights.h" "connect_wifi.cpp" "connect_wifi.h")

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS ".")

spiffs_create_partition_image(storage ../spiffs_data FLASH_IN_PROJECT)
#find_package(nlohmann_json REQUIRED)
include_directories(/home/ssv/libraries_cpp/l_json/json/include)
include_directories(/home/ssv/libraries_cpp/Arduino_json/ArduinoJson/src)