#pragma once
#include "Plant.h"
class Belladona :
	public Plant
{
public:
	Belladona(World& WorldToLive);
	Belladona(World& WorldToLive, Point P);
	virtual ~Belladona();
	int Draw() override;
	void Reproduce() override;
	int Collide(Organism* AnotherOrganism) override;
	std::string GetSpecies() override;
};

