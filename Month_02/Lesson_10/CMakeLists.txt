cmake_minimum_required(VERSION 3.5)

project(Statistics)

add_executable(statistics
        src/main.cpp
        src/IStatistics.h
        src/CMax.h
        src/CMax.cpp
        src/CMean.h
        src/CMean.cpp
        src/CMin.h
        src/CMin.cpp)
