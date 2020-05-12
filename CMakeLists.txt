cmake_minimum_required(VERSION 3.16)
project(RWA3_Group5)

set(CMAKE_CXX_STANDARD 14)

add_executable(RWA3_Group5 main.cpp LandBasedRobot/landbasedrobot.cpp LandBasedRobot/landbasedrobot.h LandBasedTracked/LandBasedWheeled.cpp LandBasedTracked/LandBasedWheeled.h LandBasedWheeled/LandBasedTracked.cpp LandBasedWheeled/LandBasedTracked.h)