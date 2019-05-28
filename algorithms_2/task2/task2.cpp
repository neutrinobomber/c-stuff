#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void BubbleSort(int arr[], size_t len)
{
	bool swapped = true;
	int iteration = 0;

	while (swapped)
	{
		swapped = false;
		for (size_t i = 0; i < len - 3; i++)
		{
			if (arr[i] < arr[i + 1] && arr[i] < arr[i + 2])
			{
				Swap(arr[i], arr[i + 2]);
				swapped = true;
			}
			if (arr[i + 1] < arr[i] && arr[i + 1] < arr[i + 2])
			{
				Swap(arr[i + 1], arr[i]);
				swapped = true;
			}
			if (arr[i + 2] < arr[i] && arr[i + 2] < arr[i + 1])
			{
				Swap(arr[i + 2], arr[i + 1]);
				swapped = true;
			}
		}
		iteration += 2;
	}
}

int main()
{
	int count = 0;
	cin >> count;
	int* data = new int[count];

	for (size_t i = 0; i < count; i++)
	{
		cin >> data[i];
	}

	BubbleSort(data, count);

	for (size_t i = 0; i < count; i++)
	{
		cout << data[i] << " ";
	}

	return 0;
}