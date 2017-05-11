#include <iostream>
#include <fstream>
#include <sstream> 

using namespace std;

int main()
{
	const int ROWS = 500;
	const int COLS = 600;

	ostringstream oss;

	int cells = 0;
	for (size_t row = 1; row < ROWS; row++)
	{
		for (size_t col = 1; col < COLS; col++)
		{
			oss << row << " " << col << endl;

			cells++;
		}
	}

	ofstream fileOutput("test1.txt");
	fileOutput << cells << endl;
	fileOutput << oss.str() << endl;


	return 0;
}