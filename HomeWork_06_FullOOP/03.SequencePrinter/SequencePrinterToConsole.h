#pragma once
#include "SequencePrinterBase.h"

namespace SequencePrinters
{
	class SequencePrinterToConsole : public SequencePrinterBase
	{
	public:
		void print();
	};

}
