#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	virtual ~Point();
	int GetX() const;
	int GetY() const;
private:
	int x;
	int y;
};

