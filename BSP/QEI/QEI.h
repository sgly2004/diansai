#ifndef __QEI_H
#define __QEI_H

#include "main.h"


void get_Encoder(void);
void get_encoder_value(void);

extern int count,speed,count_last;

extern int  Encoder_Left,Encoder_Right;         		  //×óÓÒ±àÂëÆ÷µÄÂö³å¼ÆÊı
extern int  Encoder_Left_cnt,Encoder_Right_cnt;

#endif /* __QEI_H */