#pragma once
#include"Stack.h"

int isFull();//���� ���� ���δ� ���� top���� �Ǵ�, top�� size�� ���� �� 1 ��ȯ,�ƴϸ� 0
int isEmpty();//top�� -1�� �� 1��ȯ, �ƴϸ� 0
int insert(int ascii);// �ƽ�Ű �ڵ带 ���ڷ� ����, isFull()�� �˻��� top+1�Ͽ� �� ������ ����, ���� ������ 1 ��ȯ
int pop();//isEmpty()�˻���, �ش� ������ '\0'��ȯ,���� ������ ������ ���� ��ȯ
void isComplete(int ascii);//�����ڸ� �����ö����� compare�迭�� ������ ������ �ܾ� ���̸�ŭ ������, �� �� �ܾ�� ��, �´ٸ� AddtoInventory ���� 

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
		//UI���� ��á�ٴ°� ǥ��
		return 0;
	}
	else
	{
		top++;
		stack[top] = ascii;
		getAlphabetUI(top, stack[top]);
		return 1;
	}
}

int pop()
{
	int ascii = stack[top];
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		stack[top] = '\0';
		top--;
		return ascii;
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

//void AddToInventory(Item item)
//{
//
//}
