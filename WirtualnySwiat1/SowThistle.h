#pragma once
#include "Plant.h"
class SowThistle :
	public Plant
{
public:
	SowThistle(World& WorldToLive);
	virtual ~SowThistle();
	int Draw() override;
	std::string GetSpecies() override;
};

