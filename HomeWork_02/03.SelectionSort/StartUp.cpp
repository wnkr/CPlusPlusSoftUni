#include <iostream>

using namespace std;

void PrintArray(int arr[], int size);

void SwapInt(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void SelectionSort(int a[], int start, int end)
{
	int currIndex = start;
	while (currIndex < end - 1)
	{
		int smallestNumber = numeric_limits<int>::max();
		int smallestElemIndex = 0;
		for (size_t i = currIndex; i < end; i++)
		{
			if (a[i] < smallestNumber)
			{
				smallestElemIndex = i;
				smallestNumber = a[i];
			}
		}

		if (currIndex != smallestElemIndex)
		{
			SwapInt(a[currIndex], a[smallestElemIndex]);
		}
		currIndex++;
	}
}

void PrintArray(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 33, 1, -2, 0, 25 };

	SelectionSort(arr, 1, 4);
	PrintArray(arr, 5);

	return 0;
}