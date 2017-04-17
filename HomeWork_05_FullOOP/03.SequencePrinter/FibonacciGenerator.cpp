#include "FibonacciGenerator.h"

using namespace std;

namespace SequenceGenerators
{
	const string FibonacciGenerator::nameMessage = "Fibonacci ";

	// With recursion starting with 0...
	int FibonacciGenerator::FindFibonacci(int n)
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

	FibonacciGenerator::FibonacciGenerator(int startFibonacciNumber, int endFibonacciNumber)
		: SequenceGenerator(startFibonacciNumber, endFibonacciNumber)
	{
		this->generateSequence(startFibonacciNumber, endFibonacciNumber);
	}

	void FibonacciGenerator::generateSequence(int startNumber, int endNumber)
	{
		for (size_t i = 0; i < endNumber - startNumber; i++)
		{
			this->numbers[i] = FindFibonacci(i + startNumber);
			this->names[i] = nameMessage + to_string(i + startNumber);
		}
	}
}