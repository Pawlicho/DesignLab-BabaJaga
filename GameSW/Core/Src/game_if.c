#include "game_if.h"

void game_init(char* player_one_name, char* player_two_name)
{
    /* Disable IRQN */
    NVIC_DisableIRQ(EXTI0_IRQn);
	NVIC_DisableIRQ(EXTI1_IRQn);
	HAL_GPIO_WritePin(PIR1_VCC_GPIO_Port, PIR1_VCC_Pin, 0);
	HAL_GPIO_WritePin(PIR2_VCC_GPIO_Port, PIR2_VCC_Pin, 0);
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);

    /* Reset score */
    player_one.score = 0;
    player_two.score = 0;

    /* Setting up players' name */
    strcpy(player_one.name, player_one_name);
    strcpy(player_two.name, player_two_name);

    /* Enable IRQN - game starts now*/
	HAL_GPIO_WritePin(PIR1_VCC_GPIO_Port, PIR1_VCC_Pin, 1);
	HAL_GPIO_WritePin(PIR2_VCC_GPIO_Port, PIR2_VCC_Pin, 1);
    NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
}

void end_game()
{
    NVIC_DisableIRQ(EXTI0_IRQn);
	NVIC_DisableIRQ(EXTI1_IRQn);
	HAL_GPIO_WritePin(PIR1_VCC_GPIO_Port, PIR1_VCC_Pin, 0);
	HAL_GPIO_WritePin(PIR2_VCC_GPIO_Port, PIR2_VCC_Pin, 0);
    player_one.score = 0;
    player_two.score = 0;

	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);
}

