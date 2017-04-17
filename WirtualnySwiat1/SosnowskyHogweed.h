#pragma once
#include "Plant.h"
class SosnowskyHogweed :
	public Plant
{
public:
	SosnowskyHogweed(World& WorldToLive);
	SosnowskyHogweed(World& WorldToLive, Point P);
	virtual ~SosnowskyHogweed();
	int Draw() override;
	int Act() override;
	void Reproduce() override;
	int Collide(Organism* AnotherOrganism) override;
	std::string GetSpecies() override;
};

