#include "StartupTask.h"

#define START_TASK_PRIO 10  						//任务优先级
#define START_STK_SIZE 1024 							//任务堆栈
static TaskHandle_t StartTask_Handler; 	//任务句柄

#define RGB_TASK_PRIO 6  							//任务优先级
#define RGB_STK_SIZE 512 							//任务堆栈
static TaskHandle_t RGBTask_Handler; 	//任务句
void RGB_task(void *pvParameters);

#define OLED_TASK_PRIO 6  							//任务优先级
#define OLED_STK_SIZE 512 							//任务堆栈
static TaskHandle_t OLEDTask_Handler; 	//任务句
void OLED_task(void *pvParameters);

#define main_TASK_PRIO 6  							//任务优先级
#define main_STK_SIZE 512 							//任务堆栈
static TaskHandle_t mainTask_Handler; 	//任务句
void main_task(void *pvParameters);

#define line_TASK_PRIO 6  							//任务优先级
#define line_STK_SIZE 128 							//任务堆栈
static TaskHandle_t lineTask_Handler; 	//任务句
void line_task(void *pvParameters);

#define Set0_TASK_PRIO 6  							//任务优先级
#define Set0_STK_SIZE 256 							//任务堆栈
static TaskHandle_t Set0Task_Handler; 	//任务句
void Set0_task(void *pvParameters);

#define Circle_TASK_PRIO 6  							//任务优先级
#define Circle_STK_SIZE 256 							//任务堆栈
static TaskHandle_t Circle_Task_Handler; 	//任务句
void circle_task(void *pvParameters);

#define QEI_TASK_PRIO 6  							//任务优先级
#define QEI_STK_SIZE 128 							//任务堆栈
static TaskHandle_t QEI_Task_Handler; 	//任务句
void QEI_task(void *pvParameters);

/**********************************************************************************************************
*函 数 名: start_task
*功能说明: 创建所有任务
*形    参: *pvParameters
*返 回 值: 无
**********************************************************************************************************/
//void start_task(void *pvParameters)
//{
////	taskENTER_CRITICAL();//进入临界区
//	

//	xTaskCreate((TaskFunction_t ) RGB_task,          	 //任务函数
//							(char*          ) "RGB",           		 //任务名字  
//							(uint16_t       ) RGB_STK_SIZE,     	 //任务堆栈
//							(void*          ) NULL,                //传入的任务参数
//							(UBaseType_t    ) RGB_TASK_PRIO,       //任务优先级
//							(TaskHandle_t*  ) &RGBTask_Handler); 	 //任务句柄
//							

//	xTaskCreate((TaskFunction_t ) OLED_task,          	 //任务函数
//							(char*          ) "OLED",           		 //任务名字  
//							(uint16_t       ) OLED_STK_SIZE,     	 //任务堆栈
//							(void*          ) NULL,                //传入的任务参数
//							(UBaseType_t    ) OLED_TASK_PRIO,       //任务优先级
//							(TaskHandle_t*  ) &OLEDTask_Handler); 	 //任务句柄
//	
//	xTaskCreate((TaskFunction_t ) main_task,          	 //任务函数
//							(char*          ) "main",           		 //任务名字  
//							(uint16_t       ) main_STK_SIZE,     	 //任务堆栈
//							(void*          ) NULL,                //传入的任务参数
//							(UBaseType_t    ) main_TASK_PRIO,       //任务优先级
//							(TaskHandle_t*  ) &mainTask_Handler); 	 //任务句柄
//							
//	xTaskCreate((TaskFunction_t ) line_task,          	 //任务函数
//							(char*          ) "line",           		 //任务名字  
//							(uint16_t       ) line_STK_SIZE,     	 //任务堆栈
//							(void*          ) NULL,                //传入的任务参数
//							(UBaseType_t    ) line_TASK_PRIO,       //任务优先级
//							(TaskHandle_t*  ) &lineTask_Handler); 	 //任务句柄
//	
////	vTaskDelete(StartTask_Handler); //删除开始任务
////	
////  taskEXIT_CRITICAL();            //退出临界区
//}

/**********************************************************************************************************
*函 数 名: StartupTast
*功能说明: 创建初始化任务
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void StartupTask(void)
{
	
		xTaskCreate((TaskFunction_t ) RGB_task,          	 //任务函数
							(char*          ) "RGB",           		 //任务名字  
							(uint16_t       ) RGB_STK_SIZE,     	 //任务堆栈
							(void*          ) NULL,                //传入的任务参数
							(UBaseType_t    ) RGB_TASK_PRIO,       //任务优先级
							(TaskHandle_t*  ) &RGBTask_Handler); 	 //任务句柄
							

	xTaskCreate((TaskFunction_t ) OLED_task,          	 //任务函数
							(char*          ) "OLED",           		 //任务名字  
							(uint16_t       ) OLED_STK_SIZE,     	 //任务堆栈
							(void*          ) NULL,                //传入的任务参数
							(UBaseType_t    ) OLED_TASK_PRIO,       //任务优先级
							(TaskHandle_t*  ) &OLEDTask_Handler); 	 //任务句柄
	
	xTaskCreate((TaskFunction_t ) main_task,          	 //任务函数
							(char*          ) "main",           		 //任务名字  
							(uint16_t       ) main_STK_SIZE,     	 //任务堆栈
							(void*          ) NULL,                //传入的任务参数
							(UBaseType_t    ) main_TASK_PRIO,       //任务优先级
							(TaskHandle_t*  ) &mainTask_Handler); 	 //任务句柄
							
	xTaskCreate((TaskFunction_t ) line_task,          	 //任务函数
							(char*          ) "line",           		 //任务名字  
							(uint16_t       ) line_STK_SIZE,     	 //任务堆栈
							(void*          ) NULL,                //传入的任务参数
							(UBaseType_t    ) line_TASK_PRIO,       //任务优先级
							(TaskHandle_t*  ) &lineTask_Handler); 	 //任务句柄

	xTaskCreate((TaskFunction_t ) Set0_task,          	 //任务函数
							(char*          ) "Set0",           		 //任务名字  
							(uint16_t       ) Set0_STK_SIZE,     	 //任务堆栈
							(void*          ) NULL,                //传入的任务参数
							(UBaseType_t    ) Set0_TASK_PRIO,       //任务优先级
							(TaskHandle_t*  ) &Set0Task_Handler); 	 //任务句柄
							
	xTaskCreate((TaskFunction_t ) circle_task,          	 //任务函数
							(char*          ) "Circle",           		 //任务名字  
							(uint16_t       ) Circle_STK_SIZE,     	 //任务堆栈
							(void*          ) NULL,                //传入的任务参数
							(UBaseType_t    ) Circle_TASK_PRIO,       //任务优先级
							(TaskHandle_t*  ) &Circle_Task_Handler); 	 //任务句柄
							
	xTaskCreate((TaskFunction_t ) QEI_task,          	 //任务函数
							(char*          ) "QEI",           		 //任务名字  
							(uint16_t       ) QEI_STK_SIZE,     	 //任务堆栈
							(void*          ) NULL,                //传入的任务参数
							(UBaseType_t    ) QEI_TASK_PRIO,       //任务优先级
							(TaskHandle_t*  ) &QEI_Task_Handler); 	 //任务句柄
							
						
							
}

//可以检查堆栈是否溢出，溢出则调用该函数
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName)
{

}
//malloc失败时被调用
void vApplicationMallocFailedHook( void )
{

}

//空闲任务钩子函数，当系统进入空闲状态时，FreeRTOS会周期性地调用vApplicationIdleHook函数。
void vApplicationIdleHook( void )
{

}

//随着系统滴答进行调用,1ms一次
void vApplicationTickHook( void )
{

}

void RGB_task(void *pvParameters)
{
	uint32_t Color=0x0000ff;
	
	vTaskDelay(500);
	
	while (1)
	{
//		Color=Color<<8;
//		if(Color>0xff0000)Color=0x0000ff;
//		WS2812_Set_Color(Color);
//        WS2812_Send_Array(); // 发送更新
		vTaskDelay(1000);
	
	}
}

#define Y_Init		6000
#define X_SPEED_MAX  12		//云台X轴速度限幅
#define FABS(a) (a>0?a:-a)
int err_cx,err_cy;
int Greenx=320/2,Greeny=125;		//目标点
float CyPwmOut=Y_Init,Cy_out;
int test=0;
int Start_flag=0,Set0_flag=0,Set0_status=0, Ccircle_flag=0;	//用于各个task的启动标志
int YunTai_EN=0,Line_EN=0;		//云台和循迹使能功能标志
uint32_t distance=0;			//总路程计数
uint16_t last_x,last_y;
#define  ERR_RANGE		3		//云台定位范围，未启用

int yuntai_flag = 0;  			//设置云台初始位置
int car_go_dir = 1; 			//第一问圈数
int yutai_3_init_falg = 1; 		//第三问中云台转向标志
int open_line_falg = 0; 		//第四问开始巡线的标志
int location_err_falg = 0; 		//云台追踪误差小于计数位

//主逻辑任务
void main_task(void *pvParameters)
{
	PID_Init();
	vTaskDelay(500);
	
	//菜单
	TI();
	Start_flag=1;

//	vTaskDelay(500);
//	Set0_flag=1;
	
//	Emm_V5_Vel_Control( 0x01, 1, 12, 0,  false);

	//运行巡线任务，参数：直线模式
	// Motor_Open(MOTOR_Line);

	//电机旋转
	// Motor_Write(1500,1500);

	//运行方向：1：往右
	// Emm_V5_Pos_Control(0x01, 1, 5, 0, 1400, false, false);

	//运动方向，减小角度为向下
	// Set_Servo(SERVO1,90);

	//给PWM计数原始值,减小角度向下
//	MaixCam_Send_XY(Greenx,Greeny);
//	Set_Servo_raw(SERVO1, Y_Init);
//	vTaskDelay(1000);
	
//	while(1) vTaskDelay(10);
	while (1)
	{
		
		//第二问
		if(YunTai_EN==1 || YunTai_EN==3)
		{
			//第二问先进行开环转动一段距离到靶纸上再进行定位
			//可以直接将摄像头对准靶纸，取消这部分开环转动
			Emm_V5_En_Control(1, true, false, UART_1_INST); // 电机使能控制
	        Emm_V5_En_Control(1, true, false, UART_0_INST);
// 			if(yuntai_flag == 0)  
// 			{
// 			Emm_V5_En_Control(1, true, false, UART_1_INST); // 电机使能控制
// 	        Emm_V5_En_Control(1, true, false, UART_0_INST);
// 		    vTaskDelay(10);
			
// 			if(YunTai_EN == 1)  //第二问给的初始位置
// 			{
// 			Emm_V5_Origin_Trigger_Return(1, 0, false ,UART_1_INST);
// 			vTaskDelay(10);
// //			Emm_V5_Origin_Trigger_Return(1, 0, false ,UART_0_INST);
// 			vTaskDelay(10);
// //			POS_Control(30 , 5*256, PITCH);
// //			vTaskDelay(100);	
// 			POS_Control(-30 , 50*256, YAW);
// 			vTaskDelay(10);
// 			POS_Control(30 , 5*256, PITCH);
// 			vTaskDelay(350);
// 			yuntai_flag = 1;
// 			}

// //			if(YunTai_EN == 3)  //第四问给的初始位置
// //			{
// //			POS_Control(-30 , 70*256, YAW);
// //			POS_Control(30 , 5*256, PITCH);
// //			vTaskDelay(1000);
// //			yuntai_flag = 1;
// //			}				

// 			}	
			
			//如果摄像头识别到目标则开始运行
			Camera_flag=0;
			while(!Camera_flag) vTaskDelay(2);
							
			err_cx = JiGuang[0] - Greenx;
			err_cy = JiGuang[1] - Greeny;

			Erect_pid(&Serx,JiGuang[0],Greenx);
			Erect_pid(&Sery,JiGuang[1],Greeny);
			
			last_x = JiGuang[0];
			last_y = JiGuang[1];
			
			if(Serx.out >0 )
			Serx.out= Serx.out + 0.8f;
			else if(Serx.out <0 )
			Serx.out= Serx.out - 0.8f;
			
			if(Sery.out >0 )
			Sery.out= Sery.out + 0.8f;
			else if(Sery.out <0 )
			Sery.out= Sery.out - 0.8f;
			
//			if( (err_cx > -ERR_RANGE && err_cx < ERR_RANGE) ) Serx.out=0;
			Serx.out=Serx.out>(X_SPEED_MAX)?(X_SPEED_MAX):Serx.out;
			Serx.out=Serx.out<(-X_SPEED_MAX)?(-X_SPEED_MAX):Serx.out;
			
//			if( (err_cy > -ERR_RANGE && err_cy < ERR_RANGE) ) Sery.out=0;
			Sery.out=Sery.out>(X_SPEED_MAX)?(X_SPEED_MAX):Sery.out;
			Sery.out=Sery.out<(-X_SPEED_MAX)?(-X_SPEED_MAX):Sery.out;
			
			Speed_Control(Serx.out , YAW);
			Speed_Control(Sery.out , PITCH);
//			if(Line_EN ==1 )
//			{
//			 Speed_Control(Serx.out - 1 , YAW);
//			}
			
			
		if(YunTai_EN == 3)  //第四问
		{
		if(Serx.err <3 && open_line_falg==0 )
		{
		location_err_falg ++;
		if(location_err_falg > 50){
		Line_EN=1;
		open_line_falg=1;
		location_err_falg=0;
		}
		}
		}

		}
		
		//第三问
		else if(YunTai_EN==2)
		{
			
			if(yuntai_flag == 0)  
			{	
			//这部分只运行一次，通过判断yuntai_flag来选择云台初始运动方向是左还是右
			//yuntai_flag标志由按键进行决定，在第三问的菜单中，KEY4代表左运行，KEY3代表右运行
			Emm_V5_En_Control(1, true, false, UART_1_INST); // 电机使能控制
	        Emm_V5_En_Control(1, true, false, UART_0_INST);
		    vTaskDelay(10);
				
//			POS_Control(-30 , 50*256, YAW);
//			POS_Control(30 , 5*256, PITCH); 
			Emm_V5_Origin_Trigger_Return(1, 0, false ,UART_1_INST);
			vTaskDelay(100);
			POS_Control(30 , 5*256, PITCH);
			vTaskDelay(100);
			yuntai_flag = 1;
			}
			
			if(yuntai_flag == 1)  
			{
			//右运动		
			if(yutai_3_init_falg == 1)  Speed_Control(10, YAW);
			else if(yutai_3_init_falg == 2)  Speed_Control(-10, YAW);
			yuntai_flag = 2;	
			}
			
			Camera_flag=0;
			while(!Camera_flag) {
			vTaskDelay(2);
			}
							
			err_cx = JiGuang[0] - Greenx;
			err_cy = JiGuang[1] - Greeny;
			

			Erect_pid(&Serx,JiGuang[0],Greenx);
			Erect_pid(&Sery,JiGuang[1],Greeny);
			
			last_x = JiGuang[0];
			last_y = JiGuang[1];
			
			if(Serx.out >0 )
			Serx.out= Serx.out + 0.8f;
			else if(Serx.out <0 )
			Serx.out= Serx.out - 0.8f;
			
			if(Sery.out >0 )
			Sery.out= Sery.out + 0.8f;
			else if(Sery.out <0 )
			Sery.out= Sery.out - 0.8f;
			
//			if( (err_cx > -ERR_RANGE && err_cx < ERR_RANGE) ) Serx.out=0;
			Serx.out=Serx.out>(X_SPEED_MAX)?(X_SPEED_MAX):Serx.out;
			Serx.out=Serx.out<(-X_SPEED_MAX)?(-X_SPEED_MAX):Serx.out;
			
//			if( (err_cy > -ERR_RANGE && err_cy < ERR_RANGE) ) Sery.out=0;
			Sery.out=Sery.out>(X_SPEED_MAX)?(X_SPEED_MAX):Sery.out;
			Sery.out=Sery.out<(-X_SPEED_MAX)?(-X_SPEED_MAX):Sery.out;
			
			Speed_Control(Serx.out, YAW);
			Speed_Control(Sery.out , PITCH);

		}
		else
		{
			Emm_V5_Stop_Now(0x01,false,UART_0_INST);
			Emm_V5_Stop_Now(0x01,false,UART_1_INST);
			vTaskDelay(20);
		}
		
		vTaskDelay(8);
		}
	}



int LINE_MODE =0;
int QEI_Vaule;

void line_task(void *pvParameters)
{
	
	while(1)
	{
		
	if(Line_EN==1)
	{
		Line_Control();
	//car_go_dir由菜单中的按键决定，是1-5圈，一圈的编码器计数大概24000
	if(distance > (car_go_dir*24000) )  
	{
		Motor_Write(0,0);
		while (1) vTaskDelay(10);
	}
		vTaskDelay(2);
	}
	else
	{
		vTaskDelay(20);
	}
		
		
	}
}

//OLED实时显示
void OLED_task(void *pvParameters)
{
	vTaskDelay(500);
	
	while (1)
	{

		//用法：0(0-127)行0(0-7)列，字体大小16，后面的用法参考printf，通过%d，%f等进行打印数据
//		OLED_Write(0,0,16,"HW1 :%d  ", HW_IO1);
//		OLED_Write(0,2,16,"HW2 :%d  ", HW_IO2);
//		OLED_Write(0,4,16,"HW3 :%d  ", HW_IO3);
//		OLED_Write(0,6,16,"HW4 :%d  ", KEY1);
//		OLED_Write(0,2,16,"x:%d y:%d  ", JiGuang[0], JiGuang[1]);
//		OLED_Write(0,4,16,"fps :%d  ", (int)KEY1);
//		OLED_Write(0,6,16,"d:%d  ", distance);
//		OLED_Write(0,6,16,"d:%d  ", Get_Encoder());
		
		vTaskDelay(100);
		
	}
}

//未用到
//云台归零任务
void Set0_task(void *pvParameters)
{
	// uint32_t distance=0;
	int16_t speed[2]={0};
	
	vTaskDelay(500);
	Set0_flag=0;
	

	while (1)
	{
		
		while(!Set0_flag) vTaskDelay(10);
		
//		YunTai_EN=0;
//		Line_EN=0;
		for(int i=5;i>0;i--)
		{
			Motor_Write(0,0);
			Emm_V5_Stop_Now(0x01, false, UART_0_INST);
			Emm_V5_Stop_Now(0x01, false, UART_1_INST);
			vTaskDelay(20);
		}
		
		//停止了
//		if(Set0_status==3) {YunTai_EN=1;while(1) __nop();}


		vTaskDelay(50);
//		POS_Control(10 , 200*256, YAW);
//		Emm_V5_Pos_Control(0x01, 1, 200, 70, 200*256, false, false);
		vTaskDelay(600);
		MaixCam_Send_XY(last_x,last_y);
		vTaskDelay(50);
		YunTai_EN=1;
		vTaskDelay(500);
		Line_EN=1;
		
		Set0_flag=0;
//		
		
//		//延时40ms
//		vTaskDelay(1000);
	}
}
int16_t speed[2]={0};
	   
//不断更新编码器计数值
void QEI_task(void *pvParameters)
{
	vTaskDelay(500);

  	while(1)
	{
		Get_Encoder(speed);
		distance += FABS(speed[0]);
		vTaskDelay(20);
	} 
}	

//发挥部分画圆
void circle_task(void *pvParameters)
{
	float x_out,y_out;
	int k=0;

	while(1)
	{
		
		vTaskDelay(10);
	}
	
}


