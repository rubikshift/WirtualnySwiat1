#pragma once
#include "Plant.h"
class SosnowskyHogweed :
	public Plant
{
public:
	SosnowskyHogweed(World& WorldToLive);
	virtual ~SosnowskyHogweed();
	int Draw() override;
	std::string GetSpecies() override;
};

