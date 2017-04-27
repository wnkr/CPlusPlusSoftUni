#pragma once
#include "BigInt.h"

class BigIntExtended : public BigInt
{
public:
	BigIntExtended()
		: BigInt()
	{}

	BigIntExtended(std::string digits)
		: BigInt(digits)
	{}

	BigIntExtended(int number)
		: BigInt(number)
	{}


	bool isDivisibleBy45() const
	{
		bool isDivisibleBy5 = this->isDivbisibleBy5();
		bool isDivisibleBy9 = this->isDivisibleBy9();

		if (isDivisibleBy5 && isDivisibleBy9)
		{
			return true;
		}

		return false;
	}

private:
	bool isDivbisibleBy5() const
	{
		int lastElementIndex = this->digits.size();
		if (this->digits[lastElementIndex - 1]  -'0' == 5 
			|| this->digits[lastElementIndex - 1] -'0' == 0)
		{
			return true;
		}

		return false;
	}

	bool isDivisibleBy9() const
	{
		int sumOfDigits = 0;
		for (int i = 0; i < this->digits.size(); i++) {
			sumOfDigits += this->digits[i] - '0';
		}

		if (!(sumOfDigits % 9))
		{
			return true;
		}

		return false;
	}
};
