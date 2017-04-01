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
		this->name = ValidateName(name);
	}

	int GetAge() const
	{
		return this->age;
	}

	void SetAge(int age)
	{
		this->age = ValidateAge(age);
	}

	int GetId() const
	{
		return this->uniqueId;
	}

	void SetId(int id)
	{
		this->uniqueId = id;
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

private:
	static std::string ValidateName(std::string name)
	{
		if (name.empty())
		{
			throw "Person name cannot be empty.";
		}

		return name;
	}

	static int ValidateAge(int age)
	{
		if (age <= 0)
		{
			throw "Invalid person age.";
		}

		return age;
	}
};

int Person::serialId = 0;
