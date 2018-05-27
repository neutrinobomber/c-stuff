#include <iostream>
#include <cmath>

using namespace std;

void binaryInsertionSort(int arr[], int len)
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

void linearEquationSystem()
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

double f(double a, double b, double c, double x)
{
	// this is a * x * x + b * x + c = 0, but with extracted x
	return -(a * x * x + c) / b;
}

double findRoot(double a, double b, double c, double x, double delta)
{
	double fx = 0, diff = 0;
	unsigned currentIter = 1;
	unsigned maxIter = 1000000;

	do
	{
		fx = f(a, b, c, x);
		diff = fabs(x - fx);
		x = fx;

		currentIter++;
	} while (diff >= delta && currentIter <= maxIter);

	return x;
}

double f2(double x)
{
	double a = 8, b = 7, c = 1, d = 3;
	return a * pow(cos(x), 3) + b * sin(pow(x, 2)) + 1. / 10. * c * x + d;
}

void findRootScan(double start, double end, double spacing)
{
	unsigned rootsFound = 0;
	unsigned rootsToFind = 5;
	double left = 0, right = 0, leftRes = 0, rightRes = 0, mid = 0;

	for (double i = start; i <= end; i += spacing)
	{
		left = i;
		right = i + spacing;
		leftRes = f2(left);
		rightRes = f2(right);

		if (leftRes * rightRes < 0 && rootsFound <= rootsToFind)
		{
			rootsFound++;

			mid = (left + right) / 2;
			cout << "found root:" << endl;
			cout << "    x: " << mid << endl;
			cout << "    f(x): " << f2(mid) << endl;
		}
	}
}

int main()
{
	double start = -20;
	double end = 20;
	double spacing = 0.001;

	cout << "start: " << start << endl
		<< "end: " << end << endl
		<< "spacing: " << spacing << endl << endl;

	findRootScan(start, end, spacing);
	
	return 0;
}