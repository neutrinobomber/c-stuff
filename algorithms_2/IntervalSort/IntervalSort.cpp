#include <iostream>

using namespace std;

int Abs(int number)
{
	if (number < 0)
	{
		return -number;
	}

	return number;
}

void IntervalSort(int arr[], int temp[], int len)
{
	int min = arr[0];
	int max = arr[len - 1];
	for (size_t i = 0; i < len; i++)
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

	int interval = Abs(max - min) / (len - 1);
	for (size_t i = 0; i < len; i++)
	{
		temp[Abs(arr[i] - min) / interval] = arr[i];
	}

	for (size_t i = 0; i < len; i++)
	{
		arr[i] = temp[i];
	}
}

void IntervalSortInPlace(int arr[], int len)
{
	int min = arr[0];
	int max = arr[len - 1];
	for (size_t i = 0; i < len; i++)
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

	int interval = Abs(max - min) / (len - 1);
	for (size_t i = 0; i < len; i++)
	{
		arr[i] = min + interval * i;
	}
}

int main()
{
	const int len = 8;
	int arr[len] = { -2, -4, -6, -8, -10, -12, -14, -16 };
	int temp[len] = { 0 };

	//IntervalSort(arr, temp, len);
	IntervalSortInPlace(arr, len);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}