#include <iostream>
#include <fstream>
#include <sstream> 
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	// srand((unsigned)time(NULL));

	const int DNAs = 1000;// 1048575;

	vector<string> dnas;
	set<string> uniqueDNAs;

	int currSize = 2;
	for (size_t row = 1; row <= DNAs; row++)
	{
		ostringstream oss;
		string currDNA;
		oss << hex << std::setw(5) << std::setfill('0') << row;

		currDNA = oss.str();

		uniqueDNAs.insert(currDNA);
		for (size_t col = 0; col < currSize; col++)
		{
			dnas.push_back(currDNA);
		}

		currSize += 2;
	}

	dnas.push_back("fffff");

	std::random_shuffle(dnas.begin(), dnas.end());

	ofstream fileOutput("test1.txt");
	for (const auto& dna : dnas)
	{
		fileOutput << dna;
	}

	return 0;
}