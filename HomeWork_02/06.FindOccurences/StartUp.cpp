#include <iostream>
#include <string>

using namespace std;

int Occurences(const string& text, const string& search)
{
	int count = 0;
	string newText = text;

	int foundIndex = newText.find(search);
	while (foundIndex != string::npos)
	{
		count++;

		newText = newText.substr(foundIndex + search.size(), text.size() - foundIndex - search.size());

		foundIndex = newText.find(search);
	}

	return count;
}

int main()
{
	string text = "string text = “Write a function int occurences(const string& text, const string& search) which returns the number of times search is contained in text” string search = “on”;occurences(text, search);";
	string search = "on";

	cout << Occurences(text, search) << endl;
	return 0;
}