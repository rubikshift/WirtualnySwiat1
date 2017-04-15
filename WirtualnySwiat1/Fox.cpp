#include "Fox.h"
#include "Direction.h"
#include "MyRandom.h"


Fox::Fox(World& WorldToLive) : Animal(3, 7, WorldToLive)
{
}

Fox::Fox(World& WorldToLive, Point P) : Animal(3, 7, WorldToLive, P)
{
}


Fox::~Fox()
{
}

int Fox::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = FOX;
	return 0;
}

int Fox::Act()
{

	MyRandom random;
	Point FuturePosition;
	Direction dir;
	Organism * AnotherOrganism;
	bool isSet = false;
	if (!this->GoodNose())
	{
		this->WorldToLive.AddLog(this->GetSpecies() + " nie zweszyl dobrego miejsca, tu mu dobrze");
		return 0;
	}
	this->WorldToLive.AddLog(this->GetSpecies() + " zweszyl dobre miejsce");
	while(!isSet)
	{
		dir = random.RandomDirection();
		switch (dir)
		{
			case LEFT:
				if (this->Position.GetX() - this->MoveDistance >= 0)
				{
					FuturePosition = { this->Position.GetX() - this->MoveDistance, this->Position.GetY() };
					if(this->WorldToLive.GetOrganismQueue()->Find(FuturePosition) == nullptr
						|| (this->WorldToLive.GetOrganismQueue()->Find(FuturePosition) != nullptr 
						&& this->WorldToLive.GetOrganismQueue()->Find(FuturePosition)->GetStrength() <= this->Strength))
						isSet = true;
				}
				break;
			case RIGHT:
				if(this->Position.GetX() + this->MoveDistance < this->WorldToLive.GetWidth())
				{

					FuturePosition = {this->Position.GetX() + this->MoveDistance, this->Position.GetY()};
					if(this->WorldToLive.GetOrganismQueue()->Find(FuturePosition) == nullptr
						|| (this->WorldToLive.GetOrganismQueue()->Find(FuturePosition) != nullptr 
						&& this->WorldToLive.GetOrganismQueue()->Find(FuturePosition)->GetStrength() <= this->Strength))
						isSet = true;
				}
				break;
			case UP:
				if(this->Position.GetY() - this->MoveDistance >= 0)
				{
					FuturePosition = {this->Position.GetX(), this->Position.GetY() - this->MoveDistance };
					if(this->WorldToLive.GetOrganismQueue()->Find(FuturePosition) == nullptr
						|| (this->WorldToLive.GetOrganismQueue()->Find(FuturePosition) != nullptr 
						&& this->WorldToLive.GetOrganismQueue()->Find(FuturePosition)->GetStrength() <= this->Strength))
						isSet = true;
				}
				break;
			case DOWN:
				if (this->Position.GetY() + this->MoveDistance < this->WorldToLive.GetHeight())
				{
					FuturePosition = { this->Position.GetX(), this->Position.GetY() + this->MoveDistance };
					if(this->WorldToLive.GetOrganismQueue()->Find(FuturePosition) == nullptr
						|| (this->WorldToLive.GetOrganismQueue()->Find(FuturePosition) != nullptr 
						&& this->WorldToLive.GetOrganismQueue()->Find(FuturePosition)->GetStrength() <= this->Strength))
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

bool Fox::GoodNose()
{
	if (this->Position.GetX() + 1 < this->WorldToLive.GetWidth() 
		&& ( this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX() + 1, this->Position.GetY() }) == nullptr
		|| (this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX() + 1, this->Position.GetY() }) != nullptr
		&& this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX() + 1, this->Position.GetY() })->GetStrength() <= this->Strength)))
		return true;
	else if (this->Position.GetX() - 1 >= 0 
		&& (this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX() - 1, this->Position.GetY() }) == nullptr
		|| (this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX() - 1, this->Position.GetY() }) != nullptr
		&& this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX() - 1, this->Position.GetY() })->GetStrength() <= this->Strength)))
		return true;
	else if (this->Position.GetY() + 1 < this->WorldToLive.GetHeight() 
		&& (this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX(), this->Position.GetY() + 1}) == nullptr
		|| (this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX(), this->Position.GetY() + 1}) != nullptr
		&& this->WorldToLive.GetOrganismQueue()->Find({this->Position.GetX(), this->Position.GetY() + 1 })->GetStrength() <= this->Strength)))
		return true;
	else if (this->Position.GetY() - 1 >= 0 
		&& (this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX(), this->Position.GetY() - 1}) == nullptr
		|| (this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX(), this->Position.GetY() - 1 }) != nullptr
		&& this->WorldToLive.GetOrganismQueue()->Find({ this->Position.GetX(), this->Position.GetY() - 1 })->GetStrength() <= this->Strength)))
		return true;
	return false;
}

int Fox::Collide(Organism * AnotherOrganism)
{
	if (dynamic_cast<Fox*>(AnotherOrganism))
		this->Reproduce();
	else
		Animal::Collide(AnotherOrganism);
	return 0;
}

void Fox::Reproduce()
{
	Point ChildPosition = this->GetChildPosition();
	if (ChildPosition != this->Position)
	{
		auto YoungFox = new Fox(this->WorldToLive, ChildPosition);
		Animal::Reproduce();
	}
}

std::string Fox::GetSpecies()
{
	return "Lis";
}
