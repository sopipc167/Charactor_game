
#pragma once
#include "ObjectInfo.h"
#include "Item.h"
#include <stdlib.h>
#include<time.h>
#include<Windows.h>


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
	Key.use = useKey;

	Food.duration = 1;
	Food.name = "DOOF";
	Food.use = useFood;
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
	else if (index == 3)
	{
		if (Inventory[index] == NULL)
			Inventory[index] = item + index;
	}
	else if (index == 4)
	{
		if (Inventory[index] == NULL)
			Inventory[index] = item + index;
	}
}

void useFood(Character* p, int heal)
{
	if (heal >= 0)
		p->hp += heal;
	Inventory[4]->duration--;
	if (Inventory[4]->duration == 0)
	{
		Inventory[4]->duration = 1;
		Inventory[4] = NULL;
	}
	return 0;
}
void useKey(Character* p, int a)
{
	int flag = 0;
	if (gameBoardInfo[map_id][p->pos.y][(p->pos.x + 2) / 2] == 15)
	{
		gameBoardInfo[map_id][p->pos.y][(p->pos.x + 2) / 2] = 0;
		flag = 1;
	}
	else if (gameBoardInfo[map_id][p->pos.y][(p->pos.x - 2) / 2] == 15)
	{
		gameBoardInfo[map_id][p->pos.y][(p->pos.x - 2) / 2] = 0;
		flag = 1;
	}
	else if (gameBoardInfo[map_id][p->pos.y + 1][p->pos.x / 2] == 15)
	{
		gameBoardInfo[map_id][p->pos.y + 1][p->pos.x / 2] = 0;
		flag = 1;
	}
	else if (gameBoardInfo[map_id][p->pos.y - 1][p->pos.x / 2] == 15)
	{
		gameBoardInfo[map_id][p->pos.y - 1][p->pos.x / 2] = 0;
		flag = 1;
	}
	if (flag == 1)
	{
		Inventory[a-1]->duration--;
		if (Inventory[a-1]->duration == 0)
		{
			Inventory[a-1]->duration = 30;
			Inventory[a-1] = NULL;
		}
	}
}