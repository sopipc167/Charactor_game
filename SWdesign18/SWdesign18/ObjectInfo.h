#pragma once
#include "GameBoardInfo.h"

#define _MONSTER_HP 5
#define _MONSTER_ATK 1
#define _MONSTER_MOVE_DELTATIME 100

#define _MONSTER_MAX_COUNT 9
#define _MONSTER_MAX_MOVE 130

typedef struct item
{
	int duration;
	char* name;
	void (*use)(struct character* p,int x);//int->void로 바꿈
}Item;

typedef struct character
{
	int map;
	Direction* route;
	int routeCnt;
	Vector pos;
	Direction Di;
	int hp;
	int atk;
	int isDie;
	void (*move)(struct character* p, int);
	void (*getHit)(struct character* p, int x);
	int (*attack)(struct character* p);
	void (*die)(struct character* p);
	Item* inventory;
}Character;

//플레이어 
Character pc;
//몬스터 이동, 공격 루틴 변수
int routeDelta;

Character MonsterArray[_MAP_COUNT][11];
int DetectCollision(int floor,int x, int y);


Direction monsterRoutes[_MAP_COUNT][_MONSTER_MAX_COUNT][_MONSTER_MAX_MOVE];
Vector monsterInitPosition[_MAP_COUNT][_MONSTER_MAX_COUNT];
void InitMonster(Character* monster, int _floor, Vector _pos, Direction _route[]);
int PlayerAttack(Character* p);
void PlayerHit(Character* p, int atk);
int MonsterRoute(Character* _m, int idx);
int MonsterAttack(Character* _m);
void MonsterHit(Character* _m, int atk);
void MonsterDie(Character* _m);
