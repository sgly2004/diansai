#ifndef __PID_H
#define __PID_H
#include "main.h"                  // Device header



typedef struct
{
    float Kp;
	float Ki;
	float Kd;
//    float err;
	float Last_err;
	float sum;
}PID;

extern PID T_X,T_Y;
void Get_PID_Data(void);
float Set_PID(PID* pid,int16_t err);
float Set_y(int16_t err);
float Set_x(int16_t err);

#endif
