#include "Turtle.h"
#include "MyRandom.h"


Turtle::Turtle(World& WorldToLive) : Animal(2, 1, WorldToLive)
{
	Type = TURTLE;
}

Turtle::Turtle(World & WorldToLive, std::fstream & in) : Animal(1, WorldToLive, in)
{
	Type = TURTLE;
}

Turtle::Turtle(World & WorldToLive, Point P) : Animal(2, 1, WorldToLive, P)
{
	Type = TURTLE;
}


Turtle::~Turtle()
{
}

bool Turtle::DeflectedAttack(Organism * Enemy)
{
	if (Enemy->GetStrength() < 5)
	{
		this->WorldToLive.AddLog(this->GetSpecies() + " odbija atak " + Enemy->GetSpecies());
		return true;
	}
	else return false;
}

int Turtle::Act()
{
	MyRandom random;
	auto i = random.RandomInt(1, 100);
	if (i > 75)
		Animal::Act();
	return 0;
}

int Turtle::Collide(Organism * AnotherOrganism)
{
	if (dynamic_cast<Turtle*>(AnotherOrganism))
		this->Reproduce();
	else
		Animal::Collide(AnotherOrganism);
	return 0;
}

void Turtle::Reproduce()
{
	Point ChildPosition = this->GetChildPosition();
	if (ChildPosition != this->Position)
	{
		auto YoungTurtle = new Turtle(this->WorldToLive, ChildPosition);
		Animal::Reproduce();
	}
}

std::string Turtle::GetSpecies()
{
	return "Zolw";
}
