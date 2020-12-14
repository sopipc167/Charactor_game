#pragma once
#include <stdio.h>
#include <Windows.h>
#include "GameBoardInfo.h"
#include "ObjectInfo.h"
#include"Stack.h"
#include"Item.h"

void ProcessKeyInput();
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos();
void DrawLine(int type, int length, COORD start);
void CursorView(char show);//Ŀ�� �����
Character pc;
int map_index;
//�÷��̾� ��ȣ=20


//�κ��丮 �迭
//item �迭

//���� �迭
Character MonsterArray[_MAP_COUNT][11];

int main()
{
	initItem();
	initList();
	map_index=0;
	pc.map = 0;        //�÷��̾� �� �ε���
	pc.pos.x = 64;     //�÷��̾� �ʱ� x��
	pc.pos.y = 32;     //�÷��̾� �ʱ� y��
	pc.hp = 0;
	gameBoardInfo[0][32][31] = 20;
	CursorView(0);     //Ŀ�� �����
	system("mode con cols=155 lines=42");
	DrawBoard(map_index);
	DrawUI();
	setmapinfo();
	SetCurrentCursorPos(pc.pos.x, pc.pos.y);
	printf("��");


	for (int i = 0; i < _MAP_COUNT; i++)
	{
		for(int j = 0; j< 11; j++)
		{
			if(monsterRoutes[i][j] != NULL)
			{
				InitMonster(MonsterArray[i] + j, i, monsterInitPosition[i][j], monsterRoutes[i][j]);
			}
		}
	}
	while (1) {
		ProcessKeyInput();
		for(int i = 0; i < _MONSTER_MAX_COUNT; i++)
		{
			Character* k = MonsterArray[map_index] + i;
			if (k != NULL)
				k->move(k, i);
		}
		Sleep(20);
	}
}

void SetCurrentCursorPos(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

COORD GetCurrentCursorPos()
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;
	return curPoint;
}

void DrawVerticalLine(int type, int length, COORD start)
{
	SetCurrentCursorPos(start.X, start.Y);
	if (type == 0)
	{
		for (int i = 0; i < length; i++)
		{
			SetCurrentCursorPos(i * 2 + start.X, start.Y);
			printf("��");
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			SetCurrentCursorPos(start.X, start.Y + i);
			printf("��");
		}
	}
}

void DrawHorizontalLine(int type, int length, COORD start)
{

}

void CursorView(char show)//Ŀ�������
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}



