#pragma once
#include<string.h>
#include"GameBoardInfo.h"
#define SIZE 7

char stack[SIZE] = { '\0' };
char compare[SIZE] = { '\0' };
int count = 0;
int top = -1;


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

char insert(char ascii)
{
	if (isFull())
	{
		//UI���� ��á�ٴ°� ǥ��
		printf("isFull\n");
		return 0;
	}
	else
	{
		top++;
		count++;
		stack[top] = ascii;
		getAlphabetUI(top, stack[top]);
		return ascii;
	}
}

char pop()
{
	char ascii = stack[top];
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		stack[top] = '\0';
		getAlphabetUI(top, stack[top]);
		top--;
		count--;
		return ascii;
	}
}

void isComplete(int ascii)
{
	int i, j = 0;
	for (i = 0; i < SIZE; i++)
		compare[i] = '\0';
	if (ascii == 'D')
	{
		if (top >= 3)
		{
			for (i = top; i >= top - 4; i--)
			{
				compare[j] = stack[i];
				j++;
			}
			if (strcmp(compare, "DOOF") == 0)
			{
				//�κ��丮�� �߰�
				//AddToInventory(Food);
			}
		}
	}
	else if (ascii == 'R')
	{
		if (top >= 4)
		{
			for (i = top; i >= top - 5; i--)
			{
				compare[j] = stack[i];
				j++;
			}
			if (strcmp(compare, "REDRO") == 0)
			{
				//�κ��丮�� �߰�
			}
		}
	}
}
