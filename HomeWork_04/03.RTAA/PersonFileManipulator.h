#pragma once
#include <fstream>
#include <vector>
#include "Person.h"
#include "StringSplitter.h"

class PersonFileManipulator
{
private:
	static const std::string FILENAME;
	static const char DELIMETER = ':';

public:
	static bool Write(const std::vector<Person*>& persons)
	{
		std::ofstream outStream(FILENAME);

		if (outStream.is_open())
		{
			for (const auto& person : persons)
			{
				outStream << person->GetName() << DELIMETER << person->GetId() << DELIMETER << person->GetAge() << std::endl;
			}

			outStream.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	static bool Read(std::vector<Person*>& persons)
	{
		std::ifstream inStream(FILENAME);

		if (inStream.is_open())
		{
			persons.clear();

			std::vector<std::string> parsedPerson;
			std::string line;
			while (getline(inStream, line))
			{
				parsedPerson = StringSplitter::split(line, DELIMETER);

				Person * person = new Person(parsedPerson[0], std::stoi(parsedPerson[2]));
				person->SetId(std::stoi(parsedPerson[1]));

				persons.push_back(person);
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

const std::string PersonFileManipulator::FILENAME = "persons.txt";