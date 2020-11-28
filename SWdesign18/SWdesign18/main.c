#include <stdio.h>
#include <Windows.h>
#include "GameBoardInfo.h"
#include "ObjectInfo.h"

void ProcessKeyInput();
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos();
void DrawLine(int type, int length, COORD start);
void CursorView(char show);//目辑 见扁扁

Character pc;

int main()
{
	pc.pos.x = 64;
	pc.pos.y = 31;
	pc.pos.floor = 0;
	CursorView(0);

	system("mode con cols=140 lines=42");
	DrawBoard();
	SetCurrentCursorPos(pc.pos.x, pc.pos.y);
	printf("≤");
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
			printf("Μ");
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			SetCurrentCursorPos(start.X, start.Y + i);
			printf("Ν");
		}
	}
}

void DrawHorizontalLine(int type, int length, COORD start)
{

}

void CursorView(char show)//目辑见扁扁
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}