#pragma once
#include "Animal.h"
#include "Plant.h"
class Sheep :
	public Animal
{
public:
	Sheep(World& WorldToLive);
	Sheep(World& WorldToLive, Point P);
	virtual ~Sheep();
	int Draw() override;
	int Collide(Organism* AnotherOrganism) override;
	void Reproduce() override;
	std::string GetSpecies() override;
};

