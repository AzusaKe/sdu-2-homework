cmake_minimum_required(VERSION 3.31)
project(SDU_2_homework)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_EXE_LINKER_FLAGS "-static")

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(SDU_2_homework ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp  ${SRC_LIST})
