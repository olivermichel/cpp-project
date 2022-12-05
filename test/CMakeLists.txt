
set(LIB_SRC
    add.h)

list(TRANSFORM LIB_SRC PREPEND ../src/lib/)

add_executable(unit unit_main.cc
    add_test.cc)

target_include_directories(unit PUBLIC ${PROJECT_SOURCE_DIR}/src/lib)
target_include_directories(unit PUBLIC ${PROJECT_SOURCE_DIR}/test/include)

add_test(NAME unit COMMAND unit WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
