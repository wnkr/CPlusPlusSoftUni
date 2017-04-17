#pragma once
#include <ostream>

enum class AstronomicalObjectType
{
	Star,
	RockyPlanet,
	GasGiant,
	Unknown
};

std::ostream& operator<<(std::ostream& os, const AstronomicalObjectType& planet)
{
	os << static_cast<std::underlying_type<AstronomicalObjectType>::type>(planet);
	return os;
}