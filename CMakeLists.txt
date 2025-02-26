cmake_minimum_required(VERSION 3.30)
project(custom_print_test)

set(CMAKE_CXX_STANDARD 20)

add_executable(custom_print_test
        src/main.cpp
        src/measure_performance.cpp
        src/example.cpp)

target_include_directories(custom_print_test PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

add_subdirectory(lib/custom_print)

target_link_libraries(custom_print_test PRIVATE custom_print)

target_include_directories(custom_print_test PRIVATE lib/custom_print/include)