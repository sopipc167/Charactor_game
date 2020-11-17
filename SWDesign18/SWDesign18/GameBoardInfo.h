#pragma once

#define _MAP_WIDTH (55)
#define _MAP_HEIGHT (35)

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
}Vector;
void DrawBoard();
int gameBoardInfo[10][_MAP_HEIGHT][_MAP_WIDTH];