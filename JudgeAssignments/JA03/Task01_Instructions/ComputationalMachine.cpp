#include <sstream> 

#include "ComputationalMachine.h"

void ComputationalMachine::insert(int number)
{
	this->memory.push_back(number);
}

void ComputationalMachine::sum()
{
	int x = this->getLast();
	int y = this->getLast();

	int sum = x + y;
	this->memory.push_back(sum);
}

void ComputationalMachine::subtract()
{
	int x = this->getLast();
	int y = this->getLast();

	int difference = x - y;
	this->memory.push_back(difference);
}

void ComputationalMachine::concat()
{
	if (this->checkLastElementIsNegative())
	{
		return;
	}

	int x = this->getLast();
	int y = this->getLast();

	std::ostringstream oss;
	oss << y << x;

	int concatenatedNumber = std::stoi(oss.str());
	this->memory.push_back(concatenatedNumber);
}

void ComputationalMachine::discard()
{
	this->memory.pop_back();
}

std::string ComputationalMachine::toString() const
{
	std::ostringstream result;

	for (const auto& elem : this->memory)
	{
		result << elem << std::endl;
	}

	return result.str();
}

bool ComputationalMachine::checkLastElementIsNegative() const
{
	int x = this->memory.back();
	bool isNegative = (x < 0) ? true : false;
	return isNegative;
}

int ComputationalMachine::getLast()
{
	int x = this->memory.back();
	this->memory.pop_back();
	return x;
}
