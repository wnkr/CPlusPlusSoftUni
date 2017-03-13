#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int FindNumberOfLines(string fileName)
{
	int number_of_lines = 0;
	std::string line;
	std::ifstream myfile(fileName);

	while (std::getline(myfile, line))
		++number_of_lines;

	return number_of_lines;
}

bool CheckSameLines(string fileName1, string fileName2)
{
	if (FindNumberOfLines(fileName1) != FindNumberOfLines(fileName2))
	{
		return false;
	}

	vector<string> lines1;
	vector<string> lines2;

	std::string line1;
	std::ifstream myfile1(fileName1);

	std::string line2;
	std::ifstream myfile2(fileName2);


	while (std::getline(myfile1, line1) && std::getline(myfile2, line2))
	{
		if (line1 != line2)
		{
			return false;
		}
	}

	myfile1.close();
	myfile2.close();

	return true;
}

int main()
{
	cout << CheckSameLines("test1.txt", "test2.txt") << endl;

	return 0;
}