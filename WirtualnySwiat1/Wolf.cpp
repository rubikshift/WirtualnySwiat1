#include "Wolf.h"



Wolf::Wolf(World& WorldToLive) : Animal(9, 5, WorldToLive)
{
}


Wolf::~Wolf()
{
}

int Wolf::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = WOLF;
	return 0;
}
