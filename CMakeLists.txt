cmake_minimum_required(VERSION 3.24)
project(cpp_project)

set(CMAKE_CXX_STANDARD 20)

include(cmake/catch.cmake)
include(cmake/cxxopts.cmake)

add_executable(add src/cmd/add_main.cc
    src/lib/add.h)

target_include_directories(add PUBLIC ext/include)
set_target_properties(add PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()
add_subdirectory(test)
