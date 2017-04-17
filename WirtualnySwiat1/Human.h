#pragma once
#include "Animal.h"
class Human :
	public Animal
{
public:
	Human(World& WorldToLive);
	virtual ~Human();
	int Draw() override;
	int Act();
	void Reproduce() override;
	std::string GetSpecies() override;
};

