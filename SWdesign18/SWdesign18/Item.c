#include "ObjectInfo.h"
#include "Item.h"
#include <stdlib.h>



int useFood(Character* p, int heal)
{
	if (heal >= 0)
		p->hp += heal;
	return 0;
}

int useOrder(Character* arr, int sec)
{
	int* atkData = (int*)malloc(sizeof(int) * (sizeof(arr) / sizeof(Character)));
	for (int i = 0; i < sizeof(arr) / sizeof(Character); i++)
	{
		//���� ���� ����(�̱���)
		atkData[i] = arr[i].atk;
		arr[i].atk = 0;
	}

	//sleep(sec)

	for (int i = 0; i < sizeof(arr) / sizeof(Character); i++)
	{
		//���� ���� �簳(�̱���)
		arr[i].atk = atkData[i];
	}

	free(atkData);
	return 0;
}

void makeList()
{
	ItemList[0] = Sword;
	ItemList[1] = Rifle;
	ItemList[2] = Rocket;
	ItemList[3] = Food;
	ItemList[4] = Order;
	ItemList[5] = Star;
	ItemList[6] = Key;
}
