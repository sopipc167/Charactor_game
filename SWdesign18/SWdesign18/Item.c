
#pragma once
#include "ObjectInfo.h"
#include "Item.h"
#include <stdlib.h>
#include<time.h>
#include<Windows.h>

extern Character pc;

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
	ItemList[0] = Knife;
	ItemList[1] = Rifle;
	ItemList[2] = Rocket;
	ItemList[3] = Key;
	ItemList[4] = Food;
}
void initInventory(Character* p)
{
	p->inventory[0].duration=0;
	p->inventory[0].name = NULL;
	p->inventory[0].use = NULL;

	p->inventory[1].duration = 0;
	p->inventory[1].name = NULL;
	p->inventory[1].use = NULL;

	p->inventory[2].duration = 0;
	p->inventory[2].name = NULL;
	p->inventory[2].use = NULL;

	p->inventory[3].duration = 0;
	p->inventory[3].name = NULL;
	p->inventory[3].use = NULL;

	p->inventory[4].duration = 0;
	p->inventory[4].name = NULL;
	p->inventory[4].use = NULL;
}

void AddToInventory(Item it[],int index)
{
	if (pc.inventory[index].duration == 0)
	{
		pc.inventory[index] = it[index];
		getItemUI(index, pc.inventory[index].duration, pc.inventory[index].name);
	}
}

void useFood(Character* p, int heal)
{
	if (p->hp < 3)
	{
		p->hp += heal;
		p->inventory[4].duration--;
		getItemUI(4, p->inventory[4].duration, p->inventory[4].name);
		if (p->inventory[4].duration)
		{
			p->inventory[4].name = NULL;
			p->inventory[4].use = NULL;
		}
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
		p->inventory[a-1].duration--;
		getItemUI(3, p->inventory[3].duration, p->inventory[3].name);
		if (p->inventory[a - 1].duration == 0)
		{
			p->inventory[a - 1].name = NULL;
			p->inventory[a - 1].use = NULL;
		}
	}
}
