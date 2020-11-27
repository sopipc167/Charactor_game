#include"Stack.h"
#include<string.h>

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
				//인벤토리에 추가
			}
		}
	}
}
//void AddToInventory(Item item)
//{
//
//}
