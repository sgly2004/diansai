#include "imu.h"

float IMU_Roll,
			IMU_Pitch,
			IMU_Yaw;

void UART5_Init(uint32_t baud)
{
    //清除串口中断标志
    NVIC_ClearPendingIRQ(IMU_INST_INT_IRQN);
    //使能串口中断
    NVIC_EnableIRQ(IMU_INST_INT_IRQN);

}

void IMU_Init(void)
{
	UART5_Init(115200);
}

/******************************************
函数功能：对IMU接收的协议包进行解析
入口参数：原始协议包
返回  值：0：解析错误，协议包不正确
					1：解析正确，是要接收的数据
*******************************************/
static int IMU_data_parse(int *pack)
{
	if(pack[0] != 0x55) 									return 0;
	if(pack[1] != 0x55) 									return 0;
	if(pack[2] != 0x01) 									return 0;
	return 1;
}

static void IMU_data_Solve(uint8_t IMU_Roll_L, uint8_t IMU_Roll_H, uint8_t IMU_Pitch_L, uint8_t IMU_Pitch_H, uint8_t IMU_Yaw_L, uint8_t IMU_Yaw_H)
{
	IMU_Roll =  (float)((int16_t)(IMU_Roll_H << 8) | IMU_Roll_L) / 32768 * 180;
	IMU_Pitch = (float)((int16_t)(IMU_Pitch_H << 8) | IMU_Pitch_L) / 32768 * 180;
	IMU_Yaw = 	(float)((int16_t)(IMU_Yaw_H << 8) | IMU_Yaw_L) / 32768 * 180;
}

//void UART5_Handler(void)
//{
//	uint32_t a;
//	static uint8_t i=0;
//	static uint8_t dataFlag=0;
//	static int IMU_data_buff[IMU_DATA_SIZE]={0};
//  uint32_t status=0;
//	status = UARTIntStatus(UART5_BASE, true); 	//读取UART1中断状态
//	while(UARTCharsAvail(UART5_BASE)) 				  //指示FIFO中是否存在有UART数据
//	{		
//		a = UARTCharGetNonBlocking(UART5_BASE);	//读取接收到的信息
//		if(dataFlag==0 && a==0x55) //判断帧头
//		{
//			dataFlag=1;
//			i=0;
//		}
//	
//		if(dataFlag==1)  //接收到帧头，开始接收数据        
//		{
//			IMU_data_buff[i]=a;
//			if(i < (IMU_DATA_SIZE-1) ) i++;
//			else  //数据接收完，开始校验
//			{
//				dataFlag=0;
//				i=0;
//				if(IMU_data_parse(IMU_data_buff))  //校验成功，是要接收的数据
//				{
//					//数据处理
//					IMU_data_Solve(IMU_data_buff[4],
//												 IMU_data_buff[5],
//												 IMU_data_buff[6],
//												 IMU_data_buff[7],
//												 IMU_data_buff[8],
//												 IMU_data_buff[9]);
//				}
//			}
//		}
//	}
//	UARTIntClear(UART5_BASE, status); 			//清除UART1中断标志
//}
void UART0_IRQHandler(void)
{
	uint8_t a;
	static uint8_t i=0;
	static uint8_t dataFlag=0;
	static int IMU_data_buff[IMU_DATA_SIZE]={0};
    //如果产生了串口中断
    switch( DL_UART_getPendingInterrupt(IMU_INST) )
    {
        case DL_UART_IIDX_RX://如果是接收中断
            //接发送过来的数据保存在变量中
            a = DL_UART_Main_receiveData(IMU_INST);
       
            if(dataFlag==0 && a==0x55) //判断帧头
			{
				dataFlag=1;
				i=0;
			}
			if(dataFlag==1)  //接收到帧头，开始接收数据        
			{
			IMU_data_buff[i]=a;
			if(i < (IMU_DATA_SIZE-1) ) i++;
			else  //数据接收完，开始校验
				{
					dataFlag=0;
					i=0;
					if(IMU_data_parse(IMU_data_buff))  //校验成功，是要接收的数据
					{
					//数据处理
					IMU_data_Solve(IMU_data_buff[4],
												 IMU_data_buff[5],
												 IMU_data_buff[6],
												 IMU_data_buff[7],
												 IMU_data_buff[8],
												 IMU_data_buff[9]);
					}
					}
			}
	  
            break;

        default://其他的串口中断
            break;
    }
}

