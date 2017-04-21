#pragma once
#include "Plant.h"
class SowThistle :
	public Plant
{
public:
	SowThistle(World& WorldToLive);
	SowThistle(World& WorldToLive, std::fstream& in);
	SowThistle(World& WorldToLive, Point P);
	virtual ~SowThistle();
	void Reproduce() override;
	std::string GetSpecies() override;
};

