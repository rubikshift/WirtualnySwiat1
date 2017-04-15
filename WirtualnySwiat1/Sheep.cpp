#include "Sheep.h"
#include "MyRandom.h"


Sheep::Sheep(World& WorldToLive) : Animal(4, 4, WorldToLive)
{
}

Sheep::Sheep(World & WorldToLive, Point P) :  Animal(4, 4, WorldToLive, P)
{
}


Sheep::~Sheep()
{
}

int Sheep::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = SHEEP;
	return 0;
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
