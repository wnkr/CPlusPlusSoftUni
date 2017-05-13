#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Utils.hpp"
#include "Visitor.h"

using namespace std;

int main()
{
	string inputLine;
	getline(cin, inputLine);

	unordered_map<string, Visitor> visitors;

	while (inputLine != "end")
	{
		vector<string> tokens = tokenizeString(inputLine);

		processCommand(tokens, visitors);

		getline(cin, inputLine);
	}

	return 0;
}