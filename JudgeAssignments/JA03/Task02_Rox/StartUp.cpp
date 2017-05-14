#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	int numberOfDNAs = input.length() / 5;

	set<string> DNAs;
	int pos = 0;
	while (numberOfDNAs > 0)
	{
		string currDNA = input.substr(pos, 5);

		bool is_in = DNAs.find(currDNA) != DNAs.end();
		if (is_in)
		{
			DNAs.erase(currDNA);
		}
		else
		{
			DNAs.insert(currDNA);
		}

		pos += 5;
		numberOfDNAs--;
	}


	for (const auto& dna : DNAs)
	{
		cout << dna << endl;
	}


	return 0;
}