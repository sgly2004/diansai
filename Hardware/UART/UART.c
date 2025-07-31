#include "main.h"

#if !defined(__MICROLIB)
//不使用微库的话就需要添加下面的函数
#if (__ARMCLIB_VERSION <= 6000000)
//如果编译器是AC5  就定义下面这个结构体
struct __FILE
{
        int handle;
};
#endif
FILE __stdout;
//定义_sys_exit()以避免使用半主机模式
void _sys_exit(int x)
{
        x = x;
}
#endif

//void UART_Init(void)
//{
//	    //清除串口中断标志
//    NVIC_ClearPendingIRQ(UART_2_INST_INT_IRQN);
//    //使能串口中断
//    NVIC_EnableIRQ(UART_2_INST_INT_IRQN);
//}

////串口发送单个字符
//void uart2_send_char(char ch)
//{
//    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
//    while( DL_UART_isBusy(UART_2_INST) == true );
//    //发送单个字符
//    DL_UART_Main_transmitData(UART_2_INST, ch);
//}

////串口发送字符串
//void uart2_send_string(char* str)
//{
//    //当前字符串地址不在结尾 并且 字符串首地址不为空
//    while(*str!=0&&str!=0)
//    {
//        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
//        uart2_send_char(*str++);
//    }
//}

//int fputc(int ch, FILE *stream)
//{
//        while( DL_UART_isBusy(UART_2_INST) == true );

//        DL_UART_Main_transmitData(UART_2_INST, ch);

//        return ch;
//}

//uint8_t   uart_data ;

////串口的中断服务函数
//void UART_2_INST_IRQHandler(void)
//{
//    //如果产生了串口中断
//    switch( DL_UART_getPendingInterrupt(UART_2_INST) )
//    {
//        case DL_UART_IIDX_RX://如果是接收中断
//            //接发送过来的数据保存在变量中
//            uart_data = DL_UART_Main_receiveData(UART_2_INST);
//            //将保存的数据再发送出去
//         
//            break;

//        default://其他的串口中断
//            break;
//    }
//}