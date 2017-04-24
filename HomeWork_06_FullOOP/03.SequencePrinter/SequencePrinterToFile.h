#pragma once
#include <fstream>
#include <string>
#include "SequencePrinterBase.h"

namespace SequencePrinters
{
	class SequencePrinterToFile : public SequencePrinterBase
	{
	private:
		std::ofstream stream;
	public:
		SequencePrinterToFile(std::string fileName);
		void print();
	};
}