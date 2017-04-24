#include "SequencePrinterToFile.h"

namespace SequencePrinters
{
	SequencePrinters::SequencePrinterToFile::SequencePrinterToFile(std::string fileName)
		: stream(fileName)
	{
	}

	void SequencePrinterToFile::print()
	{
		this->checkSetSequence();
		this->stream << this->m_sequence->writeNumbers() << std::endl;
	}
}

