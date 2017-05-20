#include <iostream>
#include <string>
#include <sstream>

#include "List.h"

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
