#include "ObjectInfo.h"
#include "GameBoardInfo.h"


//����, ��, ���� ���̸� �̵� �Ұ�(1), �����, ���� ��, ������, �����̸� �̵� ����(0) 
int DetectCollision(int floor, int x, int y)
{
	int num = gameBoardInfo[floor][y][x];
	
	if ((x <= -10) || ((x >= 1) && (x <= 10)) /*|| (���� ��)*/)
		return 1;
	else if ((x == 0) || ((x >= 30) && (x <= 120)) /* || (���� ��) || (����)*/)
		return 0;	
}