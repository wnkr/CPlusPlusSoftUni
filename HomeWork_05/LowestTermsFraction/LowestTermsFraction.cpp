#include "LowestTermsFraction.h"

static int greatestCommonDivisor(const int &a, const int &b) {
	int divisorCand = a < b ? a : b;

	// NOTE: there is a better algorithm for gcd, but we're trying to keep things simple
	while ((a % divisorCand != 0) || (b % divisorCand != 0)) {
		divisorCand--;
	}

	return divisorCand;
}

static int leastCommonMultiple(const int &a, const int &b) {
	return (a * b) / greatestCommonDivisor(a, b);
}

LowestTermsFraction::LowestTermsFraction() {}

LowestTermsFraction::LowestTermsFraction(int nominator, int denominator)
	: Fraction(nominator / greatestCommonDivisor(nominator, denominator),
			   denominator / greatestCommonDivisor(nominator, denominator))
{}

LowestTermsFraction operator+(const LowestTermsFraction& a, const LowestTermsFraction& b)
{
	int lcm = leastCommonMultiple(a.denominator, b.denominator);

	return LowestTermsFraction(a.nominator * (lcm / a.denominator) + b.nominator * (lcm / b.denominator), lcm);
}

LowestTermsFraction LowestTermsFraction::operator*(const int& number)
{
	return LowestTermsFraction(this->nominator * number, denominator);
}

LowestTermsFraction& LowestTermsFraction::operator*=(const int& number)
{
	(*this) = (*this) * number;
	return *this;
}

LowestTermsFraction LowestTermsFraction::operator*(const LowestTermsFraction& other)
{
	return LowestTermsFraction(this->nominator * other.nominator, this->denominator * other.denominator);
}

LowestTermsFraction& LowestTermsFraction::operator*=(const LowestTermsFraction& other)
{
	(*this) = (*this) * other;
	return *this;
}

LowestTermsFraction LowestTermsFraction::operator/(const int& number)
{
	return (*this) * LowestTermsFraction(1, number);
}

LowestTermsFraction& LowestTermsFraction::operator/=(const int& number)
{
	(*this) = (*this) / number;
	return *this;
}

LowestTermsFraction LowestTermsFraction::operator/(const LowestTermsFraction& other)
{
	return (*this) * LowestTermsFraction(other.denominator, other.nominator);
}

LowestTermsFraction& LowestTermsFraction::operator/=(const LowestTermsFraction& other)
{
	(*this) = (*this) / other;
	return *this;
}

LowestTermsFraction LowestTermsFraction::getReciprocal() const
{
	return LowestTermsFraction(this->denominator, this->nominator);
}









