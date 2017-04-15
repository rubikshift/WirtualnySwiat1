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
	while(!isSet)
	{
		dir = random.RandomDirection();
		switch (dir)
		{
			case LEFT:
				if (this->Position.GetX() - this->MoveDistance >= 0)
				{
					FuturePosition = { this->Position.GetX() - this->MoveDistance, this->Position.GetY() };
					isSet = true;
				}
				break;
			case RIGHT:
				if(this->Position.GetX() + this->MoveDistance < this->WorldToLive.GetWidth())
				{

					FuturePosition = {this->Position.GetX() + this->MoveDistance, this->Position.GetY()};
					isSet = true;
				}
				break;
			case UP:
				if(this->Position.GetY() - this->MoveDistance >= 0)
				{
					FuturePosition = {this->Position.GetX(), this->Position.GetY() - this->MoveDistance };
					isSet = true;
				}
				break;
			case DOWN:
				if (this->Position.GetY() + this->MoveDistance < this->WorldToLive.GetHeight())
				{
					FuturePosition = { this->Position.GetX(), this->Position.GetY() + this->MoveDistance };
					isSet = true;
				}
				break;
		}
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
