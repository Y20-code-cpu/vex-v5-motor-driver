# VEX V5 电机驱动项目

VEX V5 电机驱动 - 使用 C++ 实现四电机控制

## 项目概述

本项目基于 VEX 官方 C++ 软件库，为 VEX V5 机器人平台提供一套简洁易用的四电机驱动解决方案。代码采用模块化设计，所有注释均使用中文，便于理解和维护。

## 功能说明

- **初始化电机**：统一初始化四个 V5 电机
- **速度控制**：为指定电机设置 -100 到 100 范围内的速度
- **停止控制**：支持停止单个电机或一次性停止所有电机
- **电机反转**：可独立设置每个电机的旋转方向

## 使用方法

### 前置条件

- VEX V5 主控器
- 四个 VEX V5 智能电机，分别连接到端口 1、2、3、4
- VEX 官方 C++ 软件库

### 编译与构建

```bash
mkdir build
cd build
cmake ..
make
```

### 基本用法示例

```cpp
#include "MotorDriver.h"

int main() {
    // 创建电机驱动器实例
    MotorDriver driver;

    // 初始化所有电机
    driver.init();

    // 设置电机 0 的速度为 50%
    driver.setMotorSpeed(0, 50);

    // 停止所有电机
    driver.stopAll();

    return 0;
}
```

## 项目结构

```
vex-v5-motor-driver/
├── README.md                  # 项目说明文档（中文）
├── CMakeLists.txt             # CMake 构建配置
├── include/
│   └── MotorDriver.h          # 电机驱动器头文件
└── src/
    ├── main.cpp               # 主程序示例
    └── MotorDriver.cpp        # 电机驱动器实现
```

## MotorDriver 接口说明

| 函数 | 说明 |
|------|------|
| `init()` | 初始化所有电机 |
| `setMotorSpeed(int motorId, int speed)` | 设置指定电机速度（-100 到 100） |
| `stopMotor(int motorId)` | 停止指定电机 |
| `stopAll()` | 停止所有电机 |
| `reverseMotor(int motorId, bool reverse)` | 设置电机反转方向 |

## 注意事项

- 电机 ID 从 0 开始，范围为 0 到 3（对应四个电机）
- 速度值范围为 -100 到 100，负值表示反转
- 使用前请确保电机已正确连接到 VEX V5 主控器的对应端口
