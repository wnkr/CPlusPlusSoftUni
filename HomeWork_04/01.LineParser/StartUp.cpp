#include <iostream>
#include <sstream>
#include <vector>

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

vector<int> ParseNumbers(const string& str)
{
	istringstream is(str);

	vector<int> arrayNumbers;
	int number = 0;
	while (is >> number)
	{
		arrayNumbers.push_back(number);
	}

	return arrayNumbers;
}

class LineParser
{
private:
	string line;

public:
	LineParser(const string& line)
		: line(line)
	{

	}

	vector<int> GetNumbers() const
	{
		int numberOfInts = this->line.length();

		vector<int> intArray = ParseNumbers(this->line);

		return intArray;
	}

	vector<string> GetStrings() const
	{
		auto words = SplitTextInWords(this->line);
		int numberOfWords = words.size();

		vector<string> stringArray;
		for (size_t i = 0; i < numberOfWords; i++)
		{
			stringArray.push_back(words[i]);
		}

		return stringArray;
	}

	vector<char> GetChars() const
	{
		int numberOfChars = this->line.length();

		vector<char> charArray;
		for (size_t i = 0; i < numberOfChars; i++)
		{
			if (this->line[i] != ' ')
			{
				charArray.push_back(this->line[i]);
			}
		}

		return charArray;
	}

	void ChangeLine(const string& line)
	{
		this->line = line;
	}
};

template<typename T>
void PrintVector(const vector<T>& vec)
{
	for (const auto& element : vec)
	{
		cout << element << " ";
	}
	cout << endl;
}

int main()
{
	string lineWIthNumbers = "12 3 25";
	LineParser * lineParser = new LineParser(lineWIthNumbers);
	auto intArray = lineParser->GetNumbers();
	PrintVector(intArray);

	string lineWithWords = "wanker,.reknaw!wanker,.reknaw!wanker,.reknaw!wanker,.reknaw!wanker,.reknaw!wanker,.reknaw!wanker,.reknaw!wanker,.reknaw!";
	lineParser->ChangeLine(lineWithWords);
	auto stringArray = lineParser->GetStrings();
	PrintVector(stringArray);

	string lineWithChars = "wanker reknaw";
	lineParser->ChangeLine(lineWithChars);
	auto charArray = lineParser->GetChars();
	PrintVector(charArray);

	return 0;
}