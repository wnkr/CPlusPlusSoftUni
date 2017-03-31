// Create classes to represent cars with registered owners, for records kept by the Road Transport Administration Agency. 

#include <iostream>
#include <vector>
#include "Person.h"
#include "CarRegistration.h"

using namespace std;

static vector<Person*> persons;
static vector<CarRegistration*> registrations;

void PrintPersons()
{
	for (const auto& person : persons)
	{
		cout << person->Print() << endl;
	}
}

void PrintRegistrations()
{
	for (const auto& reg : registrations)
	{
		cout << reg->Print() << endl;
	}
}

Person* CreatePerson()
{
	cout << "Enter a name: ";
	string name;
	cin >> name;

	cout << "Enter an age: ";
	int age;
	cin >> age;

	Person* person = new Person(name, age);

	return person;
}

CarRegistration* CreateRegistration()
{
	cout << "Enter a manufacturer: ";
	string manufacturer;
	cin >> manufacturer;

	cout << "Enter an model: ";
	string model;
	cin >> model;

	cout << "Enter an horsepower: ";
	int horsepower;
	cin >> horsepower;

	cout << "Enter a registration number: ";
	string registrationNumber;
	cin >> registrationNumber;

	PrintPersons();

	cout << "Choose owner for this car(enter the id of the person): ";
	int id;
	cin >> id;

	CarRegistration* registration = new CarRegistration(manufacturer, model, persons[id], horsepower, registrationNumber);

	return registration;
}

int GetProperId(string message)
{
	PrintPersons();

	cout << message << endl;
	int id;

	while (true)
	{
		if (cin >> id && id < persons.size())
		{
			return id;
		}
		else
		{
			std::cout << "Error! You have entered an invalid id." << endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

int GetProperRegistrationNumber(string message)
{
	PrintRegistrations();

	cout << message << endl;
	string registrationNumber;

	while (cin >> registrationNumber)
	{
		for (size_t i = 0; i < registrations.size(); i++)
		{
			if (registrationNumber == registrations[i]->GetRegistrationNumber())
			{
				return i;
			}
		}

		cout << "The entered registration number is not in the database. Enter new one:" << endl;
	}
}

void ChangeOwnerName()
{
	int id = GetProperId("Enter the id of the person you want his name changed:");

	cout << "Enter the new name for the person with id: " << id << endl;
	string name;
	cin >> name;

	persons[id]->SetName(name);
}

void ChangeOwnerAge()
{
	int id = GetProperId("Enter the id of the person you want his age changed:");

	cout << "Enter the new age for the person with id: " << id << endl;
	int age;
	cin >> age;

	persons[id]->SetAge(age);
}

void ChangeCarRegistration()
{
	int foundRegistration = GetProperRegistrationNumber("Enter the registration number of the car you want to change:");
	int id = GetProperId("Enter the id of the person you want be the new owner:");

	cout << "Enter the new registration number for the car with registration number: " << registrations[foundRegistration]->GetRegistrationNumber() << endl;
	string newRegistrationNumber;
	cin >> newRegistrationNumber;

	registrations[foundRegistration]->ChangeOwner(persons[id], newRegistrationNumber);
}

bool PrintMenu()
{
	int myChoice = 0;

	std::cout << "********** Main Menu **********" << std::endl;
	std::cout << "(1): Create new person" << std::endl;
	std::cout << "(2): Create new registration" << std::endl;
	std::cout << "(3): List all owners" << std::endl;
	std::cout << "(4): List all registrations" << std::endl;
	std::cout << "(5): Change owner name" << std::endl;
	std::cout << "(6): Change owner age" << std::endl;
	std::cout << "(7): Change car registration" << std::endl;
	std::cout << "(0): Exit" << std::endl;

	if (std::cin >> myChoice)
	{
		switch (myChoice)
		{
		case 0:
			return false;
		case 1:
		{
			Person* owner = CreatePerson();
			persons.push_back(owner);
			break;
		}
		case 2:
		{
			CarRegistration* registration = CreateRegistration();
			registrations.push_back(registration);
			break;
		}
		case 3:
			PrintPersons();
			break;
		case 4:
			PrintRegistrations();
			break;
		case 5:
			ChangeOwnerName();
			break;
		case 6:
			ChangeOwnerAge();
			break;
		case 7:
			ChangeCarRegistration();
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

int main()
{
	bool toContinue = PrintMenu();
	while (toContinue)
	{
		toContinue = PrintMenu();
	}

	return 0;
}