#pragma once
#include <ostream>
#include <istream>

class Fraction
{
protected:
	int nominator;
	int denominator;
public:
	Fraction();
	Fraction(int nominator, int denominator);

	// Fraction operator+(const Fraction& other);
	friend Fraction operator+(const Fraction& a, const Fraction& b);

	friend std::ostream& operator << (std::ostream& stream, const Fraction& f);
	friend std::istream& operator >> (std::istream& stream, Fraction& f);

	Fraction& operator++();
	Fraction operator++(int);
};