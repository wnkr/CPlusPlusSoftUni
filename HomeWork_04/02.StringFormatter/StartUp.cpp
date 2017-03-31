#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StringFormatter
{
private:
	string& stringToFormat;
	string formatPrefix;

public:
	StringFormatter(string& stringToFormat, const string& formatPrefix)
		: stringToFormat(stringToFormat), formatPrefix(formatPrefix)
	{}

	void Format(const vector<string>& insertArr)
	{
		FindAndReplaceWithString(insertArr);
	}

	void Format(const vector<int>& insertArr)
	{
		FindAndReplaceWithInt(insertArr);
	}

private:
	void FindAndReplaceWithString(const vector<string>& insertArr)
	{
		CheckInsertArr(insertArr);

		int foundIndex = this->stringToFormat.find(this->formatPrefix);

		int prefixCharCount = this->formatPrefix.length();

		int prefixCounter = 0;
		while (foundIndex != string::npos)
		{
			if (prefixCounter <= 9)
			{
				this->stringToFormat = this->stringToFormat.replace(foundIndex, prefixCharCount + 1, insertArr[prefixCounter]);
			}
			else if ( 10 <= prefixCounter && prefixCounter <= 99)
			{
				this->stringToFormat = this->stringToFormat.replace(foundIndex, prefixCharCount + 2, insertArr[prefixCounter]);
			}
			else if (100 <= prefixCounter && prefixCounter <= 999)
			{
				this->stringToFormat = this->stringToFormat.replace(foundIndex, prefixCharCount + 3, insertArr[prefixCounter]);
			}

			foundIndex = this->stringToFormat.find(this->formatPrefix);
			prefixCounter++;
		}
	}

	void FindAndReplaceWithInt(const vector<int>& insertArr)
	{
		CheckInsertArr(insertArr);

		int foundIndex = this->stringToFormat.find(this->formatPrefix);

		int prefixCharCount = this->formatPrefix.length();

		int prefixCounter = 0;
		while (foundIndex != string::npos)
		{
			if (prefixCounter <= 9)
			{
				this->stringToFormat = this->stringToFormat.replace(foundIndex, prefixCharCount + 1, std::to_string(insertArr[prefixCounter]));
			}
			else if (10 <= prefixCounter && prefixCounter <= 99)
			{
				this->stringToFormat = this->stringToFormat.replace(foundIndex, prefixCharCount + 2, std::to_string(insertArr[prefixCounter]));
			}
			else if (100 <= prefixCounter && prefixCounter <= 999)
			{
				this->stringToFormat = this->stringToFormat.replace(foundIndex, prefixCharCount + 3, std::to_string(insertArr[prefixCounter]));
			}

			foundIndex = this->stringToFormat.find(this->formatPrefix);
			prefixCounter++;
		}
	}

	int CountPrefixes()
	{
		int foundIndex = this->stringToFormat.find(this->formatPrefix, 0);

		int prefixCounter = 0;
		while (foundIndex != string::npos)
		{
			prefixCounter++;

			foundIndex = this->stringToFormat.find(this->formatPrefix, foundIndex + 1);
		}

		return prefixCounter;
	}

	template<typename T>
	void CheckInsertArr(const vector<T>& insertArr)
	{
		if (insertArr.size() > CountPrefixes())
		{
			throw "the insertArr is bigger than the number of formatPrefixes in the text";
		}
	}
};

int main()
{
	string s1 = "Dear *:0 *:1, Our company *:2 *:3 *:4 *:5 *:6 *:7 wants to make you a Donation Of *:8 Million *:9 in good faith.Please send us a picture of your *:10 card";
	StringFormatter firstFormatter(s1, "*:");

	vector<string> insertArrayStr{ "Ben", "Dover", "Totally", "Legit", "Non", "Spam", "Ltd", "EOOD", "13", "Leva", "credit" };
	firstFormatter.Format(insertArrayStr);
	cout << s1 << endl; //should print “Dear Ben Dover, Our company Totally Legit NonSpam Ltd wants to make you a Donation Of 13 Million Leva in good faith. Please send us a picture of your credit card” 

	string s2 = "Dear {}0, Our company {}1 wants to make you a Donation Of {}2 Million {}3 in good faith.Please send us a picture of your credit card";
	StringFormatter secondFormatter(s2, "{}");

	vector<int> insertArrayInt{ 10, 11, 12, 13 };
	secondFormatter.Format(insertArrayInt);
	cout << s2 << endl;

	return 0;
}