#include "GameBoardInfo.h"
#include "ObjectInfo.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define keyboard_LEFT (75)
#define keyboard_RIGHT (77)
#define keyboard_UP (72)
#define keyboard_DOWN (80)
#define keyboard_a (97)

Character pc;

//get,set�Լ��� ���ο��� ����. ��ĥ�� �����ϱ�
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


void ShowCharacter() {
    printf("��");//����,�÷��̾� ���� �ٸ�������� ����ü�� �־���ҵ�
}

void DeleteCharacter(int x, int y) {
    COORD curpos = GetCurrentCursorPos();
    SetCurrentCursorPos(x, y);
    printf("  ");
    SetCurrentCursorPos(curpos.X, curpos.Y);
}

void ShiftRight(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, (x + 2) / 2, y)) {
        return;
    }
    DeleteCharacter(x, y);
    x += 2;
    // pc.curx = x;   ��ǥ �����ϴ°��� ���
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}

void ShiftLeft(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, (x - 2) / 2, y)) {
        return;
    }
    DeleteCharacter(x, y);
    x = x - 2;
    // pc.curx = x;      ��ǥ �����ϴ°��� ���
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}

void ShiftDown(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, x / 2, y + 1)) {
        return;
    }
    DeleteCharacter(x, y);
    y++;
    // pc.cury = y;      ��ǥ �����ϴ°��� ���
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}

void ShiftUp(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, x / 2, y - 1)) {
        return;
    }
    DeleteCharacter(x, y);
    y--;
    // pc.cury = y;        ��ǥ �����ϴ°��� ���
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}




void ProcessKeyInput() {
    int x, y , floor = 0;//��ǥ, ��ǥ�� ĳ���� ����ü�� �ۿ��� �����ð�

    x = pc.pos.x;
    y = pc.pos.y;

    int key;//����� ����
    for (int i = 0; i < 20; i++) {
        if (_kbhit() != 0) {
            key = _getch();
            if (key == 224)
            {
                do { key = _getch(); } while (key == 224);
                switch (key)
                {
                case keyboard_LEFT:
                    ShiftLeft(pc, floor, x, y);
                    break;
                case keyboard_RIGHT:
                    ShiftRight(pc, floor, x, y);
                    break;
                case keyboard_UP:
                    ShiftUp(pc, floor, x, y);
                    break;
                case keyboard_DOWN:
                    ShiftDown(pc, floor, x, y);
                    break;
                case keyboard_a:

                    break;
                }
            }
            else {
                switch (key) {
                case keyboard_a:
                    //pc.inventory->use(&pc, x);
                    break;
                }
            }
        }
        Sleep(0.1);
    }
}