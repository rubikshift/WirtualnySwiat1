#pragma once
#include "Animal.h"
class Antelope :
	public Animal
{
public:
	Antelope(World& WorldToLive);
	Antelope(World& WorldToLive, Point P);
	virtual ~Antelope();
	int Draw() override;
	int Collide(Organism* AnotherOrganism) override;
	void Reproduce() override;
	bool RunAway(Organism* Enemy) override;
	std::string GetSpecies() override;
};

