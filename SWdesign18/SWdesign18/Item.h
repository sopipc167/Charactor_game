#pragma once
#include "ObjectInfo.h"

/* ���� 3���� �߰� �ʿ�*/
Item ItemList[8];

int useFood(Character*, int);
int useOrder(Character*, int);

Item Sword = {
	30,
	"DROWS",
};

Item Rifle = {
	30,
	"ELFIR",
};

Item Rocket = {
	6,
	"TEKCOR",
};

Item Food = {
	1,
	"DOOF",
	useFood
};

Item Order = {
	1,
	"REDRO",
	useOrder
};



