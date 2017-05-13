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

	map<string, string> visitorsNames;
	map<string, int> visitorsAges;

	while (inputLine != "end")
	{
		vector<string> tokens = tokenizeString(inputLine);

		processCommand(tokens, visitorsNames, visitorsAges);

		getline(cin, inputLine);
	}

	return 0;
}