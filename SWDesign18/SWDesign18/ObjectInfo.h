#pragma once
#include "GameBoardInfo.h"

typedef struct character
{
	int hp;
	int atk;
	void (*move)(Vector, direction);
	void (*getHit)(Character, int);
	//attack function pointer
	void (*die)();
	Item* inventory;
}Character;

typedef struct item
{
	int duration;
	char* name;
	void (*use)();
}Item;