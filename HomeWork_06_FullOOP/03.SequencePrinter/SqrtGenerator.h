#pragma once
#include "SequenceGenerator.h"

namespace SequenceGenerators
{
	class SqrtGenerator : public SequenceGenerator
	{
	public:
		SqrtGenerator(int startInteger, int endInteger);
	private:
		void generateSequence(int startNumber, int endNumber);
	};
}

