#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const string PUNCTUATION_DELIMETERS = ".,;!? ";

string ReplacePunctuationWithSpace(const string& text, const string& punc)
{
	string replacedText = text;

	for (size_t i = 0; i < text.length(); i++)
	{
		for (size_t j = 0; j < punc.length(); j++)
		{
			if (text[i] == punc[j])
			{
				replacedText[i] = ' ';
			}
		}
	}

	return replacedText;
}

vector<string> SplitTextInWords(const string& text)
{
	string replacedText = ReplacePunctuationWithSpace(text, PUNCTUATION_DELIMETERS);

	istringstream iss(replacedText);

	vector<string> words;
	string word;
	while (iss >> word) {
		words.push_back(word);
	}

	return words;
}

bool CheckSimilarWords(const string& inputWord, const string& word, int percentage)
{
	bool areSameLength = inputWord.length() == word.length();
	bool startsWithSameLetter = inputWord[0] == word[0];

	if (!areSameLength || !startsWithSameLetter)
	{
		return false;
	}

	int matchingLetters = 0;
	for (size_t i = 0; i < inputWord.length(); i++)
	{
		if (inputWord[i] == word[i])
		{
			matchingLetters++;
		}
	}

	double percentageMatchingLetters = (matchingLetters * 100.0) / inputWord.length();

	if (percentageMatchingLetters >= percentage)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string text;
	getline(cin, text);

	string inputWord;
	int P;
	cin >> inputWord >> P;

	vector<string> words = SplitTextInWords(text);

	//for (auto& word : words)
	//{
	//	cout << word << endl;
	//}

	int similarWords = 0;
	for (const auto& word : words)
	{
		if (CheckSimilarWords(word, inputWord, P))
		{
			similarWords++;
		}
	}

	cout << similarWords << endl;

	return 0;
}