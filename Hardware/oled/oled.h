#ifndef __OLED_H
#define __OLED_H
#include "main.h"


#define OLED_NUM     0
#define OLED_Str     1
#define OLED_f       2



void OLED_Init(void);
void OLED_IIC_Init(void);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t no);
void OLED_ShowString(uint8_t x,uint8_t y,char *chr,uint8_t Char_Size);
void OLED_float(float a,int x,int y);
void OLED_ShowNum(uint8_t x, uint8_t y, int_least64_t num, uint8_t len, uint8_t sizey);
uint32_t oled_pow(uint8_t m,uint8_t n);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size);
void OLED_Clear(void);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void IIC_XIE_DATA(unsigned char IIC_Command);
void IIC_XIE_ML(unsigned char IIC_Command);
void IIC_XIE(unsigned char IIC_Byte);
void IIC_Ack(void);
void IIC_Stop(void);
void IIC_Start(void);
void OLED_Write(int x,int y,int Size,const char *formate,...);



#endif
