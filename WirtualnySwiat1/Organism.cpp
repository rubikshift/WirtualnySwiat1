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
		this->Kill(Enemy);
	else
		Enemy->Kill(this);
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

	Point P1 = { this->Position.GetX() + 1, this->Position.GetY() };
	Point P2 = { this->Position.GetX() - 1, this->Position.GetY() };
	Point P3 = { this->Position.GetX(), this->Position.GetY() + 1 };
	Point P4 = { this->Position.GetX(), this->Position.GetY() - 1 };

	Organism* O1 = this->WorldToLive.GetOrganismQueue()->Find(P1);
	Organism* O2 = this->WorldToLive.GetOrganismQueue()->Find(P2);
	Organism* O3 = this->WorldToLive.GetOrganismQueue()->Find(P3);
	Organism* O4 = this->WorldToLive.GetOrganismQueue()->Find(P4);

	if (!this->WorldToLive.IsEmptyNear(this->Position))
		return this->Position;
	while(!isSet)
	{

		dir = random.RandomDirection();
		switch (dir)
		{
			case LEFT:
				if (P2.GetX() >= 0)
				{
					ChildPosition = P2;
					if (O2 == nullptr)
						isSet = true;
				}
				break;
			case RIGHT:
				if(P1.GetX()< this->WorldToLive.GetWidth())
				{

					ChildPosition = P1;
					if (O1 == nullptr)
						isSet = true;
				}
				break;
			case UP:
				if(P4.GetY() >= 0)
				{
					ChildPosition = P4;
					if (O4 == nullptr)
						isSet = true;
				}
				break;
			case DOWN:
				if (P3.GetY() < this->WorldToLive.GetHeight())
				{
					ChildPosition = P3;
					if (O3 == nullptr)
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
	this->WorldToLive.AddLog(this->GetSpecies() + " zabija " + AnotherOrganism->GetSpecies());
	AnotherOrganism->Die();
}
