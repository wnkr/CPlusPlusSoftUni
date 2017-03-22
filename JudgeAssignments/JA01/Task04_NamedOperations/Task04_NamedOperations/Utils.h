#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

typedef int(*operFuncPtr)(const vector<int>&, int, int);

static vector<operFuncPtr> pointerOperations;

// Printing
template<class T>
void PrintArray(const vector<T>& array)
{
	for (const auto& symbol : array)
	{
		cout << symbol << " ";
	}
	cout << endl;
}

template<class T>
void PrintMatrix(const vector<vector<T>>& matrix)
{
	for (const auto& row : matrix)
	{
		for (const auto& ch : row)
		{
			cout << ch;
		}
		cout << endl;
	}
}

// Operations
int sum(const vector<int>& array, int startIndex, int endIndex)
{
	int sum = 0;
	for (size_t i = startIndex; i < endIndex; i++)
	{
		sum += array[i];
	}

	return sum;
}

int average(const vector<int>& array, int startIndex, int endIndex)
{
	int average = sum(array, startIndex, endIndex) / (endIndex - startIndex);

	return average;
}

int minimum(const vector<int>& array, int startIndex, int endIndex)
{
	int min = numeric_limits<int>::max();
	for (const auto& num : array)
	{
		if (num < min)
		{
			min = num;
		}
	}

	return min;
}

int maximum(const vector<int>& array, int startIndex, int endIndex)
{
	int max = numeric_limits<int>::min();
	for (const auto& num : array)
	{
		if (num > max)
		{
			max = num;
		}
	}

	return max;
}

static void PopulatePointerOperations()
{
	int(*funcPtr)(const vector<int>&, int, int) = sum;
	pointerOperations.push_back(funcPtr);

	funcPtr = average;
	pointerOperations.push_back(funcPtr);

	funcPtr = minimum;
	pointerOperations.push_back(funcPtr);

	funcPtr = maximum;
	pointerOperations.push_back(funcPtr);
}


// Core Logic
void GetOperations(vector<vector<string>>& operations, int P)
{
	for (size_t i = 0; i < P; i++)
	{
		string line;
		getline(cin, line);

		istringstream is(line);

		vector<string> commands;
		string operand;
		while (is >> operand)
		{
			commands.push_back(operand);
		}

		int numberOfOperation = stoi(commands[1]);

		switch (numberOfOperation)
		{
		case 0:
			operations[0].push_back(commands[0]);
			break;
		case 1:
			operations[1].push_back(commands[0]);
			break;
		case 2:
			operations[2].push_back(commands[0]);
			break;
		case 3:
			operations[3].push_back(commands[0]);
			break;
		default:
			break;
		}
	}
}

string ExecuteOperation(const string& command, const vector<vector<string>>& operations, const vector<int>& array)
{
	istringstream is(command);

	vector<string> commands;
	string operand;
	while (is >> operand)
	{
		commands.push_back(operand);
	}

	int startIndex = stoi(commands[1]);
	int endIndex = stoi(commands[2]);

	ostringstream outputStream;

	outputStream << commands[0] << "(" << commands[1] << "," << commands[2] << ")=";

	for (size_t i = 0; i < operations.size(); i++)
	{
		for (size_t j = 0; j < operations[i].size(); j++)
		{
			if (commands[0] == operations[i][j])
			{
				outputStream << pointerOperations[i](array, startIndex, endIndex);
			}
		}
	}

	return outputStream.str();
}

// Print Output
string PrintOperations(int numberOfOperations, const vector<string>& outputOperations)
{
	ostringstream outputStream;

	outputStream << "[" << numberOfOperations << "]{";

	for (size_t i = 0; i < outputOperations.size(); i++)
	{
		outputStream << outputOperations[i];
		if (i < outputOperations.size() - 1)
		{
			outputStream << ",";
		}
	}

	outputStream << "}";

	return outputStream.str();
}
