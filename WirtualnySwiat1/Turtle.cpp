#include "Turtle.h"



Turtle::Turtle(World& WorldToLive) : Animal(2, 1, WorldToLive)
{
}


Turtle::~Turtle()
{
}

int Turtle::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = TURTLE;
	return 0;
}

bool Turtle::DeflectedAttack(Organism * Enemy) const
{
	return Enemy->GetStrength() < 5;
}
