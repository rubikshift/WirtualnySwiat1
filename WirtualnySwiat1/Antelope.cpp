#include "Antelope.h"
#include "MyRandom.h"


Antelope::Antelope(World& WorldToLive) : Animal(4, 4, WorldToLive)
{
}


Antelope::~Antelope()
{
}

int Antelope::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = ANTELOPE;
	return 0;
}

int Antelope::Act()
{
	MyRandom random;
	Direction MoveDirection = random.RandomDirection();
	return 0;
}

int Antelope::Collide(Organism * AnotherOrgansim)
{
	return 0;
}
