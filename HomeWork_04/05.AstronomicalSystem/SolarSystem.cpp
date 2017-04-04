#include "SolarSystem.h"

using namespace std;

SolarSystem::SolarSystem(string name)
{
	this->SetName(name);
}

string SolarSystem::GetName() const
{
	return this->name;
}

void SolarSystem::SetName(string name)
{
	this->name = ValidateName(name);
}

string SolarSystem::ToString() const
{
	std::ostringstream output;

	output << this->GetName();

	return output.str();
}

bool SolarSystem::operator==(const SolarSystem& other)
{
	return this->name == other.name;
}

bool SolarSystem::operator!=(const SolarSystem& other)
{
	return !(*this == other);
}

string SolarSystem::ValidateName(string name)
{
	if (name.empty())
	{
		throw "Solar system's name cannot be empty.";
	}

	return name;
}