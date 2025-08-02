#include "control.h"
//#include "LED_Key.h"
/**************************PID����************* */
#define PID_K   1.4f
extern int Greenx,Greeny;
extern int is_turning;
int is_turning = 0; 

float feed_forward= 0.0f;

// 0��ʾû����ת��
struct PID Serx,Sery;
//λ��ʽPID����
void PID_Init(void)
{
	Serx.kp=-0.12;//-0.15;
	Serx.kd=-0.1;
	
	Sery.kp=-0.05;
	Sery.kd=-0.1;
	feed_forward = 0;
	
}

void Set_PID_1(void)
{
	Serx.kp=-0.9;//-0.15;
	Serx.kd=-0.3;
	
	Sery.kp=-0.05;
	Sery.kd=-0.1;

	feed_forward = -20;
}

void Set_PID_2(void)
{
	Serx.kp=(-0.15f/PID_K);
	Serx.kd=(-0.3f/PID_K);
	
	Sery.kp=0.5f;
	Sery.kd=0.5f;
	
	Greenx=265;
	Greeny=170;
	
//	Sery.kp=(0.35f/PID_K);
//	Sery.kd=(0.5f/PID_K);
}

//λ��ʽPID
float Erect_pid(struct PID* para,float hope, float now)
{
	(*para).err = now - hope;
	
	(*para).err_last_dev = (*para).err - (*para).err_last;
	
	(*para).out = (*para).kp*(*para).err + (*para).kd*(*para).err_last_dev + (*para).ki*(*para).err_add;
	
	(*para).err_last =  (*para).err;
	
	(*para).err_add+=(*para).err;
	
	(*para).out = (*para).out + feed_forward;

	return (*para).out;
}
/**************************PID����************* */

/**************************ѭ������************* */
uint8_t Line[4];

//���ⰲװ����������������   1, 2, 3, 4���������壩
//��ģ���϶�Ӧ����           2, 3, 6, 7��̽ͷ��Ӳ��λ��λ�ã�
void Get_hw(void)
{
	Line[0] = HW_IO1;
	Line[1] = HW_IO2;
	Line[2] = HW_IO3;
	Line[3] = HW_IO4;
}

//void Line_Control(void)
//{
//	Get_hw();	
//    if(Line[3] == 1)
//	{
//	Motor_Write(SPEED*0.5+(GAIN*GAIN_K*5),SPEED*0.5);
//		while(Line[3])
//		{
//			Get_hw();
//			vTaskDelay(10);	
//		}
//	}		
//    else if(Line[0] == 1)
//	{
//		Motor_Write(SPEED*0.5,SPEED*0.5+(GAIN*GAIN_K*5));
//		while(Line[0] == 1)
//		{
//		Get_hw();	
//		vTaskDelay(10);      
//		}
//	}      
//	
//	else if(Line[2] == 1) 
//	{
//		Motor_Write(SPEED+GAIN,SPEED-GAIN);
//		while(Line[2] == 1)
//		{
//		Get_hw();	
//		vTaskDelay(10);      
//		}
//	}	
//	else if(Line[1] == 1) 	   
//	{
//		Motor_Write(SPEED-GAIN,SPEED+GAIN);
//		while(Line[1] == 1)
//		{
//		Get_hw();	
//		vTaskDelay(10);      
//		}
//	}
//	Motor_Write(SPEED,SPEED);
//}


//void Line_Control(void)
//{
//	Get_hw();	
//    if(Line[3] == 1)
//	{
//	Motor_Write(SPEED+(GAIN*GAIN_K),0);
////	while(Line[3] == 1);	
//	vTaskDelay(740);
//		
//	}		
//    else if(Line[0] == 1){
//	Motor_Write(0,SPEED+(GAIN*GAIN_K));
////	while(Line[0] == 1);
//	vTaskDelay(740);
//	}      
//	
//	else if(Line[2] == 1) 		Motor_Write(SPEED+GAIN,SPEED-GAIN);
//	else if(Line[1] == 1) 	    Motor_Write(SPEED-GAIN,SPEED+GAIN);
//	else 					    Motor_Write(SPEED,SPEED);
//}


void Line_Control(void)
{
	Get_hw();	
    if(Line[3] == 0){
		//vTaskDelay(60);
	//	while (HW_IO3 == 0) vTaskDelay(2);

		Motor_Write(SPEED_UP,-1);
		vTaskDelay(80);
		while (HW_IO3 == 1) vTaskDelay(50);
	//	vTaskDelay(50);
	}
	
    else if(Line[0] == 0){
	//vTaskDelay(100);
//	while (HW_IO2 == 0) vTaskDelay(2);

	Motor_Write(-1,SPEED_UP);	
	vTaskDelay(80);
	while (HW_IO2 == 1) vTaskDelay(50);
	//vTaskDelay(50);
	}       

	else if(Line[2] == 0) 		Motor_Write(SPEED,SPEED-GAIN);
	else if(Line[1] == 0) 	    Motor_Write(SPEED-GAIN,SPEED);
	else 					    Motor_Write(SPEED,SPEED);
}

void Line_Control2(void)
{
	Get_hw();	
    if(Line[3] == 0){
		
		//	vTaskDelay(60);
		is_turning = 1;
	//	while (HW_IO3 == 0) vTaskDelay(2);
		Speed_Control(10 , YAW);
	// vTaskDelay(60);
		Motor_Write(SPEED_UP2,-1);
		vTaskDelay(80);
		while (HW_IO3 == 1) vTaskDelay(50);
		//vTaskDelay(80);
		is_turning = 0;
	}
	
    else if(Line[0] == 0){
	//vTaskDelay(100);
	is_turning = 1;
//	while (HW_IO2 == 0) vTaskDelay(2);
	Speed_Control(-10 , YAW);
	// vTaskDelay(60);
	Motor_Write(-1,SPEED_UP2);	
	vTaskDelay(80);
	while (HW_IO2 == 1) vTaskDelay(50);
	//vTaskDelay(80);
	is_turning = 0;
	}       

	else if(Line[2] == 0) 		Motor_Write(SPEED2,SPEED2-GAIN2);
	else if(Line[1] == 0) 	    Motor_Write(SPEED2-GAIN2,SPEED2);
	else 					    Motor_Write(SPEED2,SPEED2);
}

//void Line_Control(void)
//{
//	Get_hw();	
//    if(Line[3] == 0){
//	vTaskDelay(300);
//	Motor_Write(2000,-2000);
//	while (HW_IO3 == 1) vTaskDelay(2);
//	vTaskDelay(200);
//	Motor_Write(0,0);		
//	}
//	
//    else if(Line[0] == 0){
//	vTaskDelay(300);
//	Motor_Write(-2000,2000);
//	while (HW_IO2 == 1) vTaskDelay(2);
//	vTaskDelay(200);
//	Motor_Write(0,0);		
//	}       
//	else if(Line[2] == 0) 		Motor_Write(SPEED,SPEED-GAIN);
//	else if(Line[1] == 0) 	    Motor_Write(SPEED-GAIN,SPEED);
//	else 					    Motor_Write(SPEED,SPEED+100);
//}


/*************************
��������:�Բ�ͬ��ʽ�������?
��ڲ���?:
Mode:            ��ѡ��Ѳ��or��ת
����ֵ:��
*************************/
void Motor_Open(int Mode)
{
	if(Mode == MOTOR_Line)                                 //Ѱ��ֱ��ģʽ
	{
		//����ѭ��
        while(1)
        // while(!(HW_IO1 || HW_IO4))
        {
            //ѭ���ж�
            Line_Control();
            vTaskDelay(2);
        }
        Motor_Write(SPEED,SPEED);
        vTaskDelay(40);
	}
	else if(Mode == MOTOR_TURN)
	{

        // while(Distance_limit(distance_hope,distance_count))
        // {
        //     if(dir == LEFT_OR)	Motor_Write(-SPEED,SPEED);
        //     else if(dir == RIGHT_OR)	Motor_Write(SPEED,-SPEED);
        //     vTaskDelay(2);
        // }
        
        // if(dir == LEFT_OR) 
        // {
        //     //�ȴ�С����ת���Ҷ�ģ�鴥������
        //     while(HW_IO2) vTaskDelay(2);
        //     Motor_Write(0,0);  //���ͣ�?
        //     vTaskDelay(20);
        // }
        // else
        // {
        //     while(HW_IO3) vTaskDelay(2);
        //     Motor_Write(0,0);  //���ͣ�?
        //     vTaskDelay(20);
        // }
		
	}
	
	// Motor_Write(0,0);  //���ͣ�?
}
/**************************ѭ������************* */






uint8_t a=0;
uint8_t b=0;

void TASK_1()
{
		vTaskDelay(10);
		while(KEY2==1) vTaskDelay(5);
		OLED_Clear();	
        OLED_Write(0,0,8,"N:%d",car_go_dir);
			
		while(1){
		if(KEY1==1)  //��Ȧ
		{
			vTaskDelay(10);
			while(KEY1==1)vTaskDelay(5);
			car_go_dir++;
			if(car_go_dir>5) car_go_dir=1;
			OLED_Write(0,0,8,"N:%d",car_go_dir);
		}
		
		if(KEY2==1)
		{
			vTaskDelay(10);
			while(KEY2==1)vTaskDelay(5);
			
			OLED_Clear();
			OLED_Write(0,0,8,"OK");
			Line_EN= 1;
			return;
		}
		vTaskDelay(10);
	}
  }

  
  
void TASK_3()
{
		vTaskDelay(10);
		while(KEY2==1) vTaskDelay(5);
		OLED_Clear();
		OLED_Write(0,0,8,"ready");
			
		while(1)
		{
			if(KEY1==1)
			{
				yutai_3_init_falg=2;
				YunTai_EN= 2;
				break;
			}	
			if(KEY2==1)
			{
				yutai_3_init_falg=1;
				YunTai_EN= 2;
				break;
			}
		
			vTaskDelay(10);
		}
  }

  
 void TASK_4()
{
   YunTai_EN= 3; 
   Line_EN= 3;
}

 void TASK_5()
{
   YunTai_EN= 3; 
   Line_EN= 4;
}



void TI(void)
{

	
	OLED_Write(0,0,8,"Mode1");  //��һ��
	OLED_Write(0,1,8,"Mode2");	//�ڶ���
	OLED_Write(0,2,8,"Mode3");	//������
	OLED_Write(0,3,8,"Mode4");  //������
	OLED_Write(0,4,8,"Mode5");	//���Ӳ���
	OLED_Write(0,5,8,"Mode6");	//�ڶ���У׼
	OLED_Write(0,6,8,"Mode7");	//������У׼
	OLED_Write(100,0,8,"*");
	
	
	while(1)
	{
//	 if(a==0)
//	 {
//		if(KEY2==1&&b==0) 
//		{
//		vTaskDelay(10);
//		while(KEY2==1) vTaskDelay(5);
//		OLED_Clear();	
//        OLED_Write(0,0,8,"N:%d",car_go_dir);
////		OLED_Write(0,1,8,"2");	//��
////		OLED_Write(0,2,8,"3");	//��
////		OLED_Write(0,3,8,"4");  //��
////		OLED_Write(0,4,8,"4");  //��
////		OLED_Write(100,0,8,"*");
////				
//		while(1){
//		if(KEY1==1)  //��Ȧ
//		{
//			vTaskDelay(10);
//			while(KEY1==1)vTaskDelay(5);
//			car_go_dir++;
//			if(car_go_dir>5) car_go_dir=1;
//			OLED_Write(0,0,8,"N:%d",car_go_dir);
//		}
//		
//		if(KEY2==1)
//		{
//			vTaskDelay(10);
//			while(KEY2==1)vTaskDelay(5);
//			
//			OLED_Clear();
//			OLED_Write(0,0,8,"OK");
//			Line_EN= 1;
//			return;
//		}
//		vTaskDelay(10);
//		}	
//		

//		   
//		}
//	 }
	 
	   
		//�ڶ��ʲ˵�
		if(KEY1==1&&a==0)
		{
			vTaskDelay(10);
			while(KEY1==1) vTaskDelay(5);
			OLED_Write(100,0,8," ",16);
			OLED_Write(100,1,8,"*",16);
			a=1;
		}
		
		
		
		
		//������
		if(KEY1==1&&a==1)
		{
		vTaskDelay(10);
		while(KEY1==1)vTaskDelay(5);
		OLED_Write(100,1,8," ",16);
		OLED_Write(100,2,8,"*",16);
		a=2;
		}

		if(KEY1==1&&a==2)
		{
			vTaskDelay(10);
			while(KEY1==1)vTaskDelay(5);
			OLED_Write(100,2,8," ",16);
			OLED_Write(100,3,8,"*",16);
			a=3;
		}
		if(KEY1==1&&a==3)
		{
			vTaskDelay(10);
			while(KEY1==1)vTaskDelay(5);
			OLED_Write(100,3,8," ",16);
			OLED_Write(100,4,8,"*",16);
			a=4;
		}
		if(KEY1==1&&a==4)
		{
			vTaskDelay(10);
			while(KEY1==1)vTaskDelay(5);
			OLED_Write(100,4,8," ",16);
			OLED_Write(100,5,8,"*",16);
			a=5;
		}
		if(KEY1==1&&a==5)
		{
			vTaskDelay(10);
			while(KEY1==1)vTaskDelay(5);
			OLED_Write(100,5,8," ",16);
			OLED_Write(100,6,8,"*",16);
			a=6;
		}
		if(KEY1==1&&a==6)
		{
			vTaskDelay(10);
			while(KEY1==1) vTaskDelay(5) ;
			OLED_Write(100,6,8," ",16);
			OLED_Write(100,0,8,"*",16);
			a=0;
		}
		if(KEY2==1)
		{
			vTaskDelay(10);
			while(KEY2==1) ;
			OLED_Clear();
//			EXTIX_Init();
			if(a==0) TASK_1(); //��һ��
			else if(a==1) {YunTai_EN= 1;}  //�ڶ���
	 		else if(a==2) {TASK_3();}		//������
			else if(a==3) {TASK_4();}  //������
			else if(a==4)	{TASK_5();}//����
//			else if(a==5)	{EXTIX_Init();Task0();}	 //�ڶ���У׼
//			else if(a==6)	{EXTIX_Init();Task00();} //������У׼
			break;
		}
		vTaskDelay(10);
	}
}


