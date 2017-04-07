#pragma once
class Point
{
public:
	Point();
	virtual ~Point();
	int GetX() const;
	int GetY() const;
private:
	int x;
	int y;
};

