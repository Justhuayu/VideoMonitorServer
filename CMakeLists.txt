cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(VideoMonitorServer)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加network目录作为子目录
add_subdirectory(network)
add_subdirectory(utils)

# 添加main目录
add_executable(main main.cpp)

# 链接network库到main
target_link_libraries(main PRIVATE network utils)
