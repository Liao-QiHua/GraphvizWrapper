cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(GraphvizWrapper)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)

# 添加头文件目录
include_directories(include)

# 添加源代码目录
add_subdirectory(src)

# 添加测试目录
add_subdirectory(tests)
