#include "pch.h"
#include <iostream>

using namespace std;

const int len = 7;
int arr[len] = { 7, 2, 3, 9, 5, 6, 7 };
int arrCopy[len] = { 0 };

void PrintDataRange(int start, int end)
{
	for (size_t i = start; i <= end; i++)
	{
		cout << arr[i] << " ";
	}
}

void PrintData()
{
	for (auto el : arr)
	{
		cout << el << " ";
	}
	cout << endl;
}

void Merge(int leftStart, int leftEnd, int rightStart, int rightEnd)
{
	cout << "merging ";
	PrintDataRange(leftStart, leftEnd);
	cout << "with ";
	PrintDataRange(rightStart, rightEnd);
	cout << endl;

	int leftIdx = leftStart;
	int rightIdx = rightStart;
	int copyIdx = leftStart;

	while (leftIdx <= leftEnd && rightIdx <= rightEnd)
	{
		if (arr[leftIdx] <= arr[rightIdx])
		{
			arrCopy[copyIdx] = arr[leftIdx];
			leftIdx++;
		}
		else
		{
			arrCopy[copyIdx] = arr[rightIdx];
			rightIdx++;
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

void MergeSort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(left, mid);

		MergeSort(mid + 1, right);
		cout << endl << "emerging!" << endl;
		Merge(left, mid, mid + 1, right);
	}
}

int main()
{
	cout << "unordered data: ";
	PrintData();

	MergeSort(0, len - 1);

	cout << endl << "ordered data: ";
	PrintData();

	return 0;
}