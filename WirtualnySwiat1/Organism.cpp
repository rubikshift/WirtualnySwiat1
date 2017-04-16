#include "Organism.h"
#include "MyRandom.h"


Organism::Organism(int Strength, int Initative, World& WorldToLive) : WorldToLive(WorldToLive)
{
	this->Strength = Strength;
	this->Initative = Initative;
	Age = 0;
	isDead = false;
	isTurnAllowed = false;
	MyRandom random;
	bool ok = false;
	while (!ok)
	{
		this->Position.SetX(random.RandomInt(0, this->WorldToLive.GetWidth() - 1));
		this->Position.SetY(random.RandomInt(0, this->WorldToLive.GetHeight() - 1));
		if (this->WorldToLive.GetOrganismQueue()->Find(this->Position) == nullptr)
			ok = true;
	}
	this->WorldToLive.AddOrganismToWorld(this);
	
}

Organism::Organism(int Strength, int Initative, World & WorldToLive, Point P) : WorldToLive(WorldToLive)
{
	this->Strength = Strength;
	this->Initative = Initative;
	Age = 0;
	isDead = false;
	isTurnAllowed = false;
	this->Position = P;
	this->WorldToLive.AddOrganismToWorld(this);
}


Organism::~Organism()
{
}

int Organism::GetStrength() const
{
	return this->Strength;
}

int Organism::GetInitative() const
{
	return this->Initative;
}

int Organism::GetAge() const
{
	return this->Age;
}

Point Organism::GetPosition() const
{
	return this->Position;
}

void Organism::GetOlder()
{
	this->Age++;
}

void Organism::Fight(Organism * Enemy)
{
	this->WorldToLive.AddLog(this->GetSpecies() + " walczy z " + Enemy->GetSpecies());
	if (this->Strength >= Enemy->GetStrength())
	{
		this->WorldToLive.AddLog(this->GetSpecies() + " zabija " + Enemy->GetSpecies());
		Enemy->Die();
	}
	else
	{
		this->WorldToLive.AddLog(Enemy->GetSpecies() + " zabija " + this->GetSpecies());
		this->Die();
	}
}

bool Organism::DeflectedAttack(Organism * Enemy)
{
	return false;
}

bool Organism::RunAway(Organism* Enemy)
{
	return false;
}

void Organism::Eat(Organism * SomePlant)
{
	this->WorldToLive.AddLog(this->GetSpecies() + " zjada " + SomePlant->GetSpecies());
	SomePlant->Collide(this);
	SomePlant->Die();
}

Point Organism::GetChildPosition()
{
	MyRandom random;
	Direction dir;
	Point ChildPosition;
	bool isSet = false;
	if (!this->WorldToLive.IsEmptyNear(this->Position))
		return this->Position;
	while(!isSet)
	{

		dir = random.RandomDirection();
		switch (dir)
		{
			case LEFT:
				if (this->Position.GetX() - 1 >= 0)
				{
					ChildPosition = { this->Position.GetX() - 1, this->Position.GetY() };
					if (this->WorldToLive.GetOrganismQueue()->Find(ChildPosition) == nullptr)
						isSet = true;
				}
				break;
			case RIGHT:
				if(this->Position.GetX() + 1 < this->WorldToLive.GetWidth())
				{

					ChildPosition = {this->Position.GetX() + 1, this->Position.GetY()};
					if (this->WorldToLive.GetOrganismQueue()->Find(ChildPosition) == nullptr)
						isSet = true;
				}
				break;
			case UP:
				if(this->Position.GetY() - 1 >= 0)
				{
					ChildPosition = {this->Position.GetX(), this->Position.GetY() - 1 };
					if (this->WorldToLive.GetOrganismQueue()->Find(ChildPosition) == nullptr)
						isSet = true;
				}
				break;
			case DOWN:
				if (this->Position.GetY() + 1 < this->WorldToLive.GetHeight())
				{
					ChildPosition = { this->Position.GetX(), this->Position.GetY() + 1 };
					if (this->WorldToLive.GetOrganismQueue()->Find(ChildPosition) == nullptr)
						isSet = true;
				}
				break;
		}
	}
	return ChildPosition;
}

void Organism::Die()
{
	this->isDead = true;
}

bool Organism::IsDead() const
{
	return isDead;
}

bool Organism::IsTurnAllowed() const
{
	return this->isTurnAllowed;
}

void Organism::AllowMakingTurn()
{
	this->isTurnAllowed = true;
}

void Organism::Kill(Organism * AnotherOrganism)
{
	AnotherOrganism->Die();
}
