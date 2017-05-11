#include "Point.h"

Point::Point(int x, int y)
	: X{ x }, Y{ y }
{
}

int Point::getX() const
{
	return this->X;
}

int Point::getY() const
{
	return this->Y;
}

bool operator<(const Point & point1, const Point & point2)
{
	return point1.getX() < point2.getX() 
		|| (point1.getX() == point2.getX() && point1.getY() < point2.getY());
}