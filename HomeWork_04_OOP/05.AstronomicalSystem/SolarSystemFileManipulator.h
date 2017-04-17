#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "SolarSystem.h"
#include "StringSplitter.h"

class SolarSystemFileManipulator
{
private:
	static const std::string FILENAME;
	static const char DELIMETER = ':';

public:
	static bool Write(const std::vector<SolarSystem>& solarSystems)
	{
		std::ofstream outStream(FILENAME);

		if (outStream.is_open())
		{
			for (const auto& system : solarSystems)
			{
				outStream << system.GetName() << DELIMETER << std::endl;
			}

			outStream.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	static bool Read(std::vector<SolarSystem>& solarSystems)
	{
		std::ifstream inStream(FILENAME);

		if (inStream.is_open())
		{
			solarSystems.clear();

			std::vector<std::string> parsedSystem;
			std::string line;
			while (getline(inStream, line))
			{
				parsedSystem = StringSplitter::split(line, DELIMETER);

				SolarSystem person(parsedSystem[0]);

				solarSystems.push_back(person);
			};

			inStream.close();
			return true;
		}
		else
		{
			return false;
		}
	}
	
};

const std::string SolarSystemFileManipulator::FILENAME = "solarsystems.txt";