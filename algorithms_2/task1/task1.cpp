#include <iostream>

using namespace std;

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

int BinarySearch(int arr[], int len, int search)
{
	int left = 0;
	int right = len - 1;

	while (left <= right)
	{
		int m = left + (right - left) / 2;

		if (arr[m] == search)
		{
			return m;
		}

		if (arr[m] < search)
		{
			left = m + 1;
		}
		else
		{
			right = m - 1;
		}
	}

	return -1;
}

void PrintData(int arr[], int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int firstCount = 0;
	int secondCount = 0;

	cin >> firstCount >> secondCount;

	int* first = new int[firstCount];
	int* second = new int[secondCount];
	int* firstCopy = new int[firstCount];
	int* secondCopy = new int[secondCount];

	for (size_t i = 0; i < firstCount; i++)
	{
		cin >> first[i];
		firstCopy[i] = 0;
	}

	for (size_t i = 0; i < secondCount; i++)
	{
		cin >> second[i];
		secondCopy[i] = 0;
	}

	MergeSort(first, firstCopy, firstCount, 0, firstCount - 1);
	MergeSort(second, secondCopy, secondCount, 0, secondCount - 1);

	int resultLen = firstCount + secondCount;
	int* result = new int[resultLen];
	int* resultCopy = new int[resultLen];
	for (size_t i = 0; i < resultLen; i++)
	{
		result[i] = -1;
		resultCopy[i] = 0;
	}
	int resultIdx = 0;

	for (size_t i = 0; i < firstCount; i++)
	{
		if (BinarySearch(second, secondCount, first[i]) == -1)
		{
			result[resultIdx++] = first[i];
		}
	}

	for (size_t i = 0; i < secondCount; i++)
	{
		if (BinarySearch(first, firstCount, second[i]) == -1)
		{
			result[resultIdx++] = second[i];
		}
	}

	MergeSort(result, resultCopy, resultLen, 0, resultLen - 1);

	for (size_t i = 0; i < resultLen; i++)
	{
		if (result[i] > -1)
		{
			cout << result[i] << " ";
		}
	}

	return 0;
}