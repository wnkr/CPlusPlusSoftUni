#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int* ParseNumbers(const string& str, int& resultLength)
{
	istringstream is(str);

	int number = 0;
	while (is >> number)
	{
		resultLength++;
	}

	int* arrayNumbers = new int[resultLength];

	is.clear();
	is.str(str);

	int count = 0;
	while (is >> number)
	{
		arrayNumbers[count] = number;
		count++;
	}

	return arrayNumbers;
}

int main()
{
	int lines = 0;
	cin >> lines;

	cin.ignore();

	int sum = 0;
	for (size_t i = 0; i < lines; i++)
	{
		string line;
		getline(cin, line);

		int arrayLength = 0;
		int * array = ParseNumbers(line, arrayLength);

		for (size_t j = 0; j < arrayLength; j++)
		{
			sum += array[j];
		}
	}

	cout << sum << endl;

	return 0;
}