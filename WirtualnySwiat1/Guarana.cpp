#include "Guarana.h"



Guarana::Guarana(World& WorldToLive) : Plant(0, WorldToLive)
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

std::string Guarana::GetSpecies()
{
	return "Guarana";
}
