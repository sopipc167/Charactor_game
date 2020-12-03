#pragma once
#include "ObjectInfo.h"


Item ItemList[8];

int useFood(Character*, int);
int useOrder(Character*, int);
void initList();

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
