#ifndef _IMU_H
#define _IMU_H

#include "main.h"

#define IMU_DATA_SIZE  255

extern float IMU_Roll, IMU_Pitch,IMU_Yaw;

void IMU_Init(void);
	
#endif

