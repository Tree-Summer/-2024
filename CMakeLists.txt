cmake_minimum_required(VERSION 3.24)
project(wyl_git)

set(CMAKE_CXX_STANDARD 17)

add_executable(wyl_git goods.cpp map.cpp robot.cpp ship.cpp  main.cpp goods.h map.h robot.h ship.h)