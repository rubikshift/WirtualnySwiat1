#include "CyberSheep.h"



CyberSheep::CyberSheep(World& WorldToLive) : Animal(11, 4, WorldToLive)
{
	Type = CYBER_SHEEP;
}


CyberSheep::~CyberSheep()
{
}

std::string CyberSheep::GetSpecies()
{
	return "Cyber owca";
}
