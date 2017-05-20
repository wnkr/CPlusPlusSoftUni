#include <iostream>
#include <string>
#include <sstream>

#include "List.h"

template<typename T>
List<T> mergeSortedLists(List<T> a, List<T> b) {
    List<T> merged;

    while(!a.isEmpty() || !b.isEmpty()) {
        List<T> * listToTakeFrom;
        if (a.isEmpty()) {
            listToTakeFrom = &b;
        } else if (b.isEmpty()) {
            listToTakeFrom = &a;
        } else {
            if (a.first() < b.first()) {
                listToTakeFrom = &a;
            } else {
                listToTakeFrom = &b;
            }
        }

        merged.add(listToTakeFrom->first());
        listToTakeFrom->removeFirst();
    }

    return merged;
}

int main() {
	List<int> numbers;
	numbers.add(1);
	numbers.add(-2);
	numbers.add(42);
	for (int n : numbers) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	List<std::string> words;
	words.add("Guardians");
	words.add("galaxy");
	for (auto word : words) {
		std::cout << word << " ";
	}
	std::cout << std::endl;

    return 0;
}
