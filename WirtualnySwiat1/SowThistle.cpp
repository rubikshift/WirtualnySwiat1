#include "SowThistle.h"



SowThistle::SowThistle(World& WorldToLive) : Plant(0, WorldToLive)
{
}

SowThistle::SowThistle(World& WorldToLive, Point P) : Plant(0, WorldToLive, P)
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

void SowThistle::Reproduce()
{
	Point ChildPosition = this->GetChildPosition();
	if (ChildPosition != this->Position)
	{
		auto YoungSowThistle = new SowThistle(this->WorldToLive, ChildPosition);
		Plant::Reproduce();
	}
}

std::string SowThistle::GetSpecies()
{
	return "Mlecz";
}
