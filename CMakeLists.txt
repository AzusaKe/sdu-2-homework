cmake_minimum_required(VERSION 3.31)
project(SDU_2_homework)

set(CMAKE_CXX_STANDARD 20)

#添加Qt5库
if (WIN32)
    set(Qt5_DIR "F:/Qt/5.15.18/mingw81_64/lib/cmake/Qt5")
elseif (UNIX AND NOT APPLE)
    set(Qt6_DIR "/home/tiny/Qt-6.9d/6.7.3/gcc_arm64/lib/cmake/Qt6")
else ()

endif ()

#寻找Qt5包
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

#set(CMAKE_EXE_LINKER_FLAGS "-static")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(SDU_2_homework ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp  ${SRC_LIST})

#链接Qt5库
if(WIN32 OR UNIX AND NOT APPLE)
target_link_libraries(SDU_2_homework Qt6::Core Qt6::Gui Qt6::Widgets)
endif()