#include <iostream>
#include <unordered_set>

#include "List.h"

using namespace std;

namespace std
{
	template<typename T>
	struct hash<List<T>>
	{
		size_t operator()(const List<T>& list) const
		{
			size_t hashCodeList = 0;
			int position = 1;
			for (const auto& item : list)
			{
				hashCodeList += std::hash<T>()(item) * position;
				position++;
			}

			return hashCodeList;
		}
	};
}

int main() {

	List<int> numbers{ 13, 42, 69 };
	List<int> anotherNumbers{ 0, 10, -2, 42 };

	unordered_set<List<int>> setOfLists;
	setOfLists.insert(numbers);
	setOfLists.insert(anotherNumbers);

	for (auto i = setOfLists.begin(); i != setOfLists.end(); i++)
	{
		cout << (*i).toString() << endl;
	}

	return 0;
}
