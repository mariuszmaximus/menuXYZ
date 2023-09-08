cmake_minimum_required(VERSION 3.5)

project(menuXYZ VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_executable(menuXYZ  main.cpp menuxy.cpp menuxy.h)
target_link_libraries(menuXYZ PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

add_executable(menuXYZ_UI  mainwindow.cpp mainwindow.h mainwindow.ui main_UI.cpp menuxy.cpp menuxy.h)
target_link_libraries(menuXYZ_UI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
