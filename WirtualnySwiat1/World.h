#pragma once
#include <list>
#include <fstream>
#include <string>
#include "WorldField.h"
#include "OrganismQueue.h"
#include "Point.h"

#define DEBUG

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
	void AddLog(std::string Log);

private:
	WorldField** Map;
	OrganismQueue* Organisms;
	int Width, Height, Turn;
	std::list<std::string> Logs;
#ifdef DEBUG
	std::ofstream out;
#endif // DEBUG
};

