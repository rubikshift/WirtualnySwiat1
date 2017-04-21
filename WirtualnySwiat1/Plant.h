#pragma once
#include "Organism.h"
class Plant :
	public Organism
{
public:
	Plant(int Strength, World& WorldToLive);
	Plant(World& WorldToLive, std::fstream& in);
	Plant(int Strength, World& WorldToLive, Point P);
	virtual ~Plant();

	virtual int Act() override;
	virtual void Reproduce() override;
	virtual int Collide(Organism* AntoherOrganism) override;

protected:
	int ReproduceProbability;
};

