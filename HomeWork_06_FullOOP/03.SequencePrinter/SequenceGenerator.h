#pragma once
#include <string>
#include <vector>

namespace SequenceGenerators
{
	class SequenceGenerator
	{
	protected:
		int length;
		double * numbers;
		std::string * names;

	public:
		SequenceGenerator(int startNumber, int endNumber);
		SequenceGenerator(const SequenceGenerator& other);
		SequenceGenerator& SequenceGenerator::operator=(const SequenceGenerator& other);
		~SequenceGenerator();

	public:
		std::string getName(int index) const;
		double getValue(int index) const;
		std::string writeNumbers() const;

	protected:
		virtual void generateSequence(int startNumber, int endNumber) = 0;

	private:
		template<typename T>
		static void CopyData(T * source, int sourceLength, T * dest, int destLength);
		void insureIndexInbounds(int index) const;
	};
}
