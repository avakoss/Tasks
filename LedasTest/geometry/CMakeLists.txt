cmake_minimum_required(VERSION 3.23)
project(LedasTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(LedasTest src/main.cpp src/Geometry.cpp)