#pragma once
#include "Animal.h"
class Fox :
	public Animal
{
public:
	Fox(World& WorldToLive);
	Fox(World& WorldToLive, std::fstream& in);
	Fox(World& WorldToLive, Point P);
	virtual ~Fox();
	int Act() override;
	void Reproduce() override;
	int Collide(Organism * AnotherOrganism) override;
	bool GoodNose();
	std::string GetSpecies() override;
};

