#include <stdio.h>
#include <Windows.h>
#define _MAP_WIDTH (55)
#define _MAP_HEIGHT (35)
int DetectCollision(int floor, int x, int y);
#define keyboard_LEFT (75)
#define keyboard_RIGHT (77)
#define keyboard_UP (72)
#define keyboard_DOWN (80)
#define keyboard_a (97)


void DrawBoard();
int gameBoardInfo[10][_MAP_HEIGHT][_MAP_WIDTH];
void DrawLine(int type, int length, COORD start);

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

void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos();







gameBoardInfo[10][_MAP_HEIGHT][_MAP_WIDTH] =
{
    {
    3,1,1,1,1,1,1,1,1,1,1,1,10,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,
    2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
    7,1,1,1,1,1,1,1,4,0,0,0,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,0,0,0,2,
    2,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,
    0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,
    2,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,
    7,1,1,1,4,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,
    2,0,0,0,2,0,0,0,2,0,0,0,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0,0,0,3,1,1,1,10,1,1,1,1,1,1,1,0,0,0,2,0,0,0,2,
    2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,
    2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,
    2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,
    2,0,0,0,2,0,0,0,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0,0,0,2,0,0,0,1,1,1,1,1,1,1,8,0,0,0,2,
    2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,
    2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,
    2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,
    2,0,0,0,6,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,2,0,0,0,3,1,1,1,1,1,1,4,0,0,0,3,1,1,1,5,0,0,0,1,1,1,4,0,0,0,2,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,2,
    7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0,0,0,6,1,1,1,1,1,1,5,0,0,0,6,1,1,1,1,1,1,4,0,0,0,6,1,1,1,5,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,
    2,0,0,0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,0,0,0,6,1,1,1,1,1,1,1,1,0,0,0,2,
    2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
    2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
    2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
    2,0,0,0,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,0,0,0,6,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
    6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5
    }
};
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
                printf("━");

            }
            else if (gameBoardInfo[0][y][x] == 2)
            {
                printf("┃");

            }
            else if (gameBoardInfo[0][y][x] == 3)
            {
                printf("┏");

            }
            else if (gameBoardInfo[0][y][x] == 4)
            {
                printf("┓");

            }
            else if (gameBoardInfo[0][y][x] == 5)
            {
                printf("┛");

            }
            else if (gameBoardInfo[0][y][x] == 6)
            {
                printf("┗");

            }
            else if (gameBoardInfo[0][y][x] == 7)
            {
                printf("┣");

            }
            else if (gameBoardInfo[0][y][x] == 8)
            {
                printf("┫");

            }
            else if (gameBoardInfo[0][y][x] == 9)
            {
                printf("┻");

            }
            else if (gameBoardInfo[0][y][x] == 10)
            {
                printf("┳");
            }

            SetCurrentCursorPos(x * 2 + 2, y);

        }
    }
}


















int DetectCollision(int floor, int x, int y)
{
    int num = gameBoardInfo[floor][y][x];

    if ((num <= -10) || ((num >= 1) && (num <= 10)) /*|| (막힌 문)*/)
        return 1;
    else if ((num == 0) || ((num >= 30) && (num <= 120)) /* || (열린 문) || (함정)*/)
        return 0;
}


typedef struct item
{
    int duration;
    char* name;
    void (*use)();
}Item;

typedef struct character
{
    int hp;
    int atk;
    int curx, cury;
    int Direction;
    boolean isDie;
    Item* inventory;
}Character;


Character enemy;
Character pc;//임시 캐릭터 구조체들
Direction Dir;


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
    printf("●");//각각 다른모양으로 구조체에 넣어야할듯
}

void DeleteCharacter(int x, int y) {
    COORD curpos = GetCurrentCursorPos();
    SetCurrentCursorPos(x, y);
    printf("  ");
    SetCurrentCursorPos(curpos.X, curpos.Y);
}

void HIT()
{

}

void ShiftRight(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, (x + 2)/2, y)) {
        return;
    }
    DeleteCharacter(x, y);
    x += 2;
    pc.curx = x;
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}

void ShiftLeft(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, (x - 2)/2, y)) {
        return;
    }
    DeleteCharacter(x, y);
    x = x - 2;
    pc.curx = x;
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}

void ShiftDown(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, x/2, y+1 )) {
        return;
    }
    DeleteCharacter(x, y);
    y++;
    pc.cury = y;
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}

void ShiftUp(Character moving, int floor, int x, int y) {
    if (DetectCollision(floor, x/2, y - 1)) {
        return;
    }
    DeleteCharacter(x, y);
    y--;
    pc.cury = y;
    SetCurrentCursorPos(x, y);
    ShowCharacter();
}

void use_KNIFE(int floor, int x, int y) {
    switch (Dir)
    {
    case 0:
        for (int reach = 0; reach < 3; reach++) {
            if (DetectCollision(floor, x - 1, y) == 1)
                break;
            printf("<");
            x--;
            if (gameBoardInfo[floor][y][x] <= -10)
                HIT();
        }
        break;
    default:
        break;
    }
}

void use_RIFLE() {

}

void use_ROCKET() {

}

void ProcessKeyInput() {
    int x=pc.curx, y=pc.cury, floor=0;//좌표
    int i, key;//연산용 변수
    int speed = 0.1;//임시
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
                        pc.inventory->use();
                    break;
                }
            }
        }
        Sleep(speed);
    }
}














int main()
{

    pc.curx = 64;//64
    pc.cury = 31;
    pc.hp = 100;
    system("mode con cols=140 lines=42");
    DrawBoard();
    while (1) {
        COORD curpos = GetCurrentCursorPos();
        SetCurrentCursorPos(64, 31);
        ShowCharacter();
        
        while (1) {
            ProcessKeyInput();
        }
    }
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