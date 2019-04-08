#include <iostream>

using namespace std;

int BinarySearch(int arr[], int len, int search)
{
	int left = 0;
	int right = len - 1;

	while (left <= right)
	{
		int m = left + (right - left) / 2;

		if (arr[m] == search)
		{
			return m;
		}

		if (arr[m] < search)
		{
			left = m + 1;
		}
		else
		{
			right = m - 1;
		}
	}

	return -1;
}

int main()
{
	const int len = 5;
	int arr[len] = { 1, 2, 3, 4, 5 };

	cout << BinarySearch(arr, len, 3);

	return 0;
}