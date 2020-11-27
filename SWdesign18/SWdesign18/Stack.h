#pragma once

#define SIZE 7

char stack[SIZE] = { '\0' };
char compare[SIZE] = { '\0' };
int top = -1;

int isFull();
int isEmpty();
int insert(int ascii);
int pop(int ascii);

int isFull()
{
	if (top + 1 == SIZE)
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
int insert(int ascii)
{
	if (isFull())
	{
		//UI¿¡¼­ ²ËÃ¡´Ù´Â°Å Ç¥½Ã
		return 0;
	}
	else
	{
		top++;
		stack[top] = ascii;
		return 1;
	}
}

int pop(int ascii)
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		stack[top] = '\0';
		top--;
		return 1;
	}
}
