#pragma once
#include <vector>
#include <string>

class ComputationalMachine
{
private:
	std::vector<int> memory;

public:
	void insert(int number);
	void sum();
	void subtract();
	void concat();
	void discard();

	std::string toString() const;

private:
	bool checkLastElementIsNegative() const;
	int getLast();
};