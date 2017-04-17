#include "Animal.h"
#include "Plant.h"
#include "MyRandom.h"
#include "Direction.h"

Animal::Animal(int Strength, int Initative, World& WorldToLive) : Organism(Strength, Initative, WorldToLive)
{
	this->MoveDistance = 1;
}

Animal::Animal(int Strength, int Initative, World & WorldToLive, Point P) : Organism(Strength, Initative, WorldToLive, P)
{
	this->MoveDistance = 1;
}


Animal::~Animal()
{
}

int Animal::Act()
{
	MyRandom random;
	Point FuturePosition;
	Direction dir;
	Organism * AnotherOrganism;
	bool isSet = false;

	Point P1 = { this->Position.GetX() + MoveDistance, this->Position.GetY() };
	Point P2 = { this->Position.GetX() - MoveDistance, this->Position.GetY() };
	Point P3 = { this->Position.GetX(), this->Position.GetY() + MoveDistance };
	Point P4 = { this->Position.GetX(), this->Position.GetY() - MoveDistance };

	while(!isSet)
	{
		dir = random.RandomDirection();
		switch (dir)
		{
			case LEFT:
				if (P2.GetX() >= 0)
					FuturePosition = P2;
				break;
			case RIGHT:
				if(P1.GetX() < this->WorldToLive.GetWidth())
					FuturePosition = P1;
				break;
			case UP:
				if(P4.GetY() >= 0)
					FuturePosition = P4;
				break;
			case DOWN:
				if (P3.GetY() < this->WorldToLive.GetHeight())
					FuturePosition = P3;
				break;
		}
		if (Position != FuturePosition)
			isSet = true;
	}
	AnotherOrganism = this->WorldToLive.GetOrganismQueue()->Find(FuturePosition);
	if (AnotherOrganism != nullptr)
	{
		this->Collide(AnotherOrganism);
		if (AnotherOrganism->IsDead())
			this->Position = FuturePosition;
	}
	else
		this->Position = FuturePosition;
	return 0;
}

int Animal::Collide(Organism* AnotherOrganism)
{
	if (dynamic_cast<Plant*>(AnotherOrganism))
		this->Eat(AnotherOrganism);
	else if (!AnotherOrganism->DeflectedAttack(this) && !AnotherOrganism->RunAway(this))
		this->Fight(AnotherOrganism);
	return 0;
}

void Animal::Reproduce()
{
	this->WorldToLive.AddLog("Milosc rosnie wokol nas! Urodzilo sie nowe zwierzatko (" + this->GetSpecies() + ")");
}
