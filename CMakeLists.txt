cmake_minimum_required(VERSION 3.14)
project(EjemploTDA)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS system window graphics)
add_executable(EjemploTDA main.cpp Auto.cpp)
target_link_libraries(EjemploTDA sfml-system sfml-window sfml-graphics)