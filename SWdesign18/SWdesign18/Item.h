#pragma once
#include "ObjectInfo.h"


Item ItemList[8];
Item *Inventory[6];

void use_KNIFE(Character ch);
void useRIFLE(Character *ch,int x);
void useCANNON(Character *ch,int x);
void useFood(Character*, int);// int->void�� �ٲ�
void initList();
void initItem();
void AddToInventory(Item item[],int index);

Item Knife;
Item Rifle;
Item Rocket;
Item Key;
Item Food;
Item Star;
int index;
Item Order;