#pragma once
#include "Node.h"

class Node;

class OrganismQueue
{
public:
	OrganismQueue();
	~OrganismQueue();

private:
	Node* First;
};

