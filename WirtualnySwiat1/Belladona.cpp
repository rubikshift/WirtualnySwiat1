#include "Belladona.h"

#define BELLADONA_PROBABILTY 15

Belladona::Belladona(World& WorldToLive) : Plant(9, WorldToLive)
{
	this->ReproduceProbability = BELLADONA_PROBABILTY;
	Type = BELLADONA;
}

Belladona::Belladona(World & WorldToLive, std::fstream & in) : Plant(WorldToLive, in)
{
	this->ReproduceProbability = BELLADONA_PROBABILTY;
	Type = BELLADONA;
}

Belladona::Belladona(World& WorldToLive, Point P) : Plant(9, WorldToLive, P)
{
	this->ReproduceProbability = BELLADONA_PROBABILTY;
	Type = BELLADONA;
}


Belladona::~Belladona()
{
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
