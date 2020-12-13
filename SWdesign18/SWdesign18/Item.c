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
	return 0;
}