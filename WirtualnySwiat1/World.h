#pragma once
#include "Organism.h"
#include "WorldField.h"

class World
{
public:
	World(int m, int n);
	~World();

	int MakeTurn();
	int Draw();
	WorldField** GetMap();

private:
	WorldField** Map;
	int m, n;
};

