#pragma once
#include "ObjectInfo.h"


Item ItemList[5];//비교용 단어완성 
Item Inventory[5];

void use_KNIFE(Character ch);
void useRIFLE(Character *ch,int x);
void useCANNON(Character *ch,int x);
void useFood(Character*, int);
void useKey(Character*, int);
void initList();
void initItem();
void initInventory(Character* p);
void AddToInventory(Item It[],int index);

Item Knife;
Item Rifle;
Item Rocket;
Item Key;
Item Food;
Item Key;
Item Star;
int index;