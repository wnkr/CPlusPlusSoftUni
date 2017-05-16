#include <iostream>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <iomanip>
#include <cmath>  

using namespace std;

int getDecFromHex(char ch)
{
	switch (ch)
	{
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
		return ch - 'a' + 10;
	default:
		return ch - '0';
	}
}

int main()
{
	// Optimize solution
	const unsigned int NumOfDigitsPerNumber = 5;

	char currentDNA[NumOfDigitsPerNumber] = {};

	size_t xorred = 0;

	while (cin >> currentDNA[0])
	{
		if (currentDNA[0] == '.')
		{
			break;
		}

		cin >> currentDNA[1] >> currentDNA[2] >> currentDNA[3] >> currentDNA[4];

		int value = 0;
		for (size_t i = 0; i < NumOfDigitsPerNumber; i++)
		{
			value += getDecFromHex(currentDNA[i]) * (int)pow(16, 4 - i);
		}

		xorred ^= value;
	}

	cout << hex << setfill('0') << setw(5) << xorred << endl;

	/// Trivial solution
	//string input;
	////cin >> input;

	//ifstream fileInput("test1.txt");
	//getline(fileInput, input);

	//int length = input.size();
	//int numberOfDNAs = length / 5;

	//set<string> DNAs;

	//int pos = 0;
	//while (numberOfDNAs > 0)
	//{
	//	string currDNA = input.substr(pos, 5);

	//	bool is_in = DNAs.find(currDNA) != DNAs.end();
	//	if (is_in)
	//	{
	//		DNAs.erase(currDNA);
	//	}
	//	else
	//	{
	//		DNAs.insert(currDNA);
	//	}

	//	pos += 5;
	//	numberOfDNAs--;
	//}

	//for (const auto& dna : DNAs)
	//{
	//	cout << dna << endl;
	//}

	return 0;
}