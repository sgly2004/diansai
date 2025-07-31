#include "YunQue.h"

void UART3_Init(void)
{
	  //清除串口中断标志
    NVIC_ClearPendingIRQ(UART_3_INST_INT_IRQN);
    //使能串口中断
    NVIC_EnableIRQ(UART_3_INST_INT_IRQN);
}

//串口发送单个字符
void uart3_send_char(uint16_t ch)
{
    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
    while( DL_UART_isBusy(UART_3_INST) == true );
    //发送单个字符
    DL_UART_Main_transmitData(UART_3_INST, ch);
}

//串口发送字符串
void uart3_send_string(char* str)
{
    //当前字符串地址不在结尾 并且 字符串首地址不为空
    while(*str!=0&&str!=0)
    {
        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
        uart3_send_char(*str++);
    }
}

//int fputc(int ch, FILE *stream)
//{
//		while( DL_UART_isBusy(UART_3_INST) == true );

//		DL_UART_Main_transmitData(UART_3_INST, ch);

//		return ch;
//}

void YunQue_Init(void)
{
	UART3_Init();
}

void YunQue_CMD(const char *formate,...)
{
	char buf[32]={'\0'};
	va_list ap;
	
	va_start(ap,formate);
	vsprintf(buf,formate,ap);
	va_end(ap);
	uart3_send_string(buf);
	vTaskDelay(1);
}

static int YunQue_data_parse(int *pack)
{
	if(pack[0] != 0xFD) 										return 0;
	if(pack[YUNQUE_DATA_SIZE-1] != 0xFE) 	return 0;
	return 1;
}

////串口的中断服务函数
//void UART_3_INST_IRQHandler(void)
//{
//	uint8_t a;
//	static uint8_t i=0;
//	static uint8_t dataFlag=0;
//	static int YunQue_data_buff[YUNQUE_DATA_SIZE+3]={0};
//	
//	NVIC_ClearPendingIRQ(UART_3_INST_INT_IRQN);

////	//如果产生了串口中断
////	switch( DL_UART_getPendingInterrupt(UART_3_INST) )
////	{
////			case DL_UART_IIDX_RX://如果是接收中断
////			{
////				//接发送过来的数据保存在变量中
////				a = DL_UART_Main_receiveData(UART_3_INST);
////				NVIC_ClearPendingIRQ(UART_3_INST_INT_IRQN);
////				if(dataFlag==0 && a==0xFD) //判断帧头
////				{
////					dataFlag=1;
////					i=0;
////				}
////				if(dataFlag==1)  //接收到帧头，开始接收数据        
////				{
////					YunQue_data_buff[i]=a;
////					if(i < (MAIXCAM_DATA_SIZE-1) ) i++;
////					else  //数据接收完，开始校验
////					{
////						dataFlag=0;
////						i=0;
////						if(YunQue_data_parse(YunQue_data_buff))  //校验成功，是要接收的数据
////						{
////							if( YunQue_data_buff[1]==0x01)
////							{
////								JiGuang[0] = YunQue_data_buff[2]*255 + YunQue_data_buff[3];
////								JiGuang[1] = YunQue_data_buff[4]*255 + YunQue_data_buff[5];
////								Camera_fps++;
////								Camera_flag=1;
////							}
////						}
////					}
////				}
////				break;
////		 }
////		
////		default://其他的串口中断
////				break;
////	}
//}