#include <iostream>
#include <string>
#include <vector>
#include "BigInt.h"
#include "BigIntExtended.h"

using namespace std;

static std::vector<BigIntExtended> findDivisibleBy45(BigIntExtended startRange, BigIntExtended endRange)
{
	std::vector<BigIntExtended> divisibleNumbers;

	BigIntExtended bigIntOne(1);
	for (BigIntExtended i = startRange; i < endRange; i += bigIntOne)
	{
		if (i.isDivisibleBy45())
		{
			divisibleNumbers.push_back(i);
		}
	}

	return divisibleNumbers;
}

int main()
{
	string S;
	string E;

	cin >> S;
	cin >> E;

	BigIntExtended start(S);
	BigIntExtended end(E);

	/*cout << start.isDivisibleBy45() << endl;
	cout << end.isDivisibleBy45() << endl;*/

	std::vector<BigIntExtended> divisibleNumbers = findDivisibleBy45(start, end);

	for (const auto& bigIntNumber : divisibleNumbers)
	{
		cout << bigIntNumber << endl;
	}

	return 0;
}