#pragma once
#include"Stack.h"
#include"Item.h"

count = -1;
top = -1;


int isFull()
{
	if (top + 1 == SIZE_M)
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
		//UI에서 꽉찼다는거 표시
		return 0;
	}
	else
	{
		top++;
		stack[top] = ascii;
		getAlphabetUI(top, stack[top]);
		isComplete(ascii);
		return ascii;
	}
}

char pop()
{
	char ascii = stack[top];
	if (isEmpty())
	{
		//ui
		return 0;
	}
	else
	{
		stack[top] = '\0';
		getAlphabetUI(top, '_');
		top--;
		return ascii;
	}
}

void isComplete(int ascii)
{
	int i, j = 0;
	count = top;
	for (i = 0; i < SIZE_M; i++)
		compare[i] = '\0';
	if (ascii == 'E')
	{
		if (top >= 4)
		{
			for (i = count; i >= count - 4; i--)
			{
				compare[j] = stack[i];
				j++;
			}
			if (strcmp(compare, ItemList[0].name) == 0)
			{
				index = 0;
				for (i = count; i >= count - 4; i--)
					pop();
				//인벤토리에 추가
				count -= 5;
				AddToInventory(ItemList, index);
			}
			if (strcmp(compare, ItemList[1].name) == 0)
			{
				index = 1;
				for (i = count; i >= count - 4; i--)
					pop();
				count -= 5;
				AddToInventory(ItemList, index);
				//인벤토리에 추가
				//AddToInventory(Food);
			}
		}
	}
	else if (ascii == 'T')
	{
		if (top >= 5)
		{
			for (i = count; i >= count - 5; i--)
			{
				compare[j] = stack[i];
				j++;
			}
			if (strcmp(compare, ItemList[2].name) == 0)
			{
				index = 2;
				for (i = count; i >= count - 5; i--)
					pop();
				count -= 6;
				AddToInventory(ItemList, index);
				//인벤토리에 추가
				//AddToInventory(Food);
			}
		}
	}
	else if (ascii == 'Y')
	{
		if (top >= 2)
		{
			for (i = count; i >= count - 2; i--)
			{
				compare[j] = stack[i];
				j++;
			}
			if (strcmp(compare, ItemList[3].name) == 0)
			{
				index = 3;
				for (i = count; i >= count - 2; i--)
					pop();
				count -= 3;
				//인벤토리에 추가
				//AddToInventory(Food);
				AddToInventory(ItemList, index);
			}
		}
	}
	else if (ascii == 'D')
	{
		if (top >= 3)
		{
			for (i = count; i >= count - 3; i--)
			{
				compare[j] = stack[i];
				j++;
			}
			if (strcmp(compare,ItemList[4].name) == 0)
			{
				index = 4;
				for (i = count; i >= count - 3; i--)
					pop();
				count -= 4;
				//인벤토리에 추가
				//AddToInventory(Food);
				AddToInventory(ItemList, index);
			}
		}
	}
}
