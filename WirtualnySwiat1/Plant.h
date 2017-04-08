#pragma once
#include "Organism.h"
class Plant :
	public Organism
{
public:
	Plant(int Strength, World& WorldToLive);
	virtual ~Plant();

	virtual int Act() = 0;
	virtual int Draw() = 0;
};

