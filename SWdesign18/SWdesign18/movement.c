#pragma once


#include "ObjectInfo.h"
#include <Windows.h>
#include <conio.h>
#include "Stack.h"
#include"Item.h"


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
void map_switch(int map);

extern Character pc;
extern int map_index;

int countd = 0;
int pick = 0;
Vector bullet;
Direction bulD = 0;
int bulletuse = 0;
Vector cannonball;
Direction cannD = 0;
int cannonuse = 0;
int cancountdown = 0;
int explos = 0;





void ShowCharacter(Character Ch,int x,int y) {
    SetCurrentCursorPos(x, y);
    if (Ch.hp <= 5)
        printf("●");
    else
        printf("★");
}

void Show_alp(char alp, int x, int y) {
    SetCurrentCursorPos(x, y);
    printf("%c ", alp);
}

void DeleteCharacter(int x, int y) {
    SetCurrentCursorPos(x, y);
    printf("  ");
}

void ShiftRight() {
    pc.Di = RIGHT;


    if (DetectSpell(pc.map, (pc.pos.x + 2) / 2, pc.pos.y))
    {
        return;
    }



    if (gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] >= 30 && gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] <= 120) {
        Show_alp(gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2], pc.pos.x, pc.pos.y);
    }
    else {
        DeleteCharacter(pc.pos.x, pc.pos.y);
        gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] = 0;
    }
    pc.pos.x += 2;

    if (pc.pos.x == (_MAP_WIDTH-1)*2) {
        map_switch(pc.map,1);
    }
    ShowCharacter(pc,pc.pos.x,pc.pos.y);
    if (gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] < 30 || gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2] > 120) {
        gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] = 20;
    }
}

void ShiftLeft() {
    pc.Di = LEFT;


    if (DetectSpell(pc.map, (pc.pos.x - 2) / 2, pc.pos.y))
    {
        return;
    }



    if (gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2] >= 30 && gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] <= 120) {
        Show_alp(gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2], pc.pos.x, pc.pos.y);
    }
    else {
        DeleteCharacter(pc.pos.x, pc.pos.y);
        gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2] = 0;
    }
    pc.pos.x -=2;
    if (pc.pos.x == 0) {
        map_switch(pc.map,3);
    }
    ShowCharacter(pc, pc.pos.x, pc.pos.y);
    if (gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] < 30 || gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2] > 120) {
        gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] = 20;
    }
}

void ShiftDown() {
    pc.Di = DOWN;

    if (DetectSpell(pc.map, (pc.pos.x) / 2, pc.pos.y+1))
    {
        return;
    }


    if (gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2] >= 30 && gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] <= 120) {
        Show_alp(gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2], pc.pos.x, pc.pos.y);
    }
    else {
        DeleteCharacter(pc.pos.x, pc.pos.y);
        gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2] = 0;
    }
    pc.pos.y++;
    if (pc.pos.y == _MAP_HEIGHT-1) {
        map_switch(pc.map,2);
    }
    ShowCharacter(pc, pc.pos.x, pc.pos.y);
    if (gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] < 30 || gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2] > 120) {
        gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] = 20;
    }
}

void ShiftUp() {
    pc.Di = UP;


    if (DetectSpell(pc.map, (pc.pos.x) / 2, pc.pos.y-1))
    {
        return;
    }


    if (gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2] >= 30 && gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] <= 120) {
        Show_alp(gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2], pc.pos.x, pc.pos.y);
    }
    else {
        DeleteCharacter(pc.pos.x, pc.pos.y);
        gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2] = 0;
    }
    pc.pos.y--;
    if (pc.pos.y == 0) {
        map_switch(pc.map,0);
    }
    ShowCharacter(pc, pc.pos.x, pc.pos.y);
    if (gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] < 30 || gameBoardInfo[pc.map][pc.pos.y][pc.pos.x / 2] > 120) {
        gameBoardInfo[pc.map][pc.pos.y][pc.pos.x/2] = 20;
    }
}


void use_KNIFE(Character ch) {
    int count = 0;
    COORD curpos = GetCurrentCursorPos();
    SetCurrentCursorPos(ch.pos.x, ch.pos.y);
    if (ch.Di == 0) {
        for (int reach = 0; reach < 3; reach++) {
            if (DetectCollision(ch.map, (ch.pos.x - 2) / 2, ch.pos.y))
                break;
            ch.pos.x -= 2;
            count++;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("─");
            if (gameBoardInfo[ch.map][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
            }
        }
        SetCurrentCursorPos(ch.pos.x, ch.pos.y);
        Sleep(150);
        for (int i = 1; i < count+1; i++) {
            SetCurrentCursorPos(pc.pos.x - i * 2, pc.pos.y);
            if (gameBoardInfo[pc.map][pc.pos.y][(pc.pos.x-i*2) / 2] >= 30 && gameBoardInfo[pc.map][pc.pos.y][(pc.pos.x - i * 2) / 2] <= 120) {
                Show_alp(gameBoardInfo[pc.map][pc.pos.y][(pc.pos.x - i * 2) / 2], pc.pos.x - i * 2, pc.pos.y);
            }
            else {
                printf("  ");
            }
        }
    }
    else if (ch.Di == 1)
    {
        for (int reach = 0; reach < 3; reach++) {
            if (DetectCollision(ch.map, (ch.pos.x + 2) / 2, ch.pos.y))
                break;
            ch.pos.x += 2;
            count++;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("─");
            if (gameBoardInfo[ch.map][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
            }
        }
        Sleep(150);
        for (int i = 1; i < count + 1; i++) {
            SetCurrentCursorPos(pc.pos.x + i * 2, pc.pos.y);
            if (gameBoardInfo[pc.map][pc.pos.y][(pc.pos.x + i * 2) / 2] >= 30 && gameBoardInfo[pc.map][pc.pos.y][(pc.pos.x + i * 2) / 2] <= 120) {
                Show_alp(gameBoardInfo[pc.map][pc.pos.y][(pc.pos.x + i * 2) / 2], pc.pos.x + i * 2, pc.pos.y);
            }
            else {
                printf("  ");
            }
        }

    }
    else if (ch.Di == 2) {
        for (int reach = 0; reach < 3; reach++) {
            if (DetectCollision(ch.map, ch.pos.x / 2, ch.pos.y - 1))
                break;
            ch.pos.y--;
            count++;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("│");
            if (gameBoardInfo[ch.map][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
            }
        }
        SetCurrentCursorPos(ch.pos.x, ch.pos.y);
        Sleep(150);
        for (int i = 1; i < count + 1; i++) {
            SetCurrentCursorPos(pc.pos.x, pc.pos.y-i);
            if (gameBoardInfo[pc.map][pc.pos.y-i][(pc.pos.x) / 2] >= 30 && gameBoardInfo[pc.map][pc.pos.y-i][(pc.pos.x) / 2] <= 120) {
                Show_alp(gameBoardInfo[pc.map][pc.pos.y-i][(pc.pos.x) / 2], pc.pos.x , pc.pos.y-i);
            }
            else {
                printf("  ");
            }
        }

    }
    else if (ch.Di == 3) {
        for (int reach = 0; reach < 3; reach++) {
            if (DetectCollision(ch.map, ch.pos.x / 2, ch.pos.y + 1))
                break;
            ch.pos.y++;
            count++;
            SetCurrentCursorPos(ch.pos.x, ch.pos.y);
            printf("│");
            if (gameBoardInfo[ch.map][ch.pos.y][ch.pos.x / 2] <= -10) {
                //damage(-(gameBoardInfo[floor][y][x/2]+10),30);
            }
        }
        SetCurrentCursorPos(ch.pos.x, ch.pos.y);
        Sleep(150);
        for (int i = 1; i < count + 1; i++) {
            SetCurrentCursorPos(pc.pos.x, pc.pos.y + i);
            if (gameBoardInfo[pc.map][pc.pos.y + i][(pc.pos.x) / 2] >= 30 && gameBoardInfo[pc.map][pc.pos.y + i][(pc.pos.x) / 2] <= 120) {
                Show_alp(gameBoardInfo[pc.map][pc.pos.y + i][(pc.pos.x) / 2], pc.pos.x, pc.pos.y + i);
            }
            else {
                printf("  ");
            }
        }


    }
    Inventory[0]->duration--;
    if (Inventory[0]->duration == 0)
    {
        Inventory[0]->duration = 30;
        Inventory[0] = NULL;
    }
}

void bulletmove() {//총알
    if (bullet.x != pc.pos.x || bullet.y != pc.pos.y) {
        SetCurrentCursorPos(bullet.x, bullet.y);
        printf("  ");
    }
    if (gameBoardInfo[pc.map][bullet.y][bullet.x / 2] >= 30 && gameBoardInfo[pc.map][bullet.y][bullet.x / 2] <= 120) {
        Show_alp(gameBoardInfo[pc.map][bullet.y][bullet.x / 2], bullet.x, bullet.y);
    }
    if (bulD == 0) {
        bullet.x -= 2;
        if (DetectCollision(pc.map, bullet.x / 2, bullet.y)) {
            bulletuse = 0;
            return;
        }
        SetCurrentCursorPos(bullet.x, bullet.y);
        printf("＊");
    }
    else if (bulD == 1) {
        bullet.x += 2;
        if (DetectCollision(pc.map, bullet.x / 2, bullet.y)) {
            bulletuse = 0;
            return;
        }
        SetCurrentCursorPos(bullet.x, bullet.y);
        printf("*");
    }
    else if (bulD == 2) {
        bullet.y--;
        if (DetectCollision(pc.map, bullet.x / 2, bullet.y)) {
            bulletuse = 0;
            return;
        }
        SetCurrentCursorPos(bullet.x, bullet.y);
        printf("*");
    }
    else if (bulD == 3) {
        bullet.y++;
        if (DetectCollision(pc.map, bullet.x / 2, bullet.y)) {
            bulletuse = 0;
            return;
        }
        SetCurrentCursorPos(bullet.x, bullet.y);
        printf("*");
    }
}

void explosion(int x, int y) {//폭발 이펙트
    for (int x1 = 0; x1 < 3; x1++) {
        for (int y1 = 0; y1 < 3; y1++) {
            if (pc.map == 0) {
                if (x - 2 + x1 * 2 >= 0 && y - 1 + y1 >= 0) {
                    if (x - 2 + x1 * 2 > 0 && y - 1 + y1 > 0 && y - 1 + y1 <= _MAP_HEIGHT - 4 && x - 2 + x1 * 2 <= (_MAP_WIDTH - 2) * 2) {
                        SetCurrentCursorPos(x - 2 + x1 * 2, y - 1 + y1);
                        printf("＊");
                    }
                }
            }
            else {
                if (x - 2 + x1 * 2 >= 0 && y - 1 + y1 >= 0) {
                    if (x - 2 + x1 * 2 > 0 && y - 1 + y1 > 0 && y - 1 + y1 <= _MAP_HEIGHT - 2 && x - 2 + x1 * 2 <= (_MAP_WIDTH - 2) * 2) {
                        SetCurrentCursorPos(x - 2 + x1 * 2, y - 1 + y1);
                        printf("＊");
                    }
                }
            }
        }
    }
    cancountdown++;
    if (cancountdown == 5) {
        for (int x1 = 0; x1 < 3; x1++) {
            for (int y1 = 0; y1 < 3; y1++) {
                int x2 = x - 2 + x1 * 2;
                int y2 = y - 1 + y1;
                if (pc.map == 0) {
                    if (x2 >= 0 && y2 >= 0) {
                        if (x2 > 0 && y2 > 0 && y2 <= _MAP_HEIGHT - 4 && x2 <= (_MAP_WIDTH - 2) * 2) {
                            SetCurrentCursorPos(x2, y2);
                            printf("  ");
                            gameBoardInfo[pc.map][y2][x2 / 2] = 0;
                        }
                    }
                }
                else {
                    if (x2 >= 0 && y2 >= 0) {
                        if (x2 > 0 && y2 > 0 && y2 <= _MAP_HEIGHT - 2 && x2 <= (_MAP_WIDTH - 2) * 2) {
                            SetCurrentCursorPos(x2, y2);
                            printf("  ");
                            gameBoardInfo[pc.map][y2][x2 / 2] = 0;
                        }
                    }
                }
                if (pc.pos.x == x2 && pc.pos.y == y2) {
                    ShowCharacter(pc,pc.pos.x,pc.pos.y);
                }
            }
        }
        cancountdown = 0;
        explos = 0;
    }
}

void cannonmove() {//대포알
    if (cannonball.x != pc.pos.x || cannonball.y != pc.pos.y) {
        SetCurrentCursorPos(cannonball.x, cannonball.y);
        printf("  ");
    }
    if (gameBoardInfo[pc.map][cannonball.y][cannonball.x / 2] >= 30 && gameBoardInfo[pc.map][cannonball.y][cannonball.x/ 2] <= 120) {
        Show_alp(gameBoardInfo[pc.map][cannonball.y][cannonball.x / 2], cannonball.x, cannonball.y);
    }
    if (cannD == 0) {
        cannonball.x -= 2;
        if (DetectCollision(pc.map, cannonball.x / 2, cannonball.y)) {
            cannonuse = 0;
            explos = 1;
            return;
        }
        SetCurrentCursorPos(cannonball.x, cannonball.y);
        printf("⊂");
    }
    else if (cannD == 1) {
        cannonball.x += 2;
        if (DetectCollision(pc.map, cannonball.x / 2, cannonball.y)) {
            cannonuse = 0;
            explos = 1;
            return;
        }
        SetCurrentCursorPos(cannonball.x, cannonball.y);
        printf("⊃");
    }
    else if (cannD == 2) {
        cannonball.y--;
        if (DetectCollision(pc.map, cannonball.x / 2, cannonball.y)) {
            cannonuse = 0;
            explos = 1;
            return;
        }
        SetCurrentCursorPos(cannonball.x, cannonball.y);
        printf("∩");
    }
    else if (cannD == 3) {
        cannonball.y++;
        if (DetectCollision(pc.map, cannonball.x / 2, cannonball.y)) {
            cannonuse = 0;
            explos = 1;
            return;
        }
        SetCurrentCursorPos(cannonball.x, cannonball.y);
        printf("∪");
    }
}

BOOL iskeydown(int key) {
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}//키다운 함수

void map_switch(int map,int direc) {
    int mapdes_x;
    int mapdes_y;
    int numb;
    numb = Mapinfo[map][direc];
    map_index = numb / 10000;
    mapdes_x = (numb / 100)%100;
    mapdes_y = numb % 100;
    system("cls");
    DrawBoard(map_index);
    DrawUI();
    pc.pos.x = mapdes_x*2;
    pc.pos.y = mapdes_y;
    pc.map = map_index;
    SetCurrentCursorPos(pc.pos.x, pc.pos.y);
}

void useRIFLE(Character* ch, int x) {//������ ��� �Ϸ�
    bulletuse = 1;
    bullet.x = pc.pos.x;
    bullet.y = pc.pos.y;
    bulD = pc.Di;
    Inventory[1]->duration--;
    if (Inventory[1]->duration == 0)
    {
        Inventory[1]->duration = 30;
        Inventory[1] = NULL;
    }
}

void useCANNON(Character* ch, int x) {
    cannonuse = 1;
    cannonball.x = pc.pos.x;
    cannonball.y = pc.pos.y;
    cannD = pc.Di;
    Inventory[2]->duration--;
    if (Inventory[2]->duration == 0)
    {
        Inventory[2]->duration = 3;
        Inventory[2] = NULL;
    }
}

void ProcessKeyInput() {
    int key;//연산용 변수
    for (int i = 0; i < 1; i++) {
        if (countd == 1) {
            countd = 0;
        }
        else if (countd == 0) {
            countd = 1;
        }
        if (countd % 2 == 0) {
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
                        if (Inventory[0] != NULL)
                        {
                            //Inventory[0]->use(&pc, 0);
                            use_KNIFE(pc);
                        }
                    }
                    else if (pick == 2) {
                        if (bulletuse == 0) {
                            if (Inventory[1] != NULL)
                            {
                                printf("%d", pick);
                                Inventory[1]->use(&pc,0);
                                //useRIFLE();
                            }
                        }
                    }
                    else if (pick == 3) {
                        if (cannonuse == 0&&explos!=1) {
                            if (Inventory[2] != NULL)
                            {
                                //cannonuse = 1;
                                //cannonball.x = pc.pos.x;
                                //cannonball.y = pc.pos.y;
                                //cannD = pc.Di;
                                Inventory[2]->use(&pc, 0);
                            }
                        }
                    }
                    else if (pick == 4)
                    {
                        if (Inventory[3] != NULL)
                        {
                            Inventory[3]->use(&pc, 4);
                        }
                    }
                    else if (pick == 5)
                    {
                        if (Inventory[4] != NULL)
                        {
                            Inventory[4]->use(&pc, 1);
                        }
                    }
                }
                else if (key == keyboard_s_test) {
                    pop();
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
                else if (key == keyboard_4) {
                    pick = 4;
                }
                else if (key == keyboard_5) {
                    pick = 5;
                }
            }
        }
        if (bulletuse == 1) {
            bulletmove();
        }
        if (cannonuse == 1) {
            cannonmove();
        }
        if (explos == 1) {
            explosion(cannonball.x, cannonball.y);
        }
    }
}