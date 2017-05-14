#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <sstream>
#include <bitset>

using namespace std;


//int hexToDec(string hex)
//{
//	int x;
//	std::istringstream stream(hex);
//
//	stream >> std::hex >> x;
//
//	return x;
//}
//
//const char* hex_char_to_bin(char c);
//std::string hex_str_to_bin_str(const std::string& hex);
//
//bitset<20> hexToBinary(string hex)
//{
//	string binaryStr = hex_str_to_bin_str(hex);
//	bitset<20> binary(binaryStr);
//
//	return binary;
//}

int main()
{
	string input;
	getline(cin, input);

	// int numberOfDNAs = input.length() / 5;

	set<string> DNAs;
	int position = 0;

	int countUnique = 0;
	bool pos;
	string currDNA;
	bool is_in;
	while (true)
	{
		currDNA = input.substr(position, 5);
		
		//auto binary = hexToBinary(currDNA);
		// bitset<20> currDNAInBinary = hexToBinary(currDNA);

		// bool is_in = DNAs.find(currDNA) != DNAs.end();

		pos = input.find(currDNA, position + 5) != string::npos;
		is_in = DNAs.find(currDNA) != DNAs.end();
		if (pos)
		{
			DNAs.insert(currDNA);
		}
		else if (!is_in)
		{
			cout << currDNA << endl;
			break;
		}
		//while (pos != string::npos)
		//{
		//	countUnique++;
		//	input = input.erase(pos, 5);
		//	pos = input.find(currDNA/*, pos + 5*/);
		//}

		//if (countUnique == 1)
		//{
		//	cout << currDNA << endl;
		//	break;
		//}

		// countUnique = 0;

		//if (!is_repeated)
		//{
		//	cout << currDNA << endl;
		//	/*DNAs.erase(currDNA);*/
		//}
		//else
		//{
		//	/*DNAs.insert(currDNA);*/
		//}

		position += 5;
		// numberOfDNAs--;
	}

	//for (const auto& dna : DNAs)
	//{
	//	/*ostringstream res;
	//	res << hex << dna.to_ulong();
	//	cout << res.str() << endl;*/
	//	cout << dna << endl;
	//}

	return 0;
}

//const char* hex_char_to_bin(char c)
//{
//	// TODO handle default / error
//	switch (toupper(c))
//	{
//	case '0': return "0000";
//	case '1': return "0001";
//	case '2': return "0010";
//	case '3': return "0011";
//	case '4': return "0100";
//	case '5': return "0101";
//	case '6': return "0110";
//	case '7': return "0111";
//	case '8': return "1000";
//	case '9': return "1001";
//	case 'A': return "1010";
//	case 'B': return "1011";
//	case 'C': return "1100";
//	case 'D': return "1101";
//	case 'E': return "1110";
//	case 'F': return "1111";
//	}
//}
//
//std::string hex_str_to_bin_str(const std::string& hex)
//{
//	// TODO use a loop from <algorithm> or smth
//	std::string bin;
//	for (unsigned i = 0; i != hex.length(); ++i)
//		bin += hex_char_to_bin(hex[i]);
//	return bin;
//}