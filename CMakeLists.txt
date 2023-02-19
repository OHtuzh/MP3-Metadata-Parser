cmake_minimum_required(VERSION 3.23)
project(labwork_7_OHtuzh)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib)

add_executable(labwork_7_OHtuzh main.cpp)

target_link_libraries(labwork_7_OHtuzh MP3_METADATA)