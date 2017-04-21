#pragma once
#include "Animal.h"
class Turtle :
	public Animal
{
public:
	Turtle(World& WorldToLive);
	Turtle(World& WorldToLive, std::fstream& in);
	Turtle(World& WorldToLive, Point P);
	virtual ~Turtle();
	bool DeflectedAttack(Organism* Enemy) override;
	int Act() override;
	int Collide(Organism* AnotherOrganism) override;
	void Reproduce() override;
	std::string GetSpecies() override;
};

