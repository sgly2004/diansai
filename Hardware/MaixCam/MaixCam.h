#ifndef __MaixCam_H
#define __MaixCam_H

#include "main.h"

#define MAIXCAM_DATA_SIZE  6

extern uint16_t JiGuang[2];
extern __IO int Camera_fps,Camera_flag;

void MaixCam_Init(void);
void MaixCam_Send_XY(uint16_t x, uint16_t y);
// void uart2_send_char(char ch);
// void uart2_send_string(char* str);

#endif