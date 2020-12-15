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
void CursorView(char show);//커서 숨기기
//Character pc;
int map_index;
//플레이어 번호=20


//인벤토리 배열
//item 배열

//몬스터 배열
Character MonsterArray[_MAP_COUNT][11];

int main()
{
	initItem();
	initList();
	map_index=0;
	pc.routeCnt = 50;
	pc.isDie = 0;
	pc.inventory = Inventory;
	pc.map = 0;        //플레이어 맵 인덱스
	pc.pos.x = 44;     //플레이어 초기 x축
	pc.pos.y = 33;     //플레이어 초기 y축
	pc.hp = 5;
	pc.getHit = PlayerHit;

	routeDelta = 0;

	gameBoardInfo[map_index][pc.pos.y][pc.pos.x/2] = 20;
	initInventory(&pc);
	CursorView(0);     //커서 숨기기
	system("mode con cols=155 lines=42");
	DrawBoard(map_index);
	DrawUI();
	setHp(pc.hp);
	setmapinfo();
	SetCurrentCursorPos(pc.pos.x, pc.pos.y);
	printf("●");

	for (int i = 0; i < _MAP_COUNT; i++)
	{
		for(int j = 0; j< 11; j++)
		{
			if(monsterRoutes[i][j][0] != END)
			{
				InitMonster(MonsterArray[i] + j, i, monsterInitPosition[i][j], monsterRoutes[i][j]);
			}
		}
	}
	while (1)
	{
		routeDelta++;
		pc.routeCnt++;
		if (routeDelta % 3 == 0)
		{
			for (int i = 0; i < _MONSTER_MAX_COUNT; i++)
			{
				Character* k = MonsterArray[map_index] + i;
				if (monsterRoutes[map_index][i][0] != END && k->isDie != 1)
					k->move(k, i);
			}
		}
		ProcessKeyInput();
		if (pc.isDie)
			break;
		Sleep(20);
	}
	//게임 오버
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
			printf("━");
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			SetCurrentCursorPos(start.X, start.Y + i);
			printf("┃");
		}
	}
}

void DrawHorizontalLine(int type, int length, COORD start)
{

}

void CursorView(char show)//커서숨기기
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}



