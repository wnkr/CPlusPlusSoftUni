#include <sstream>
#include "SequencePrinterToString.h"

using namespace std;

namespace SequencePrinters
{
	SequencePrinterToString::SequencePrinterToString(string& s)
		: str(s)
	{
	}

	void SequencePrinterToString::print()
	{
		this->checkSetSequence();

		ostringstream stream;
		stream << this->m_sequence->writeNumbers() << endl;

		this->str += stream.str();
	}

	//std::string& operator+=(std::string& str, const SequencePrinterToString& printer)
	//{
	//	str += printer.m_sequence->writeNumbers();
	//	return str;
	//}

	//std::ostream & operator<<(std::ostream & stream, const SequencePrinterToString & printer)
	//{
	//	stream << printer.m_sequence->writeNumbers();

	//	return stream;
	//}
}