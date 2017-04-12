#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	Point(const Point& P);
	~Point();
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
	void operator=(Point P);
	bool operator==(Point P);
private:
	int x;
	int y;
};

