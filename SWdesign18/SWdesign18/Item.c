
#pragma once
#include "ObjectInfo.h"
#include "Item.h"
#include <stdlib.h>


void initItem()
{
	Knife.duration = 30;
	Knife.name = "EFINK";

	//Knife.use = use_KNIFE;

	Rifle.duration = 30;
	Rifle.name = "ELFIR";

	Rifle.use = useRIFLE;

	Rocket.duration = 3;
	Rocket.name = "TEKCOR";

	Rocket.use = useCANNON;
	Key.duration = 1;
	Key.name = "YEK";
	Food.duration = 1;
	Food.name = "DOOF";
	Food.use = useFood;
	Star.duration = 1;
	Star.name = "RATS";
}

void initList()
{
	for (int i = 0; i < 6; i++)
		Inventory[i] = NULL;
	ItemList[0] = Knife;
	ItemList[1] = Rifle;
	ItemList[2] = Rocket;
	ItemList[3] = Key;
	ItemList[4] = Food;
	ItemList[5] = Star;
}
void AddToInventory(Item item[],int index)
{

	if (index == 0)
	{
		if (Inventory[index] == NULL)
		{
			Inventory[index] = item+index;
			printf("%d", Inventory[0]->duration);
		}
	}
	else if (index == 1)
	{
		if (Inventory[index] == NULL)
		{
			Inventory[index] = item+index;
			printf("%d", Inventory[1]->duration);
		}
	}
	else if (index == 2)
	{
		if (Inventory[index] == NULL)
			Inventory[index] = item+index;
	}
	else
	{
		for (int i = 3; i < 6; i++)
			if (Inventory[i] == NULL)
			{
				Inventory[i] = &item;
				return;
			}
	}
}

void useFood(Character* p, int heal)
{
	if (heal >= 0)
		p->hp += heal;
	Inventory[3]->duration--;
	if (Inventory[3]->duration == 0)
	{
		Inventory[3]->duration = 1;
		Inventory[3] = NULL;
	}
	return 0;
<<<<<<< Updated upstream
=======


int useFood(Character* p, int heal)
{
	if (heal >= 0)
		p->hp += heal;
	return 0;
>>>>>>> Stashed changes
}


int useOrder(Character* arr, int sec)
{
	int* atkData = (int*)malloc(sizeof(int) * (sizeof(arr) / sizeof(Character)));
	for (int i = 0; i < sizeof(arr) / sizeof(Character); i++)
	{
		//몬스터 공격 안함(미구현)
		atkData[i] = arr[i].atk;
		arr[i].atk = 0;
	}

	//sleep(sec)

	for (int i = 0; i < sizeof(arr) / sizeof(Character); i++)
	{
		//몬스터 공격 재개(미구현)
		arr[i].atk = atkData[i];
	}

	free(atkData);

}