#include <iostream>

#include "FibonacciGenerator.h"
#include "SqrtGenerator.h"

using namespace std;
using namespace SequenceGenerators;

int main()
{
	const long BIG_NUMBER =  10000;
	for (int ind1 = 0; ind1 < BIG_NUMBER; ind1++) {
		for (int ind2 = 0; ind2 < BIG_NUMBER; ind2++) {
			FibonacciGenerator g(1, 10);
			FibonacciGenerator copyConstructed(g);
			FibonacciGenerator copyAssigned(1, 5);
			copyAssigned = g;
			// print copyAssigned and copyConstructed to see they are correct
			// or just have a function which checks each of their values
			cout << copyAssigned.writeNumbers() << "copyAssigned" << endl;
			cout << copyConstructed.writeNumbers() << "copyConstructed" << endl;
		}
	}

	return 0;
}