#ifndef __SERVO_H
#define __SERVO_H

#include "main.h"                  // Device header
  
typedef enum{SERVO1=1,SERVO2=2,SERVO3=3,SERVO4=4}SERVOx;
	
void Set_Servo(SERVOx SERVO,float Angle );
void Set_Servo_raw(SERVOx SERVO, uint16_t value);

#endif