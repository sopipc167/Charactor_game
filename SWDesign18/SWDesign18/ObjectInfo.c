#include "ObjectInfo.h"
#include "GameBoardInfo.h"


//몬스터, 벽, 막힌 문이면 이동 불가(1), 빈공간, 열린 문, 아이템, 함정이면 이동 가능(0) 
int DetectCollision(int floor, int x, int y)
{
	int num = gameBoardInfo[floor][y][x];
	
	if ((x <= -10) || ((x >= 1) && (x <= 10)) /*|| (막힌 문)*/)
		return 1;
	else if ((x == 0) || ((x >= 30) && (x <= 120)) /* || (열린 문) || (함정)*/)
		return 0;	
}