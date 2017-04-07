#pragma once
#include "Animal.h"
class Wolf :
	public Animal
{
public:
	Wolf(World& WorldToLive);
	virtual ~Wolf();
};

