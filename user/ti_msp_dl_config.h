/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3505

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for MOTOR_PWM */
#define MOTOR_PWM_INST                                                     TIMG0
#define MOTOR_PWM_INST_IRQHandler                               TIMG0_IRQHandler
#define MOTOR_PWM_INST_INT_IRQN                                 (TIMG0_INT_IRQn)
#define MOTOR_PWM_INST_CLK_FREQ                                         32000000
/* GPIO defines for channel 0 */
#define GPIO_MOTOR_PWM_C0_PORT                                             GPIOA
#define GPIO_MOTOR_PWM_C0_PIN                                     DL_GPIO_PIN_12
#define GPIO_MOTOR_PWM_C0_IOMUX                                  (IOMUX_PINCM34)
#define GPIO_MOTOR_PWM_C0_IOMUX_FUNC                 IOMUX_PINCM34_PF_TIMG0_CCP0
#define GPIO_MOTOR_PWM_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_MOTOR_PWM_C1_PORT                                             GPIOA
#define GPIO_MOTOR_PWM_C1_PIN                                     DL_GPIO_PIN_13
#define GPIO_MOTOR_PWM_C1_IOMUX                                  (IOMUX_PINCM35)
#define GPIO_MOTOR_PWM_C1_IOMUX_FUNC                 IOMUX_PINCM35_PF_TIMG0_CCP1
#define GPIO_MOTOR_PWM_C1_IDX                                DL_TIMER_CC_1_INDEX

/* Defines for Servo */
#define Servo_INST                                                         TIMA0
#define Servo_INST_IRQHandler                                   TIMA0_IRQHandler
#define Servo_INST_INT_IRQN                                     (TIMA0_INT_IRQn)
#define Servo_INST_CLK_FREQ                                              3200000
/* GPIO defines for channel 0 */
#define GPIO_Servo_C0_PORT                                                 GPIOA
#define GPIO_Servo_C0_PIN                                         DL_GPIO_PIN_21
#define GPIO_Servo_C0_IOMUX                                      (IOMUX_PINCM46)
#define GPIO_Servo_C0_IOMUX_FUNC                     IOMUX_PINCM46_PF_TIMA0_CCP0
#define GPIO_Servo_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_Servo_C1_PORT                                                 GPIOA
#define GPIO_Servo_C1_PIN                                         DL_GPIO_PIN_22
#define GPIO_Servo_C1_IOMUX                                      (IOMUX_PINCM47)
#define GPIO_Servo_C1_IOMUX_FUNC                     IOMUX_PINCM47_PF_TIMA0_CCP1
#define GPIO_Servo_C1_IDX                                    DL_TIMER_CC_1_INDEX
/* GPIO defines for channel 2 */
#define GPIO_Servo_C2_PORT                                                 GPIOA
#define GPIO_Servo_C2_PIN                                         DL_GPIO_PIN_15
#define GPIO_Servo_C2_IOMUX                                      (IOMUX_PINCM37)
#define GPIO_Servo_C2_IOMUX_FUNC                     IOMUX_PINCM37_PF_TIMA0_CCP2
#define GPIO_Servo_C2_IDX                                    DL_TIMER_CC_2_INDEX
/* GPIO defines for channel 3 */
#define GPIO_Servo_C3_PORT                                                 GPIOA
#define GPIO_Servo_C3_PIN                                         DL_GPIO_PIN_17
#define GPIO_Servo_C3_IOMUX                                      (IOMUX_PINCM39)
#define GPIO_Servo_C3_IOMUX_FUNC                     IOMUX_PINCM39_PF_TIMA0_CCP3
#define GPIO_Servo_C3_IDX                                    DL_TIMER_CC_3_INDEX




/* Defines for QEI_0 */
#define QEI_0_INST                                                         TIMG8
#define QEI_0_INST_IRQHandler                                   TIMG8_IRQHandler
#define QEI_0_INST_INT_IRQN                                     (TIMG8_INT_IRQn)
/* Pin configuration defines for QEI_0 PHA Pin */
#define GPIO_QEI_0_PHA_PORT                                                GPIOA
#define GPIO_QEI_0_PHA_PIN                                        DL_GPIO_PIN_26
#define GPIO_QEI_0_PHA_IOMUX                                     (IOMUX_PINCM59)
#define GPIO_QEI_0_PHA_IOMUX_FUNC                    IOMUX_PINCM59_PF_TIMG8_CCP0
/* Pin configuration defines for QEI_0 PHB Pin */
#define GPIO_QEI_0_PHB_PORT                                                GPIOA
#define GPIO_QEI_0_PHB_PIN                                        DL_GPIO_PIN_27
#define GPIO_QEI_0_PHB_IOMUX                                     (IOMUX_PINCM60)
#define GPIO_QEI_0_PHB_IOMUX_FUNC                    IOMUX_PINCM60_PF_TIMG8_CCP1


/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG7)
#define TIMER_0_INST_IRQHandler                                 TIMG7_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG7_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                           (999U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_FREQUENCY                                           16000000
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                         DL_GPIO_PIN_1
#define GPIO_UART_0_TX_PIN                                         DL_GPIO_PIN_0
#define GPIO_UART_0_IOMUX_RX                                      (IOMUX_PINCM2)
#define GPIO_UART_0_IOMUX_TX                                      (IOMUX_PINCM1)
#define GPIO_UART_0_IOMUX_RX_FUNC                       IOMUX_PINCM2_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                       IOMUX_PINCM1_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_16_MHZ_115200_BAUD                                       (8)
#define UART_0_FBRD_16_MHZ_115200_BAUD                                      (44)
/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_FREQUENCY                                           32000000
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOB
#define GPIO_UART_1_TX_PORT                                                GPIOB
#define GPIO_UART_1_RX_PIN                                         DL_GPIO_PIN_7
#define GPIO_UART_1_TX_PIN                                         DL_GPIO_PIN_6
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM24)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM23)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM24_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM23_PF_UART1_TX
#define UART_1_BAUD_RATE                                                (115200)
#define UART_1_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_1_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for UART_3 */
#define UART_3_INST                                                        UART3
#define UART_3_INST_FREQUENCY                                           32000000
#define UART_3_INST_IRQHandler                                  UART3_IRQHandler
#define UART_3_INST_INT_IRQN                                      UART3_INT_IRQn
#define GPIO_UART_3_RX_PORT                                                GPIOB
#define GPIO_UART_3_TX_PORT                                                GPIOB
#define GPIO_UART_3_RX_PIN                                         DL_GPIO_PIN_3
#define GPIO_UART_3_TX_PIN                                         DL_GPIO_PIN_2
#define GPIO_UART_3_IOMUX_RX                                     (IOMUX_PINCM16)
#define GPIO_UART_3_IOMUX_TX                                     (IOMUX_PINCM15)
#define GPIO_UART_3_IOMUX_RX_FUNC                      IOMUX_PINCM16_PF_UART3_RX
#define GPIO_UART_3_IOMUX_TX_FUNC                      IOMUX_PINCM15_PF_UART3_TX
#define UART_3_BAUD_RATE                                                (115200)
#define UART_3_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_3_FBRD_32_MHZ_115200_BAUD                                      (23)




/* Defines for SPI_WS2812 */
#define SPI_WS2812_INST                                                    SPI1
#define SPI_WS2812_INST_IRQHandler                              SPI1_IRQHandler
#define SPI_WS2812_INST_INT_IRQN                                  SPI1_INT_IRQn
#define GPIO_SPI_WS2812_PICO_PORT                                         GPIOB
#define GPIO_SPI_WS2812_PICO_PIN                                 DL_GPIO_PIN_15
#define GPIO_SPI_WS2812_IOMUX_PICO                              (IOMUX_PINCM32)
#define GPIO_SPI_WS2812_IOMUX_PICO_FUNC              IOMUX_PINCM32_PF_SPI1_PICO
#define GPIO_SPI_WS2812_POCI_PORT                                         GPIOB
#define GPIO_SPI_WS2812_POCI_PIN                                 DL_GPIO_PIN_14
#define GPIO_SPI_WS2812_IOMUX_POCI                              (IOMUX_PINCM31)
#define GPIO_SPI_WS2812_IOMUX_POCI_FUNC              IOMUX_PINCM31_PF_SPI1_POCI
/* GPIO configuration for SPI_WS2812 */
#define GPIO_SPI_WS2812_SCLK_PORT                                         GPIOB
#define GPIO_SPI_WS2812_SCLK_PIN                                 DL_GPIO_PIN_16
#define GPIO_SPI_WS2812_IOMUX_SCLK                              (IOMUX_PINCM33)
#define GPIO_SPI_WS2812_IOMUX_SCLK_FUNC              IOMUX_PINCM33_PF_SPI1_SCLK



/* Port definition for Pin Group BUZZER */
#define BUZZER_PORT                                                      (GPIOA)

/* Defines for PIN_0: GPIOA.7 with pinCMx 14 on package pin 49 */
#define BUZZER_PIN_0_PIN                                         (DL_GPIO_PIN_7)
#define BUZZER_PIN_0_IOMUX                                       (IOMUX_PINCM14)
/* Port definition for Pin Group M2_1_Dir */
#define M2_1_Dir_PORT                                                    (GPIOA)

/* Defines for PIN_3: GPIOA.16 with pinCMx 38 on package pin 9 */
#define M2_1_Dir_PIN_3_PIN                                      (DL_GPIO_PIN_16)
#define M2_1_Dir_PIN_3_IOMUX                                     (IOMUX_PINCM38)
/* Port definition for Pin Group M1_2_Dir */
#define M1_2_Dir_PORT                                                    (GPIOB)

/* Defines for PIN_2: GPIOB.17 with pinCMx 43 on package pin 14 */
#define M1_2_Dir_PIN_2_PIN                                      (DL_GPIO_PIN_17)
#define M1_2_Dir_PIN_2_IOMUX                                     (IOMUX_PINCM43)
/* Port definition for Pin Group M1_1_Dir */
#define M1_1_Dir_PORT                                                    (GPIOB)

/* Defines for PIN_1: GPIOB.19 with pinCMx 45 on package pin 16 */
#define M1_1_Dir_PIN_1_PIN                                      (DL_GPIO_PIN_19)
#define M1_1_Dir_PIN_1_IOMUX                                     (IOMUX_PINCM45)
/* Port definition for Pin Group M2_2_Dir */
#define M2_2_Dir_PORT                                                    (GPIOB)

/* Defines for PIN_4: GPIOB.24 with pinCMx 52 on package pin 23 */
#define M2_2_Dir_PIN_4_PIN                                      (DL_GPIO_PIN_24)
#define M2_2_Dir_PIN_4_IOMUX                                     (IOMUX_PINCM52)
/* Port definition for Pin Group RED */
#define RED_PORT                                                         (GPIOA)

/* Defines for LED1: GPIOA.2 with pinCMx 7 on package pin 42 */
#define RED_LED1_PIN                                             (DL_GPIO_PIN_2)
#define RED_LED1_IOMUX                                            (IOMUX_PINCM7)
/* Port definition for Pin Group BLUE */
#define BLUE_PORT                                                        (GPIOA)

/* Defines for LED3: GPIOA.18 with pinCMx 40 on package pin 11 */
#define BLUE_LED3_PIN                                           (DL_GPIO_PIN_18)
#define BLUE_LED3_IOMUX                                          (IOMUX_PINCM40)
/* Port definition for Pin Group OLED */
#define OLED_PORT                                                        (GPIOA)

/* Defines for SCL: GPIOA.31 with pinCMx 6 on package pin 39 */
#define OLED_SCL_PIN                                            (DL_GPIO_PIN_31)
#define OLED_SCL_IOMUX                                            (IOMUX_PINCM6)
/* Defines for SDA: GPIOA.28 with pinCMx 3 on package pin 35 */
#define OLED_SDA_PIN                                            (DL_GPIO_PIN_28)
#define OLED_SDA_IOMUX                                            (IOMUX_PINCM3)
/* Port definition for Pin Group IOA */
#define IOA_PORT                                                         (GPIOA)

/* Defines for IOA1: GPIOA.10 with pinCMx 21 on package pin 56 */
#define IOA_IOA1_PIN                                            (DL_GPIO_PIN_10)
#define IOA_IOA1_IOMUX                                           (IOMUX_PINCM21)
/* Defines for IOA2: GPIOA.11 with pinCMx 22 on package pin 57 */
#define IOA_IOA2_PIN                                            (DL_GPIO_PIN_11)
#define IOA_IOA2_IOMUX                                           (IOMUX_PINCM22)
/* Defines for IOA3: GPIOA.30 with pinCMx 5 on package pin 37 */
#define IOA_IOA3_PIN                                            (DL_GPIO_PIN_30)
#define IOA_IOA3_IOMUX                                            (IOMUX_PINCM5)
/* Port definition for Pin Group HW */
#define HW_PORT                                                          (GPIOB)

/* Defines for HW1: GPIOB.0 with pinCMx 12 on package pin 47 */
#define HW_HW1_PIN                                               (DL_GPIO_PIN_0)
#define HW_HW1_IOMUX                                             (IOMUX_PINCM12)
/* Defines for HW2: GPIOB.1 with pinCMx 13 on package pin 48 */
#define HW_HW2_PIN                                               (DL_GPIO_PIN_1)
#define HW_HW2_IOMUX                                             (IOMUX_PINCM13)
/* Defines for HW3: GPIOB.10 with pinCMx 27 on package pin 62 */
#define HW_HW3_PIN                                              (DL_GPIO_PIN_10)
#define HW_HW3_IOMUX                                             (IOMUX_PINCM27)
/* Defines for HW4: GPIOB.11 with pinCMx 28 on package pin 63 */
#define HW_HW4_PIN                                              (DL_GPIO_PIN_11)
#define HW_HW4_IOMUX                                             (IOMUX_PINCM28)
/* Port definition for Pin Group KEY1 */
#define KEY1_PORT                                                        (GPIOB)

/* Defines for PIN_21: GPIOB.25 with pinCMx 56 on package pin 27 */
#define KEY1_PIN_21_PIN                                         (DL_GPIO_PIN_25)
#define KEY1_PIN_21_IOMUX                                        (IOMUX_PINCM56)
/* Defines for PIN_22: GPIOB.22 with pinCMx 50 on package pin 21 */
#define KEY1_PIN_22_PIN                                         (DL_GPIO_PIN_22)
#define KEY1_PIN_22_IOMUX                                        (IOMUX_PINCM50)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_MOTOR_PWM_init(void);
void SYSCFG_DL_Servo_init(void);
void SYSCFG_DL_QEI_0_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_UART_3_init(void);
void SYSCFG_DL_SPI_WS2812_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
