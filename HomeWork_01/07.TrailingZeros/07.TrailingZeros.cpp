#include <iostream>

int max = 50000;

void display(int arr[]) 
{
	int ctr = 0;
	for (int i = 0; i < max; i++) {
		if (!ctr && arr[i])         ctr = 1;
		if (ctr)
			std::cout << arr[i];
	}
}

int calculateZeros(int arr[])
{
	int counter = 0;
	for (int i = max - 1; i >= 0; --i) 
	{
		if (arr[i] == 0)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	return counter;
}

void factorial(int arr[], int n) {
	if (!n) return;
	int carry = 0;
	for (int i = max - 1; i >= 0; --i) {
		arr[i] = (arr[i] * n) + carry;
		carry = arr[i] / 10;
		arr[i] %= 10;
	}
	factorial(arr, n - 1);
}

// works for up about N = 4500...
int main() {
	int *arr = new int[max];
	std::memset(arr, 0, max * sizeof(int));
	arr[max - 1] = 1;
	int num;
	std::cout << "Enter the number: ";
	std::cin >> num;
	std::cout << "factorial of " << num << " is ";
	factorial(arr, num);
	display(arr);
	std::cout << std::endl << "The trailing zeros are: " << calculateZeros(arr) << std::endl;
	delete[] arr;
	return 0;
}