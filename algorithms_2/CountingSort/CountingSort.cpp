#include <iostream>

using namespace std;

void CountingSort(int arr[], int len)
{
	int* result = new int[len];

	int min = arr[0];
	int max = arr[len - 1];
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}

		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	int tempLen = max - min + 2;
	int* temp = new int[tempLen];
	for (int i = 0; i < tempLen; ++i)
	{
		temp[i] = 0;
	}

	for (int i = 0; i < len; ++i)
	{
		//temp[arr[i]] += 1;

		temp[arr[i] - min] += 1;
	}

	for (int i = 1; i < tempLen; ++i)
	{
		temp[i] += temp[i - 1];
	}

	for (int i = len - 1; i >= 0; --i)
	{
		/*int tempIdx = arr[i];
		temp[tempIdx] -= 1;
		int resultIdx = temp[tempIdx];
		result[resultIdx] = arr[i];*/

		result[temp[arr[i] - min] - 1] = arr[i];
		temp[arr[i] - min] -= 1;
	}

	for (size_t i = 0; i < len; ++i)
	{
		arr[i] = result[i];
	}
}

int main()
{
	const int len = 8;
	int arr[len] = { -1, -2, -4, 5, -6, 6, 6, 6 };
	
	CountingSort(arr, len);

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}