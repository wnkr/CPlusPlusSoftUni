#include <iostream>
#include <string>
#include <map>
#include <stdio.h>

#include "ComputationalMachine.h"
#include "OperationState.h"

using namespace std;

static std::map<std::string, OperationState> mapStringValues;

void InitializeMapEnums()
{
	mapStringValues["insert"] = OperationState::Insert;
	mapStringValues["sum"] = OperationState::Sum;
	mapStringValues["subtract"] = OperationState::Subtract;
	mapStringValues["concat"] = OperationState::Concat;
	mapStringValues["discard"] = OperationState::Discard;
}

int main()
{
	InitializeMapEnums();

	string line;
	getline(cin, line);

	ComputationalMachine * compMachine = new ComputationalMachine();;

	while (line != "end")
	{
		switch (mapStringValues[line])
		{
		case OperationState::Sum:
			compMachine->sum();
			break;
		case OperationState::Subtract:
			compMachine->subtract();
			break;
		case OperationState::Concat:
			compMachine->concat();
			break;
		case OperationState::Discard:
			compMachine->discard();
			break;
		default:
			/*int i;
			sscanf(line.c_str(), "%d", &i);*/
			compMachine->insert(std::stoi(line));
			break;
		}

		getline(cin, line);
	}

	cout << compMachine->toString();

	return 0;
}