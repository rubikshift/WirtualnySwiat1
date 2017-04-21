#pragma once
#include "Organism.h"
class Animal :
	public Organism
{
public:
	Animal(int Strength, int Initative, World& WorldToLive);
	Animal(int Initative, World& WorldToLive, std::fstream& in);
	Animal(int Strength, int Initative, World& WorldToLive, Point P);
	virtual ~Animal();

	virtual int Act();
	virtual int Collide(Organism* AnotherOrgansim) override;
	virtual void Reproduce() override;
protected:
	int MoveDistance;

};

