#include "Plant.h"
#include "MyRandom.h"


Plant::Plant(int Strength, World& WorldToLive) : Organism(Strength, 0, WorldToLive)
{
	this->ReproduceProbability = 35;
}

Plant::Plant(int Strength, World& WorldToLive, Point P) : Organism(Strength, 0, WorldToLive, P)
{
	this->ReproduceProbability = 35;
}

int Plant::Act()
{
	MyRandom random;
	auto i = random.RandomInt(1, 100);
	if (i <= this->ReproduceProbability)
		this->Reproduce();
	return 0;
}

void Plant::Reproduce()
{
	this->WorldToLive.AddLog(this->GetSpecies() + " rozsiewa sie");
}

int Plant::Collide(Organism * AntoherOrganism)
{
	return 0;
}


Plant::~Plant()
{
}
