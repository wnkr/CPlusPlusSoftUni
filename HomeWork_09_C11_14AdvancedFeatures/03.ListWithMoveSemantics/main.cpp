#include <iostream>

#include "List.h"

List<int> f(const List<int> & a) {
	List<int> result(a);
	return result;
}

int main() {
	for (size_t i = 0; i < 100000000; i++)
	{
		List<int> numbers{ 1, 2, 3 };
		List<int> movedCtorNumbers = f(numbers);

		List<int> movedAssNumbers{ 10, 20, 30 };
		movedAssNumbers = f(numbers);
	}
	
	return 0;
}
