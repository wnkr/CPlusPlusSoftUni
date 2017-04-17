#pragma once
#include <string>
#include <sstream>

class SolarSystem
{
private:
	std::string name;

public:
	SolarSystem() {}
	SolarSystem(std::string name);

	std::string GetName() const;
	void SetName(std::string name);

	std::string ToString() const;

	bool operator==(const SolarSystem& other);

	bool operator!=(const SolarSystem& other);

private:
	static std::string ValidateName(std::string name);
};
