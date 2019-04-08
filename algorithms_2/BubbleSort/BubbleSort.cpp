#include <iostream>

using namespace std;

void BubbleSort(int arr[], size_t len)
{
	bool swapped = true;
	int iteration = 0;

	while (swapped)
	{
		swapped = false;
		for (size_t i = 0; i < len - iteration - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = true;
			}
		}
		iteration++;
	}
}

int main()
{
	const size_t len = 5;
	int arr[len] = { 5, 4, 3, 2, 1 };
	BubbleSort(arr, len);

	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}