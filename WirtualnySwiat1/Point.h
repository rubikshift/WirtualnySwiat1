#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
private:
	int x;
	int y;
};

