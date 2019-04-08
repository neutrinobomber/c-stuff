#include <iostream>

using namespace std;

void PrintData(int arr[], int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Merge(int arr[], int arrCopy[], int leftStart, int leftEnd, int rightStart, int rightEnd)
{
	int leftIdx = leftStart;
	int rightIdx = rightStart;
	int copyIdx = leftStart;

	while (leftIdx <= leftEnd && rightIdx <= rightEnd)
	{
		if (arr[rightIdx] < arr[leftIdx])
		{
			arrCopy[copyIdx] = arr[rightIdx];
			rightIdx++;
		}
		else
		{
			arrCopy[copyIdx] = arr[leftIdx];
			leftIdx++;
		}

		copyIdx++;
	}

	for (size_t i = rightIdx; i <= rightEnd; i++)
	{
		arrCopy[copyIdx] = arr[i];
		copyIdx++;
	}

	for (size_t i = leftIdx; i <= leftEnd; i++)
	{
		arrCopy[copyIdx] = arr[i];
		copyIdx++;
	}

	for (size_t i = leftStart; i <= rightEnd; i++)
	{
		arr[i] = arrCopy[i];
	}
}

void MergeSort(int arr[], int arrCopy[], int len, int left, int right)
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
	int arr[len] = { 5, 4, 3, 2, 1 };
	int arrCopy[len] = { 0 };

	MergeSort(arr, arrCopy, len, 0, len - 1);
	PrintData(arr, len);

	return 0;
}