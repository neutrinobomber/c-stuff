#include <iostream>

using namespace std;

void Partition(int numbers[], int left, int right, int& newLeft, int& newRight)
{
	do
	{
		int picked = numbers[(right + left) / 2];

		newLeft = left;
		while (numbers[newLeft] < picked)
		{
			newLeft++;
		}

		newRight = right;
		while (numbers[newRight] > picked)
		{
			newRight--;
		}

		if (newLeft <= newRight)
		{
			int tmp = numbers[newLeft];
			numbers[newLeft] = numbers[newRight];
			numbers[newRight] = tmp;

			newLeft++;
			newRight--;
		}
	} while (newLeft <= newRight);
}

void QuickSort(int arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int newLeft = 0;
	int newRight = 0;
	Partition(arr, left, right, newLeft, newRight);

	QuickSort(arr, left, newRight);
	QuickSort(arr, newLeft, right);
}

int main()
{
	const int len = 5;
	int arr[len] = { 5, 4, 3, 2, 1 };
	QuickSort(arr, 0, len - 1);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}