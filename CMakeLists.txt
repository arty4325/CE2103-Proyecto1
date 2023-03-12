cmake_minimum_required(VERSION 3.24)
project(Proyecto_1_BattleSpace)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto_1_BattleSpace main.cpp)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
