#include <iostream>

using namespace std;

void binary_insertion_sort(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int begin = 0;
		int end = i;
		int mid = i / 2;

		do
		{
			if (arr[i] > arr[mid])
			{
				begin = mid + 1;
			}
			else if (arr[i] < arr[mid])
			{
				end = mid;
			}
			else
			{
				break;
			}

			mid = (begin + end) / 2;
		} while (begin < end);

		if (mid < i)
		{
			int tmp = arr[i];
			arr[i] = arr[mid];
			arr[mid] = tmp;
		}
	}
}

void linear_equation_system()
{
	const int rows = 3;
	const int cols = 4;
	double equation[rows][cols] =
	{
		{ 2, 1, 0, 134 },
		{ 5, -3, 4, 12 },
		{ 8, 9, 5, -36 }
	};

	for (size_t row = 0; row < rows; row++)
	{
		double div = equation[row][row];
		for (size_t col = row; col < cols; col++)
		{
			equation[row][col] /= div;
		}

		for (size_t r = row + 1; r < rows; r++)
		{
			double mult = equation[r][row];
			for (size_t col = row; col < cols; col++)
			{
				equation[r][col] -= equation[row][col] * mult;
			}
		}
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << equation[i][j] << ", ";
		}
		cout << endl;
	}
}

int main()
{
	const int len = 5;
	int arr[len] = { 8, 7, 1, 3, 4 };

	binary_insertion_sort(arr, len);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}