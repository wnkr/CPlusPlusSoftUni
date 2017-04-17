#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	double discriminant = pow(b, 2) - 4 * a * c;

	if (discriminant > 0)
	{
		double firstRoot = (-b + sqrt(discriminant)) / (2 * a);
		double secondRoot = (-b - sqrt(discriminant)) / (2 * a);

		cout << firstRoot << " " << secondRoot << endl;
	}
	else if (discriminant == 0)
	{
		double root = -b / 2 * a;

		cout << root << endl;
	}
	else
	{
		cout << "Zero real roots" << endl;
	}


	return 0;
}