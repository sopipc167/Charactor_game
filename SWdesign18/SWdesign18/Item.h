#pragma once
#include "ObjectInfo.h"


Item ItemList[5];
Item *Inventory[5];

void use_KNIFE(Character ch);
void useRIFLE(Character *ch,int x);
void useCANNON(Character *ch,int x);
void useFood(Character*, int);
void useKey(Character*, int);
void useStar(Character*, int);
void initList();
void initItem();
void AddToInventory(Item item[],int index);

Item Knife;
Item Rifle;
Item Rocket;
Item Key;
Item Food;
Item Key;
Item Star;
int index;