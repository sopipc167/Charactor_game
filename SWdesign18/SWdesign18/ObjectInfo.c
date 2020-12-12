#include "ObjectInfo.h"
#include "GameBoardInfo.h"


//����, ��, ���� ���̸� �̵� �Ұ�(1), �����, ���� ��, ������, �����̸� �̵� ����(0) 
int DetectCollision(int floor, int x, int y)
{
	int num = gameBoardInfo[floor][y][x];
	
	if ((num <= -10) || ((num >= 1) && (num <= 10)) /*|| (���� ��)*/)
		return 1;
	else if ((num == 0) || ((num >= 30) && (num <= 120)) /* || (���� ��) || (����)*/)
	{
		if ((num > 30) && (num <= 120))
			insert(num);
		return 0;
	}
	else//����
		return -1;
}

void InitMonster(Character* monster, int _floor, int _x, int _y, Direction _route[])
{
	monster->map = _floor;
	monster->pos.x = _x;
	monster->pos.y = _y;
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

int MonsterRoute(Character* _m, int delta)
{
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
		monster->pos = nextPos;
		routeCnt++;
		return 0;
	}

	else return -1;
}