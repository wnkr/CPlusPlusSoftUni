#pragma once
#include <string>
#include <sstream>

class Person
{
private:
	static int serialId;

	std::string name;
	int age;
	int uniqueId;
	
public:
	Person(std::string name, int age)
		: uniqueId(serialId)
	{
		this->SetName(name);
		this->SetAge(age);
		this->serialId++;
	}

	std::string GetName() const
	{
		return this->name;
	}

	void SetName(std::string name)
	{
		if (name.empty())
		{
			throw "Person name cannot be empty.";
		}

		this->name = name;
	}

	int GetAge() const
	{
		return this->age;
	}

	void SetAge(int age)
	{
		if (age <= 0)
		{
			throw "Invalid person age.";
		}

		this->age = age;
	}

	int GetId() const
	{
		return this->uniqueId;
	}

	std::string Print() const
	{
		std::ostringstream output;

		output << "....." << std::endl;
		output << "  Name: " << this->GetName() << std::endl
			<< "  Id: " << this->GetId() << std::endl
			<< "  Age: " << this->GetAge() << std::endl;
		output << "..............................";

		return output.str();
	}
};

int Person::serialId = 0;
