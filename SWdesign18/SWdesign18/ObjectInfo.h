#pragma once
#include "GameBoardInfo.h"

#define _MONSTER_HP 5
#define _MONSTER_ATK 1
#define _MONSTER_MOVE_DELTATIME 100

#define _MONSTER_MAX_COUNT 11
#define _MONSTER_MAX_MOVE 50

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



int DetectCollision(int floor,int x, int y);

void InitMonster(Character* monster, int _floor, int _x, int _y, Direction a[]);
int MonsterRoute(Character* _m, int delta);
int MonsterAttack(Character* _m, int atk);
void MonsterHit(Character* _m, int atk);
void MonsterDie();