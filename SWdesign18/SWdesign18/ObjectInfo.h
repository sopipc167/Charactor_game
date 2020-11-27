#pragma once
#include "GameBoardInfo.h"

typedef struct item
{
	int duration;
	char* name;
	int (*use)(Character, int);
}Item;

typedef struct character
{
	int hp;
	int atk;
	void (*move)(Vector, Direction);
	void (*getHit)(Character*, int);
	int (*attack)(Character*, int);
	void (*die)();
	Item* inventory;
}Character;


int DetectCollision(int floor,int x, int y);