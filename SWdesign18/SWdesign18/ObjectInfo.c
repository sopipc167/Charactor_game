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
