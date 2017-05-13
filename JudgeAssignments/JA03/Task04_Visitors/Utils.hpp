#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm> 

#include "Visitor.h"

std::map<std::string, int> namesCount;
std::map<int, int> agesCount;

void processEntryCommand(std::vector<std::string> commands, std::map<std::string, std::string>& visitorsNames, std::map<std::string, int>& visitorsAges);
int processNameCommand(std::vector<std::string> commands, std::map<std::string, std::string>& visitorsNames);
int processAgeCommand(std::vector<std::string> commands, std::map<std::string, int>& visitorsAges);

std::vector<std::string> tokenizeString(const std::string& text)
{
	std::string buf; // Have a buffer string
	std::istringstream ss(text); // Insert the string into a stream

	std::vector<std::string> tokens; // Create vector to hold our words

	while (ss >> buf)
		tokens.push_back(buf);

	return tokens;
}

void processCommand(std::vector<std::string> commands, std::map<std::string, std::string>& visitorsNames, std::map<std::string, int>& visitorsAges
					/* std::map<std::string, Visitor>& visitors*/)
{
	if (commands[0] == "entry")
	{
		processEntryCommand(commands, visitorsNames, visitorsAges);
	}
	else if (commands[0] == "name")
	{
		int count = processNameCommand(commands, visitorsNames);
		std::cout << count << std::endl;
	}
	else if (commands[0] == "age")
	{
		int count = processAgeCommand(commands, visitorsAges);
		std::cout << count << std::endl;
	}
}

void processEntryCommand(std::vector<std::string> commands, std::map<std::string, std::string>& visitorsNames, std::map<std::string, int>& visitorsAges)
{
	std::string id = commands[1];
	std::string name = commands[2];
	int age = stoi(commands[3]);

	Visitor visitor(id, name, age);

	// visitors.insert(std::pair<std::string, Visitor>(id, visitor));
	// visitors[id] = visitor;

	if (visitorsNames[id].empty())
	{
		namesCount[name]++;
		agesCount[age]++;
	}
	visitorsNames[id] = name;

	visitorsAges[id] = age;

	// std::cout << "Visitor with id " << id << " inserted" << std::endl;
}

int processNameCommand(std::vector<std::string> commands, std::map<std::string, std::string>& visitorsNames)
{
	std::string searchedName = commands[1];

	// auto beginPtr = visitors.begin();
	// auto endPtr = visitors.end();

	//auto foundVisitorPtr = std::find_if(beginPtr, endPtr, [&](const std::pair<std::string,  Visitor>& p) {return p.second.getName() == searchedName; });

	int countFounded = 0;
	//while (foundVisitorPtr != visitors.end())
	//{
	//	countFounded++;
	//	foundVisitorPtr = std::find_if(++foundVisitorPtr, endPtr, [&](const std::pair<std::string, Visitor>& p) {return p.second.getName() == searchedName; });
	//}
	//for (const auto& v : visitorsNames)
	//{
	//	if (v.second == searchedName)
	//	{
	//		countFounded++;
	//	}
	//}

	return namesCount[searchedName];
}

int processAgeCommand(std::vector<std::string> commands, std::map<std::string, int>& visitorsAges)
{
	int startAge = stoi(commands[1]);
	int endAge = stoi(commands[2]);

	//auto beginPtr = visitors.begin();
	//auto endPtr = visitors.end();

	//auto foundVisitorPtr = std::find_if(beginPtr, endPtr, [&](const std::pair<std::string, Visitor>& p) {return startAge <= p.second.getAge() && p.second.getAge() < endAge; });

	int countFounded = 0;
	//while (foundVisitorPtr != visitors.end())
	//{
	//	countFounded++;
	//	foundVisitorPtr = std::find_if(++foundVisitorPtr, endPtr, [&](const std::pair<std::string, Visitor>& p) {return startAge <= p.second.getAge() && p.second.getAge() < endAge; });
	//}

	unsigned diffStartEnd = endAge - startAge;
	for (const auto& v : agesCount)
	{
		if ((unsigned)(v.first - startAge) < diffStartEnd)
		{
			countFounded += v.second;
		}
	}

	return countFounded;
}