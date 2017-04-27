#pragma once
#include <string>
#include "Vector2D.h"

class Town
{
private:
	std::string name;
	Vector2D position;
public:
	Town()
		: name(""), position(0, 0)
	{}

	Town(std::string name, Vector2D position)
		: name{ name }, position(position)
	{}

	std::string getName() const
	{
		return this->name;
	}

	Vector2D getPosition() const
	{
		return this->position;
	}
};
