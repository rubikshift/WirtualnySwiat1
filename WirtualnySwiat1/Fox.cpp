#include "Fox.h"



Fox::Fox(World& WorldToLive) : Animal(3, 7, WorldToLive)
{
}


Fox::~Fox()
{
}

int Fox::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = FOX;
	return 0;
}