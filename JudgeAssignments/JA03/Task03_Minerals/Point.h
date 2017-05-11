#pragma once

class Point
{
private:
	int X;
	int Y;

public:
	Point(int X, int Y);

	int getX() const;
	int getY() const;
	
};

bool operator<(const Point& point1, const Point& point2);