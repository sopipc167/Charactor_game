#pragma once
#include "GameBoardInfo.h"

typedef struct item
{
	int duration;
	char* name;
	int (*use)(struct character* p, int x);
}Item;

typedef struct character
{
	int map;
	Vector pos;
	Direction Di;
	int hp;
	int atk;
	void (*move)(Vector, Direction);
	void (*getHit)(struct character* p, int x);
	int (*attack)(struct character* p, int x);
	void (*die)();
	Item* inventory;
}Character;


int DetectCollision(int floor,int x, int y);