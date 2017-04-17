#include "SequencePrinter.h"

namespace SequencePrinters
{
	SequencePrinter & SequencePrinter::operator<<(const SequenceGenerator & sequence)
	{
		this->setSequence(sequence);
		this->print();

		return (*this);
	}
}

