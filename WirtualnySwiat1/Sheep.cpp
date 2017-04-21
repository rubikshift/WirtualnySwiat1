#include "Sheep.h"
#include "MyRandom.h"


Sheep::Sheep(World& WorldToLive) : Animal(4, 4, WorldToLive)
{
	Type = SHEEP;
}

Sheep::Sheep(World & WorldToLive, std::fstream & in) : Animal(4, WorldToLive, in)
{
	Type = SHEEP;
}

Sheep::Sheep(World & WorldToLive, Point P) :  Animal(4, 4, WorldToLive, P)
{
	Type = SHEEP;
}


Sheep::~Sheep()
{
}

int Sheep::Collide(Organism * AnotherOrganism)
{
	if (dynamic_cast<Sheep*>(AnotherOrganism))
		this->Reproduce();
	else
		Animal::Collide(AnotherOrganism);
	return 0;
}

void Sheep::Reproduce()
{
	Point ChildPosition = this->GetChildPosition();
	if (ChildPosition != this->Position)
	{
		auto YoungSheep = new Sheep(this->WorldToLive, ChildPosition);
		Animal::Reproduce();
	}
}

std::string Sheep::GetSpecies()
{
	return "Owca";
}
