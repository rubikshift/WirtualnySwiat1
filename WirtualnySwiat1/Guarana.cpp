#include "Guarana.h"



Guarana::Guarana(World& WorldToLive) : Plant(0, WorldToLive)
{
}

Guarana::Guarana(World& WorldToLive, Point P) : Plant(0, WorldToLive, P)
{
}


Guarana::~Guarana()
{
}

int Guarana::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = GUARANA;
	return 0;
}

void Guarana::Reproduce()
{
	Point ChildPosition = this->GetChildPosition();
	if (ChildPosition != this->Position)
	{
		auto YoungGuarana = new Guarana(this->WorldToLive, ChildPosition);
		Plant::Reproduce();
	}
}

int Guarana::Collide(Organism * AnotherOrganism)
{
	AnotherOrganism->Buff(3);
	return 0;
}

std::string Guarana::GetSpecies()
{
	return "Guarana";
}
