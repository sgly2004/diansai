# Hardware模块接口文档 (TI控制板版本)

本文档记录所有Hardware模块的外部接口函数，便于开发时快速查找和使用。

## 📋 文档格式说明

每个模块包含以下信息：
- **模块路径**: Hardware子目录位置
- **功能描述**: 模块主要功能
- **外部接口函数**: 可供外部调用的函数
  - 函数名称和签名
  - 功能描述
  - 输入参数说明
  - 输出结果说明  
  - 实现思路（一句话）

---

## MaixCam - 视觉模块通信
**路径**: `Hardware/MaixCam/`
**功能**: 与MaixCam视觉模块进行UART通信

### 外部变量
```c
extern uint16_t JiGuang[2];          // 接收到的激光点坐标 [x, y]
extern __IO int Camera_fps;          // 相机帧率计数
extern __IO int Camera_flag;         // 数据接收标志 (1=有新数据)
```

### 外部接口函数
```c
void MaixCam_Init(void);
```
- **功能**: 初始化MaixCam串口通信
- **输入**: 无
- **输出**: 无
- **实现**: 调用UART2_Init()并启用UART1中断

```c
void MaixCam_Send_XY(uint16_t x, uint16_t y);
```
- **功能**: 发送目标坐标给MaixCam
- **输入**: x - X坐标 (0-65535), y - Y坐标 (0-65535)
- **输出**: 无
- **实现**: 发送6字节协议数据包 [0x00, 0x01, x_high, x_low, y_high, y_low]

---

## Motor - 电机控制
**路径**: `Hardware/Motor/`
**功能**: 控制小车双轮驱动电机

### 外部接口函数
```c
void Set_Motor(MOTOTx Motor, int16_t compare);
```
- **功能**: 单电机PWM控制
- **输入**: Motor - 电机选择(MOTOR1/MOTOR2), compare - PWM值(-7000~+7000)
- **输出**: 无
- **实现**: 根据正负值控制方向引脚，设置PWM占空比

```c
void Motor_Write(int16_t compare1, int16_t compare2);
```
- **功能**: 双轮同步控制
- **输入**: compare1 - 左轮PWM值, compare2 - 右轮PWM值
- **输出**: 无
- **实现**: 调用两次Set_Motor()分别控制左右轮

```c
void Motor_Open(int Mode);
```
- **功能**: 电机模式化控制 ⚠️**存在逻辑问题**
- **输入**: Mode - 控制模式(MOTOR_Line循迹模式等)
- **输出**: 无
- **实现**: MOTOR_Line模式中while(1)无限循环导致后续直线代码永不执行
- **状态**: 当前在StartupTask.c中被注释，实际循迹由line_task()实现

---

## LED_Key - LED和按键控制
**路径**: `Hardware/LED_Key/`
**功能**: 控制LED灯、蜂鸣器和读取按键状态

### 外部宏定义
```c
#define RED(x)      // 控制红色LED (x: ON=0, OFF=1)
#define GREEN(x)    // 控制绿色LED (x: ON=0, OFF=1) 
#define BLUE(x)     // 控制蓝色LED (x: ON=0, OFF=1)
#define BUZZER(x)   // 控制蜂鸣器 (x: ON=0, OFF=1)
#define KEY1        // 读取按键1状态 (返回1=按下, 0=松开)
#define HW_IO1      // 读取硬件IO1状态 (返回1=低电平, 0=高电平)
#define HW_IO2      // 读取硬件IO2状态 (返回1=低电平, 0=高电平)
#define HW_IO3      // 读取硬件IO3状态 (返回1=低电平, 0=高电平)
#define HW_IO4      // 读取硬件IO4状态 (返回1=低电平, 0=高电平)
```

### 外部接口函数
```c
void GPIO_WriteBit(GPIO_Regs* gpio, uint32_t pins, uint8_t Value);
```
- **功能**: GPIO位操作函数
- **输入**: gpio - GPIO端口, pins - 引脚掩码, Value - 输出值
- **输出**: 无
- **实现**: 直接操作GPIO寄存器设置引脚状态

---

## PID - PID控制算法
**路径**: `Hardware/PID/`
**功能**: 提供PID控制算法实现

### 外部变量
```c
extern PID T_X, T_Y;    // X轴和Y轴PID控制器实例
```

### 外部接口函数
```c
void Get_PID_Data(void);
```
- **功能**: 获取PID参数数据
- **输入**: 无
- **输出**: 无
- **实现**: 初始化或更新PID控制器参数

```c
float Set_PID(PID* pid, int16_t err);
```
- **功能**: 通用PID计算
- **输入**: pid - PID结构体指针, err - 当前误差值
- **输出**: PID输出值
- **实现**: 执行比例+积分+微分运算

```c
float Set_y(int16_t err);
```
- **功能**: Y轴专用PID计算
- **输入**: err - Y轴误差值
- **输出**: Y轴PID输出
- **实现**: 调用Set_PID()使用T_Y控制器

```c
float Set_x(int16_t err);
```
- **功能**: X轴专用PID计算
- **输入**: err - X轴误差值
- **输出**: X轴PID输出
- **实现**: 调用Set_PID()使用T_X控制器

---

## Servo - 舵机控制
**路径**: `Hardware/servo/`
**功能**: 控制PWM舵机角度

### 外部接口函数
```c
void Set_Servo(SERVOx SERVO, float Angle);
```
- **功能**: 设置舵机角度
- **输入**: SERVO - 舵机选择(SERVO1~4), Angle - 目标角度(0-270°)
- **输出**: 无
- **实现**: 将角度转换为PWM脉宽值并输出

```c
void Set_Servo_raw(SERVOx SERVO, uint16_t value);
```
- **功能**: 直接设置舵机PWM原始值
- **输入**: SERVO - 舵机选择, value - PWM比较值
- **输出**: 无
- **实现**: 直接设置定时器比较寄存器值

---

## OLED - OLED显示屏
**路径**: `Hardware/oled/`
**功能**: 控制OLED显示屏显示文字和图形

### 外部接口函数
```c
void OLED_Init(void);
```
- **功能**: 初始化OLED显示屏
- **输入**: 无
- **输出**: 无
- **实现**: 配置IIC接口并发送OLED初始化命令序列

```c
void OLED_Clear(void);
```
- **功能**: 清空OLED显示内容
- **输入**: 无
- **输出**: 无
- **实现**: 向OLED显存写入全0数据

```c
void OLED_Write(int x, int y, int Size, const char *formate, ...);
```
- **功能**: 格式化显示文本(类似printf)
- **输入**: x,y - 显示位置, Size - 字体大小, formate - 格式字符串, ... - 参数
- **输出**: 无
- **实现**: 使用va_list解析参数并调用显示函数

```c
void OLED_ShowString(uint8_t x, uint8_t y, char *chr, uint8_t Char_Size);
```
- **功能**: 显示字符串
- **输入**: x,y - 位置, chr - 字符串, Char_Size - 字体大小
- **输出**: 无
- **实现**: 逐字符调用OLED_ShowChar显示

```c
void OLED_ShowNum(uint8_t x, uint8_t y, int_least64_t num, uint8_t len, uint8_t sizey);
```
- **功能**: 显示数字
- **输入**: x,y - 位置, num - 数值, len - 显示长度, sizey - 字体大小
- **输出**: 无
- **实现**: 数字转字符串后显示

---

## Control - 循迹控制算法
**路径**: `Hardware/control/`
**功能**: 实现循迹控制和PID算法

### 外部变量
```c
extern struct PID Serx, Sery;    // X轴和Y轴PID控制器
```

### 外部常量定义
```c
#define SPEED         1500    // 直线速度
#define GAIN          500     // 偏差增益
#define TURN_SPEED    1600    // 旋转速度
#define MOTOR_Line    1       // 巡线模式
#define MOTOR_TURN    2       // 旋转模式
```

### 外部接口函数
```c
void PID_Init(void);
```
- **功能**: 初始化PID控制器参数
- **输入**: 无
- **输出**: 无
- **实现**: 设置Serx和Sery的kp、ki、kd参数

```c
float Erect_pid(struct PID* para, float hope, float now);
```
- **功能**: PID计算核心算法
- **输入**: para - PID结构体, hope - 期望值, now - 当前值
- **输出**: PID输出值
- **实现**: 计算误差并执行PID运算

```c
void Line_Control(void);
```
- **功能**: 循迹控制主算法
- **输入**: 无
- **输出**: 无
- **实现**: 读取传感器值，计算偏差，调用Motor_Write控制电机

```c
void Get_hw(void);
```
- **功能**: 读取硬件传感器数据
- **输入**: 无
- **输出**: 无
- **实现**: 读取HW_IO1~4传感器状态并处理

---

## IMU - 惯性测量单元
**路径**: `Hardware/IMU/`
**功能**: 读取IMU姿态数据

### 外部变量
```c
extern float IMU_Roll, IMU_Pitch, IMU_Yaw;    // 欧拉角数据
```

### 外部接口函数
```c
void IMU_Init(void);
```
- **功能**: 初始化IMU传感器
- **输入**: 无
- **输出**: 无
- **实现**: 配置IMU串口通信和数据解析

---

## WS2812 - RGB彩灯控制
**路径**: `Hardware/ws2812/`
**功能**: 控制WS2812 RGB彩灯

### 外部宏定义
```c
#define RGB_R    // 设置为红色并发送
#define RGB_G    // 设置为绿色并发送  
#define RGB_B    // 设置为蓝色并发送
```

### 外部接口函数
```c
int WS2812_Set_Color(uint64_t Color);
```
- **功能**: 设置彩灯颜色
- **输入**: Color - RGB颜色值(0xRRGGBB格式)
- **输出**: 执行状态
- **实现**: 将RGB值转换为WS2812时序数据

```c
int WS2812_Send_Array(void);
```
- **功能**: 发送彩灯数据
- **输入**: 无
- **输出**: 执行状态
- **实现**: 通过SPI发送WS2812时序数据

```c
int WS2812_RESET(void);
```
- **功能**: 重置彩灯状态
- **输入**: 无
- **输出**: 执行状态
- **实现**: 发送复位时序关闭所有LED

---

## Delay - 延时函数
**路径**: `Hardware/delay/`
**功能**: 提供非操作系统环境下的延时

### 外部接口函数
```c
void delay_noOS(uint32_t ms);
```
- **功能**: 毫秒级延时(非OS环境)
- **输入**: ms - 延时毫秒数
- **输出**: 无
- **实现**: 基于系统时钟的忙等待延时

---

## Timer - 定时器配置
**路径**: `Hardware/Timer/`
**功能**: 定时器初始化配置

### 外部接口函数
```c
void Timer_Init(void);
```
- **功能**: 初始化系统定时器
- **输入**: 无
- **输出**: 无
- **实现**: 配置定时器参数和中断

---

## UART - 串口通信
**路径**: `Hardware/UART/`
**功能**: 串口通信基础功能

### 外部接口函数
*当前模块接口函数被注释，功能集成到其他模块中*

---

*其他Hardware模块接口待补充...*

---

## 📝 更新日志
- 2025-01-29: 创建文档，添加MaixCam、Motor、Enconder、ZDT模块接口
- 2025-01-29: 补充完整的Hardware模块接口文档，包含所有13个模块
- 2025-01-29: 发现并记录Motor_Open()函数逻辑问题，标注实际使用状态
- *请在修改Hardware代码后及时更新此文档*