#pragma once
#include <string>
#include "Person.h"

class CarRegistration
{
private:
	std::string manufacturer;
	std::string model;
	Person* owner;
	int horsepower;
	std::string registrationNumber;

public:
	CarRegistration(std::string manufacturer, std::string model, Person* owner, int horsepower, std::string registrationNumber)
		: manufacturer(manufacturer), model(model), owner(owner), horsepower(horsepower), registrationNumber(registrationNumber)
	{

	}

	~CarRegistration()
	{
		delete owner;
	}

	std::string GetRegistrationNumber() const
	{
		return this->registrationNumber;
	}

	void ChangeOwner(Person* owner, std::string registrationNumber)
	{
		this->owner = owner;
		this->SetRegistrationNumber(registrationNumber);
	}

	std::string Print() const
	{
		std::ostringstream output;

		output << ".............................." << std::endl;
		output << "Manufacturer: " << this->manufacturer << std::endl
			   << "Model: " << this->model << std::endl 
			   << "Horsepower: " << this->horsepower << std::endl 
			   << "Registration number: " << this->registrationNumber << std::endl;
		output << "Current owner: " << std::endl <<  this->owner->Print();

		return output.str();
	}

private:
	void SetRegistrationNumber(std::string registrationNumber)
	{
	if (registrationNumber.empty())
	{
	throw "Car registration number cannot be empty.";
	}

	this->registrationNumber = registrationNumber;
	}
};