cmake_minimum_required(VERSION 3.20)

project(MyUtility)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyUtility
    src/main.cpp
    src/VideoJob.cpp
    src/Downloader.cpp
)

target_include_directories(MyUtility PRIVATE include)

