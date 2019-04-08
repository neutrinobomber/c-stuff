#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void PrintArr(int arr[], int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void CocktailSort2(int arr[], int len)
{
	int q = (len - 1) / 2;
	bool swapped = false;

	for (int i = 0; i < q; i++)
	{
		int min = i;
		int max = i;

		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}

			if (arr[j] > arr[max])
			{
				max = j;
			}
		}

		if (max != len - 1)
		{
			Swap(arr[len - 1], arr[max]);
		}

		if (min != i)
		{
			Swap(arr[i], arr[min]);
		}

		len -= 1;
	}
}

int main()
{
	const int len = 5;
	int arr[len] = { -5, 4, 3, -2, 1 };
	CocktailSort2(arr, len);

	PrintArr(arr, len);

	return 0;
}