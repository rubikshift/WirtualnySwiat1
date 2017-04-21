#include "SowThistle.h"



SowThistle::SowThistle(World& WorldToLive) : Plant(0, WorldToLive)
{
	Type = SOW_THISTLE;
}

SowThistle::SowThistle(World & WorldToLive, std::fstream & in) : Plant(WorldToLive, in)
{
	Type = SOW_THISTLE;
}

SowThistle::SowThistle(World& WorldToLive, Point P) : Plant(0, WorldToLive, P)
{
	Type = SOW_THISTLE;
}


SowThistle::~SowThistle()
{
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
