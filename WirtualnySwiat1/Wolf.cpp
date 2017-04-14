#include "Wolf.h"



Wolf::Wolf(World& WorldToLive) : Animal(9, 5, WorldToLive)
{
}

Wolf::Wolf(World & WorldToLive, Point P) : Animal(9, 5, WorldToLive, P)
{
}


Wolf::~Wolf()
{
}

int Wolf::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = WOLF;
	return 0;
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
	if(ChildPosition != this->Position)
		auto YoungSheep = new Wolf(this->WorldToLive, ChildPosition);
}
