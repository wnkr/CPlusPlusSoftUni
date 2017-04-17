#pragma once
#include <string>
// #include <ostream>
#include "SequencePrinterBase.h"

namespace SequencePrinters
{
	class SequencePrinterToString : public SequencePrinterBase
	{
	private:
		std::string& str;
	public:
		SequencePrinterToString(std::string& s);

		//friend std::string& operator+=(std::string& str, const SequencePrinterToString& sequencePrinter);
		//friend std::ostream& operator<<(std::ostream& stream, const SequencePrinterToString& printer);
		
		void print();
	};
}
