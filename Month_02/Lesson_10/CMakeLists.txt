cmake_minimum_required(VERSION 3.5)

project(Statistics)

add_executable(statistics
        src/main.cpp
        src/IStatistics.h
        src/CMin.h
        src/CMin.cpp)
