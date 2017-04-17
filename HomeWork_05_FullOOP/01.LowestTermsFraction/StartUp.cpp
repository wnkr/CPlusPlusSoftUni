#include <iostream>
#include "Fraction.h"
#include "LowestTermsFraction.h"

using namespace std;

int main()
{	
	LowestTermsFraction a, b;
	cin >> a >> b;

	a *= 3;
	a /= 3;
	a *= b;
	a /= b;
	LowestTermsFraction multBy3 = a * 3;
	LowestTermsFraction multByB = a * b;
	LowestTermsFraction divBy3 = a / 3;
	LowestTermsFraction divByB = a / b;
	LowestTermsFraction reciprocalA = a.getReciprocal();

	cout << a << " " << b << " " << multBy3 << " " << multByB << " " << divBy3 << " " << divByB << " " << reciprocalA << endl;

	return 0;
}