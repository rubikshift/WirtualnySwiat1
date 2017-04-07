#pragma once
#include "World.h"
#include "Point.h"

class World;

class Organism
{
public:
	Organism();
	Organism(int Strength, int Initative, World& WorldToLive);
	virtual ~Organism();

	int Act();
	int Collide();
	virtual int Draw() = 0;
protected:
	int Strength;
	int Initative;
	int Age;
	Point Position;
	World& WorldToLive;
};

