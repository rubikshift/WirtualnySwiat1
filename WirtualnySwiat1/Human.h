#pragma once
#include "Animal.h"
#include "Direction.h"

class Human :
	public Animal
{
public:
	Human(World& WorldToLive);
	Human(World& WorldToLive, std::fstream& in);
	virtual ~Human();
	int Act();
	void Reproduce() override;
	std::string GetSpecies() override;
	bool Control(Direction Dir);
	bool SuperPower();
	int GetSuperPowerCoolDown() const;
	int GetSuperPowerTurnsLeft() const;
	bool IsSuperPowerActive() const;
	void Save(std::fstream& out) override;
private:
	Point FuturePosition;
	int SuperPowerCoolDown;
	int SuperPowerTurnsLeft;
	bool SuperPowerActive;
};

