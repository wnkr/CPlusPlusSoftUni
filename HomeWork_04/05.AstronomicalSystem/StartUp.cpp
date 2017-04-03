#include <iostream>
#include <vector>

#include "AstronomicalObject.h"
#include "SolarSystem.h"
#include "SolarSystemFileManipulator.h"
#include "AstronomicalObjectFileManipulator.h"

using namespace std;

vector<AstronomicalObject> astroObjects;
vector<SolarSystem> solarSystems;

void PrintAstroObjects()
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

void PrintSolarSystems()
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
	cin >> name;

	SolarSystem solarSystem(name);

	return solarSystem;
}

int GetProperSolarSystemIndex(string message)
{
	PrintSolarSystems();

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

bool PrintMenu()
{
	int myChoice = 0;

	std::cout << "********** Main Menu **********" << std::endl;
	std::cout << "(1): Create new solar system" << std::endl;
	std::cout << "(2): Create new astronomical object" << std::endl;
	std::cout << "(3): List all solar systems" << std::endl;
	std::cout << "(4): List all astronomical objects" << std::endl;
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
			PrintSolarSystems();
			break;
		case 4:
			PrintAstroObjects();
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