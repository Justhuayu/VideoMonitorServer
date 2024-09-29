# utils 目录的 CMakeLists.txt
add_library(utils INTERFACE)

# 将 utils 目录作为头文件目录
target_include_directories(utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})