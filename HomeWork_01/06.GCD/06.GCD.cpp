#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Calculates the greatest common divisor (GCD) of given two numbers
// with the Euclidean algorithm using recursion
int GCD(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	else
	{
		if (a > b)
		{
			return GCD(a - b, b);
		}
		else if (a < b)
		{
			return GCD(a, b - a);
		}
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << "The greatest common divisor(GCD) of " << a << " and " << b << " is: " << GCD(a, b) << endl;

	return 0;
}