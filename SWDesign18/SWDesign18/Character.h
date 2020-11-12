#pragma once

enum direction
{
	LEFT = 0,
	RIGHT,
	UP,	
	DOWN
};

typedef struct vector
{
	int x;
	int y;
}Vector;

typedef struct character
{
	int hp;
	int atk;
	void (*move)(Vector, direction);
	void (*getHit)(Character, int);
	//attack function pointer
	void (*die)();
	//Item function array
}Character;