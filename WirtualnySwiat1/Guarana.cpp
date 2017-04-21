#include "Guarana.h"



Guarana::Guarana(World& WorldToLive) : Plant(0, WorldToLive)
{
	Type = GUARANA;
}

Guarana::Guarana(World & WorldToLive, std::fstream & in) : Plant(WorldToLive, in)
{
	Type = GUARANA;
}

Guarana::Guarana(World& WorldToLive, Point P) : Plant(0, WorldToLive, P)
{
	Type = GUARANA;
}


Guarana::~Guarana()
{
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
