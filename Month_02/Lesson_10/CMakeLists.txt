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
        src/CMin.cpp
        src/CPct90.h
        src/CPct90.cpp
        src/CPct95.h
        src/CPct95.cpp
        src/CStdDev.h
        src/CStdDev.cpp)
