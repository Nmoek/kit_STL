cmake_minimum_required(VERSION 3.0)
project(kit_STL)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include (cmake/utils.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

include_directories(.)

set(LIB_SRC


)

# add_library(kit_STL SHARED ${LIB_SRC})
# redefine_file_macro(kit_STL)  # redefine __FILE__


set(LIB_LIB
    pthread
)

# *************************************tests************************************* #
add_executable(test_alloctor tests/test_alloctor.cpp)
redefine_file_macro(test_alloctor)
target_link_libraries(test_alloctor ${LIB_LIB})


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)