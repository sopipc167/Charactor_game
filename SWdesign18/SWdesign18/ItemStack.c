#include"Stack.h"
#include"Item.h"
#include<string.h>

int isFull();//스택 공간 여부는 변수 top으로 판단, top이 size랑 같을 시 1 반환,아니면 0
int isEmpty();//top이 -1일 때 1반환, 아니면 0
char insert(char ascii);// 아스키 코드를 인자로 가짐, isFull()로 검사후 top+1하여 그 공간에 삽입, 삽입 성공시 1 반환
char pop();//isEmpty()검사후, 해당 공간을 '\0'반환,삭제 성공시 삭제된 원소 반환
void isComplete(char ascii);//끝글자를 가져올때마다 compare배열에 스택의 내용을 단어 길이만큼 가져옴, 그 후 단어와 비교, 맞다면 AddtoInventory 실행 

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
		//UI에서 꽉찼다는거 표시
		printf("isFull\n");
		return 0;
	}
	else
	{
		top++;
		count++;
		stack[top] = ascii;
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
		top--;
		count--;
		return ascii;
	}
}

void isComplete(char ascii)
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
			if (strcmp(compare,ItemList[3].name) == 0)
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

void AddToInventory(Item item)
{

}
