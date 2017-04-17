#include "Human.h"
#include <iostream>
#include <conio.h>

Human::Human(World& WorldToLive) : Animal(5, 4, WorldToLive)
{
}


Human::~Human()
{
}

int Human::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = HUMAN;
	return 0;
}

int Human::Act()
{
	Point FuturePosition;
	Organism * AnotherOrganism;
	char dir;
	bool isSet = false;

	Point P1 = { this->Position.GetX() + MoveDistance, this->Position.GetY() };
	Point P2 = { this->Position.GetX() - MoveDistance, this->Position.GetY() };
	Point P3 = { this->Position.GetX(), this->Position.GetY() + MoveDistance };
	Point P4 = { this->Position.GetX(), this->Position.GetY() - MoveDistance };

	while (!isSet)
	{
		dir = getch();
		switch (dir)
		{
		case 'a':
		case 'A':
			if (P2.GetX() >= 0)
				FuturePosition = P2;
			break;
		case 'd':
		case 'D':
			if (P1.GetX() < this->WorldToLive.GetWidth())
				FuturePosition = P1;
			break;
		case 'w':
		case 'W':
			if (P4.GetY() >= 0)
				FuturePosition = P4;
			break;
		case 's':
		case 'S':
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

void Human::Reproduce()
{
	return;
}

std::string Human::GetSpecies()
{
	return "Czlowiek";
}
