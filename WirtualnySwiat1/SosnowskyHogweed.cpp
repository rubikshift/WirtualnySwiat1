#include "SosnowskyHogweed.h"



SosnowskyHogweed::SosnowskyHogweed(World& WorldToLive) : Plant(10, WorldToLive)
{
}


SosnowskyHogweed::~SosnowskyHogweed()
{
}

int SosnowskyHogweed::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = SOSNOWSKY_HOGWEED;
	return 0;
}

std::string SosnowskyHogweed::GetSpecies()
{
	return "Barszcz Sosnowskiego";
}
