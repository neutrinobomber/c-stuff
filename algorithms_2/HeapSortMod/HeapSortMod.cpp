#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void HeapifyMod(int arr[], int len, int i, int treeSize)
{
	int largest = i;

	for (size_t j = 1; j <= treeSize; j++)
	{
		int branch = treeSize * i + j;

		if (branch < len && arr[branch] > arr[largest])
		{
			largest = branch;
		}
	}

	if (largest != i)
	{
		Swap(arr[i], arr[largest]);

		HeapifyMod(arr, len, largest, treeSize);
	}
}

void HeapSortMod(int arr[], int len, int treeSize)
{
	for (int i = len / treeSize; i >= 0; i--)
	{
		HeapifyMod(arr, len, i, treeSize);
	}

	for (int i = len - 1; i >= 0; i--)
	{
		Swap(arr[0], arr[i]);

		HeapifyMod(arr, i, 0, treeSize);
	}
}

int main()
{
	const int len = 6;
	int arr[len] = { 5, 5, 4, 3, 2, -1 };

	HeapSortMod(arr, len, 3);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}