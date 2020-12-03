#include "ObjectInfo.h"
#include "GameBoardInfo.h"


//몬스터, 벽, 막힌 문이면 이동 불가(1), 빈공간, 열린 문, 아이템, 함정이면 이동 가능(0) 
int DetectCollision(int floor, int x, int y)
{
	int num = gameBoardInfo[floor][y][x];
	
	if ((num <= -10) || ((num >= 1) && (num <= 10)) /*|| (막힌 문)*/)
		return 1;
	else if ((num == 0) || ((num >= 30) && (num <= 120)) /* || (열린 문) || (함정)*/)
	{
		if ((num > 30) && (num <= 120))
			insert(num);
		return 0;
	}
	else//몬스터
		return -1;
}
