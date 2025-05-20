cmake_minimum_required(VERSION 3.31)
project(SDU_2_homework)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

#添加Qt5库(已弃用)
#if (WIN32)
    #set(Qt6_DIR "F:/Qt/6.7.3/mingw81_64/lib/cmake/Qt6")
#elseif (UNIX AND NOT APPLE)

#else ()

#endif ()

#寻找Qt6包
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB UI_HEADERS_UI ${PROJECT_SOURCE_DIR}/src/*.ui)

qt6_wrap_ui(UI_HEADERS ${UI_HEADERS_UI})

#set(CMAKE_EXE_LINKER_FLAGS "-static")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

set(HEADERS
    ./include/mainwindow.h
    ${UI_HEADERS})

add_executable(SDU_2_homework ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp  ${SRC_LIST} ${HEADERS})

#链接Qt6库
if(WIN32 OR UNIX AND NOT APPLE)
target_link_libraries(SDU_2_homework Qt6::Core Qt6::Gui Qt6::Widgets)
endif()