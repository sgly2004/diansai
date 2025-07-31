#include "bsp_uart.h"
		//****************UART******************//
		
//串口发送多字节
void Uart_Send(uint8_t *p_data,uint8_t uiSize,UART_Regs *uart)
{	
	unsigned int i;
	for(i = 0; i < uiSize; i++)
	{	
    DL_UART_Main_transmitDataBlocking(uart, p_data[i]);		
	}
}
		
		
		
		//****************UART2******************//
//void UART_2_INST_IRQHandler(void)
//{
//	unsigned char ucTemp;
//    switch (DL_UART_Main_getPendingInterrupt(UART_2_INST)) {
//        case DL_UART_MAIN_IIDX_RX:
//            ucTemp = DL_UART_Main_receiveData(UART_2_INST);
////				    WitSerialDataIn(ucTemp);  //维特陀螺仪处理函数
//						CopeSerial4Data(ucTemp);
//            break;
//        default:
//            break;
//    }
//}

//void Uart2Send(unsigned char *p_data, unsigned int uiSize)
//{	
//	unsigned int i;
//	for(i = 0; i < uiSize; i++)
//	{	
//    DL_UART_Main_transmitData(UART_2_INST, *p_data++);		
//	}
//}


//void UART_3_INST_IRQHandler(void)
//{
//	unsigned char ucTemp;
//    switch (DL_UART_Main_getPendingInterrupt(UART_3_INST)) {
//        case DL_UART_MAIN_IIDX_RX:
//            ucTemp = DL_UART_Main_receiveData(UART_3_INST);
////				    WitSerialDataIn(ucTemp);  //维特陀螺仪处理函数
//            break;
//        default:
//            break;
//    }
//}


