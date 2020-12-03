#pragma once
#include<string.h>
#include"GameBoardInfo.h"
#define M_SIZE 7

char stack[M_SIZE];
char compare[M_SIZE];
int count;
int top;


int isFull();

int isEmpty();

char insert(char ascii);

char pop();

void isComplete(int ascii);
