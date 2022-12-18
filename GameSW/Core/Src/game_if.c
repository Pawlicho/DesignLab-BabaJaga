#include "game_if.h"

int game_init(char* player_one_name, char* player_two_name)
{
    /* Disable IRQN */
    NVIC_DisableIRQ(EXTI0_IRQn);
	NVIC_DisableIRQ(EXTI1_IRQn);

    /* Reset score */
    player_one.score = 0;
    player_two.score = 0;

    /* Setting up players' name */
    strcpy(player_one.name, player_one_name);
    strcpy(player_two.name, player_two_name);

    /* Enable IRQN - game starts now*/
    NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
	return 0;
}

void end_game()
{
    NVIC_DisableIRQ(EXTI0_IRQn);
	NVIC_DisableIRQ(EXTI1_IRQn);
    player_one.score = 0;
    player_two.score = 0;

	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);
}

int read_configuration()
{
	/* TODO */
	/* Implement some logic for stopping game according to some clock or whatever */

	return 0;
}
