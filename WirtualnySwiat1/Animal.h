#pragma once
#include "Organism.h"
class Animal :
	public Organism
{
public:
	Animal(int Strength, int Initative, World& WorldToLive);
	Animal(int Strength, int Initative, World& WorldToLive, Point P);
	virtual ~Animal();

	virtual int Act();
	virtual int Collide(Organism* AnotherOrgansim) override;
	virtual int Draw() = 0;
	virtual void Reproduce() override;
protected:
	int MoveDistance;

};

