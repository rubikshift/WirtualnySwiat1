#include "MyRandom.h"



MyRandom::MyRandom()
{
	gen = std::mt19937(rd());
}


MyRandom::~MyRandom()
{
}

Direction MyRandom::RandomDirection()
{
	std::uniform_int_distribution<> dis(0, 3);
	int x = dis(gen);
	return (Direction)x;
}

int MyRandom::RandomInt(int a, int b)
{
	std::uniform_int_distribution<> dis(a, b);
	return dis(gen);
}
