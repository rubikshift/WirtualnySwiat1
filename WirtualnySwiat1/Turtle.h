#pragma once
#include "Animal.h"
class Turtle :
	public Animal
{
public:
	Turtle(World& WorldToLive);
	virtual ~Turtle();
	int Draw() override;
};

