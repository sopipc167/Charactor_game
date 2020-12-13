#pragma once
#include<string.h>
#include"GameBoardInfo.h"
#define SIZE_M 8

char stack[SIZE_M];
char compare[SIZE_M];
int count;
int top;


int isFull();

int isEmpty();

char insert(char ascii);

char pop();

void isComplete(int ascii);