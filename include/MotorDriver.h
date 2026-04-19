#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

// VEX V5 官方库头文件
#include "vex.h"

// 最大支持的电机数量
#define MAX_MOTORS 4

/**
 * @brief VEX V5 电机驱动器类
 *
 * 该类封装了对四个 VEX V5 智能电机的控制操作，
 * 提供初始化、速度控制、停止及方向反转等功能。
 */
class MotorDriver {
public:
    /**
     * @brief 构造函数
     *
     * 创建电机驱动器实例，并将四个电机分别绑定到
     * PORT1、PORT2、PORT3、PORT4。
     */
    MotorDriver();

    /**
     * @brief 析构函数
     *
     * 销毁电机驱动器实例前，先停止所有电机。
     */
    ~MotorDriver();

    /**
     * @brief 初始化所有电机
     *
     * 将所有电机速度重置为零，并清除编码器计数。
     */
    void init();

    /**
     * @brief 设置指定电机的速度
     *
     * @param motorId 电机编号（0 到 3）
     * @param speed   速度值（-100 到 100），负值表示反转
     */
    void setMotorSpeed(int motorId, int speed);

    /**
     * @brief 停止指定电机
     *
     * @param motorId 电机编号（0 到 3）
     */
    void stopMotor(int motorId);

    /**
     * @brief 停止所有电机
     *
     * 一次性将所有四个电机的速度设置为零。
     */
    void stopAll();

    /**
     * @brief 设置指定电机的旋转方向
     *
     * @param motorId 电机编号（0 到 3）
     * @param reverse true 表示反转，false 表示正转
     */
    void reverseMotor(int motorId, bool reverse);

private:
    // 四个 VEX V5 智能电机对象
    vex::motor motors[MAX_MOTORS];

    /**
     * @brief 检查电机编号是否合法
     *
     * @param motorId 待检查的电机编号
     * @return true 合法，false 非法
     */
    bool isValidMotorId(int motorId) const;
};

#endif // MOTOR_DRIVER_H
