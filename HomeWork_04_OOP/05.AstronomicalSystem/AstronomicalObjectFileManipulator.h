#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "AstronomicalObject.h"
#include "StringSplitter.h"

class AstronomicalObjectFileManipulator
{
private:
	static const std::string FILENAME;
	static const char DELIMETER = ':';

public:
	static bool Write(const std::vector<AstronomicalObject>& astronomicalObjects)
	{
		std::ofstream outStream(FILENAME);

		if (outStream.is_open())
		{
			for (const auto& astroObject : astronomicalObjects)
			{
				outStream << astroObject.GetSolarSystem().GetName() << DELIMETER << astroObject.GetPosition() << DELIMETER
					<< astroObject.GetMass() << DELIMETER << astroObject.GetRadius() << DELIMETER
					<< astroObject.GetType() << DELIMETER << astroObject.GetNickname() << std::endl;
			}

			outStream.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	static bool Read(std::vector<AstronomicalObject>& astronomicalObjects)
	{
		std::ifstream inStream(FILENAME);

		if (inStream.is_open())
		{
			astronomicalObjects.clear();

			std::vector<std::string> parsedAstroObject;
			std::string line;
			while (getline(inStream, line))
			{
				parsedAstroObject = StringSplitter::split(line, DELIMETER);

				SolarSystem solarSystem(parsedAstroObject[0]);

				AstronomicalObject astroObject;
				if (parsedAstroObject.size() != 6)
				{
					 astroObject = AstronomicalObject(solarSystem, std::stoi(parsedAstroObject[1]), std::stod(parsedAstroObject[2]), std::stod(parsedAstroObject[3]),
						(AstronomicalObjectType)std::stoi(parsedAstroObject[4]), "");
				}
				else
				{
					astroObject = AstronomicalObject(solarSystem, std::stoi(parsedAstroObject[1]), std::stod(parsedAstroObject[2]), std::stod(parsedAstroObject[3]),
						(AstronomicalObjectType)std::stoi(parsedAstroObject[4]), parsedAstroObject[5]);
				}

				astronomicalObjects.push_back(astroObject);
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

const std::string AstronomicalObjectFileManipulator::FILENAME = "astronomicalobjects.txt";