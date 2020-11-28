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
#define keyboard_s_test (115)
#define keyboard_d_test (100)
#define keyboard_1 (49)
#define keyboard_2 (50)
#define keyboard_3 (51)
#define keyboard_4 (52)
#define keyboard_5 (53)


int SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos();
extern Character pc;
int pick = 0;
Vector bullet;
Direction bulD = 0;
int bulletuse = 0;
Vector cannonball;
Direction cannD = 0;
int cannonuse = 0;

void ShowCharacter(Character Ch,int x,int y) {
    SetCurrentCursorPos(x, y);
    printf("●");
}

void DeleteCharacter(int x, int y) {
    SetCurrentCursorPos(x, y);
    printf("  ");
}

void ShiftRight() {
    pc.Di = 1;
    if (DetectCollision(pc.pos.floor, (pc.pos.x + 2) / 2, pc.pos.y)) {
        return;
    }
    DeleteCharacter(pc.pos.x, pc.pos.y);
    pc.pos.x += 2;
    ShowCharacter(pc,pc.pos.x,pc.pos.y);
}

void ShiftLeft() {
    pc.Di = 0;
    if (DetectCollision(pc.pos.floor, (pc.pos.x - 2) / 2, pc.pos.y)) {
        return;
    }
    DeleteCharacter(pc.pos.x, pc.pos.y);
    pc.pos.x -=2;
    ShowCharacter(pc, pc.pos.x, pc.pos.y);
}

void ShiftDown() {
    pc.Di = 3;
    if (DetectCollision(pc.pos.floor, pc.pos.x / 2, pc.pos.y+1)) {
        return;
    }
    DeleteCharacter(pc.pos.x, pc.pos.y);
    pc.pos.y++;
    ShowCharacter(pc, pc.pos.x, pc.pos.y);
}

void ShiftUp() {
    pc.Di = 2;
    if (DetectCollision(pc.pos.floor, pc.pos.x / 2, pc.pos.y-1)) {
        return;
    }
    DeleteCharacter(pc.pos.x, pc.pos.y);
    pc.pos.y--;
    ShowCharacter(pc, pc.pos.x, pc.pos.y);
}


void use_KNIFE(Character ch) {
    int count = 0;

    COORD curpos = GetCurrentCursorPos();
    SetCurrentCursorPos(ch.pos.x, ch.pos.y);
    if (ch.Di == 0) {
        for (int reach = 0; reach < 3; reach++) {
            if (DetectCollision(ch.pos.floor, (ch.pos.x - 2) / 2, ch.pos.y))
                break;
            ch.pos.x -= 2;
            count++;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("─");
            if (gameBoardInfo[ch.pos.floor][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
            }
        }
        SetCurrentCursorPos(ch.pos.x, ch.pos.y);
        Sleep(150);
        for (int i = 0; i < count; i++) {
            printf("  ");
        }
    }
    else if (ch.Di == 1)
    {
        for (int reach = 0; reach < 3; reach++) {
            if (DetectCollision(ch.pos.floor, (ch.pos.x + 2) / 2, ch.pos.y))
                break;
            ch.pos.x += 2;
            count++;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("─");
            if (gameBoardInfo[ch.pos.floor][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
            }
        }
        Sleep(150);
        for (int i = 0; i < count; i++) {
            SetCurrentCursorPos(ch.pos.x-i*2, ch.pos.y);
            printf("  ");
        }
    }
    else if (ch.Di == 2) {
        for (int reach = 0; reach < 3; reach++) {
            if (DetectCollision(ch.pos.floor, ch.pos.x / 2, ch.pos.y - 1))
                break;
            ch.pos.y--;
            count++;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("│");
            if (gameBoardInfo[ch.pos.floor][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
            }
        }
        SetCurrentCursorPos(ch.pos.x, ch.pos.y);
        Sleep(150);
        for (int i = 0; i < count; i++) {
            SetCurrentCursorPos(ch.pos.x, ch.pos.y + i);
            printf("  ");
        }
    }
    else if (ch.Di == 3) {
        for (int reach = 0; reach < 3; reach++) {
            if (DetectCollision(ch.pos.floor, ch.pos.x / 2, ch.pos.y + 1))
                break;
            ch.pos.y++;
            count++;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("│");
            if (gameBoardInfo[ch.pos.floor][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
            }
        }
        SetCurrentCursorPos(ch.pos.x, ch.pos.y);
        Sleep(150);
        for (int i = 0; i < count; i++) {
            SetCurrentCursorPos(ch.pos.x, ch.pos.y - i);
            printf("  ");
        }
    }
}


void use_ROCKET(Character ch) {
    COORD curpos = GetCurrentCursorPos();
    if (pc.Di == 0) {
        for (int reach = 0; reach < 100; reach++) {
            if (DetectCollision(ch.pos.floor, (ch.pos.x - 2) / 2, ch.pos.y)) {
                for (int x1 = 0; x1 < 3; x1++) {
                    for (int y1 = 0; y1 < 3; y1++) {
                        SetCurrentCursorPos(ch.pos.x - 2 + x1 * 2, ch.pos.y - 1 + y1);
                        printf("*");
                    }
                }
                Sleep(100);
                for (int x1 = 0; x1 < 3; x1++) {
                    for (int y1 = 0; y1 < 3; y1++) {
                        SetCurrentCursorPos(ch.pos.x - 2 + x1 * 2, ch.pos.y - 1 + y1);
                        printf(" ");
                        gameBoardInfo[ch.pos.floor][ch.pos.y - 1 + y1][(ch.pos.x - 2 + x1 * 2) / 2] = 0;
                    }
                }
                break;
            }
            ch.pos.x -= 2;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            if (gameBoardInfo[ch.pos.floor][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
                break;
            }
            printf("⊂");
            Sleep(10);
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("  ");
        }
    }
    else if (pc.Di == 1) {
        for (int reach = 0; reach < 100; reach++) {
            if (DetectCollision(ch.pos.floor, (ch.pos.x + 2) / 2, ch.pos.y)) {
                for (int x1 = 0; x1 < 3; x1++) {
                    for (int y1 = 0; y1 < 3; y1++) {
                        SetCurrentCursorPos(ch.pos.x - 2 + x1 * 2, ch.pos.y - 1 + y1);
                        printf("*");
                    }
                }
                Sleep(100);
                for (int x1 = 0; x1 < 3; x1++) {
                    for (int y1 = 0; y1 < 3; y1++) {
                        SetCurrentCursorPos(ch.pos.x - 2 + x1 * 2, ch.pos.y - 1 + y1);
                        printf(" ");
                        gameBoardInfo[ch.pos.floor][ch.pos.y - 1 + y1][(ch.pos.x - 2 + x1 * 2) / 2] = 0;
                    }
                }
                break;
            }
            ch.pos.x += 2;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            if (gameBoardInfo[ch.pos.floor][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
                break;
            }
            printf("⊃");
            Sleep(10);
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("  ");
        }
    }
    else if (pc.Di == 2) {
        for (int reach = 0; reach < 100; reach++) {
            if (DetectCollision(ch.pos.floor, ch.pos.x / 2, ch.pos.y-1)) {
                for (int x1 = 0; x1 < 3; x1++) {
                    for (int y1 = 0; y1 < 3; y1++) {
                        SetCurrentCursorPos(ch.pos.x - 2 + x1 * 2, ch.pos.y - 1 + y1);
                        printf("*");
                    }
                }
                Sleep(100);
                for (int x1 = 0; x1 < 3; x1++) {
                    for (int y1 = 0; y1 < 3; y1++) {
                        SetCurrentCursorPos(ch.pos.x - 2 + x1 * 2, ch.pos.y - 1 + y1);
                        printf(" ");
                        gameBoardInfo[ch.pos.floor][ch.pos.y - 1 + y1][(ch.pos.x - 2 + x1 * 2) / 2] = 0;
                    }
                }
                break;
            }
            ch.pos.y--;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            if (gameBoardInfo[ch.pos.floor][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
                break;
            }
            printf("∩");
            Sleep(10);
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("  ");
        }
    }
    else if (pc.Di == 3) {
        for (int reach = 0; reach < 100; reach++) {
            if (DetectCollision(ch.pos.floor, ch.pos.x / 2, ch.pos.y+1)) {
                for (int x1 = 0; x1 < 3; x1++) {
                    for (int y1 = 0; y1 < 3; y1++) {
                        SetCurrentCursorPos(ch.pos.x - 2 + x1 * 2, ch.pos.y - 1 + y1);
                        printf("*");
                    }
                }
                Sleep(100);
                for (int x1 = 0; x1 < 3; x1++) {
                    for (int y1 = 0; y1 < 3; y1++) {
                        SetCurrentCursorPos(ch.pos.x - 2 + x1 * 2, ch.pos.y - 1 + y1);
                        printf(" ");
                        gameBoardInfo[ch.pos.floor][ch.pos.y - 1 + y1][(ch.pos.x - 2 + x1 * 2) / 2] = 0;
                    }
                }
                break;
            }
            ch.pos.y++;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            if (gameBoardInfo[ch.pos.floor][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
                break;
            }
            printf("∪");
            Sleep(10);
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("  ");
        }
    }
}

void bulletmove() {
    if (bullet.x != pc.pos.x || bullet.y != pc.pos.y) {
        SetCurrentCursorPos(bullet.x, bullet.y);
        printf("  ");
    }
    if (bulD == 0) {
        bullet.x -= 2;
        if (DetectCollision(pc.pos.floor, bullet.x / 2, bullet.y)) {
            bulletuse = 0;
            return;
        }
        SetCurrentCursorPos(bullet.x, bullet.y);
        printf("＊");
    }
    else if (bulD == 1) {
        bullet.x += 2;
        if (DetectCollision(pc.pos.floor, bullet.x / 2, bullet.y)) {
            bulletuse = 0;
            return;
        }
        SetCurrentCursorPos(bullet.x, bullet.y);
        printf("*");
    }
    else if (bulD == 2) {
        bullet.y--;
        if (DetectCollision(pc.pos.floor, bullet.x / 2, bullet.y)) {
            bulletuse = 0;
            return;
        }
        SetCurrentCursorPos(bullet.x, bullet.y);
        printf("*");
    }
    else if (bulD == 3) {
        bullet.y++;
        if (DetectCollision(pc.pos.floor, bullet.x / 2, bullet.y)) {
            bulletuse = 0;
            return;
        }
        SetCurrentCursorPos(bullet.x, bullet.y);
        printf("*");
    }
}



void explosion(int x, int y) {
    for (int x1 = 0; x1 < 3; x1++) {
        for (int y1 = 0; y1 < 3; y1++) {
            if (x - 2 + x1 * 2 >= 0 && y - 1 + y1 >= 0) {
                SetCurrentCursorPos(x - 2 + x1 * 2, y - 1 + y1);
                printf("＊");
            }
        }
    }
    Sleep(100);
    for (int x1 = 0; x1 < 3; x1++) {
        for (int y1 = 0; y1 < 3; y1++) {
            if (x - 2 + x1 * 2 >= 0 && y - 1 + y1 >= 0) {
                SetCurrentCursorPos(x - 2 + x1 * 2, y - 1 + y1);
                printf("  ");
                gameBoardInfo[pc.pos.floor][y - 1 + y1][(x - 2 + x1 * 2) / 2] = 0;
            }
        }
    }
}



void cannonmove() {
    if (cannonball.x != pc.pos.x || cannonball.y != pc.pos.y) {
        SetCurrentCursorPos(cannonball.x, cannonball.y);
        printf("  ");
    }
    if (cannD == 0) {
        cannonball.x -= 2;
        if (DetectCollision(pc.pos.floor, cannonball.x / 2, cannonball.y)) {
            cannonuse = 0;
            explosion(cannonball.x, cannonball.y);
            return;
        }
        SetCurrentCursorPos(cannonball.x, cannonball.y);
        printf("⊂");
    }
    else if (cannD == 1) {
        cannonball.x += 2;
        if (DetectCollision(pc.pos.floor, cannonball.x / 2, cannonball.y)) {
            cannonuse = 0;
            explosion(cannonball.x, cannonball.y);
            return;
        }
        SetCurrentCursorPos(cannonball.x, cannonball.y);
        printf("⊃");
    }
    else if (cannD == 2) {
        cannonball.y--;
        if (DetectCollision(pc.pos.floor, cannonball.x / 2, cannonball.y)) {
            cannonuse = 0;
            explosion(cannonball.x, cannonball.y);
            return;
        }
        SetCurrentCursorPos(cannonball.x, cannonball.y);
        printf("∩");
    }
    else if (cannD == 3) {
        cannonball.y++;
        if (DetectCollision(pc.pos.floor, cannonball.x / 2, cannonball.y)) {
            cannonuse = 0;
            explosion(cannonball.x, cannonball.y);
            return;
        }
        SetCurrentCursorPos(cannonball.x, cannonball.y);
        printf("∪");
    }
}

BOOL iskeydown(int key) {
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

void ProcessKeyInput() {
    int key;//연산용 변수
    for (int i = 0; i < 20; i++) {
        if (i % 2 == 0) {
            if (iskeydown(VK_LEFT)) {
                ShiftLeft();
            }
            if (iskeydown(VK_RIGHT)) {
                ShiftRight();
            }
            if (iskeydown(VK_UP)) {
                ShiftUp();
            }
            if (iskeydown(VK_DOWN)) {
                ShiftDown();
            }
            if (_kbhit()) {
                key = _getch();

                if (key == keyboard_a) {
                    if (pick == 1) {
                        use_KNIFE(pc);
                    }
                    else if (pick == 2) {
                        if (bulletuse == 0) {
                            bulletuse = 1;
                            bullet.x = pc.pos.x;
                            bullet.y = pc.pos.y;
                            bulD = pc.Di;
                        }
                    }
                    else if (pick == 3) {
                        if (cannonuse == 0) {
                            cannonuse = 1;
                            cannonball.x = pc.pos.x;
                            cannonball.y = pc.pos.y;
                            cannD = pc.Di;
                        }
                    }
                }
                else if (key == keyboard_1) {
                    pick = 1;
                }
                else if (key == keyboard_2) {
                    pick = 2;
                }
                else if (key == keyboard_3) {
                    pick = 3;
                }

            }
        }
        if (bulletuse == 1) {
            bulletmove();
        }
        if (cannonuse == 1) {
            cannonmove();
        }
        Sleep(20);
    }
}