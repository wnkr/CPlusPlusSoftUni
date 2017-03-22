#include "Utils.h"

using namespace std;

int main()
{
	string numbers;
	getline(cin, numbers);

	istringstream is(numbers);

	vector<int> arrayNumbers;
	int number;
	while (is >> number)
	{
		arrayNumbers.push_back(number);
	}

	// PrintArray(array);

	int P;
	cin >> P;

	cin.ignore();

	vector<vector<string>> operations(4);
	GetOperations(operations, P);

	// PrintMatrix(operations);

	PopulatePointerOperations();

	int numberOfOperations = 0;
	vector<string> outputOperations;
	string line;
	while (getline(cin, line) && line != "end")
	{
		outputOperations.push_back(ExecuteOperation(line, operations, arrayNumbers));
		numberOfOperations++;
	}

	cout << PrintOperations(numberOfOperations, outputOperations);

	return 0;
}