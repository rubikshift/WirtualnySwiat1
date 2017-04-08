#pragma once
#include "World.h"
#include "Point.h"

class World;

class Organism
{
public:
	Organism(int Strength, int Initative, World& WorldToLive);
	virtual ~Organism();

	virtual int Act() = 0;
	virtual int Collide(Organism* AnotherOrgansim) = 0;
	virtual int Draw() = 0;
	virtual int GetStrength() const;
	virtual int GetInitative() const;
	virtual int GetAge() const;
	virtual bool IsDead();

protected:
	int Strength;
	int Initative;
	int Age;
	bool isDead;
	Point Position;
	World& WorldToLive;	
	virtual void Die();
	virtual void Kill(Organism* AnotherOrganism);
};

