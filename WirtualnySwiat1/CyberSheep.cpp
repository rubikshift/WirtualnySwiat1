#include "CyberSheep.h"



CyberSheep::CyberSheep(World& WorldToLive) : Animal(11, 4, WorldToLive)
{
}


CyberSheep::~CyberSheep()
{
}

int CyberSheep::Draw()
{
	auto Map = this->WorldToLive.GetMap();
	Map[this->Position.GetX()][this->Position.GetY()] = CYBER_SHEEP;
	return 0;
}