#include "Organism.h"



Organism::Organism(int Strength, int Initative, World& WorldToLive) : WorldToLive(WorldToLive)
{
	this->Strength = Strength;
	this->Initative = Initative;
	Age = 0;
	this->WorldToLive.AddOrganismToWorld(this);
}


Organism::~Organism()
{
}

int Organism::GetStrength() const
{
	return this->Strength;
}

int Organism::GetInitative() const
{
	return this->Initative;
}

int Organism::GetAge() const
{
	return this->Age;
}

Point Organism::GetPosition() const
{
	return this->Position;
}

void Organism::Die()
{
	this->isDead = true;
}

bool Organism::IsDead()
{
	return isDead;
}

void Organism::Kill(Organism * AnotherOrganism)
{
	AnotherOrganism->Die();
}
