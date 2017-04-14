#pragma once
#include "WorldField.h"
#include "OrganismQueue.h"
#include "Point.h"

class Organism;
class OrganismQueue;

class World
{
public:
	World();
	World(int Width, int Height);
	~World();

	int MakeTurn();
	int Draw();
	WorldField** GetMap();
	void AddOrganismToWorld(Organism* LivingOrganism);
	int GetWidth() const;
	int GetHeight() const;
	OrganismQueue* GetOrganismQueue();
	bool IsEmptyNear(Point P);

private:
	WorldField** Map;
	OrganismQueue* Organisms;
	int Width, Height;
};

