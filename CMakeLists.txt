cmake_minimum_required(VERSION 3.14)

project(GameSnack LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(GameSnack
  main.cpp SnackSceen.h SnackSceen.cpp
)
target_link_libraries(GameSnack Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS GameSnack
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
