#include <iostream>

using namespace std;

bool compArr(int arr1[], int arr2[], int size)
{
	bool areEqual = true;
	for (int i = 0; i < size; i++)
	{
		if (arr1[i] != arr2[i])
		{
			areEqual = false;
			break;
		}
	}

	return areEqual;
}

int main()
{
	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 1, 2, 3 };

	cout << compArr(arr1, arr2, 3) << endl;

	return 0;
}