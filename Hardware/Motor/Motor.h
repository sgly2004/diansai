#ifndef __MOTOR_H
#define __MOTOR_H


#include "main.h"


#define M_ABS(x)            (x<0?-x:x)


#define MOTOR1_1(x)         do{if(x>0)DL_GPIO_setPins(M1_1_Dir_PORT,M1_1_Dir_PIN_1_PIN);else DL_GPIO_clearPins(M1_1_Dir_PORT,M1_1_Dir_PIN_1_PIN); }while(0); 
#define MOTOR1_2(x)         do{if(x>0)DL_GPIO_setPins(M1_2_Dir_PORT ,M1_2_Dir_PIN_2_PIN);else DL_GPIO_clearPins(M1_2_Dir_PORT,M1_2_Dir_PIN_2_PIN);}while(0);

#define MOTOR2_1(x)         do{if(x>0)DL_GPIO_setPins(M2_1_Dir_PORT,M2_1_Dir_PIN_3_PIN);else DL_GPIO_clearPins(M2_1_Dir_PORT,M2_1_Dir_PIN_3_PIN); }while(0);  
#define MOTOR2_2(x)         do{if(x>0)DL_GPIO_setPins(M2_2_Dir_PORT,M2_2_Dir_PIN_4_PIN);else DL_GPIO_clearPins(M2_2_Dir_PORT,M2_2_Dir_PIN_4_PIN);}while(0);
 

#define M1_PWM(x)			do{DL_TimerG_setCaptureCompareValue(MOTOR_PWM_INST,M_ABS(x)  ,GPIO_MOTOR_PWM_C0_IDX);}while(0);
#define M2_PWM(x)			do{DL_TimerG_setCaptureCompareValue(MOTOR_PWM_INST,M_ABS(x)  ,GPIO_MOTOR_PWM_C1_IDX);}while(0);


typedef enum{MOTOR1=1,MOTOR2=2,MOTOR3=3,MOTOR4=4}MOTOTx;

void Motor_Init(void);
void Set_Motor(MOTOTx Motor,int16_t compare);
void Motor_Write(int16_t compare1,int16_t compare2);

#endif