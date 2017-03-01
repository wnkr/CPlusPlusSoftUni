#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int min = numeric_limits<int>::max();
	int max = numeric_limits<int>::min();

	int number;
	for (size_t i = 0; i < N; i++)
	{
		cin >> number;
		if (number < min)
		{
			min = number;
		}
		if (number > max)
		{
			max = number;
		}
	}

	cout << "Min: " << min << " Max: " << max << endl;

	return 0;
}