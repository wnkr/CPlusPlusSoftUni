#include <iostream>
#include "SequencePrinterToConsole.h"

namespace SequencePrinters
{
	using std::cout;

	void SequencePrinters::SequencePrinterToConsole::print()
	{
		this->checkSetSequence();
		cout << this->m_sequence->writeNumbers() << std::endl;
	}
}

