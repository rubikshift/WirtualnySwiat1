#pragma once
#include "Animal.h"
class CyberSheep :
	public Animal
{
public:
	CyberSheep(World& WorldToLive);
	virtual ~CyberSheep();
	std::string GetSpecies() override;
};

