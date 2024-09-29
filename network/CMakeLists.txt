# 声明网络库
add_library(network STATIC VMSocket.cpp)

# 包含目录
target_include_directories(network PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}  ${CMAKE_SOURCE_DIR}/utils)

target_link_libraries(network PUBLIC utils)
