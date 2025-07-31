#include "LED_Key.h"

void GPIO_WriteBit(GPIO_Regs* gpio, uint32_t pins,uint8_t Value)
{
	   if(Value!=0)
		   DL_GPIO_setPins(gpio,pins);
	   else 
		  DL_GPIO_clearPins(gpio,pins);
}