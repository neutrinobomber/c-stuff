#include <iostream>

using namespace std;

void InsertionSort(int arr[], size_t len)
{
	int i, key, j;
	for (i = 1; i < len; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

int main()
{
	const size_t len = 5;
	int arr[len] = { 5, 4, 3, 2, 1 };
	InsertionSort(arr, len);

	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}