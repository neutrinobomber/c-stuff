#include <iostream>

using namespace std;

void BinaryInsertionSort(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int begin = 0;
		int end = i;
		int mid = i / 2;

		do
		{
			if (arr[i] > arr[mid])
			{
				begin = mid + 1;
			}
			else if (arr[i] < arr[mid])
			{
				end = mid;
			}
			else
			{
				break;
			}

			mid = (begin + end) / 2;
		} while (begin < end);

		if (mid < i)
		{
			int tmp = arr[i];
			for (int j = i - 1; j >= mid; j--)
			{
				arr[j + 1] = arr[j];
			}

			arr[mid] = tmp;
		}
	}
}

int main()
{
	const int len = 5;
	int arr[len] = { 5, 4, 3, 2, 1 };
	BinaryInsertionSort(arr, len);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}