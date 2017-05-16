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

int countSubstring(const std::string& str, const std::string& sub)
{
	if (sub.length() == 0) return 0;
	int count = 0;
	for (size_t offset = str.find(sub); offset != std::string::npos;
		offset = str.find(sub, offset + sub.length()))
	{
		++count;
	}
	return count;
}

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

int main() {

	string input;
	cin >> input;

	//ifstream fileInput("test1.txt");
	//getline(fileInput, input);

	int length = input.length() - 1;

	// map<int, int> dnas;
	for (size_t i = 0; i < length; i += 5)
	{
		int currDNA = getDecFromHex(input[i]) * pow(16, 4)
					+ getDecFromHex(input[i + 1]) * pow(16, 3)
					+ getDecFromHex(input[i + 2]) * pow(16, 2)
					+ getDecFromHex(input[i + 3]) * pow(16, 1)
					+ getDecFromHex(input[i + 4]) * pow(16, 0);

		bool isUnique = true;
		int count = 0;
		for (size_t j = 0; j < length; j += 5)
		{
			int innerCurrDNA  = getDecFromHex(input[j]) * pow(16, 4)
				+ getDecFromHex(input[j + 1]) * pow(16, 3)
				+ getDecFromHex(input[j + 2]) * pow(16, 2)
				+ getDecFromHex(input[j + 3]) * pow(16, 1)
				+ getDecFromHex(input[j + 4]) * pow(16, 0);

			if (currDNA == innerCurrDNA)
			{
				count++;
			}

			if (count == 2)
			{
				isUnique = false;
				break;
			}
		}

		if (isUnique)
		{
			cout << hex << std::setw(5) << std::setfill('0') << currDNA << endl;
			break;
		}
		// dnas[currDNA]++;
	}

	//auto foundPtr = find_if(dnas.begin(), dnas.end(), [](const pair<int, int>& mp) { return mp.second == 1; });
	//cout << hex << (*foundPtr).first << endl;

	/*string currDNA;
	int position = 0;
	int numberOfOccurences = 0;

	while (true)
	{
		currDNA = input.substr(position, 5);

		numberOfOccurences = countSubstring(input, currDNA);
		if (numberOfOccurences == 1)
		{
			cout << currDNA << endl;
			break;
		}

		position += 5;
	}*/

	return 0;
}