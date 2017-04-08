#pragma once
#include "Organism.h"
class Animal :
	public Organism
{
public:
	Animal(int Strength, int Initative, World& WorldToLive);
	virtual ~Animal();

	virtual int Act() = 0;
	virtual int Collide(Organism* AnotherOrgansim) = 0;
	virtual int Draw() = 0;
private:

};

