cmake_minimum_required(VERSION 3.20)

project(esercitazione4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")


set(SRC_test_sorts timecounter.cpp calcolo_tempo.cpp)
add_executable(calcolo_tempo ${SRC_test_sorts})


add_executable(test_Mergesort test_Mergesort.cpp)
add_test(NAME Mergesort COMMAND test_Mergesort)

add_executable(test_Quicksort test_Quicksort.cpp)
add_test(NAME Quicksort COMMAND test_Quicksort)

add_executable(test_Bubblesort test_Bubblesort.cpp)
add_test(NAME Bubblesort COMMAND test_Bubblesort)

add_executable(test_Selectionsort test_Selectionsort.cpp)
add_test(NAME Selectionsort COMMAND test_Selectionsort)

add_executable(test_Insertionsort test_Insertionsort.cpp)
add_test(NAME Insertionsort COMMAND test_Insertionsort)


enable_testing()