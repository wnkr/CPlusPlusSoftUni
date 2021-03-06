#include <iostream>
#include <vector>

#include "AstronomicalObject.h"
#include "SolarSystem.h"
#include "SolarSystemFileManipulator.h"
#include "AstronomicalObjectFileManipulator.h"

using namespace std;

vector<AstronomicalObject> astroObjects;
vector<SolarSystem> solarSystems;

void PrintAstroObjects(const vector<AstronomicalObject>& astroObjects)
{
	if (astroObjects.empty())
	{
		cout << "There are no astronomical objects." << endl;
	}
	else
	{
		for (const auto& astroObj : astroObjects)
		{
			cout << astroObj.ToString() << endl;
		}
	}
}

void PrintSolarSystems(const vector<SolarSystem>& solarSystem)
{
	if (solarSystems.empty())
	{
		cout << "There are no solar systems." << endl;
	}
	else
	{
		for (const auto& solarSystem : solarSystems)
		{
			cout << solarSystem.ToString() << endl;
		}
	}
}

SolarSystem CreateSolarSystem()
{
	cout << "Enter a name: ";
	string name;

	cin.ignore();
	getline(cin, name);

	SolarSystem solarSystem(name);

	return solarSystem;
}

int GetProperSolarSystemIndex(string message)
{
	PrintSolarSystems(solarSystems);

	cout << message;
	string solarName;

	while (cin >> solarName)
	{
		for (size_t i = 0; i < solarSystems.size(); i++)
		{
			if (solarName == solarSystems[i].GetName())
			{
				return i;
			}
		}

		cout << "There are not any solar systems with that name in the database. Try again: ";
	}
}

AstronomicalObject CreateAstroObject()
{
	if (solarSystems.empty())
	{
		throw "First create some solar systems.";
	}

	int foundSolarSystemIndex = GetProperSolarSystemIndex("Enter the name of the solar system your object is part of: ");
	SolarSystem solarSystem = solarSystems[foundSolarSystemIndex];

	cout << "Enter the type of the object(star(0), rocky planet(1), gas giant(2), or left it unknown(3)): ";
	int typeInput;
	cin >> typeInput;
	AstronomicalObjectType type = (AstronomicalObjectType)typeInput;

	unsigned position;
	cout << "Enter the position of the object in the system(always 1 for objects of type Star): ";
	cin >> position;

	cout << "Enter the mass of the object: ";
	double mass;
	cin >> mass;

	cout << "Enter the radius of the object: ";
	double radius;
	cin >> radius;

	cin.ignore();
	cout << "Enter nickname for the object(optional): ";
	string nickname;
	getline(cin, nickname);

	AstronomicalObject astroObject(solarSystem, position, mass, radius, type, nickname);

	return astroObject;
}


vector<AstronomicalObject> FindAllPlanetsInSystem(const SolarSystem& solarSystem)
{
	vector<AstronomicalObject> objects;

	for (const auto& astroObject : astroObjects)
	{
		if (astroObject.GetSolarSystem() == solarSystem)
		{
			objects.push_back(astroObject);
		}
	}

	return objects;
}

SolarSystem& GetProperSolarSystem(string message)
{
	PrintSolarSystems(solarSystems);

	cout << message;
	string solarSystemName;

	cin.ignore();
	while (getline(cin, solarSystemName))
	{
		for (size_t i = 0; i < solarSystems.size(); i++)
		{
			if (solarSystemName == solarSystems[i].GetName())
			{
				return solarSystems[i];
			}
		}

		cout << "The entered solar system name is not in the database. Enter new one:" << endl;
	}
}

void SearchForSolarSystem()
{
	SolarSystem solarSystem = GetProperSolarSystem("Enter the solar system you want to list all planets: ");

	auto planets = FindAllPlanetsInSystem(solarSystem);

	cout << "All planets int the " << solarSystem.GetName() << " system:" << endl;
	PrintAstroObjects(planets);
}

int FindPlanet(const vector<AstronomicalObject>& planets, int position)
{
	int foundIndex = -1;
	for (rsize_t i = 0; i < planets.size(); i++)
	{
		if (planets[i].GetPosition() == position)
		{
			foundIndex = i;
		}
	}

	return foundIndex;
}

void SearchForPlanet()
{
	SolarSystem solarSystem = GetProperSolarSystem("Enter the solar system your planet is part of: ");
	auto planets = FindAllPlanetsInSystem(solarSystem);

	cout << "Enter the position of the planet in the solar system: ";
	int position;
	cin >> position;

	int foundPlanetIndex = FindPlanet(planets, position);
	if (foundPlanetIndex != -1)
	{
		cout << "The planet is found:" << endl;
		cout << planets[foundPlanetIndex].ToString() << endl;
	}
	else
	{
		cout << "The planet with position " << position << " is not found." << endl;;
	}
}

bool PrintMenu()
{
	int myChoice = 0;

	std::cout << "********** Main Menu **********" << std::endl;
	std::cout << "(1): Create new solar system" << std::endl;
	std::cout << "(2): Create new astronomical object" << std::endl;
	std::cout << "(3): List all solar systems" << std::endl;
	std::cout << "(4): List all astronomical objects" << std::endl;
	std::cout << "(5): List all planets in a star system" << std::endl;
	std::cout << "(6): Find a planet with a name and a position" << std::endl;
	std::cout << "(0): Exit" << std::endl;

	if (std::cin >> myChoice)
	{
		switch (myChoice)
		{
		case 0:
			return false;
		case 1:
		{
			SolarSystem solarSystem = CreateSolarSystem();
			solarSystems.push_back(solarSystem);
			SolarSystemFileManipulator::Write(solarSystems);
			break;
		}
		case 2:
		{
			AstronomicalObject owner = CreateAstroObject();
			astroObjects.push_back(owner);
			AstronomicalObjectFileManipulator::Write(astroObjects);
			break;
		}
		case 3:
			PrintSolarSystems(solarSystems);
			break;
		case 4:
			PrintAstroObjects(astroObjects);
			break;
		case 5:
			SearchForSolarSystem();
			break;
		case 6:
			SearchForPlanet();
			break;
		default:
			std::cout << "ERROR! You have selected an invalid choice." << std::endl;
			break;
		}
	}
	else
	{
		std::cout << "ERROR! You have entered a non numeric choice." << endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	cout << "SUCCESS!" << endl;
	return true;
}

void LoadInfo()
{
	solarSystems.clear();
	astroObjects.clear();
	SolarSystemFileManipulator::Read(solarSystems);
	AstronomicalObjectFileManipulator::Read(astroObjects);
}

int main()
{
	LoadInfo();

	while (PrintMenu())
	{
	}

	return 0;
}