#include "Grass.h"



Grass::Grass(World& WorldToLive) : Plant(0, WorldToLive)
{
	Type = GRASS;
}

Grass::Grass(World & WorldToLive, std::fstream & in) : Plant(WorldToLive, in)
{
	Type = GRASS;
}

Grass::Grass(World& WorldToLive, Point P) : Plant(0, WorldToLive, P)
{
	Type = GRASS;
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
