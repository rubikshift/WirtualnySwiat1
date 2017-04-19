#include "Human.h"
#include <iostream>
#include <conio.h>

Human::Human(World& WorldToLive) : Animal(5, 4, WorldToLive)
{
	SuperPowerOverload = 0;
	SuperPowerActive = false;
	SuperPowerTurnsLeft = 0;
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
	auto AnotherOrganism = this->WorldToLive.GetOrganismQueue()->Find(FuturePosition);
	if (AnotherOrganism != nullptr)
	{
		this->Collide(AnotherOrganism);
		if (AnotherOrganism->IsDead())
			this->Position = FuturePosition;
	}
	else
		this->Position = FuturePosition;
	if (!SuperPowerActive && SuperPowerOverload > 0)
		SuperPowerOverload--;
	else if (SuperPowerActive)
	{
		SuperPowerTurnsLeft--;
		this->Strength--;
	}
	if (SuperPowerTurnsLeft == 0)
	{
		SuperPowerActive = false;
		SuperPowerOverload = 5;
	}
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

bool Human::Control(Direction Dir)
{
	Point P1 = { this->Position.GetX() + MoveDistance, this->Position.GetY() };
	Point P2 = { this->Position.GetX() - MoveDistance, this->Position.GetY() };
	Point P3 = { this->Position.GetX(), this->Position.GetY() + MoveDistance };
	Point P4 = { this->Position.GetX(), this->Position.GetY() - MoveDistance };
	FuturePosition = Position;
	switch (Dir)
	{
		case LEFT:
			if (P2.GetX() >= 0)
				FuturePosition = P2;
			break;
		case RIGHT:
			if (P1.GetX() < this->WorldToLive.GetWidth())
				FuturePosition = P1;
			break;
		case UP:
			if (P4.GetY() >= 0)
				FuturePosition = P4;
			break;
		case DOWN:
			if (P3.GetY() < this->WorldToLive.GetHeight())
				FuturePosition = P3;
			break;
		case NONE:
			return false;
		}
	if (Position != FuturePosition)
		return true;
	else
		return false;
}

bool Human::SuperPower()
{
	if (SuperPowerActive || (!SuperPowerActive && SuperPowerOverload > 0))
		return false;
	else
	{
		SuperPowerActive = true;
		this->Strength += 5;
		SuperPowerTurnsLeft = 5;
	}
}

int Human::GetSuperPowerOverload() const
{
	return this->SuperPowerOverload;
}

int Human::GetSuperPowerTurnsLeft() const
{
	return this->SuperPowerTurnsLeft;
}

bool Human::IsSuperPowerActive() const
{
	return this->SuperPowerActive;
}
