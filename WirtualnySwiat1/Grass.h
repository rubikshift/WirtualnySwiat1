#pragma once
#include "Plant.h"
class Grass :
	public Plant
{
public:
	Grass(World& WorldToLive);
	virtual ~Grass();
};

