#include "PID.h"


extern float Knum[6][32];
int16_t My_Speed;

PID T_X;
PID T_Y;

float My_Abs(float data)
{
	if(data<0)
	{
		data=-data;
	}
	return data;
}
/*
功能：获得PID参数
参数：无
返回：无
*/
void Get_PID_Data(void)
{
	switch(rule2[L_i])
	{
		case 0:
				T_X.Kp;
				T_X.Ki;
				T_X.Kd;
				T_Y.Kp;
				T_Y.Ki;
				T_Y.Kd;				
		break;
		
		case 1:
				T_X.Kp;
				T_X.Ki;
				T_X.Kd;
				T_Y.Kp;
				T_Y.Ki;
				T_Y.Kd;	
		break;
		
	}
}

void Limit(float* Soruce,float Limit_Max,float Limit_Min)
{
	if(*Soruce>Limit_Max)   *Soruce=Limit_Max;
	if(*Soruce<Limit_Min)   *Soruce=Limit_Min;
}


float Set_PID(PID* pid,int16_t err)
{
	float out;  
	static float Alph=0.8;
	pid->sum+=err;
	out=pid->Kp*err+pid->Ki*pid->sum+pid->Kd*(err-pid->Last_err);
	pid->Last_err=Alph*err+(1-Alph)*pid->Last_err;
	Limit(&out,9000.0,-9000.0);
	return out;
} 

float Set_x(int16_t err)
{
	 return Set_PID(&T_X,err);
}
float Set_y(int16_t err)
{
	 return Set_PID(&T_Y,err);
}




