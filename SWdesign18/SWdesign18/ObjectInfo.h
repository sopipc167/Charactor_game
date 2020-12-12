#pragma once
#include "GameBoardInfo.h"

#define _MONSTER_HP 5
#define _MONSTER_ATK 1
#define _MONSTER_MOVE_DELTATIME 100

typedef struct item
{
	int duration;
	char* name;
	int (*use)(struct character* p, int x);
}Item;

typedef struct character
{
	int map;
	Direction* route;
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

void InitMonster(Character* monster, int _x, int _y, Direction a[]);
int MonsterRoute(int floor, Character* _m, int delta);