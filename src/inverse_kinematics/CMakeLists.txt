# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.12)

# 项目信息 项目名称和使用的C++标准
project (stewart_ik)
set(CMAKE_CXX_FLAGS "-std=c++11")

# 执行文件输出路径，这里需要改成调用该函数的python环境
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
set(PYTHON EXECUTABLE "~/anaconda3/envs/python/stewart/bin/python3")

# 头文件和源文件保存路径
#set(INCLUDE_DIR ./include)
set(SRC_DIR ../)
find_package(pybind11 REQUIRED)
include_directories(${pybind11_INCLUDE_DIRS})

# 链接python的库文件
link_directories(~/anaconda3/lib)  

# 将python头文件包含进来
INCLUDE_DIRECTORIES(~/anaconda3/envs/python/stewart/include/python3.9)

# 链接到python动态库文件
link_libraries(~/anaconda3/pkgs/python-3.9.7-h12debd9_1/lib/libpython3.9.so)

#include_directories(${INCLUDE_DIR})
file(GLOB_RECURSE SOURCES "*.cpp")

Pybind11_add_module(stewart_ik ${SOURCES})


