#pragma once
#include "Organism.h"

class Organism;

class Node
{
public:
	Node();
	~Node();
	Node* GetNext();
	Organism* GetOrganism();
private:
	Organism* LivingOrganism;
	Node* Next;
};

