cmake_minimum_required(VERSION 3.13)
project(dz_01)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(dz_01 main.cpp source/tests.cpp source/forward_list.hpp)

target_link_libraries(dz_01 gtest gtest_main)
