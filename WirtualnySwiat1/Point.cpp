#include "Point.h"



Point::Point()
{
	x = 0;
	y = 0;
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
