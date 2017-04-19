#pragma once
#include "Animal.h"
#include "Direction.h"

class Human :
	public Animal
{
public:
	Human(World& WorldToLive);
	virtual ~Human();
	int Draw() override;
	int Act();
	void Reproduce() override;
	std::string GetSpecies() override;
	bool Control(Direction Dir);
	bool SuperPower();
	int GetSuperPowerOverload() const;
	int GetSuperPowerTurnsLeft() const;
	bool IsSuperPowerActive() const;
private:
	Point FuturePosition;
	int SuperPowerOverload;
	int SuperPowerTurnsLeft;
	bool SuperPowerActive;
};

