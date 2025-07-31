#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "main.h"

void Uart_Send(uint8_t *p_data,uint8_t uiSize,UART_Regs *uart);

void UART_2_INST_IRQHandler(void);
void Uart2Send(unsigned char *p_data, unsigned int uiSize);

#endif /* __BSP_UART_H */