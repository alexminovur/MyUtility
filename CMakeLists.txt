cmake_minimum_required(VERSION 3.20)

project(MyUtility)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MACOSX_BUNDLE ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(MyUtility
        src/main.cpp
        src/VideoJob.cpp
        src/Downloader.cpp
        src/AudioExtractor.cpp
        src/Transcriber.cpp
        src/MyUtility.cpp

        gui/MainWindow.cpp
        include/MainWindow.hpp
)

target_include_directories(MyUtility PRIVATE
        include
        gui
)

target_link_libraries(MyUtility PRIVATE Qt6::Widgets)
