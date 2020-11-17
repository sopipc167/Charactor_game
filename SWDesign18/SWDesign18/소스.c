#pragma warning(disable:4996)
#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isFull(int top)
{
	if (top + 1 == 7)
		return true;
	else
		return false;
}
bool isEmpty(int top)
void insert(int ascii)
{
	if (isFull(top))
	{

	}
	top++;
	stack[top] = ascii;
}
void pop()
{
	top--;
	stack[top] = '\0';
}