#pragma once
#include "Animal.h"
class Wolf :
	public Animal
{
public:
	Wolf(World& WorldToLive);
	Wolf(World& WorldToLive, Point P);
	virtual ~Wolf();
	int Draw() override;
	int Collide(Organism* AnotherOrganism) override;
	void Reproduce() override;
	std::string GetSpecies() override;
};

