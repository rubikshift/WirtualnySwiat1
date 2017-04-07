#include "World.h"



World::World()
{
}

World::World(int m, int n)
{
	this->m = m;
	this->n = n;
	this->Map = new WorldField*[m];
	for (int i = 0; i < m; i++)
		this->Map[i] = new WorldField[n];
}


World::~World()
{
	for (int i = 0; i < m; i++)
		delete Map[i];
	delete Map;
}

WorldField ** World::GetMap()
{
	return this->Map;
}
