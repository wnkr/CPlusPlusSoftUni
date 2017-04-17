#pragma once
#include <string>
#include "SequenceGenerator.h"

namespace SequenceGenerators
{
	class FibonacciGenerator : public SequenceGenerator
	{
	private:
		static const std::string nameMessage;
	public:
		FibonacciGenerator(int startFibonacciNumber, int endFibonacciNumber);
		static int FindFibonacci(int n);
	private:
		void generateSequence(int startNumber, int endNumber);
	};
}
