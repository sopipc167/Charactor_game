#pragma once
#include "ObjectInfo.h"
#include "GameBoardInfo.h"


//����, ��, ���� ���̸� �̵� �Ұ�(1), �����, ���� ��, ������, �����̸� �̵� ����(0) 
int DetectCollision(int floor, int x, int y)
{
	int num = gameBoardInfo[floor][y][x];

	if ((num <= -10) || ((num >= 1) && (num <= 10)) /*|| (���� ��)*/)
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
		{RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,RIGHT,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,UP,UP,UP,UP,UP,UP,UP,UP},
		{DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,DOWN,UP,UP,UP,UP,UP,UP,UP,UP,UP}
	}
};

extern Vector monsterInitPosition[_MAP_COUNT][_MONSTER_MAX_COUNT] =
{
	//0�� ��
	{{22,15}, {41,10}}
};

int PlayerAttack(Character* p)
{

}
int PlayerHit(Character* p, int atk)
{

}

void InitMonster(Character* monster, int _floor, Vector _pos, Direction _route[])
{
	monster->map = _floor;
	monster->pos.x = _pos.x;
	monster->pos.y = _pos.y;
	monster->route = _route;

	monster->Di = _route[0];

	monster->hp = _MONSTER_HP;
	monster->atk = _MONSTER_ATK;

	monster->move = MonsterRoute;
	//monster->getHit = 
	//monster->attack = 
	//monster->die = 
	monster->inventory = NULL;
}

int MonsterRoute(Character* _m, int idx)
{
	extern Character* pc;
	static int routeCnt = 1;
	Character* monster = _m;

	Vector nextPos = monster->pos;

	switch (monster->route[routeCnt])
	{
	case LEFT:
		nextPos.x--;
		break;
	case RIGHT:
		nextPos.x++;
		break;
	case UP:
		nextPos.y++;
		break;
	case DOWN:
		nextPos.y--;
		break;
	default:
		break;
	}

	if (DetectCollision(monster->map, nextPos.x, nextPos.y) == 1)
	{
		gameBoardInfo[monster->map][monster->pos.y][monster->pos.x] = 0;
		monster->pos = nextPos;
		gameBoardInfo[monster->map][monster->pos.y][monster->pos.x] = -idx-10;
		routeCnt++;
		if(routeCnt >= sizeof(monster->route)/sizeof(Direction))
		{
			routeCnt = 0;
		}
	}

	//+ĭ ���� �÷��̾� ������ ����
	return 0;
}

int MonsterAttack(Character* _m)
{
	Character* monster = _m;
	int atk = monster->atk;

	return atk;
}