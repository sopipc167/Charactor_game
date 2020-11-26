#include"Stack.h"
#include<string.h>

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
void insert(int ascii)
{
	if (isFull())
	{
		//UI에서 꽉찼다는거 표시
	}
	else
	{
		top++;
		stack[top] = ascii;
		
	}
}
void pop(int ascii)
{
	if (isEmpty())
	{

	}
	else
	{
		stack[top] = '\0';
		top--;
	}
}
void isComplete(int ascii)
{
	int i, j=0;
	for ( i = 0; i < SIZE; i++)
		compare[i] = '\0';
	if (ascii == 'D')
	{
		if (top >= 3)
		{
			for (i = top;i >= top - 4; i--)
			{
				compare[j] = stack[i];
				j++;
			}
			if (strcmp(compare, "DOOF") == 0)
			{
				//인벤토리에 추가
				AddToInventory(Food);
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
				//인벤토리에 추가
			}
		}
	}
}
void AddToInventory(Item item)
{

}
