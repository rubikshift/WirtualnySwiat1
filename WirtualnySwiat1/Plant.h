#pragma once
#include "Organism.h"
class Plant :
	public Organism
{
public:
	Plant(int Strength, World& WorldToLive);
	virtual ~Plant();
};

