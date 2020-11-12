#pragma once

#define _MAP_WIDTH (40)
#define _MAP_HEIGHT (25)

enum direction
{
	LEFT = 0,
	RIGHT,
	UP,
	DOWN
};

typedef struct vector
{
	int x;
	int y;
}Vector;

int gameBoardInfo[10][_MAP_HEIGHT][_MAP_WIDTH];