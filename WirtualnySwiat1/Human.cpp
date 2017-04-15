#include "Human.h"



Human::Human(World& WorldToLive) : Animal(5, 4, WorldToLive)
{
}


Human::~Human()
{
}

int Human::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = HUMAN;
	return 0;
}

std::string Human::GetSpecies()
{
	return "Czlowiek";
}
