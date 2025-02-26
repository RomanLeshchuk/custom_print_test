cmake_minimum_required(VERSION 3.30)
project(custom_print)

set(CMAKE_CXX_STANDARD 20)

add_library(custom_print STATIC
        src/my_printf.cpp
        src/my_print.cpp)

target_include_directories(custom_print PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)