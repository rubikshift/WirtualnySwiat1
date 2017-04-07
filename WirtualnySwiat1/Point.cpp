#include "Point.h"



Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::~Point()
{
}

int Point::GetX() const
{
	return this->x;
}

int Point::GetY() const
{
	return this->y;
}
