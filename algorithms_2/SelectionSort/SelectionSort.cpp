#include <iostream>

using namespace std;

void SelectionSort(int data[], size_t len)
{
	int i, j, minIdx;

	for (i = 0; i < len - 1; i++)
	{
		minIdx = i;
		for (j = i + 1; j < len; j++)
		{
			if (data[j] < data[minIdx])
			{
				minIdx = j;
			}
		}

		swap(data[minIdx], data[i]);
	}
}

int main()
{
	const size_t len = 5;
	int arr[len] = { 5, 4, 3, 2, 1 };
	SelectionSort(arr, len);

	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}