#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip> 

using namespace std;

int HexToInt(string hexNumber)
{
	unsigned int x;
	std::stringstream ss;
	ss << std::hex << hexNumber;
	ss >> x;
	// return it as a signed type
	return static_cast<int>(x);
}

string IntToHex(int number)
{
	stringstream stream;
	stream << setfill('0') << setw(2) << hex << number;
	return stream.str();
}

int CalculateAverageOfTwoInts(int x, int y)
{
	int average = (x + y) / 2;
	return average;
}

string ConstructAverageColor(string firstColor, string secondColor)
{
	const int ColorChannels = 3;
	const int CountHexLetters = 2;
	int offset = 0;

	string avgColor = "#";
	for (size_t i = 0; i < ColorChannels; i++)
	{
		string firstColorChannel = firstColor.substr(1 + offset, CountHexLetters);
		int firstColorInt = HexToInt(firstColorChannel);

		string secondColorChannel = secondColor.substr(1 + offset, CountHexLetters);
		int secondColorInt = HexToInt(secondColorChannel);

		int average = CalculateAverageOfTwoInts(firstColorInt, secondColorInt);
		string averageColor = IntToHex(average);

		avgColor += averageColor;

		offset += CountHexLetters;
	}

	return avgColor;
}

int main()
{
	string input;
	getline(cin, input);

	istringstream is(input);

	vector<string> hexNumbers;
	string hexNumber;
	while (is >> hexNumber)
	{
		hexNumbers.push_back(hexNumber);
	}

	cout << ConstructAverageColor(hexNumbers[0], hexNumbers[1]) << endl;

	return 0;
}