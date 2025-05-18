cmake_minimum_required(VERSION 3.31)
project(SDU_2_homework)

set(CMAKE_CXX_STANDARD 20)

#添加Qt5库
if (WIN32)
    set(Qt5_DIR "F:/Qt/5.15.18/msvc2019_64/lib/cmake/Qt5")
elseif (UNIX AND NOT APPLE)

else ()

endif ()

#寻找Qt5包
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_EXE_LINKER_FLAGS "-static")

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(SDU_2_homework ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp  ${SRC_LIST})

#链接Qt5库
target_link_libraries(SDU_2_homework Qt5::Core Qt5::Gui Qt5::Widgets)
