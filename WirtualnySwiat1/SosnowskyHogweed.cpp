#include "SosnowskyHogweed.h"
#include "Animal.h"

#define SOSNOWSKY_HOGWEED_PROBABILTY 5

SosnowskyHogweed::SosnowskyHogweed(World& WorldToLive) : Plant(10, WorldToLive)
{
	this->ReproduceProbability = SOSNOWSKY_HOGWEED_PROBABILTY;
	Type = SOSNOWSKY_HOGWEED;
}

SosnowskyHogweed::SosnowskyHogweed(World & WorldToLive, std::fstream & in) : Plant(WorldToLive, in)
{
	this->ReproduceProbability = SOSNOWSKY_HOGWEED_PROBABILTY;
	Type = SOSNOWSKY_HOGWEED;
}

SosnowskyHogweed::SosnowskyHogweed(World& WorldToLive, Point P) : Plant(10, WorldToLive, P)
{
	this->ReproduceProbability = SOSNOWSKY_HOGWEED_PROBABILTY;
	Type = SOSNOWSKY_HOGWEED;
}


SosnowskyHogweed::~SosnowskyHogweed()
{
}

int SosnowskyHogweed::Act()
{
	Point P1 = { this->Position.GetX() + 1, this->Position.GetY() };
	Point P2 = { this->Position.GetX() - 1, this->Position.GetY() };
	Point P3 = { this->Position.GetX(), this->Position.GetY() + 1 };
	Point P4 = { this->Position.GetX(), this->Position.GetY() - 1 };

	Organism* O1 = this->WorldToLive.GetOrganismQueue()->Find(P1);
	Organism* O2 = this->WorldToLive.GetOrganismQueue()->Find(P2);
	Organism* O3 = this->WorldToLive.GetOrganismQueue()->Find(P3);
	Organism* O4 = this->WorldToLive.GetOrganismQueue()->Find(P4);

	if (O1 != nullptr && dynamic_cast<Animal*>(O1))
		this->Kill(O1);
	if (O2 != nullptr && dynamic_cast<Animal*>(O2))
		this->Kill(O2);
	if (O3 != nullptr && dynamic_cast<Animal*>(O3))
		this->Kill(O3);
	if (O4 != nullptr && dynamic_cast<Animal*>(O4))
		this->Kill(O4);

	Plant::Act();
	return 0;
}

void SosnowskyHogweed::Reproduce()
{
	Point ChildPosition = this->GetChildPosition();
	if (ChildPosition != this->Position)
	{
		auto YoungSosnowskyHogweed = new SosnowskyHogweed(this->WorldToLive, ChildPosition);
		Plant::Reproduce();
	}
}

int SosnowskyHogweed::Collide(Organism * AnotherOrganism)
{
	this->Kill(AnotherOrganism);
	return 0;
}

std::string SosnowskyHogweed::GetSpecies()
{
	return "Barszcz Sosnowskiego";
}
