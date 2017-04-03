#pragma once
#include <string>
#include <sstream>

#include "SolarSystem.h"
#include "AstronomicalObjectType.h"

class AstronomicalObject
{
private:
	SolarSystem solarSystem;
	unsigned position;
	double mass; // kg
	double radius; // meters
	AstronomicalObjectType type;
	std::string nickname = "";

public:
	AstronomicalObject(SolarSystem solarSystem, unsigned position, double mass, double radius, AstronomicalObjectType type, std::string nickname)
		: solarSystem(solarSystem), mass(mass), radius(radius), type(type), nickname(nickname)
	{
		this->SetPosition(position);
	}

	void SetPosition(unsigned position)
	{
		this->position = ValidatePosition(position);
	}

	void SetType(AstronomicalObjectType type)
	{
		if (this->type == AstronomicalObjectType::Unknown && type != AstronomicalObjectType::Unknown)
		{
			this->type = type;
		}
		else
		{
			throw "The astronomical object's type can ONLY change from unknown to star, rocky planet, or gas giant.";
		}
	}

	void ChangeSolarSystem(std::string solarName)
	{
		this->solarSystem.SetName(solarName);
	}

	std::string ToString() const
	{
		std::ostringstream output;

		std::string nicknameOutput = this->nickname.empty() ? " " : " (" + this->nickname + ") ";

		output << this->solarSystem.ToString() << "-" << this->position << nicknameOutput
			<< "{mass: " << this->mass << ", radius: " << this->radius << "}" << std::endl;
		output << "..............................";

		return output.str();
	}


private:
	unsigned ValidatePosition(unsigned position)
	{
		if (position <= 0)
		{
			throw "Invalid position.";
		}

		return position;
	}
};
