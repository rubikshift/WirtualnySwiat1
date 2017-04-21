#include "Wolf.h"



Wolf::Wolf(World& WorldToLive) : Animal(9, 5, WorldToLive)
{
	Type = WOLF;
}

Wolf::Wolf(World & WorldToLive, std::fstream & in) : Animal(5, WorldToLive, in)
{
	Type = WOLF;
}

Wolf::Wolf(World & WorldToLive, Point P) : Animal(9, 5, WorldToLive, P)
{
	Type = WOLF;
}


Wolf::~Wolf()
{
}

int Wolf::Collide(Organism * AnotherOrganism)
{
	if (dynamic_cast<Wolf*>(AnotherOrganism))
		this->Reproduce();
	else
		Animal::Collide(AnotherOrganism);
	return 0;
}

void Wolf::Reproduce()
{
	Point ChildPosition = this->GetChildPosition();
	if (ChildPosition != this->Position)
	{
		auto YoungWolf = new Wolf(this->WorldToLive, ChildPosition);
		Animal::Reproduce();
	}
}

std::string Wolf::GetSpecies()
{
	return "Wilk";
}
