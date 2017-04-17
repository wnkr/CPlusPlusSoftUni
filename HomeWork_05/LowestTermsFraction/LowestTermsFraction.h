#pragma once
#include "Fraction.h"

class LowestTermsFraction : public Fraction
{
public:
	LowestTermsFraction();
	LowestTermsFraction(int nominator, int denominator);

	friend LowestTermsFraction operator+(const LowestTermsFraction& a, const LowestTermsFraction& b);

	LowestTermsFraction operator*(const int& number);
	LowestTermsFraction& operator*=(const int& number);

	LowestTermsFraction operator*(const LowestTermsFraction& other);
	LowestTermsFraction& operator*=(const LowestTermsFraction& other);

	LowestTermsFraction operator/(const int& number);
	LowestTermsFraction& operator/=(const int& number);

	LowestTermsFraction operator/(const LowestTermsFraction& other);
	LowestTermsFraction& operator/=(const LowestTermsFraction& other);

	LowestTermsFraction getReciprocal() const;
};