#pragma once
#include "Plant.h"
class Grass :
	public Plant
{
public:
	Grass(World& WorldToLive);
	Grass(World& WorldToLive, Point P);
	virtual ~Grass();
	int Draw() override;
	int Act() override;
	void Reproduce() override;
	std::string GetSpecies() override;
};

