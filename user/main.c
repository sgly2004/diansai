#include "main.h"

int main(void)
{
    SYSCFG_DL_init();
	
//	IMU_Init(); 
// Timer_Init();  
	
	MaixCam_Init();
	OLED_Init(); 
//	ZDT_Init();
	Encoder_init();
	
//  POS_Control(30 , 200*256, YAW);
	Emm_V5_En_Control(1, false, false, UART_1_INST); // 电机使能控制
	Emm_V5_En_Control(1, false, false, UART_0_INST);
//	Emm_V5_Stop_Now(0x01,false,UART_1_INST);
//	vTaskDelay(10);
	delay_noOS(100);
	
	//注释这两句就是裸机运行
	StartupTask();						//任务创建初始化 
	vTaskStartScheduler();  	//开启任务调度
	
	//程序不会运行到这个while，接着是运行StartupTask.c文件中的每一个函数，
	//他们会同时运行
	while(1)
	{

	}
}
