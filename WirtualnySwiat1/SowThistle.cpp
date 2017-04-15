#include "SowThistle.h"



SowThistle::SowThistle(World& WorldToLive) : Plant(0, WorldToLive)
{
}


SowThistle::~SowThistle()
{
}

int SowThistle::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = SOW_THISTLE;
	return 0;
}

std::string SowThistle::GetSpecies()
{
	return "Mlecz";
}
