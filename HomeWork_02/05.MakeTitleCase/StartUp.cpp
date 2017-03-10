#include <iostream>
#include <string>

using namespace std;

void MakeTitleCase(string& text)
{
	for (size_t i = 0; i < text.size(); i++)
	{
		if (i == 0 && isalpha(text[i]))
		{
			text[i] = toupper(text[i]);
		}
		else if(!isalpha(text[i - 1]) && isalpha(text[i]))
		{
			text[i] = toupper(text[i]);
		}
	}
}

int main()
{
	string text = "on the south Carpathian mountains,a tree is swinging";
	MakeTitleCase(text);
	cout << text << endl;
	return 0;
}