#ifndef __EMM_V5_H
#define __EMM_V5_H

#include "main.h"

/**********************************************************
***	Emm_V5.0步进闭环控制例程
***	编写作者：ZHANGDATOU
***	技术支持：张大头闭环伺服
***	淘宝店铺：https://zhangdatou.taobao.com
***	CSDN博客：http s://blog.csdn.net/zhangdatou666
***	qq交流群：262438510
**********************************************************/

extern __IO bool rxFrameFlag;
#define		ABS(x)		((x) > 0 ? (x) : -(x)) 

typedef enum {

    YAW =  0,
    PITCH = 1,

}wheel_type;

typedef enum {
	S_VER   = 0,			/* 读取固件版本和对应的硬件版本 */
	S_RL    = 1,			/* 读取读取相电阻和相电感 */
	S_PID   = 2,			/* 读取PID参数 */
	S_VBUS  = 3,			/* 读取总线电压 */
	S_CPHA  = 5,			/* 读取相电流 */
	S_ENCL  = 7,			/* 读取经过线性化校准后的编码器值 */
	S_TPOS  = 8,			/* 读取电机目标位置角度 */
	S_VEL   = 9,			/* 读取电机实时转速 */
	S_CPOS  = 10,			/* 读取电机实时位置角度 */
	S_PERR  = 11,			/* 读取电机位置误差角度 */
	S_FLAG  = 13,			/* 读取使能/到位/堵转状态标志位 */
	S_Conf  = 14,			/* 读取驱动参数 */
	S_State = 15,			/* 读取系统状态参数 */
	S_ORG   = 16,     /* 读取正在回零/回零失败状态标志位 */
}SysParams_t;

typedef  struct
{
    uint8_t id;      //ID
    uint8_t cmd;     //辨识码
    uint8_t symbol;  //数据符号
	uint8_t data[2]; //速度数据
	uint8_t check;
} EmmV5_Speed_Info;

typedef  struct
{
    uint16_t speed;      //速度

} EmmV5_Info;

/**********************************************************
*** 注意：每个函数的参数的具体说明，请查阅对应函数的注释说明
**********************************************************/
void Emm_V5_Reset_CurPos_To_Zero(uint8_t addr,UART_Regs *huart); // 将当前位置清零
void Emm_V5_Reset_Clog_Pro(uint8_t addr,UART_Regs *huart); // 解除堵转保护
void Emm_V5_Read_Sys_Params(uint8_t addr, SysParams_t s,UART_Regs *huart); // 读取参数
void Emm_V5_Modify_Ctrl_Mode(uint8_t addr, bool svF, uint8_t ctrl_mode,UART_Regs *huart); // 发送命令修改开环/闭环控制模式
void Emm_V5_En_Control(uint8_t addr, bool state, bool snF,UART_Regs *huart); // 电机使能控制
void Emm_V5_Vel_Control(uint8_t addr, uint8_t dir, uint16_t vel, uint8_t acc, bool snF,UART_Regs *huart); // 速度模式控制
void Emm_V5_Pos_Control(uint8_t addr, uint8_t dir, uint16_t vel, uint8_t acc, uint32_t clk, bool raF, bool snF,UART_Regs *huart); // 位置模式控制
void Emm_V5_Stop_Now(uint8_t addr, bool snF,UART_Regs *huart); // 让电机立即停止运动
void Emm_V5_Synchronous_motion(uint8_t addr,UART_Regs *huart); // 触发多机同步开始运动
void Emm_V5_Origin_Set_O(uint8_t addr, bool svF,UART_Regs *huart); // 设置挡圈回零的零点位置
void Emm_V5_Origin_Modify_Params(uint8_t addr, bool svF, uint8_t o_mode, uint8_t o_dir, uint16_t o_vel, uint32_t o_tm, uint16_t sl_vel, uint16_t sl_ma, uint16_t sl_ms, bool potF,UART_Regs *huart); // 修改回零参数
void Emm_V5_Origin_Trigger_Return(uint8_t addr, uint8_t o_mode, bool snF,UART_Regs *huart); // 发送命令触发回零
void Emm_V5_Origin_Interrupt(uint8_t addr,UART_Regs *huart); // 强制中断并退出回零
void Wait_answer(void);//等待步进返回


 void Speed_Control(float speed, wheel_type wheel);
 void POS_Control(float speed, float pos, wheel_type wheel);

/**
  * @brief    电机数据读取
  * @param    pData :串口数据包
  * @return   数据是否更新成功（bool）
  */
bool Emm_V5_Data_Dispose(uint8_t *pData);

extern EmmV5_Speed_Info EmmV5_Speed;
extern EmmV5_Info EmmV5_return_Info;

#endif
