/**
 * @file main.cpp
 * @brief VEX V5 四电机驱动示例程序
 *
 * 本文件展示如何使用 MotorDriver 类对四个 VEX V5 智能电机
 * 进行初始化和协调控制。所有注释均使用中文。
 */

#include "vex.h"
#include "MotorDriver.h"

// VEX 竞赛环境要求的全局 brain 对象
vex::brain Brain;

// ─────────────────────────────────────────────────────────────
// 辅助函数：等待指定毫秒数
// ─────────────────────────────────────────────────────────────
static void waitMs(int ms) {
    vex::task::sleep(ms);
}

// ─────────────────────────────────────────────────────────────
// 主程序入口
// ─────────────────────────────────────────────────────────────
int main() {
    // 1. 创建电机驱动器实例
    MotorDriver driver;

    // 2. 初始化所有电机（复位速度和编码器）
    driver.init();

    // ── 示例一：四电机同步前进 ──────────────────────────────
    Brain.Screen.print("示例一：同步前进 50%%");
    Brain.Screen.newLine();

    driver.setMotorSpeed(0, 50);   // 电机 0 速度 50%
    driver.setMotorSpeed(1, 50);   // 电机 1 速度 50%
    driver.setMotorSpeed(2, 50);   // 电机 2 速度 50%
    driver.setMotorSpeed(3, 50);   // 电机 3 速度 50%

    waitMs(2000);                  // 运行 2 秒

    // ── 示例二：四电机同步后退 ──────────────────────────────
    Brain.Screen.print("示例二：同步后退 -50%%");
    Brain.Screen.newLine();

    driver.setMotorSpeed(0, -50);  // 电机 0 反转 50%
    driver.setMotorSpeed(1, -50);  // 电机 1 反转 50%
    driver.setMotorSpeed(2, -50);  // 电机 2 反转 50%
    driver.setMotorSpeed(3, -50);  // 电机 3 反转 50%

    waitMs(2000);                  // 运行 2 秒

    // ── 示例三：左右差速转向（原地右转） ───────────────────
    Brain.Screen.print("示例三：原地右转");
    Brain.Screen.newLine();

    // 左侧电机（0、2）正转，右侧电机（1、3）反转
    driver.setMotorSpeed(0,  50);
    driver.setMotorSpeed(1, -50);
    driver.setMotorSpeed(2,  50);
    driver.setMotorSpeed(3, -50);

    waitMs(1500);                  // 转向 1.5 秒

    // ── 示例四：设置电机反转标志并控制速度 ─────────────────
    Brain.Screen.print("示例四：反转标志测试");
    Brain.Screen.newLine();

    driver.reverseMotor(1, true);  // 将电机 1 设为硬件反转
    driver.reverseMotor(3, true);  // 将电机 3 设为硬件反转

    // 此时向所有电机发送相同的正速度值，机器人仍可直行
    driver.setMotorSpeed(0, 70);
    driver.setMotorSpeed(1, 70);
    driver.setMotorSpeed(2, 70);
    driver.setMotorSpeed(3, 70);

    waitMs(2000);                  // 运行 2 秒

    // 恢复反转设置
    driver.reverseMotor(1, false);
    driver.reverseMotor(3, false);

    // ── 示例五：逐个停止电机 ────────────────────────────────
    Brain.Screen.print("示例五：逐个停止");
    Brain.Screen.newLine();

    driver.stopMotor(0);           // 先停电机 0
    waitMs(500);
    driver.stopMotor(1);           // 再停电机 1
    waitMs(500);
    driver.stopMotor(2);           // 再停电机 2
    waitMs(500);
    driver.stopMotor(3);           // 最后停电机 3

    // ── 最终：停止所有电机 ──────────────────────────────────
    driver.stopAll();
    Brain.Screen.print("所有电机已停止");
    Brain.Screen.newLine();

    return 0;
}
