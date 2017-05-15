#include <iostream>
#include <string>
#include <fstream>

#include "BoyerMooreAlgorithm.h"

using namespace std;

int main()
{
	//char txt[] = "AABAACAADAABAABA";
	//char pat[] = "AABA";
	//cout << search(txt, pat) << endl;

	string input;
	// getline(cin, input);

	ifstream fileInput("test1.txt");
	getline(fileInput, input);

	string currDNA;
	int position = 0;
	while (true)
	{
		currDNA = input.substr(position, 5);

		int numberOfOccurences = search(&input[0u], &currDNA[0u]);
		if (numberOfOccurences == 1)
		{
			cout << currDNA << endl;
			break;
		}

		position += 5;
	}

	return 0;
}