#include <iostream>
#include <cmath>
#include <limits>
#include <string> 

using namespace std;

// With recursion starting with 0...
int FindFibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return FindFibonacci(n - 1) + FindFibonacci(n - 2);
	}
}


int main()
{
	int number;
	cin >> number;

	cout << FindFibonacci(number) << endl;

	return 0;
}