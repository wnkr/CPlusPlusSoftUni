#include <iostream>

using namespace std;


int main()
{
	int a, b;
	cin >> a >> b;

	cout << "Before: " << a << " " << b << endl;

	if (a > b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}

	cout << "After: " << a << " " << b << endl;

	return 0;
}