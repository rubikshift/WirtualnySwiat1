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
	int GetDeadCount();
	Organism* Find(Point P);
	int GetCount() const;

private:
	int FindDead();
	Organism** Organisms;
	int Size;
	int Count;
};

