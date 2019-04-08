#include <iostream>

using namespace std;

void CocktailSort(int arr[], int len)
{
	bool swapped = true;
	int start = 0;
	int end = len - 1;
	int temp = 0;

	while (swapped)
	{
		swapped = false;
		for (int i = start; i < end; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;

				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}

		end -= 1;

		for (int i = end - 1; i >= start; --i)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;

				swapped = true;
			}
		}

		start += 1;
	}
}

int main()
{
	const int len = 5;
	int arr[len] = { 5, 4, 3, 2, 1 };
	CocktailSort(arr, len);

	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}