cmake_minimum_required(VERSION 3.14)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(mySFML main.cpp Auto.cpp)
target_link_libraries(mySFML sfml-graphics sfml-window sfml-system)