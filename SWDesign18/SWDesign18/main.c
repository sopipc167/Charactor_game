#include <stdio.h>
#include <Windows.h>
#include "GameBoardInfo.h"
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos();
void DrawBoard();
void DrawLine(int type, int length, COORD start);
int main()
{
	system("mode con cols=140 lines=42");
	DrawBoard();
}
void DrawBoard()
{
	int x, y;
	for (y = 0; y < _MAP_HEIGHT; y++)
	{
		SetCurrentCursorPos(0, y);
		for (x = 0; x < _MAP_WIDTH; x++)
		{
			if (gameBoardInfo[0][y][x] == 1)
			{
				printf("收");

			}
			else if (gameBoardInfo[0][y][x] == 2)
			{
				printf("早");

			}
			else if (gameBoardInfo[0][y][x] == 3)
			{
				printf("旨");

			}
			else if (gameBoardInfo[0][y][x] == 4)
			{
				printf("旬");

			}
			else if (gameBoardInfo[0][y][x] == 5)
			{
				printf("旭");

			}
			else if (gameBoardInfo[0][y][x] == 6)
			{
				printf("曲");

			}
			else if (gameBoardInfo[0][y][x] == 7)
			{
				printf("曳");

			}
			else if (gameBoardInfo[0][y][x] == 8)
			{
				printf("朽");

			}
			else if (gameBoardInfo[0][y][x] == 9)
			{
				printf("朴");

			}
			else if (gameBoardInfo[0][y][x] == 10)
			{
				printf("有");
			}

			SetCurrentCursorPos(x * 2 + 2, y);

		}
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
			printf("收");
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			SetCurrentCursorPos(start.X, start.Y + i);
			printf("早");
		}
	}
}
void DrawHorizontalLine(int type, int length, COORD start)
{

}