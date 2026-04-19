cmake_minimum_required(VERSION 3.10)

# 项目名称与版本
project(vex_v5_motor_driver VERSION 1.0.0 LANGUAGES CXX)

# 使用 C++11 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ── 头文件搜索路径 ──────────────────────────────────────────
# 包含本项目的 include 目录以及 VEX 官方库的头文件目录
# 请根据实际安装路径修改 VEX_SDK_PATH
set(VEX_SDK_PATH "" CACHE PATH "VEX V5 官方 SDK 安装路径")

include_directories(
    ${CMAKE_SOURCE_DIR}/include      # 本项目头文件目录
)

# 若用户提供了 SDK 路径，追加到头文件搜索路径
if(NOT "${VEX_SDK_PATH}" STREQUAL "")
    include_directories(${VEX_SDK_PATH}/include)
    link_directories(${VEX_SDK_PATH}/lib)
endif()

# ── 源文件列表 ──────────────────────────────────────────────
set(SOURCES
    src/main.cpp
    src/MotorDriver.cpp
)

# ── 可执行目标 ──────────────────────────────────────────────
add_executable(${PROJECT_NAME} ${SOURCES})

# ── 编译选项 ────────────────────────────────────────────────
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall       # 开启常见警告
    -Wextra     # 开启额外警告
)

# ── 说明 ────────────────────────────────────────────────────
message(STATUS "项目：${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "构建类型：${CMAKE_BUILD_TYPE}")
message(STATUS "C++ 标准：C++${CMAKE_CXX_STANDARD}")
message(STATUS "请将 VEX_SDK_PATH 设置为 VEX V5 官方 SDK 的安装路径")
