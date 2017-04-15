#pragma once
#include <string>
#include "World.h"
#include "Point.h"

class World;

class Organism
{
public:
	Organism(int Strength, int Initative, World& WorldToLive);
	Organism(int Strength, int Initative, World& WorldToLive, Point P);
	virtual ~Organism();

	virtual int Act() = 0;
	virtual int Collide(Organism* AnotherOrgansim) = 0;
	virtual int Draw() = 0;
	virtual int GetStrength() const;
	virtual int GetInitative() const;
	virtual int GetAge() const;
	virtual Point GetPosition() const;
	virtual bool IsDead() const;
	virtual void GetOlder();
	virtual void Reproduce() = 0;
	virtual void Fight(Organism* Enemy);
	virtual bool DeflectedAttack(Organism* Enemy);
	virtual void Eat(Organism* SomePlant);
	virtual std::string GetSpecies() = 0;
	
protected:
	int Strength;
	int Initative;
	int Age;
	bool isDead;
	Point Position;
	World& WorldToLive;	
	virtual void Die();
	virtual void Kill(Organism* AnotherOrganism);
	virtual Point GetChildPosition();
};

