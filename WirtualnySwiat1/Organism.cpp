#include "Organism.h"



Organism::Organism(int Strength, int Initative, World& WorldToLive)
{
	this->Strength = Strength;
	this->Initative = Initative;
	Age = 0;
	this->WorldToLive = WorldToLive;
}


Organism::~Organism()
{
}
