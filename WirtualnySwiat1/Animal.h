#pragma once
#include "Organism.h"
class Animal :
	public Organism
{
public:
	Animal(int Strength, int Initative, World& WorldToLive);
	virtual ~Animal();
};

