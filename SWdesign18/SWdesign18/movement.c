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

//get,set함수는 메인에도 있음. 합칠때 제외하기
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
    printf("●");//몬스터,플레이어 각각 다른모양으로 구조체에 넣어야할듯
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
    // pc.curx = x;   좌표 저장하는곳에 기록
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}

void ShiftLeft(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, (x - 2) / 2, y)) {
        return;
    }
    DeleteCharacter(x, y);
    x = x - 2;
    // pc.curx = x;      좌표 저장하는곳에 기록
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}

void ShiftDown(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, x / 2, y + 1)) {
        return;
    }
    DeleteCharacter(x, y);
    y++;
    // pc.cury = y;      좌표 저장하는곳에 기록
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}

void ShiftUp(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, x / 2, y - 1)) {
        return;
    }
    DeleteCharacter(x, y);
    y--;
    // pc.cury = y;        좌표 저장하는곳에 기록
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}




void ProcessKeyInput() {
    int x, y , floor = 0;//좌표, 좌표와 캐릭터 구조체는 밖에서 가져올것

    x = pc.pos.x;
    y = pc.pos.y;

    int key;//연산용 변수
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