#pragma once

#define _MAP_WIDTH (57)
#define _MAP_HEIGHT (38)

typedef enum direction
{
	LEFT = 0,
	RIGHT,
	UP,
	DOWN
}Direction;

typedef struct vector
{
	int x;
	int y;
	int floor;
}Vector;
void DrawBoard(int idx);
int gameBoardInfo[10][_MAP_HEIGHT][_MAP_WIDTH];