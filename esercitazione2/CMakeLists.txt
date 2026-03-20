cmake_minimum_required(VERSION 3.20)
project(myproject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")
set(SOURCE2 primialgoritmi.cpp)
set(SOURCE1 Figura1.cpp)
set(SOURCE3 Bubblesort.cpp)


add_executable(primialgoritmi ${SOURCE2})
add_executable(Figura1 ${SOURCE1})
add_executable(Bubblesort ${SOURCE3})