#ifndef _STARTUPTASK_H
#define _STARTUPTASK_H

#include "main.h"


void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName);
void vApplicationMallocFailedHook( void );
void vApplicationIdleHook( void );
void vApplicationTickHook( void );

void StartupTask(void);
TaskHandle_t GetLanYaHandler(void);
TaskHandle_t GetMPUHandler(void);


extern int YunTai_EN,Line_EN;
extern int car_go_dir;
extern int yutai_3_init_falg; //第三问中云台转向标志

#endif

