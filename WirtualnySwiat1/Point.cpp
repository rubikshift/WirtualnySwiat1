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

Point::Point(const Point& P)
{
	this->x = P.GetX();
	this->y = P.GetY();
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

void Point::SetX(int x)
{
	this->x = x;
}

void Point::SetY(int y)
{
	this->y = y;
}

void Point::operator=(Point P)
{
	this->x = P.GetX();
	this->y = P.GetY();
}

bool Point::operator==(Point P)
{
	return this->x == P.GetX() && this->y == P.GetY();
}

bool Point::operator!=(Point P)
{
	return !(*this == P);
}
