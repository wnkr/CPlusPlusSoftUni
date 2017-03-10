#include <iostream>
#include <string>
#include <fstream>
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
	cout << "Enter the input file name: " << endl;
	string inputFile;
	cin >> inputFile;

	cout << "Enter the output file name: " << endl;
	string outputFile;
	cin >> outputFile;

	int sum = 0;

	ifstream inputStream(inputFile);
	if (inputStream.is_open())
	{
		string strLines;
		getline(inputStream, strLines);

		int lines = stoi(strLines);


		for (size_t i = 0; i < lines; i++)
		{
			string line;
			getline(inputStream, line);

			int arrayLength = 0;
			int * array = ParseNumbers(line, arrayLength);

			for (size_t j = 0; j < arrayLength; j++)
			{
				sum += array[j];
			}
		}
		inputStream.close();
	}
	else
	{
		cout << "Cannot open the file" << endl;
	}

	ofstream outputStream(outputFile, ios::trunc);
	if (outputStream.is_open())
	{
		outputStream << sum;
		outputStream.close();
	}
	else
	{
		cout << "Cannot open the file" << endl;
	}

	return 0;
}