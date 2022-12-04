#pragma once
#include <stdint.h>
#include "player.h"
#include "gpio.h"
#include <string.h>

int game_init(char* player_one_name, char* player_two_name);

int read_configuration();
