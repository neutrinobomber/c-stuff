#include <iostream>

using namespace std;

int CompareNumbers(int first[2], int second[2])
{
	double firstConverted = first[0] / (double)first[1];
	double secondConverted = second[0] / (double)second[1];

	if (firstConverted > secondConverted)
	{
		return 1;
	}
	else if (firstConverted < secondConverted)
	{
		return -1;
	}

	return 0;
}

void Merge(int arr[][2], int arrCopy[][2], int leftStart, int leftEnd, int rightStart, int rightEnd)
{
	int leftIdx = leftStart;
	int rightIdx = rightStart;
	int copyIdx = leftStart;

	while (leftIdx <= leftEnd && rightIdx <= rightEnd)
	{
		if (CompareNumbers(arr[rightIdx], arr[leftIdx]) == -1)
		{
			arrCopy[copyIdx][0] = arr[rightIdx][0];
			arrCopy[copyIdx][1] = arr[rightIdx][1];
			rightIdx++;
		}
		else
		{
			arrCopy[copyIdx][0] = arr[leftIdx][0];
			arrCopy[copyIdx][1] = arr[leftIdx][1];
			leftIdx++;
		}

		copyIdx++;
	}

	for (size_t i = rightIdx; i <= rightEnd; i++)
	{
		arrCopy[copyIdx][0] = arr[i][0];
		arrCopy[copyIdx][1] = arr[i][1];
		copyIdx++;
	}

	for (size_t i = leftIdx; i <= leftEnd; i++)
	{
		arrCopy[copyIdx][0] = arr[i][0];
		arrCopy[copyIdx][1] = arr[i][1];
		copyIdx++;
	}

	for (size_t i = leftStart; i <= rightEnd; i++)
	{
		arr[i][0] = arrCopy[i][0];
		arr[i][1] = arrCopy[i][1];
	}
}

void MergeSort(int arr[][2], int arrCopy[][2], int len, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(arr, arrCopy, len, left, mid);
		MergeSort(arr, arrCopy, len, mid + 1, right);

		Merge(arr, arrCopy, left, mid, mid + 1, right);
	}
}

int main()
{
	const int len = 5;
	int arr[len][2] =
	{
		{ 5, 2 },
		{ 3, 2 },
		{ 4, 5 },
		{ 8, 9 },
		{ 10, 6 }
	};
	int arrCopy[len][2] = { 0 };

	MergeSort(arr, arrCopy, len, 0, len - 1);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i][0] / (double)arr[i][1] << ", ";
	}
	cout << endl;

	return 0;
}