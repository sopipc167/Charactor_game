#pragma once
#include "ObjectInfo.h"

/* ���� 3���� �߰� �ʿ�*/
Item WeaponList[3];
Item ItemList[2];

int useFood(Character*, int);
int useOrder(Character*, int);

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
