#pragma once
#include "ObjectInfo.h"


Item ItemList[8];

void use_KNIFE(Character ch);
void useRIFLE();
void useCANNON();
int useFood(Character*, int);
int useOrder(Character*, int);
void initList();

Item Food;
Item Order
