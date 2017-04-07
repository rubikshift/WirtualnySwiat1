#include "Organism.h"



Organism::Organism(int Strength, int Initative, World& WorldToLive) : WorldToLive(WorldToLive)
{
	this->Strength = Strength;
	this->Initative = Initative;
	Age = 0;
}


Organism::~Organism()
{
}
