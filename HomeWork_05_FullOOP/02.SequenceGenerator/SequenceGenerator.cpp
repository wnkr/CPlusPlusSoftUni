#include <sstream>
#include "SequenceGenerator.h"

using namespace std;

namespace SequenceGenerators
{
	SequenceGenerator::SequenceGenerator(int startNumber, int endNumber)
		: length(endNumber - startNumber), numbers(new double[endNumber - startNumber]), names(new string[endNumber - startNumber])
	{
	}

	SequenceGenerator::SequenceGenerator(const SequenceGenerator& other)
		: length(other.length), numbers(new double[other.length]), names(new string[other.length])
	{
		CopyData(other.numbers, other.length, this->numbers, this->length);
		CopyData(other.names, other.length, this->names, this->length);
	}

	SequenceGenerator& SequenceGenerator::operator=(const SequenceGenerator& other)
	{
		if (this != &other)
		{
			delete[] this->numbers;
			delete[] this->names;

			this->length = other.length;
			this->numbers = new double[other.length];
			this->names = new string[other.length];

			this->CopyData(other.numbers, other.length, this->numbers, this->length);
			this->CopyData(other.names, other.length, this->names, this->length);
		}

		return *this;
	}

	SequenceGenerator::~SequenceGenerator()
	{
		delete[] this->numbers;
		delete[] this->names;
	}

	double SequenceGenerator::getValue(int index) const
	{
		this->insureIndexInbounds(index);
		return this->numbers[index];
	}

	std::string SequenceGenerator::getName(int index) const
	{
		this->insureIndexInbounds(index);
		return this->names[index];
	}

	std::string SequenceGenerator::writeNumbers() const
	{
		ostringstream stream;

		for (size_t i = 0; i < this->length; i++)
		{
			// stream << this->getName(i) << ": " << this->getValue(i) << endl;
			if (i != this->length - 1)
			{
				stream << this->getValue(i) << " ";
			}
			else
			{
				stream << this->getValue(i);
			}
		}

		return stream.str();
	}

	void SequenceGenerator::insureIndexInbounds(int index) const
	{
		if (index < 0 || index > this->length)
		{
			throw "index out of bounds";
		}
	}

	template<typename T>
	void SequenceGenerator::CopyData(T * source, int sourceLength, T * dest, int destLength)
	{
		for (size_t i = 0; i < sourceLength && i < destLength; i++)
		{
			dest[i] = source[i];
		}
	}

	template void SequenceGenerator::CopyData<double>(double * source, int sourceLength, double * dest, int destLength);
	template void SequenceGenerator::CopyData<string>(string * source, int sourceLength, string * dest, int destLength);
}

