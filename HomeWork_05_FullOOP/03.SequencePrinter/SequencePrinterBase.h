#pragma once
#include "SequencePrinter.h"
#include "SequenceGenerator.h"

namespace SequencePrinters
{
	using SequenceGenerators::SequenceGenerator;

	class SequencePrinterBase : public SequencePrinter
	{
	protected:
		const SequenceGenerator* m_sequence;
		SequencePrinterBase();
		void checkSetSequence() const;

	public:
		virtual void setSequence(const SequenceGenerator& sequence);
	};
}
