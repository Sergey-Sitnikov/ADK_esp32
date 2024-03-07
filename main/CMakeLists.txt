cmake_minimum_required(VERSION 3.11)

#project(ADK CXX)
set(CMAKE_CXX_STANDARD 17)

set(srcs "enc28j60_example_main.cpp" "My_server.h" "global.h" "Traffic_lights.h")

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS ".")

#target_include_directories(your_target_name PRIVATE "/path/to/your/library")
#list(APPEND CMAKE_INCLUDE_PATH home/ssv/libraries_cpp/l_json/json/include/nlohmann)

spiffs_create_partition_image(storage ../spiffs_data FLASH_IN_PROJECT)
#target_include_directories(05.02.01 PUBLIC /home/ssv/libraries_cpp/l_json/json/include/nlohmann)
#add_subdirectory(home/ssv/libraries_cpp/l_json/json/)
#find_package(nlohmann_json REQUIRED)
#include_directories(/home/ssv/libraries_cpp/l_json/json/include/nlohmann)
#target_link_libraries(ADK /home/ssv/libraries_cpp/l_json/json/include/nlohmann)
