#include "Belladona.h"



Belladona::Belladona(World& WorldToLive) : Plant(9, WorldToLive)
{
}


Belladona::~Belladona()
{
}

int Belladona::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = BELLADONA;
	return 0;
}