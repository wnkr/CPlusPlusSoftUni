#include <math.h>
#include "SqrtGenerator.h"

using namespace std;

namespace SequenceGenerators
{
	SqrtGenerator::SqrtGenerator(int startInteger, int endInteger)
		: SequenceGenerator(startInteger, endInteger)
	{
		this->generateSequence(startInteger, endInteger);
	}

	void SqrtGenerator::generateSequence(int startNumber, int endNumber)
	{
		for (size_t i = 0; i < endNumber - startNumber; i++)
		{
			this->numbers[i] = sqrt(i + startNumber);
			this->names[i] = "Sqrt(" + to_string(i + startNumber) + ")";
		}
	}

}