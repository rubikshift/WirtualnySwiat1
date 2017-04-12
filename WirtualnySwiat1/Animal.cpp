#include "Animal.h"
#include "MyRandom.h"
#include "Direction.h"

Animal::Animal(int Strength, int Initative, World& WorldToLive) : Organism(Strength, Initative, WorldToLive)
{
}


Animal::~Animal()
{
}

int Act()
{
	MyRandom random;
	Point FuturePosition;
	Direction dir;
	Organism * AnotherOrganism;
	bool isSet = false;
	do
	{
		dir = random.RandomDirection();
		switch (dir)
		{
			case LEFT:
				if(this->Position.GetX() - 1 > 0)
					FuturePosition = {this->Position.GetX() - 1, this->Position.GetY};
				break;
			case RIGHT:
				if(this->Position.GetX() + 1 < this->WorldToLive.GetWidth())
					FuturePosition = {this->Position.GetX() + 1, this->Position.GetY};
				break;
			case UP:
				if(this->Position.GetY() - 1 > 0)
					FuturePosition = {this->Position.GetX(), this->Position.GetY() - 1 };
				break;
			case DOWN:
				if(this->Position.GetY() + 1 < this->WorldToLive.GetHeight())
					FuturePosition = {this->Position.GetX(), this->Position.GetY() + 1}
				break;
		}
	} while(isSet == false);
	AnotherOrganism = this->WorldToLive.OrgasismQueue->Find(FuturePosition);
	if(AnotherOrganism != nullptr)
		this->Collide(AnotherOrganism);
}
