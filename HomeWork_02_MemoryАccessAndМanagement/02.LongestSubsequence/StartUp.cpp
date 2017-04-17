#include <iostream>

using namespace std;

void PrintArray(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int* FindLongestSubsequence(int arr[], int size, int& longestSeq)
{
	int currLongestSeq = 1;

	int longestNumber = 0;
	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			currLongestSeq++;
		}
		else
		{
			currLongestSeq = 1;
		}

		if (currLongestSeq > longestSeq)
		{
			longestSeq = currLongestSeq;
			longestNumber = arr[i];
		}
	}

	int* seq = new int[longestSeq];
	for (size_t i = 0; i < longestSeq; i++)
	{
		seq[i] = longestNumber;
	}

	return seq;
}

int main()
{
	const int size = 17;
	int arr[17] = { 1, 1, 1, -2, -2, -2, -2, 3, 3, 3, 4, 0, 0, 0, 0, 0, 0 };

	int longestSeq = 1;
	int* seqAr = FindLongestSubsequence(arr, size, longestSeq);
	PrintArray(seqAr, longestSeq);

	return 0;
}