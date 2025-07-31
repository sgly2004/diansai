#ifndef __BSP_WS2812_H__
#define __BSP_WS2812_H__

#include "main.h"

#define WS2812_MAX        1            // 彩灯最大个数
#define WS2812_NUMBERS    1             // 彩灯个数

#define WS2812_RED        0xff0000      // 红色
#define WS2812_GREEN      0x00ff00      // 绿色
#define WS2812_BLUE       0x0000ff      // 蓝色
#define WS2812_BLACK      0x000000      // 熄灭
#define WS2812_WHITE      0xffffff      // 白色

#define RGB_R	    do{WS2812_Set_Color( WS2812_RED);WS2812_Send_Array(); } while(0);
#define RGB_G		do{WS2812_Set_Color( WS2812_GREEN);WS2812_Send_Array(); } while(0);
#define RGB_B		do{WS2812_Set_Color( WS2812_BLUE);WS2812_Send_Array(); } while(0);

int WS2812_RESET(void);
int WS2812_Set_Color( uint64_t Color);  // 设置彩灯颜色
int WS2812_Send_Array(void);    // 发送彩灯数据

#endif