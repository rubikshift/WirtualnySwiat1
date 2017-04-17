#pragma once
#include "Plant.h"
class Guarana :
	public Plant
{
public:
	Guarana(World& WorldToLive);
	Guarana(World& WorldToLive, Point P);
	virtual ~Guarana();
	int Draw() override;
	void Reproduce() override;
	int Collide(Organism* AnotherOrganism) override;
	std::string GetSpecies() override;
};

