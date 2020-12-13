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



//�κ��丮 �迭
//item �迭
//���� �迭

int main()
{
	initItem();
	initList();
	map_index=0;
	pc.map = 0;        //�÷��̾� �� �ε���
	pc.pos.x = 64;     //�÷��̾� �ʱ� x��
	pc.pos.y = 31;     //�÷��̾� �ʱ� y��
	pc.hp = 3;
	CursorView(0);     //Ŀ�� �����
	system("mode con cols=155 lines=42");
	DrawBoard(map_index);
	DrawUI();
	setmapinfo();
	SetCurrentCursorPos(pc.pos.x, pc.pos.y);
	printf("��");
	while (1) {
		ProcessKeyInput();
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

