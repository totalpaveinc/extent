
cmake_minimum_required(VERSION 3.22.1)

project(extenttest VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    # main.cpp
    unit/Extent.cpp
)

add_executable(extenttest ${SOURCES})
target_link_libraries(extenttest tpgeomextent gtest gtest_main)
