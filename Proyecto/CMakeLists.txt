find_package(Qt5SerialPort REQUIRED)

cmake_minimum_required(VERSION 3.5)

project(Battle_Space)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH "/usr/lib/qt")



find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(Battle_Space main.cpp main.h SerialPort.h SerialPort.cpp ListaSimple.cpp ListaSimple.h Node.cpp Node.h SerialWorker.h SerialWorker.cpp main.cpp MenuDificultades.cpp MenuDificultades.h GameScreen.cpp GameScreen.h Player.cpp Player.h Enemigos.cpp Enemigos.h Bullets.cpp Bullets.h EasyEnemy.cpp EasyEnemy.h NodeList.cpp NodeList.h SimpleList.cpp SimpleList.h MediumEnemy.cpp MediumEnemy.h DifficultEnemy.cpp DifficultEnemy.h GameOver.cpp GameOver.h WonScreen.cpp WonScreen.h)
target_link_libraries(Battle_Space Qt5::SerialPort)


target_link_libraries(Battle_Space Qt5::Core Qt5::Gui Qt5::Widgets)

target_link_libraries(Battle_Space Qt5::Core Qt5::Gui Qt5::Widgets)
set_source_files_properties(SRC:/SerialThread.cpp PROPERTIES SKIP_AUTOMOC ON)  # Agregar esta línea
set(CMAKE_AUTOMOC_FLAGS "-fskip-targets=MOC_AUTOMOC_TARGETS_REGEX")

