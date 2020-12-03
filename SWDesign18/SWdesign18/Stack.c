#pragma once
#include "Stack.h"
#include"Item.h"


top = -1;
count = 0;


void initList()
{
	ItemList[3] = Food;
	ItemList[4] = Order;
}

int isFull()
{
	if (top + 1 == M_SIZE)
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
		//UI¿¡¼­ ²ËÃ¡´Ù´Â°Å Ç¥½Ã
		//printf("isFull\n");
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
		//printf("isEmpty\n");
		return 0;
	}
	else
	{
<<<<<<< HEAD
		stack[top] = ' ';
=======
		stack[top] = '\0';
>>>>>>> parent of 3750b18... ê¸€ì UIê°€ ë‹¤ìŒ ë§µì—ë„ ì ìš©ë˜ê²Œ í•¨
		getAlphabetUI(top, stack[top]);
		top--;
		count--;
		return ascii;
	}
}

void isComplete(int ascii)
{
	int i, j = 0;
	for (i = 0; i < M_SIZE; i++)
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
			if (strcmp(compare, ItemList[3].name) == 0)
			{
				//ÀÎº¥Åä¸®¿¡ Ãß°¡
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
			if (strcmp(compare, ItemList[4].name) == 0)
			{
				//ÀÎº¥Åä¸®¿¡ Ãß°¡
			}
		}
	}
}
