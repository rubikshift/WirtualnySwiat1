#include "Grass.h"



Grass::Grass(World& WorldToLive) : Plant(0, WorldToLive)
{
}

Grass::Grass(World& WorldToLive, Point P) : Plant(0, WorldToLive, P)
{
}


Grass::~Grass()
{
}

int Grass::Act()
{
	if (this->Position == this->GetChildPosition())
		return 0;
	for (int i = 0; i < 3; i++)
		Plant::Act();
	return 0;
}

int Grass::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = GRASS;
	return 0;
}

void Grass::Reproduce()
{
	Point ChildPosition = this->GetChildPosition();
	if (ChildPosition != this->Position)
	{
		auto YoungGrass = new Grass(this->WorldToLive, ChildPosition);
		Plant::Reproduce();
	}
}

std::string Grass::GetSpecies()
{
	return "Trawa";
}
