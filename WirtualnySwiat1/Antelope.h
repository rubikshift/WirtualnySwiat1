#pragma once
#include "Animal.h"
class Antelope :
	public Animal
{
public:
	Antelope(World& WorldToLive);
	virtual ~Antelope();
	int Draw() override;
};

