#include "QEI.h"

int  Encoder_Left,Encoder_Right;         		  //左右编码器的脉冲计数
int  Encoder_Left_cnt=0,Encoder_Right_cnt=0;
int  count,speed,count_last;

void get_Encoder(void)
{
count = DL_Timer_getTimerCount(QEI_0_INST);     //可得到定时器的计数值
speed = count - count_last;
count_last = count;
}

void get_encoder_value(void)
{
	get_Encoder();
	Encoder_Left=speed;
	Encoder_Right=speed;
//  Encoder_Left_cnt+=Encoder_Left;//累计出路程
//	Encoder_Right_cnt+=Encoder_Right;
	Encoder_Left_cnt=count;//累计出路程
	Encoder_Right_cnt=count;
}

void QEI_0_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(QEI_0_INST)) {
        case DL_TIMER_IIDX_DIR_CHANGE:
            if (DL_TimerG_getQEIDirection(QEI_0_INST) == DL_TIMER_QEI_DIR_DOWN)
                DL_GPIO_clearPins(GPIO_LEDS_PORT, GPIO_LEDS_USER_LED_1_PIN);
            else
                DL_GPIO_setPins(GPIO_LEDS_PORT, GPIO_LEDS_USER_LED_1_PIN);
        default:
            break;
    }
}


