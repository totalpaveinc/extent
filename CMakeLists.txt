
cmake_minimum_required(VERSION 3.22.1)

project(tpgeomextent VERSION 0.0.1 LANGUAGES CXX)

if (PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed")
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(tpgeomextent STATIC
    include/tp/geom/Extent.h
    src/Extent.cpp
)

target_include_directories(tpgeomextent PUBLIC include/)
# add_executable(qttest test/main.cpp)
# target_link_libraries(qttest tpquadtree)
