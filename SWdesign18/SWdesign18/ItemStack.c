#include"Stack.h"

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
		//UI¿¡¼­ ²ËÃ¡´Ù´Â°Å Ç¥½Ã
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
