#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "CarRegistration.h"

class CarRegistrationFileManipulator
{
private:
	static const std::string FILENAME;
	static const char DELIMETER = ':';

public:
	static bool Write(const std::vector<CarRegistration>& registrations)
	{
		std::ofstream outStream(FILENAME);

		if (outStream.is_open())
		{
			for (const auto& registration : registrations)
			{
				outStream << registration.GetManufacturer() << DELIMETER << registration.GetModel() << DELIMETER
						  << registration.GetHorsepower() << DELIMETER << registration.GetRegistrationNumber() << DELIMETER
						  << registration.GetOwner().GetId() << std::endl;
			}

			outStream.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	static bool Read(std::vector<CarRegistration>& registrations, const std::vector<Person> persons)
	{
		std::ifstream inStream(FILENAME);

		if (inStream.is_open())
		{
			registrations.clear();

			std::vector<std::string> parsedRegistration;
			std::string line;
			while (getline(inStream, line))
			{
				parsedRegistration = StringSplitter::split(line, DELIMETER);

				Person owner = FindOwner(std::stoi(parsedRegistration[4]), persons);
				CarRegistration registration(parsedRegistration[0], parsedRegistration[1], owner, 
															   std::stoi(parsedRegistration[2]), parsedRegistration[3]);

				registrations.push_back(registration);
			};

			inStream.close();
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	static Person FindOwner(int id, const std::vector<Person> persons)
	{
		int foundIndex = -1;

		for (size_t i = 0; i < persons.size(); i++)
		{
			if (persons[i].GetId() == id)
			{
				foundIndex = i;
			}
		}

		if (foundIndex != -1)
		{
			return persons[foundIndex];
		}
		else
		{
			throw "ERROR! Owner not found. Corrupted file with owners.";
		}
	}
};

const std::string CarRegistrationFileManipulator::FILENAME = "registrations.txt";