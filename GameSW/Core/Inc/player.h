#pragma once
#include <stdint.h>
#include <stdbool.h>

struct Player
{
	char name[128];
	uint8_t id;
	bool score;
};

