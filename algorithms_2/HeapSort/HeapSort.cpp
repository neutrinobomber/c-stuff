#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Heapify(int arr[], int len, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < len && arr[left] > arr[largest])
	{
		largest = left;
	}

	if (right < len && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		Swap(arr[i], arr[largest]);

		Heapify(arr, len, largest);
	}
}

void HeapSort(int arr[], int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		Heapify(arr, len, i);
	}

	for (int i = len - 1; i >= 0; i--)
	{
		Swap(arr[0], arr[i]);

		Heapify(arr, i, 0);
	}
}

int main()
{
	const int len = 5;
	int arr[len] = { 4, 10, 3, 5, 1 };

	HeapSort(arr, len);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}