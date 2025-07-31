#ifndef __CONTROL_H
#define __CONTROL_H

#include "main.h"                  // Device header

#define SPEED    2000            //直线速度
#define GAIN     750             //偏差增益
#define GAIN_K   2               //大角度偏差增益

#define TURN_SPEED    1600            //旋转速度
#define LEFT_OR        -1             //左旋转
#define RIGHT_OR        1             //右旋转

#define MOTOR_Line        1           //巡线模							式
#define MOTOR_TURN        2           //旋转模式

extern struct PID Serx,Sery;

struct PID
{
	float kp;
	float ki;
	float kd;
	
	float err;
	float err_last;
	float err_last_dev;
	float err_last_dev_last;
	float err_last_dev_lastdev;
	float err_add;
	
	float ki_p;
	
	float out;
};

float Erect_pid(struct PID* para,float hope, float now);
void PID_Init(void);
void Motor_Open(int Mode);
void Line_Control(void);
void Get_hw(void);

void Set_PID_1(void);
void Set_PID_2(void);


void TI(void);

#endif
