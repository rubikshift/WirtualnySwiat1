#pragma once
#include "Animal.h"
class Wolf :
	public Animal
{
public:
	Wolf(World& WorldToLive);
	Wolf(World& WorldToLive, std::fstream& in);
	Wolf(World& WorldToLive, Point P);
	virtual ~Wolf();
	int Collide(Organism* AnotherOrganism) override;
	void Reproduce() override;
	std::string GetSpecies() override;
};

