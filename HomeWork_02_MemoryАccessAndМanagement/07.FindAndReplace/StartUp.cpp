#include <iostream>
#include <string>

using namespace std;

void FindAndReplace(string& text, const string& find, const string& replace)
{
	int foundIndex = text.find(find);
	while (foundIndex != string::npos)
	{
		text = text.replace(foundIndex, find.size(), replace);

		foundIndex = text.find(find);
	}
}

int main()
{
	string text = "I am the night. Dark Night! No, not the knight";
	string find = "night";
	string replace = "day";

	FindAndReplace(text, find, replace);

	cout << text << endl;

	return 0;
}