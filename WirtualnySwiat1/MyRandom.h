#pragma once
#include <random>
#include "Direction.h"
class MyRandom
{
public:
	MyRandom();
	~MyRandom();
	Direction RandomDirection();
	int RandomInt(int a, int b);
private:
	std::random_device rd;
	std::mt19937 gen;
};

