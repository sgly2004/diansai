#include "oled.h"
#include "OLED_Font.h"
#include "stdarg.h"
#include "string.h"
#include "stdio.h"



void delay(void)
{
	int Delay=10;
	while(Delay--);
}

#define OLED_W_SCL(x)		do{GPIO_WriteBit(OLED_PORT , OLED_SCL_PIN , x);delay();}while(0)
#define OLED_W_SDA(x)		do{GPIO_WriteBit(OLED_PORT , OLED_SDA_PIN , x);delay();}while(0)

#define OLED_SDA_Set()      OLED_W_SDA(1)
#define OLED_SDA_Clr()      OLED_W_SDA(0)

#define OLED_SCL_Set()      OLED_W_SCL(1)
#define OLED_SCL_Clr()      OLED_W_SCL(0)

void IIC_Start(void)
{
	OLED_W_SDA(1);
	OLED_W_SCL(1);
	OLED_W_SDA(0);
	OLED_W_SCL(0);
}

void IIC_Stop(void)
{
	OLED_W_SDA(0);
	OLED_W_SCL(1);
	OLED_W_SDA(1);
}

void IIC_Ack(void)
{
	OLED_W_SCL(1);	//È¢ùÂ?ñÁöÑ‰∏Ä‰∏?Êó∂ÈíüÔºå‰∏çÂ§ÑÁêÜÂ∫îÁ≠î‰ø°Â??
	OLED_W_SCL(0);
}

void IIC_XIE(unsigned char IIC_Byte)
{
	unsigned char i;
	unsigned char m,da;
	da=IIC_Byte;
	OLED_SCL_Clr();
	for(i=0;i<8;i++)		
	{
		m=da;
		m=m&0x80;
		if(m==0x80)
		{
		  OLED_SDA_Set();
		}
		else 
		{
			OLED_SDA_Clr();
		}
			da=da<<1;
		  OLED_SCL_Set();
		  OLED_SCL_Clr();
		}
}

void IIC_XIE_ML(unsigned char IIC_Command)
{
   IIC_Start();
   IIC_XIE(0x78);
	 IIC_Ack();	
   IIC_XIE(0x00);
	 IIC_Ack();	
   IIC_XIE(IIC_Command); 
	 IIC_Ack();	
   IIC_Stop();
}

void IIC_XIE_DATA(unsigned char IIC_Command)
{
   IIC_Start();
   IIC_XIE(0x78);
	 IIC_Ack();	
   IIC_XIE(0x40);
	 IIC_Ack();	
   IIC_XIE(IIC_Command); 
	 IIC_Ack();	
   IIC_Stop();
}

void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 	
	IIC_XIE_ML(0xb0+y);
	IIC_XIE_ML(((x&0xf0)>>4)|0x10);
	IIC_XIE_ML(x&0x0f); 
}

void OLED_Clear(void)  
{  
	uint8_t i,n;		    
	for(i=0;i<8;i++)  
	{  
		IIC_XIE_ML (0xb0+i); 
		IIC_XIE_ML (0x00);
		IIC_XIE_ML (0x10);
		for(n=0;n<128;n++)IIC_XIE_DATA(0); 
	}
}

void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size)
{
	unsigned char c=0,i=0;	
	c=chr-' ';//µ√µΩ∆´“∆∫Ûµƒ÷µ			
	if(x>128-1){x=0;y=y+2;}
	if(Char_Size ==16)
	{
		OLED_Set_Pos(x,y);
		for(i=0;i<8;i++) IIC_XIE_DATA(F8X16[c*16+i]);
		
		OLED_Set_Pos(x,y+1);
		for(i=0;i<8;i++) IIC_XIE_DATA(F8X16[c*16+i+8]);
	}
	else 
	{	
		OLED_Set_Pos(x,y);
		for(i=0;i<6;i++) IIC_XIE_DATA(F6x8[c][i]);
	}
}

void OLED_ShowString(uint8_t x,uint8_t y,char *chr,uint8_t Char_Size)
{
	unsigned char j=0;
	while (chr[j]!='\0')
	{		
		OLED_ShowChar(x,y,chr[j],Char_Size);
		x+=8;
		if(x>120)
		{
			x=0;y+=2;
		}
		j++;
	}
}

void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t no)
{      			    
	uint8_t t,adder=0;
	OLED_Set_Pos(x,y);	
  for(t=0;t<16;t++)
  {
   	IIC_XIE_DATA(Hzk2[2*no][t]);
		adder+=1;
  }	
	OLED_Set_Pos(x,y+1);	
  for(t=0;t<16;t++)
	{	
		IIC_XIE_DATA(Hzk2[2*no+1][t]);
		adder+=1;
  }					
}

void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{ 	
 unsigned int j=0;
 unsigned char x,y;
  
  if(y1%8==0) y=y1/8;      
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
	    {      
	    	IIC_XIE_DATA(BMP[j++]);	    	
	    }
	}
}

void OLED_IIC_Init(void)
{
//	GPIO_InitTypeDef  GPIO_InitStructure;
//	
//	RCC_APB2PeriphClockCmd(OLED_IIC_SCL_RCC|OLED_IIC_SDA_RCC, ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = OLED_IIC_SCL_PIN;	 
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(OLED_IIC_SCL_GPIO, &GPIO_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = OLED_IIC_SDA_PIN;	 
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(OLED_IIC_SDA_GPIO, &GPIO_InitStructure);
}

void OLED_Init(void)
{
	OLED_IIC_Init();

	__IO int i,j;
	for(j=0;j<40;j++)
	{
		for(i=0;i<50000;i++)
		{
		 delay();
		}
	}
	
	IIC_XIE_ML(0xAE);
	IIC_XIE_ML(0x00);
	IIC_XIE_ML(0x10);
	IIC_XIE_ML(0x40);
	IIC_XIE_ML(0xB0);
	IIC_XIE_ML(0x81);
	IIC_XIE_ML(0xFF);
	IIC_XIE_ML(0xA1);
	IIC_XIE_ML(0xA6);
	IIC_XIE_ML(0xA8);
	IIC_XIE_ML(0x3F);
	IIC_XIE_ML(0xC8);
	IIC_XIE_ML(0xD3);
	IIC_XIE_ML(0x00);
	IIC_XIE_ML(0xD5);
	IIC_XIE_ML(0x80);
	IIC_XIE_ML(0xD8);
	IIC_XIE_ML(0x05);
	IIC_XIE_ML(0xD9);
	IIC_XIE_ML(0xF1);
	IIC_XIE_ML(0xDA);
	IIC_XIE_ML(0x12);
	IIC_XIE_ML(0xDB);
	IIC_XIE_ML(0x30);
	IIC_XIE_ML(0x8D);
	IIC_XIE_ML(0x14);
	IIC_XIE_ML(0xAF);
	OLED_Clear();
}  

int OLED_Lock=1;

void OLED_Write(int x,int y,int Size,const char *formate,...)
{
	char buf[32]={'\0'};
	va_list ap;

	while(!OLED_Lock) vTaskDelay(1);
	OLED_Lock=0;

	va_start(ap,formate);
	vsprintf(buf,formate,ap);
	va_end(ap);
	OLED_ShowString(x,y,buf,Size);

	OLED_Lock=1;
}
