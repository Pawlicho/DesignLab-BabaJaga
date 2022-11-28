#pragma once
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#define NAME_MAXSIZE (32)

enum player_id{PLAYER_ONE, PLAYER_TWO};

typedef struct
{
	char name[NAME_MAXSIZE];
	//enum player_id id;
	bool score;
}Player;
