#pragma once
#include "Organism.h"

class Organism;

class OrganismQueue
{
public:
	OrganismQueue(int m, int n);
	~OrganismQueue();

	void Add(Organism* LivingOrganism);
	Organism* operator[](int i);
	void Sort();
	Organism* FindDead();

private:
	Organism** Organisms;
	int Size;
	int Count;
};

