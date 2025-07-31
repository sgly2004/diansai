#include "Motor.h"


void Set_Motor(MOTOTx Motor,int16_t compare)
{
	if(compare>7000) compare=7000;
	else if(compare<-7000) compare=-7000;
	
	switch(Motor)
	{
		case MOTOR1:
			if(compare>0)
			{
				MOTOR1_1(1);
				MOTOR1_2(0);
			}
			else if(compare==0)
			{
				MOTOR1_1(0);
				MOTOR1_2(0);
			}
			else
			{
				MOTOR1_1(0);
				MOTOR1_2(1);
			}
			M1_PWM(compare);			
			break;
		
		case MOTOR2:
			if(compare>=0)
			{
				MOTOR2_1(0);
				MOTOR2_2(1);
			}
			else if(compare==0)
			{
				MOTOR2_1(0);
				MOTOR2_2(0);
			}
			else
			{
				MOTOR2_1(1);
				MOTOR2_2(0);
			}
			M2_PWM(compare);			
			break;
		default:
			break;
	}

}

void Motor_Write(int16_t compare1,int16_t compare2)
{
	Set_Motor(MOTOR1,compare1);
	Set_Motor(MOTOR2,compare2);
}