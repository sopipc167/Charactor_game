#pragma once
#include "ObjectInfo.h"

/* ���� 3���� �߰� �ʿ�*/
Item WeaponList[3];
Item ItemList[2];

Item Food = {
	1,
	"DOOF",
	useFood
};

int useFood(Character*, int);

Item Order = {
	1,
	"REDRO",
	useOrder
};

int useOrder(Character*, int);