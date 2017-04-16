#pragma once
#include "Plant.h"
class SowThistle :
	public Plant
{
public:
	SowThistle(World& WorldToLive);
	SowThistle(World& WorldToLive, Point P);
	virtual ~SowThistle();
	int Draw() override;
	void Reproduce() override;
	std::string GetSpecies() override;
};

