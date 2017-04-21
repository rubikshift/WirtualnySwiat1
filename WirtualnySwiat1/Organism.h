#pragma once
#include <string>
#include <fstream>
#include "World.h"
#include "Point.h"
#include "WorldField.h"
class World;

class Organism
{
public:
	Organism(int Strength, int Initative, World& WorldToLive);
	Organism(int Initative, World& WorldToLive, std::fstream& in);
	Organism(int Strength, int Initative, World& WorldToLive, Point P);
	virtual ~Organism();

	virtual int Act() = 0;
	virtual int Collide(Organism* AnotherOrgansim) = 0;
	virtual int Draw();
	virtual int GetStrength() const;
	virtual int GetInitative() const;
	virtual int GetAge() const;
	virtual Point GetPosition() const;
	virtual bool IsDead() const;
	virtual bool IsTurnAllowed() const;
	virtual void AllowMakingTurn();
	virtual void GetOlder();
	virtual void Reproduce() = 0;
	virtual void Fight(Organism* Enemy);
	virtual bool DeflectedAttack(Organism* Enemy);
	virtual bool RunAway(Organism* Enemy);
	virtual void Eat(Organism* SomePlant);
	virtual void Buff(int NewStrength);
	virtual std::string GetSpecies() = 0;
	virtual void Save(std::fstream& out);
	
protected:
	int Strength;
	int Initative;
	int Age;
	bool isDead;
	bool isTurnAllowed;
	Point Position;
	World& WorldToLive;
	WorldField Type;
	virtual void Die();
	virtual void Kill(Organism* AnotherOrganism);
	virtual Point GetChildPosition();
};

