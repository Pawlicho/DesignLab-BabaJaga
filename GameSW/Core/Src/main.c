/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "player.h"
#include "debug_settings.h"
#include "game_if.h"
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define START ('b')
#define STOP ('c')
#define BABA_JAGA_PATRZY ('d')
#define BABA_JAGA_NIE_PATRZY ('e')
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern struct Player player_one;
extern struct Player player_two;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t rx;
uint8_t debug_message[15];
uint8_t message = START;
int players_movement_allowed = 1;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* TODO */
  /* Add some mechanism to disable diodes */

  char player_one_name[BUFFOR_MAX_SIZE];
  char player_two_name[BUFFOR_MAX_SIZE];

  /* TODO */
  /* Here we should anchor some mechanism to get configuration from bluetooth */

  /* TODO */
  /* For now names gonna be static - will see if we wanna send it through bluetooth */
  char debug_name_1[BUFFOR_MAX_SIZE] = {"Pawel"};
  char debug_name_2[BUFFOR_MAX_SIZE] = {"Mariusz"};
  strcpy(player_one_name, debug_name_1);
  strcpy(player_two_name, debug_name_2);
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  HAL_UART_Receive_IT(&huart1, &rx, 1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  switch (message)
	  {
	  case START:
		  game_init(player_one_name, player_two_name);
		  players_movement_allowed = 1;
		  message = 0x00;
		  message = BABA_JAGA_NIE_PATRZY;
		  break;
	  case STOP:
		  end_game();
		  message = 0x00;
		  break;
	  case BABA_JAGA_PATRZY:
		  HAL_GPIO_WritePin(PIR1_VCC_GPIO_Port, PIR1_VCC_Pin, 1);
		  HAL_GPIO_WritePin(PIR2_VCC_GPIO_Port, PIR2_VCC_Pin, 1);
		  NVIC_EnableIRQ(EXTI0_IRQn);
		  NVIC_EnableIRQ(EXTI1_IRQn);
		  HAL_GPIO_WritePin(BABA_JAGA_PATRZY_GPIO_Port, BABA_JAGA_PATRZY_Pin, 1);
		  players_movement_allowed = 0;
		  message = 0x00;
		  break;
	  case BABA_JAGA_NIE_PATRZY:
		  HAL_GPIO_WritePin(PIR1_VCC_GPIO_Port, PIR1_VCC_Pin, 0);
		  HAL_GPIO_WritePin(PIR2_VCC_GPIO_Port, PIR2_VCC_Pin, 0);
		  NVIC_DisableIRQ(EXTI0_IRQn);
		  NVIC_DisableIRQ(EXTI1_IRQn);
		  HAL_GPIO_WritePin(BABA_JAGA_PATRZY_GPIO_Port, BABA_JAGA_PATRZY_Pin, 0);
		  players_movement_allowed = 1;
		  message = 0x00;
		  break;
	  default: ;
		  break;
	  }
	  if (players_movement_allowed == 0)
	  {
		  if (player_one.score == 1)
		  {
			  // Player 1 wins
			  HAL_GPIO_TogglePin(PIR_OUT_1_GPIO_Port, PIR_OUT_1_Pin);
			  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 1);
			  end_game();
			 }
		  else if (player_two.score == 1)
		  {
			  // Player 2 wins
			  HAL_GPIO_TogglePin(PIR_OUT_2_GPIO_Port, PIR_OUT_2_Pin);
			  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 1);
			  end_game();
		  }
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enable MSI Auto calibration
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1)
	{
		if (rx == 'e')
		{
			sprintf(debug_message, "Received e");
			HAL_GPIO_TogglePin(BABA_JAGA_PATRZY_GPIO_Port, BABA_JAGA_PATRZY_Pin);
		}
		else if (rx == 0)
		{
			sprintf(debug_message, "Received 00000");
		}
		else
		{
			sprintf(debug_message, "Received sth else");
		}
	HAL_UART_Receive_IT(&huart1, &rx, 1);
	HAL_UART_Transmit_IT(&huart1, debug_message, 15);
	}

}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
