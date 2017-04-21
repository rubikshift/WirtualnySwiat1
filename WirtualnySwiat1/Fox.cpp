#include "Fox.h"
#include "Direction.h"
#include "MyRandom.h"


Fox::Fox(World& WorldToLive) : Animal(3, 7, WorldToLive)
{
	Type = FOX;
}

Fox::Fox(World & WorldToLive, std::fstream & in) : Animal(7, WorldToLive, in)
{
	Type = FOX;
}

Fox::Fox(World& WorldToLive, Point P) : Animal(3, 7, WorldToLive, P)
{
	Type = FOX;
}


Fox::~Fox()
{
}

int Fox::Act()
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

	Organism* O1 = this->WorldToLive.GetOrganismQueue()->Find(P1);
	Organism* O2 = this->WorldToLive.GetOrganismQueue()->Find(P2);
	Organism* O3 = this->WorldToLive.GetOrganismQueue()->Find(P3);
	Organism* O4 = this->WorldToLive.GetOrganismQueue()->Find(P4);

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
				if (P2.GetX() >= 0)
				{
					FuturePosition = P2;
					if(O2 == nullptr || (O2 != nullptr && O2->GetStrength() <= this->Strength))
						isSet = true;
				}
				break;
			case RIGHT:
				if(P1.GetX() < this->WorldToLive.GetWidth())
				{

					FuturePosition = P1;
					if(O1 == nullptr || (O1 != nullptr && O1->GetStrength() <= this->Strength))
						isSet = true;
				}
				break;
			case UP:
				if(P4.GetY() >= 0)
				{
					FuturePosition = P4;
					if(O4 == nullptr || (O4 != nullptr && O4->GetStrength() <= this->Strength))
						isSet = true;
				}
				break;
			case DOWN:
				if (P3.GetY() < this->WorldToLive.GetHeight())
				{
					FuturePosition = P3;
					if(O3 == nullptr || (O3 != nullptr && O3->GetStrength() <= this->Strength))
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
	Point P1 = { this->Position.GetX() + MoveDistance, this->Position.GetY() };
	Point P2 = { this->Position.GetX() - MoveDistance, this->Position.GetY() };
	Point P3 = { this->Position.GetX(), this->Position.GetY() + MoveDistance };
	Point P4 = { this->Position.GetX(), this->Position.GetY() - MoveDistance };

	Organism* O1 = this->WorldToLive.GetOrganismQueue()->Find(P1);
	Organism* O2 = this->WorldToLive.GetOrganismQueue()->Find(P2);
	Organism* O3 = this->WorldToLive.GetOrganismQueue()->Find(P3);
	Organism* O4 = this->WorldToLive.GetOrganismQueue()->Find(P4);

	if (P1.GetX() < this->WorldToLive.GetWidth() 
		&& (O1 == nullptr || (O1 != nullptr && O1->GetStrength() <= this->Strength)))
		return true;
	else if (P2.GetX() >= 0
		&& (O2 == nullptr || (O2 != nullptr && O2->GetStrength() <= this->Strength)))
		return true;
	else if (P3.GetY() < this->WorldToLive.GetHeight()
		&& (O3 == nullptr || (O3 != nullptr && O3->GetStrength() <= this->Strength)))
		return true;
	else if (P4.GetY() >= 0
		&& (O4 == nullptr || (O4 != nullptr && O4->GetStrength() <= this->Strength)))
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
