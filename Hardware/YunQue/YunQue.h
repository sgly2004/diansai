#ifndef __YUNQUE_H
#define __YUNQUE_H

#include "main.h"
#include "stdarg.h"
#include "string.h"
#include "stdio.h"

#define YUNQUE_DATA_SIZE  7



void YunQue_Init(void);
void YunQue_CMD(const char *formate,...);
// void uart2_send_char(char ch);
// void uart2_send_string(char* str);

#endif