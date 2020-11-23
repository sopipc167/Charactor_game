#pragma once
#include "ObjectInfo.h"

/* 무기 3종류 추가 필요*/

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