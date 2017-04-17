#include "Plant.h"
#include "MyRandom.h"

#define DEFAULT_PLANT_PROBABILTY 35

Plant::Plant(int Strength, World& WorldToLive) : Organism(Strength, 0, WorldToLive)
{
	this->ReproduceProbability = DEFAULT_PLANT_PROBABILTY;
}

Plant::Plant(int Strength, World& WorldToLive, Point P) : Organism(Strength, 0, WorldToLive, P)
{
	this->ReproduceProbability = DEFAULT_PLANT_PROBABILTY;
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
