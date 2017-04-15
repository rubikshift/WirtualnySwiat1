#pragma once
#include "Animal.h"
class CyberSheep :
	public Animal
{
public:
	CyberSheep(World& WorldToLive);
	virtual ~CyberSheep();
	int Draw() override;
	std::string GetSpecies() override;
};

