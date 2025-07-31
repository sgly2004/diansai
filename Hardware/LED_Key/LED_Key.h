#ifndef __LED_KEY_H
#define __LED_KEY_H

#include "main.h"

void GPIO_WriteBit(GPIO_Regs* gpio, uint32_t pins,uint8_t Value);

#define ON			         0
#define OFF			         1

#define RED(x)		        do{GPIO_WriteBit(RED_PORT,Red_LED1_PIN ,x);}while(0);
#define GREEN(x)			do{GPIO_WriteBit(GREEN_PORT,GREEN_LED2_PIN ,x);}while(0); 
#define	BLUE(x)			    do{GPIO_WriteBit(BLUE_PORT,BLUE_LED3_PIN ,x);}while(0);

#define BUZZER(x)			do{GPIO_WriteBit(BUZZER_PORT,BUZZER_PIN_0_PIN,x);}while(0); 

#define KEY1 				(!DL_GPIO_readPins(KEY1_PORT ,KEY1_PIN_21_PIN))
#define KEY2 				(!DL_GPIO_readPins(KEY1_PORT ,KEY1_PIN_22_PIN))
//#define KEY3 				!DL_GPIO_readPins(KEY_PORT ,KEY_KEY_YELLOW_PIN)

#define HW_IO1 				(!DL_GPIO_readPins(HW_PORT ,HW_HW1_PIN))
#define HW_IO2 				(!DL_GPIO_readPins(HW_PORT ,HW_HW2_PIN))
#define HW_IO3 				(!DL_GPIO_readPins(HW_PORT ,HW_HW3_PIN))
#define HW_IO4 				(!DL_GPIO_readPins(HW_PORT ,HW_HW4_PIN))

#endif
