#include "MotorDriver.h"

// ─────────────────────────────────────────────────────────────
// 构造函数与析构函数
// ─────────────────────────────────────────────────────────────

/**
 * @brief 构造函数
 *
 * 初始化四个电机，分别绑定到 PORT1 ~ PORT4，
 * 默认方向为正转（false 表示不反转）。
 */
MotorDriver::MotorDriver()
    : motors{
        vex::motor(vex::PORT1, false),  // 电机 0：PORT1，正转
        vex::motor(vex::PORT2, false),  // 电机 1：PORT2，正转
        vex::motor(vex::PORT3, false),  // 电机 2：PORT3，正转
        vex::motor(vex::PORT4, false)   // 电机 3：PORT4，正转
      }
{
    // 构造时不做额外操作，由 init() 负责复位
}

/**
 * @brief 析构函数
 *
 * 销毁实例前停止所有电机，确保硬件安全。
 */
MotorDriver::~MotorDriver() {
    stopAll();
}

// ─────────────────────────────────────────────────────────────
// 公共接口实现
// ─────────────────────────────────────────────────────────────

/**
 * @brief 初始化所有电机
 *
 * 将所有电机的速度清零，并重置编码器计数值。
 */
void MotorDriver::init() {
    for (int i = 0; i < MAX_MOTORS; i++) {
        motors[i].stop();                                  // 停止电机
        motors[i].resetPosition();                         // 重置编码器
        motors[i].setVelocity(0, vex::velocityUnits::pct); // 初始速度为 0
    }
}

/**
 * @brief 设置指定电机的速度
 *
 * @param motorId 电机编号（0 到 3）
 * @param speed   速度值（-100 到 100），负值表示反转
 */
void MotorDriver::setMotorSpeed(int motorId, int speed) {
    // 检查电机编号是否合法
    if (!isValidMotorId(motorId)) {
        return;
    }

    // 将速度限制在 -100 到 100 的范围内
    if (speed > 100)  speed = 100;
    if (speed < -100) speed = -100;

    // 设置速度并启动电机（旋转方向由速度正负决定）
    motors[motorId].setVelocity(speed, vex::velocityUnits::pct);
    motors[motorId].spin(vex::directionType::fwd);
}

/**
 * @brief 停止指定电机
 *
 * @param motorId 电机编号（0 到 3）
 */
void MotorDriver::stopMotor(int motorId) {
    // 检查电机编号是否合法
    if (!isValidMotorId(motorId)) {
        return;
    }

    motors[motorId].stop();
}

/**
 * @brief 停止所有电机
 *
 * 依次停止四个电机。
 */
void MotorDriver::stopAll() {
    for (int i = 0; i < MAX_MOTORS; i++) {
        motors[i].stop();
    }
}

/**
 * @brief 设置指定电机的旋转方向
 *
 * @param motorId 电机编号（0 到 3）
 * @param reverse true 表示反转，false 表示正转
 */
void MotorDriver::reverseMotor(int motorId, bool reverse) {
    // 检查电机编号是否合法
    if (!isValidMotorId(motorId)) {
        return;
    }

    motors[motorId].setReversed(reverse);
}

// ─────────────────────────────────────────────────────────────
// 私有辅助函数
// ─────────────────────────────────────────────────────────────

/**
 * @brief 检查电机编号是否在合法范围内
 *
 * @param motorId 待检查的电机编号
 * @return true 合法（0 到 MAX_MOTORS-1），false 非法
 */
bool MotorDriver::isValidMotorId(int motorId) const {
    return (motorId >= 0 && motorId < MAX_MOTORS);
}
