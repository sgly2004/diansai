#include "Enconder.h"

int16_t Speed1_Temp,Speed2_Temp;
int16_t dir=1;
//uint16_t distance=0;

void Get_Encoder(int16_t* buf)
{ 
//	if(DL_Timer_getQEIDirection(QEI_0_INST) == 1)     dir=-1;  
//	else                                 dir=1; 
	buf[0] = DL_Timer_getTimerCount(QEI_0_INST) * dir;
	DL_Timer_setTimerCount(QEI_0_INST, 0);
}


void Encoder_init(void)
{
//	//编码器引脚外部中断
//	NVIC_ClearPendingIRQ(ENCODER_INT_IRQN);
//	NVIC_EnableIRQ(ENCODER_INT_IRQN);
	DL_TimerG_startCounter(QEI_0_INST);
}