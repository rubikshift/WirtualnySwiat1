#pragma once
#include "Plant.h"
class Guarana :
	public Plant
{
public:
	Guarana(World& WorldToLive);
	virtual ~Guarana();
	int Draw() override;
};
