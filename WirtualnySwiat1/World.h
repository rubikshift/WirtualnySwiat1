#pragma once
#include "WorldField.h"
#include "OrganismQueue.h"

class OrganismQueue;

class World
{
public:
	World();
	World(int m, int n);
	~World();

	int MakeTurn();
	int Draw();
	WorldField** GetMap();

private:
	WorldField** Map;
	OrganismQueue* Organisms;
	int m, n;
};

