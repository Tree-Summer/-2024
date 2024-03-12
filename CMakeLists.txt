cmake_minimum_required(VERSION 3.24)
project(wyl_git)

set(CMAKE_C_STANDARD 11)

add_executable(wyl_git main.cpp robot.cpp boat.cpp MAPPA.cpp berth.cpp)
