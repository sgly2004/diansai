#include "servo.h"


void DL_Timer_setCaptureCompareValue2(
    GPTIMER_Regs *gptimer, uint32_t value, DL_TIMER_CC_INDEX ccIndex)
{
    volatile uint32_t *pReg;

    pReg = &gptimer->COUNTERREGS.CC_01[0];
    pReg += (uint32_t) ccIndex;

    *pReg = (value);
}
		 
void Set_Servo(SERVOx SERVO,float Angle )
{
	Angle=Angle>180?180:Angle;
	uint16_t x=Angle /180*2000+500;
	switch(SERVO)
	{
		case SERVO1:
		    DL_TimerG_setCaptureCompareValue(Servo_INST,x,GPIO_Servo_C0_IDX);
			break;
		
		case SERVO2:
			DL_TimerG_setCaptureCompareValue(Servo_INST,x,GPIO_Servo_C1_IDX);
			break;
		
		case SERVO3:
			DL_TimerG_setCaptureCompareValue(Servo_INST,x,GPIO_Servo_C2_IDX);
			break;
		
		case SERVO4:
			DL_TimerG_setCaptureCompareValue(Servo_INST,x,GPIO_Servo_C3_IDX);
			break;
	}
}

//1600-8000
void Set_Servo_raw(SERVOx SERVO, uint16_t value)
{
	// value=value>8000?8000:value;
	// value=value<1600?1600:value;
	switch(SERVO)
	{
		case SERVO1:
		    DL_TimerG_setCaptureCompareValue(Servo_INST,value,GPIO_Servo_C0_IDX);
			break;
		
		case SERVO2:
			DL_TimerG_setCaptureCompareValue(Servo_INST,value,GPIO_Servo_C1_IDX);
			break;
		
		case SERVO3:
			DL_TimerG_setCaptureCompareValue(Servo_INST,value,GPIO_Servo_C2_IDX);
			break;
		
		case SERVO4:
			DL_TimerG_setCaptureCompareValue(Servo_INST,value,GPIO_Servo_C3_IDX);
			break;
	}
}

