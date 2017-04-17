#include <iostream>
#include <stack>

using namespace std;

bool CheckBrackets(string& expression)
{
	stack<char> braces;
	for (auto& symbol : expression)
	{
		if (symbol == '(')
		{
			braces.push(symbol);
		}
		else if (symbol == ')')
		{
			if (braces.empty())
			{
				return false;
			}
			braces.pop();
		}
	}

	return braces.empty() ? true : false;
}

int main()
{
	// Examples of correctly placed brackets: ((a+b)/5-d); a+b; a+(b); ((a))
	// Examples of incorrectly placed brackets: ((a+b)/5-d; (a+b; a+b); (a))
	string expression = "(a));";
	cout << CheckBrackets(expression) << endl;
	return 0;
}