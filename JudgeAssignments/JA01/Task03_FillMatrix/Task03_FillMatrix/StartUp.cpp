#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template<class T>
void PrintMatrix(const vector<vector<T>>& matrix)
{
	for(const auto& row : matrix)
	{
		for (const auto& ch : row)
		{
			cout << ch;
		}
		cout << endl;
	}
}

void ChangeMatrix(vector<vector<char>>& matrix, int startRow, int startCol, char startChar, char fillChar)
{
	matrix[startRow][startCol] = fillChar;

	int currRow = startRow;
	int currCol = startCol;

	if (currRow - 1 >= 0 && matrix[currRow - 1][currCol] == startChar)
	{
		ChangeMatrix(matrix, currRow - 1, currCol, startChar, fillChar);
	}
	if (currRow + 1 < matrix.size() && matrix[currRow + 1][currCol] == startChar)
	{
		ChangeMatrix(matrix, currRow + 1, currCol, startChar, fillChar);
	}
	if (currCol - 1 >= 0 && matrix[currRow][currCol - 1] == startChar)
	{
		ChangeMatrix(matrix, currRow, currCol - 1, startChar, fillChar);
	}
	if (currCol + 1 < matrix[0].size() && matrix[currRow][currCol + 1] == startChar)
	{
		ChangeMatrix(matrix, currRow, currCol + 1, startChar, fillChar);
	}
}

int main()
{
	int R, C;
	cin >> R >> C;

	cin.ignore();

	vector<vector<char>> matrix;
	for (size_t i = 0; i < R; i++)
	{
		string line;
		getline(cin, line);

		istringstream is(line);

		vector<char> rowOfChars;
		char ch = 0;
		while (is >> ch)
		{
			rowOfChars.push_back(ch);
		}

		matrix.push_back(rowOfChars);
	}

	// cout << R << C << endl;
	// PrintMatrix(matrix);

	char fillChar;
	cin >> fillChar;

	int startRow, startCol;
	cin >> startRow >> startCol;

	ChangeMatrix(matrix, startRow, startCol, matrix[startRow][startCol], fillChar);

	PrintMatrix(matrix);

	return 0;
}