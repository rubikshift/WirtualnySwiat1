#include "Belladona.h"

#define BELLADONA_PROBABILTY 15

Belladona::Belladona(World& WorldToLive) : Plant(9, WorldToLive)
{
	this->ReproduceProbability = BELLADONA_PROBABILTY;
}

Belladona::Belladona(World& WorldToLive, Point P) : Plant(9, WorldToLive, P)
{
	this->ReproduceProbability = BELLADONA_PROBABILTY;
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

void Belladona::Reproduce()
{
	Point ChildPosition = this->GetChildPosition();
	if (ChildPosition != this->Position)
	{
		auto YoungBelladona = new Belladona(this->WorldToLive, ChildPosition);
		Plant::Reproduce();
	}
}

int Belladona::Collide(Organism * AnotherOrganism)
{
	this->Kill(AnotherOrganism);
	return 0;
}

std::string Belladona::GetSpecies()
{
	return "Wilcza jagoda";
}
