#pragma once
#include "Organism.h"
#include "Point.h"

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
	Organism* Find(Point P);

private:
	Organism** Organisms;
	int Size;
	int Count;
};

