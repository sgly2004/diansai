#include "MaixCam.h"

uint16_t JiGuang[2]={0};

void UART2_Init(void)
{
	//清除串口中断标志
    NVIC_ClearPendingIRQ(UART_3_INST_INT_IRQN);
    //使能串口中断
    NVIC_EnableIRQ(UART_3_INST_INT_IRQN);
}

//串口发送单个字符
void uart2_send_char(uint16_t ch)
{
    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
    while( DL_UART_isBusy(UART_3_INST) == true );
    //发送单个字符
    DL_UART_Main_transmitData(UART_3_INST, ch);
}

//串口发送字符串
void uart2_send_string(char* str)
{
    //当前字符串地址不在结尾 并且 字符串首地址不为空
    while(*str!=0&&str!=0)
    {
        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
        uart2_send_char(*str++);
    }
}

int fputc(int ch, FILE *stream)
{
		while( DL_UART_isBusy(UART_3_INST) == true );

		DL_UART_Main_transmitData(UART_3_INST, ch);

		return ch;
}

void MaixCam_Init(void)
{
	UART2_Init();
}

void MaixCam_Send_XY(uint16_t x, uint16_t y)
{
	uart2_send_char(0x00);
	uart2_send_char(0x01);
	uart2_send_char((uint8_t)(x/256));
	uart2_send_char((uint8_t)(x%256));
	uart2_send_char((uint8_t)(y/256));
	uart2_send_char((uint8_t)(y%256));
}

static int MaixCam_data_parse(int *pack)
{
	if(pack[0] != 0xFE) 					return 0;
	if(pack[MAIXCAM_DATA_SIZE-1] != 0xFD) 	return 0;
	return 1;
}

__IO int Camera_fps=0,Camera_flag=0;
//串口的中断服务函数
void UART_3_INST_IRQHandler(void)
{
	uint8_t a;
	static uint8_t i=0;
	static uint8_t dataFlag=0;
	static int MaixCam_data_buff[MAIXCAM_DATA_SIZE+3]={0};

	//如果产生了串口中断
	switch( DL_UART_getPendingInterrupt(UART_3_INST) )
	{
			case DL_UART_IIDX_RX://如果是接收中断
			{
				//接发送过来的数据保存在变量中
				a = DL_UART_Main_receiveData(UART_3_INST);
				NVIC_ClearPendingIRQ(UART_3_INST_INT_IRQN);
				if(dataFlag==0 && a==0xFE) //判断帧头
				{
					dataFlag=1;
					i=0;
				}
				if(dataFlag==1)  //接收到帧头，开始接收数据        
				{
					MaixCam_data_buff[i]=a;
					if(i < (MAIXCAM_DATA_SIZE-1) ) i++;
					else  //数据接收完，开始校验
					{
						dataFlag=0;
						i=0;
						if(MaixCam_data_parse(MaixCam_data_buff))  //校验成功，是要接收的数据
						{
//							if( MaixCam_data_buff[1]==0x01)
//							{
								JiGuang[0] = MaixCam_data_buff[1]*255 + MaixCam_data_buff[2];
								JiGuang[1] = MaixCam_data_buff[3]*255 + MaixCam_data_buff[4];
								Camera_fps++;
								Camera_flag=1;
//							}
						}
					}
				}
				break;
		 }
		
		default://其他的串口中断
				break;
	}
}