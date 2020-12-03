#include "ObjectInfo.h"
#include <stdlib.h>

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
int useFood(Character* p, int heal)
{
	if (heal >= 0)
		p->hp += heal;
	return 0;
}

int useOrder(Character* arr, int sec)
{
	int* atkData = (int*)malloc(sizeof(int) * (sizeof(arr) / sizeof(Character)));
	for (int i = 0; i < sizeof(arr) / sizeof(Character); i++)
	{
		//몬스터 공격 안함(미구현)
		atkData[i] = arr[i].atk;
		arr[i].atk = 0;
	}

	//sleep(sec)

	for (int i = 0; i < sizeof(arr) / sizeof(Character); i++)
	{
		//몬스터 공격 재개(미구현)
		arr[i].atk = atkData[i];
	}

	free(atkData);
	return 0;
}