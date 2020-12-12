#pragma once
#include <stdio.h>

#define _MAP_WIDTH (57)
#define _MAP_HEIGHT (38)
#define _UI_WIDTH (20)
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
void DrawBoard(int idx);
void DrawUI();
void getAlphabetUI(int id, char a);
int gameBoardInfo[10][_MAP_HEIGHT][_MAP_WIDTH];
int Mapinfo[10][4];
// ù��° ��ȣ : ���� �ε���, �ι�° ��ȣ : �����¿�
int UIBoardInfo[_MAP_HEIGHT][_UI_WIDTH];