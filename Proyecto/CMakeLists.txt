
cmake_minimum_required(VERSION 3.5)

project(Battle_Space)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)



find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(Battle_Space nave_jugador.cpp nave_jugador.h)

target_link_libraries(Battle_Space Qt5::Core Qt5::Gui Qt5::Widgets)

target_link_libraries(Battle_Space Qt5::Core Qt5::Gui Qt5::Widgets)

set(CMAKE_AUTOMOC_FLAGS "-fskip-targets=MOC_AUTOMOC_TARGETS_REGEX")

