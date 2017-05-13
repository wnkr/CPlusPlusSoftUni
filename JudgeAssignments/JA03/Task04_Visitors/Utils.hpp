#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm> 

#include "Visitor.h"

void processEntryCommand(std::vector<std::string> commands, std::unordered_map<std::string, Visitor>& visitors);
int processNameCommand(std::vector<std::string> commands, std::unordered_map<std::string, Visitor>& visitors);
int processAgeCommand(std::vector<std::string> commands, std::unordered_map<std::string, Visitor>& visitors);

std::vector<std::string> tokenizeString(const std::string& text)
{
	std::string buf; // Have a buffer string
	std::istringstream ss(text); // Insert the string into a stream

	std::vector<std::string> tokens; // Create vector to hold our words

	while (ss >> buf)
		tokens.push_back(buf);

	return tokens;
}

void processCommand(std::vector<std::string> commands, std::unordered_map<std::string, Visitor>& visitors/* std::unordered_map<std::string, Visitor>& visitors*/)
{
	if (commands[0] == "entry")
	{
		processEntryCommand(commands, visitors);
	}
	else if (commands[0] == "name")
	{
		int count = processNameCommand(commands, visitors);
		std::cout << count << std::endl;
	}
	else if (commands[0] == "age")
	{
		int count = processAgeCommand(commands, visitors);
		std::cout << count << std::endl;
	}
}

void processEntryCommand(std::vector<std::string> commands, std::unordered_map<std::string, Visitor>& visitors)
{
	std::string id = commands[1];
	std::string name = commands[2];
	int age = stoi(commands[3]);

	Visitor visitor(id, name, age);

	// visitors.insert(std::pair<std::string, Visitor>(id, visitor));
	visitors[id] = visitor;

	// std::cout << "Visitor with id " << id << " inserted" << std::endl;
}

int processNameCommand(std::vector<std::string> commands, std::unordered_map<std::string, Visitor>& visitors)
{
	std::string searchedName = commands[1];

	auto beginPtr = visitors.begin();
	auto endPtr = visitors.end();

	//auto foundVisitorPtr = std::find_if(beginPtr, endPtr, [&](const std::pair<std::string,  Visitor>& p) {return p.second.getName() == searchedName; });

	int countFounded = 0;
	//while (foundVisitorPtr != visitors.end())
	//{
	//	countFounded++;
	//	foundVisitorPtr = std::find_if(++foundVisitorPtr, endPtr, [&](const std::pair<std::string, Visitor>& p) {return p.second.getName() == searchedName; });
	//}
	for (const auto& v : visitors)
	{
		if (v.second.getName() == searchedName)
		{
			countFounded++;
		}
	}

	return countFounded;
}

int processAgeCommand(std::vector<std::string> commands, std::unordered_map<std::string, Visitor>& visitors)
{
	int startAge = stoi(commands[1]);
	int endAge = stoi(commands[2]);

	auto beginPtr = visitors.begin();
	auto endPtr = visitors.end();

	//auto foundVisitorPtr = std::find_if(beginPtr, endPtr, [&](const std::pair<std::string, Visitor>& p) {return startAge <= p.second.getAge() && p.second.getAge() < endAge; });

	int countFounded = 0;
	//while (foundVisitorPtr != visitors.end())
	//{
	//	countFounded++;
	//	foundVisitorPtr = std::find_if(++foundVisitorPtr, endPtr, [&](const std::pair<std::string, Visitor>& p) {return startAge <= p.second.getAge() && p.second.getAge() < endAge; });
	//}
	for (const auto& v : visitors)
	{
		if (startAge <= v.second.getAge() && v.second.getAge() < endAge)
		{
			countFounded++;
		}
	}

	return countFounded;
}