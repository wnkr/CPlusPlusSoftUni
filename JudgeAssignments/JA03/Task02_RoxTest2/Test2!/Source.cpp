#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

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
	map<int, int> dnas;

	char c;
	int pos = 0;
	int currDNA = 0;
	// puts("Enter text. Include a dot ('.') in a sentence to exit:");
	do 
	{
		while (pos != 5)
		{
			c = getchar();

			if (c == '.')
			{
				break;
			}

			currDNA += getDecFromHex(c) * (int)pow(16, 4 - pos);
			pos++;
		}

		if (pos == 5)
		{
			dnas[currDNA]++;
			pos = 0;
			currDNA = 0;
		}
	} while (c != '.');

	auto foundPtr = find_if(dnas.begin(), dnas.end(), [](const pair<int, int>& mp) { return mp.second == 1; });
	cout << hex << std::setw(5) << std::setfill('0')<< (*foundPtr).first << endl;

	return 0;
}