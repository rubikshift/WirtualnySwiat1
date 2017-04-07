#pragma once
#include "Animal.h"
class Sheep :
	public Animal
{
public:
	Sheep(World& WorldToLive);
	virtual ~Sheep();
	int Draw() override;
};

