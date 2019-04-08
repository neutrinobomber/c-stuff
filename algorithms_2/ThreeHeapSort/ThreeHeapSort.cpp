#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void ThreeHeapify(int arr[], int len, int i)
{
	int largest = i;
	int left = 3 * i + 1;
	int center = 3 * i + 2;
	int right = 3 * i + 3;

	if (left < len && arr[left] > arr[largest])
	{
		largest = left;
	}

	if (right < len && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (center < len && arr[center] > arr[largest])
	{
		largest = center;
	}

	if (largest != i)
	{
		Swap(arr[i], arr[largest]);

		ThreeHeapify(arr, len, largest);
	}
}

void ThreeHeapSort(int arr[], int len)
{
	for (int i = len / 3; i >= 0; i--)
	{
		ThreeHeapify(arr, len, i);
	}

	for (int i = len - 1; i >= 0; i--)
	{
		Swap(arr[0], arr[i]);

		ThreeHeapify(arr, i, 0);
	}
}

int main()
{
	const int len = 6;
	int arr[len] = { 5, 5, 4, 3, 2, -1 };

	ThreeHeapSort(arr, len);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}