#pragma once
#include <stdint.h>
#include "player.h"
#include "gpio.h"
#include <string.h>
#include "main.h"

int game_init(char* player_one_name, char* player_two_name);

void end_game();

int read_configuration();
