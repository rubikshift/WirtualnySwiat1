#include "Grass.h"



Grass::Grass(World& WorldToLive) : Plant(0, WorldToLive)
{
}


Grass::~Grass()
{
}

int Grass::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = GRASS;
	return 0;
}