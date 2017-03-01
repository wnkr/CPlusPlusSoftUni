#include <iostream>
#include <cmath>
#include <limits>
#include <string> 

using namespace std;


int ReverseDigits(int n)
{
	string numberAsString = to_string(n);

	reverse(numberAsString.begin(), numberAsString.end());

	return stoi(numberAsString);
}

int main()
{
	int number;
	cin >> number;

	cout << ReverseDigits(number) << endl;

	return 0;
}