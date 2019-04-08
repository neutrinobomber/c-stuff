#include <iostream>

using namespace std;

void IndexSort(int arr[], int temp[], int len)
{
	for (size_t i = 0; i < len; i++)
	{
		temp[arr[i] - 1] = arr[i];
	}

	for (size_t i = 0; i < len; i++)
	{
		arr[i] = temp[i];
	}
}

void IndexSortInPlace(int arr[], int len)
{
	for (size_t i = 1; i <= len; i++)
	{
		arr[i - 1] = i;
	}
}

int main()
{
	const int len = 5;
	int arr[len] = { 5, 4, 3, 2, 1 };
	int temp[len] = { 0 };

	//IndexSort(arr, temp, len);
	IndexSortInPlace(arr, len);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}