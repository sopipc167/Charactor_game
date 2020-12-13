#pragma once
#include "GameBoardInfo.h"

typedef struct item
{
	int duration;
	char* name;
	void (*use)(struct character* p,int x);//int->void�� �ٲ�
}Item;

typedef struct character
{
	int map;
	int* route;
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

Character monsterArray[11];


int DetectCollision(int floor,int x, int y);