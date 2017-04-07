#include "Sheep.h"



Sheep::Sheep(World& WorldToLive) : Animal(4, 4, WorldToLive)
{
}


Sheep::~Sheep()
{
}

int Sheep::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = SHEEP;
	return 0;
}