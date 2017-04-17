#include "Fraction.h"

Fraction::Fraction()
	: nominator(0), denominator(0)
{}

Fraction::Fraction(int nominator, int denominator)
	: nominator(nominator), denominator(denominator)
{}

//Fraction Fraction::operator+(const Fraction& other)
//{
//	int commonDenom = this->denominator * other.denominator;
//	int newNominator = this->nominator * other.denominator + other.nominator * this->denominator;
//
//	return Fraction(newNominator, commonDenom);
//}

Fraction operator+(const Fraction& a, const Fraction& b)
{
	int commonDenom = a.denominator * b.denominator;
	int newNomiantor = a.nominator * b.denominator + b.nominator * a.denominator;

	return Fraction(newNomiantor, commonDenom);
}


std::ostream& operator<<(std::ostream& stream, const Fraction& f)
{
	stream << f.nominator << "/" << f.denominator;
	return stream;
}

std::istream& operator>>(std::istream& stream, Fraction& f)
{
	char slash;
	stream >> f.nominator >> slash >> f.denominator;
	return stream;
}

Fraction& Fraction::operator++()
{
	(*this) = *this + Fraction(1, 1);
	return  *this;
}

Fraction Fraction::operator++(int)
{
	Fraction oldValue = (*this);
	++(*this);
	return oldValue;
}