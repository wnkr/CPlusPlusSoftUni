#include "SequencePrinterBase.h"

namespace SequencePrinters
{
	SequencePrinterBase::SequencePrinterBase() :
		m_sequence(nullptr) {}

	void SequencePrinterBase::checkSetSequence() const
	{
		if (this->m_sequence == nullptr)
		{
			throw std::string("you must set up a sequence first");
		}
	}

	void SequencePrinterBase::setSequence(const SequenceGenerator& sequence)
	{
		this->m_sequence = &sequence;
	}
}