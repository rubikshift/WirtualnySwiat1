#include "Antelope.h"
#include "MyRandom.h"
#include "Plant.h"

Antelope::Antelope(World& WorldToLive) : Animal(4, 4, WorldToLive)
{
	this->MoveDistance = 2;
}

Antelope::Antelope(World& WorldToLive, Point P) : Animal(4, 4, WorldToLive, P)
{
	this->MoveDistance = 2;
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

int Antelope::Collide(Organism * AnotherOrganism)
{
	if (dynamic_cast<Antelope*>(AnotherOrganism))
		this->Reproduce();
	else if(dynamic_cast<Plant*>(AnotherOrganism) != nullptr || !this->RunAway(AnotherOrganism))
		Animal::Collide(AnotherOrganism);
	return 0;
}

void Antelope::Reproduce()
{
	Point ChildPosition = this->GetChildPosition();
	if (ChildPosition != this->Position)
	{
		auto YoungAntelope = new Antelope(this->WorldToLive, ChildPosition);
		Animal::Reproduce();
	}
}

bool Antelope::RunAway(Organism* Enemy)
{
	MyRandom random;
	auto i = random.RandomInt(1, 100);
	if (i <= 50 && this->WorldToLive.IsEmptyNear(this->Position))
	{
		this->Position = this->GetChildPosition();
		this->WorldToLive.AddLog(this->GetSpecies() + " ucieka przed " + Enemy->GetSpecies());
		return true;
	}
	else
		return false;
}

std::string Antelope::GetSpecies()
{
	return "Antylopa";
}
