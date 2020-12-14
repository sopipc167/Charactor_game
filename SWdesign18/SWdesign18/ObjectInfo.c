#pragma once
#include "ObjectInfo.h"
#include "GameBoardInfo.h"
#include <Windows.h>

//����, ��, ���� ���̸� �̵� �Ұ�(1), �����, ���� ��, ������, �����̸� �̵� ����(0) 
int DetectCollision(int floor, int x, int y)
{
	int num = gameBoardInfo[floor][y][x];

	if ((num <= -10) || ((num >= 1) && (num <= 10) || (num == 20)) /*|| (���� ��)*/)
		return 1;
	else if ((num == 0)) /* || (���� ��) || (����)*/
		return 0;
	else if ((num >= 30) && (num <= 120)) {
		return 0;
	}
	else//����
		return -1;
}


int DetectSpell(int floor, int x, int y)
{
	int num = gameBoardInfo[floor][y][x];

	if ((num <= -10) || ((num >= 1) && (num <= 10)) /*|| (���� ��)*/)
		return 1;
	else if ((num == 0)) /* || (���� ��) || (����)*/
		return 0;
	else if ((num >= 30) && (num <= 120)) {
		insert(num);
		return 0;
	}
	else//����
		return -1;
}




//���� �۾�

extern Direction monsterRoutes[_MAP_COUNT][_MONSTER_MAX_COUNT][_MONSTER_MAX_MOVE] =
{
	//0�� ��
	{
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{END},
		{END},
		{END},
		{END},
		{END},
		{END},
		{END}
	},
	//1
	{
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,DOWN,DOWN,DOWN,DOWN,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,RIGHT,RIGHT,RIGHT,RIGHT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{END},
		{END},
		{END},
		{END},
		{END},
		{END}
	},
	//2�� ��
	{
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
	},
	//3�� ��
	{
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,END},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,RIGHT,RIGHT,RIGHT,RIGHT,UP,UP,UP,UP,UP,UP,UP,UP,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{END},
		{END},
		{END},
		{END},
		{END}
	},
	//4�� ��
	{
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{END},
		{END},
		{END}
	},
	//5�� ��
	{
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{END},
		{END},
		{END},
		{END},
		{END},
		{END}
	},
	//6�� ��
	{
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,UP,UP,UP,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,UP,UP,UP,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,END},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{END},
		{END},
		{END},
		{END}
	},
	//7
	{
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,RIGHT,RIGHT,RIGHT,RIGHT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,RIGHT,RIGHT,RIGHT,RIGHT,UP,UP,UP,UP,UP,UP,UP,UP,LEFT,LEFT,LEFT,LEFT,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,UP,UP,UP,UP,UP,UP,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,RIGHT,RIGHT,RIGHT,RIGHT,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,END},
		{UP,UP,UP,UP,UP,UP,UP,UP,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,END},
		{END},
		{END},
		{END},
		{END}
	},
	//8
	{
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,UP,UP,UP,UP,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,END},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,RIGHT,RIGHT,RIGHT,RIGHT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,RIGHT,RIGHT,RIGHT,RIGHT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,LEFT,LEFT,LEFT,LEFT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,UP,END},
		{END},
		{END},
		{END},
		{END},
		{END}
	}
};

extern Vector monsterInitPosition[_MAP_COUNT][_MONSTER_MAX_COUNT] =
{
	//0�� ��
	{{22,15}, {41,10}},
	//1�� ��
	{{10,11}, {26,4},{38,11}},
	//2�� ��
	{{16,6}, {38,9},{18,12},{40,15},{20,18},{42,21},{22,24},{44,27},{24,30}},
	//3�� ��
	{{2,18}, {6,14},{18,22},{42,18}},
	//4�� ��
	{{10,6},{18,6},{14,19},{10,30},{26,22},{54,2}},
	//5
	{{4,2},{22,18},{46,22}},
	//6�� ��
	{{4,2},{22,6}, {10,14},{30,18},{54,13} },
	//7
	{{6,24},{10,10},{17,26},{30,14},{46,30}},
	//8
	{{2,4},{6,26},{30,18},{42,22}}
};

int PlayerAttack(Character* p)
{
	Character* player = p;
	int atk = player->atk;
	return atk;
}
void PlayerHit(Character* p, int atk)
{
	Character* player = p;
	player->hp -= atk;
	if (player->hp <= 0)
	{
		player->isDie = 1;
		player->die(player);
	}
}
void PlayerDie(Character* p)
{
	Character* player = p;
	if (player->isDie == 1)
	{
		printf("Game over");
	}
	//��� �� ����
	//ui ��ǥ�� ���� ���ӿ��� ���
}
void InitMonster(Character* monster, int _floor, Vector _pos, Direction _route[])
{
	monster->map = _floor;
	monster->pos.x = _pos.x;
	monster->pos.y = _pos.y;
	monster->route = _route;
	monster->routeCnt = 0;

	monster->Di = _route[0];

	monster->hp = _MONSTER_HP;
	monster->atk = _MONSTER_ATK;
	monster->isDie = 0;

	monster->move = MonsterRoute;
	monster->getHit = MonsterHit;
	monster->attack = MonsterAttack;
	monster->die = MonsterDie;
	monster->inventory = NULL;
}

int MonsterRoute(Character* _m, int idx)
{
	extern Character pc;
	Character* monster = _m;

	Vector nextPos = monster->pos;
	int end = 0;
	SetConsoleTextAttribute(GetStdHandle((STD_OUTPUT_HANDLE)), 7);
	switch (monster->route[monster->routeCnt])
	{
	case LEFT:
		nextPos.x--;
		break;
	case RIGHT:
		nextPos.x++;
		break;
	case UP:
		nextPos.y--;
		break;
	case DOWN:
		nextPos.y++;
		break;
	default:
		end = 1;
		break;
	}
	if (end)
	{
		monster->routeCnt = 0;
		return 0;
	}

	if (DetectCollision(monster->map, nextPos.x, nextPos.y) != 1)
	{
		gameBoardInfo[monster->map][monster->pos.y][monster->pos.x] = 0;
		SetCurrentCursorPos(monster->pos.x * 2, monster->pos.y);
		printf("  ");
		monster->pos = nextPos;
		gameBoardInfo[monster->map][monster->pos.y][monster->pos.x] = -idx-10;
		monster->routeCnt++;
		SetCurrentCursorPos(nextPos.x * 2, nextPos.y);
		printf("#");
	}

	if (pc.pos.x/2 - monster->pos.x <= 1 && pc.pos.x/2 - monster->pos.x >= -1 && pc.pos.y == monster->pos.y) 
		pc.getHit(&pc, monster->attack(monster));
	else if (pc.pos.y - monster->pos.y <= 1 && pc.pos.y - monster->pos.y >= -1 && pc.pos.x / 2 == monster->pos.x)
		pc.getHit(&pc, monster->attack(monster));
		
	return 0;
}

int MonsterAttack(Character* _m)
{

	return _m->atk;
}

void MonsterHit(Character* _m, int atk)
{
	Character* monster = _m;
	monster->hp -= atk;
	if (monster->hp <= 0)
	{
		monster->die(monster);
	}
}

void MonsterDie(Character* _m)
{
	_m->isDie = 1;
}