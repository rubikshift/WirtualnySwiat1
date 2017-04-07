#pragma once
class Organism
{
public:
	Organism();
	~Organism();
protected:
	int Strength;
	int Initative;
	Point position;
	World wolrd;
};

