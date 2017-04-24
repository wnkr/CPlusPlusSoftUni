#pragma once
#include <string>
#include "SequenceGenerator.h"

namespace SequencePrinters
{
	using SequenceGenerators::SequenceGenerator;

	class SequencePrinter
	{
	public:
		virtual void print() = 0;
		virtual void setSequence(const SequenceGenerator& sequence) = 0;

		SequencePrinter& operator<<(const SequenceGenerator& sequence);
	};
}

