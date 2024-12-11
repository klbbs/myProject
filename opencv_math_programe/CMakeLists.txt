cmake_minimum_required(VERSION 3.1)
project(hello)

# 查找 OpenCV 并包含头文件路径
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# 包含项目的头文件路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 获取 src 目录中的所有源文件来构建库
file(GLOB allsrc "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_library(reg STATIC ${allsrc})

# 将 OpenCV 链接到库
target_link_libraries(reg ${OpenCV_LIBS})

# 定义可执行文件并链接到库 reg
add_executable(aVideoTest main.cpp)
target_link_libraries(aVideoTest reg ${OpenCV_LIBS})
