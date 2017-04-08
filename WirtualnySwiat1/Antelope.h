#pragma once
#include "Animal.h"
class Antelope :
	public Animal
{
public:
	Antelope(World& WorldToLive);
	virtual ~Antelope();
	int Draw() override;
	int Act() override;
	int Collide(Organism* AnotherOrgansim) override;
};

