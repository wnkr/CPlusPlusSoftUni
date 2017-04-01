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
	static bool Write(const std::vector<CarRegistration*>& registrations)
	{
		std::ofstream outStream(FILENAME);

		if (outStream.is_open())
		{
			for (const auto& registration : registrations)
			{
				outStream << registration->GetManufacturer() << DELIMETER << registration->GetModel() << DELIMETER 
						  << registration->GetHorsepower() << DELIMETER << registration->GetRegistrationNumber() << DELIMETER
						  << registration->GetPerson().GetId() << std::endl;
			}

			outStream.close();
			return true;
		}
		else
		{
			return false;
		}
	}
};

const std::string CarRegistrationFileManipulator::FILENAME = "registrations.txt";