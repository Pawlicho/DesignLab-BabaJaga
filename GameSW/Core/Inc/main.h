/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern struct Player player_one;
extern struct Player player_two;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOA
#define PIR1_VCC_Pin GPIO_PIN_1
#define PIR1_VCC_GPIO_Port GPIOA
#define VCP_TX_Pin GPIO_PIN_2
#define VCP_TX_GPIO_Port GPIOA
#define PIR_OUT_1_Pin GPIO_PIN_3
#define PIR_OUT_1_GPIO_Port GPIOA
#define PIR_OUT_2_Pin GPIO_PIN_4
#define PIR_OUT_2_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_5
#define BUZZER_GPIO_Port GPIOA
#define BABA_JAGA_PATRZY_Pin GPIO_PIN_6
#define BABA_JAGA_PATRZY_GPIO_Port GPIOA
#define PIR_SIG_1_Pin GPIO_PIN_0
#define PIR_SIG_1_GPIO_Port GPIOB
#define PIR_SIG_1_EXTI_IRQn EXTI0_IRQn
#define PIR_SIG_2_Pin GPIO_PIN_1
#define PIR_SIG_2_GPIO_Port GPIOB
#define PIR_SIG_2_EXTI_IRQn EXTI1_IRQn
#define PIR2_VCC_Pin GPIO_PIN_11
#define PIR2_VCC_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_15
#define VCP_RX_GPIO_Port GPIOA
#define LD3_Pin GPIO_PIN_3
#define LD3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define BUFFOR_MAX_SIZE (128)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
