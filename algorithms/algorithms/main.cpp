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
			for (int j = i - 1; j >= mid; j--)
			{
				arr[j + 1] = arr[j];
			}
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
	double left = 0, right = 0, leftRes = 0, rightRes = 0, root = 0;

	for (double i = start; i <= end; i += spacing)
	{
		left = i;
		right = i + spacing;
		leftRes = f2(left);
		rightRes = f2(right);

		if (leftRes * rightRes < 0 && rootsFound <= rootsToFind)
		{
			rootsFound++;

			root = (left + right) / 2;
			cout << "found root:" << endl;
			cout << "    x: " << root << endl;
			cout << "    f(x): " << f2(root) << endl;
		}
	}
}

void findRootBinary(double left, double right, double delta)
{
	if (f2(left) * f2(right) < 0)
	{
		bool foundMid = false;
		double mid = 0;
		double distance = 0;

		do
		{
			mid = (left + right) / 2.;

			if (f2(right) * f2(mid) < 0)
			{
				left = mid;
			}
			else
			{
				right = mid;
			}

			foundMid = f2(mid) == 0.;
			distance = fabs(left - right);
		} while (!(distance <= delta || foundMid == true));

		cout << "found root: " << endl
			<< "x: " << mid << endl
			<< "f(x): " << f2(mid) << endl;
	}
	else
	{
		cout << "no roots in interval" << endl;
	}
}

void bubbleSort()
{
	const int len = 5;
	int arr[len] = { 5,4,3,2,1 };
	bool swapped = true;
	int iteration = 0;

	while (swapped)
	{
		swapped = false;
		for (size_t i = 0; i < len - iteration - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = true;
			}
		}
		iteration++;
	}

	cout << iteration << endl;
}

#define LEN 5

void leftDiag(int arr[LEN][LEN])
{
	cout << "left diag: " << endl;
	for (size_t i = 0; i < LEN; i++)
	{
		cout << arr[i][i] << " ";
	}
	cout << endl;
}

void rightDiag(int arr[LEN][LEN])
{
	cout << "right diag: " << endl;
	for (size_t i = 0; i < LEN; i++)
	{
		cout << arr[i][LEN - i - 1] << " ";
	}
	cout << endl;
}

void rightUpper(int arr[LEN][LEN])
{
	cout << "right upper: " << endl;
	for (int i = 0; i < LEN; i++)
		for (int j = 0; j < LEN - i - 1; j++)
			cout << arr[i][j] << " ";
	cout << endl;
}

void leftLower(int arr[LEN][LEN])
{
	cout << "left lower: " << endl;
	for (int i = 0; i < LEN; i++)
		for (int j = 0; j < i; j++)
			cout << arr[i][j] << " ";
	cout << endl;
}

void leftUpper(int arr[LEN][LEN])
{
	cout << "left upper: " << endl;
	for (int i = 0; i < LEN; i++)
		for (int j = i + 1; j < LEN; j++)
			cout << arr[i][j] << " ";
	cout << endl;
}

void rightLower(int arr[LEN][LEN])
{
	cout << "right lower: " << endl;
	for (int i = 0; i < LEN; i++)
		for (int j = LEN - i; j < LEN; j++)
			cout << arr[i][j] << " ";
	cout << endl;
}

int main()
{
	/*double start = -15;
	double end = -14;
	double spacing = 0.001;

	cout << "start: " << start << endl
		<< "end: " << end << endl
		<< "spacing: " << spacing << endl << endl;

	findRootScan(start, end, spacing);

	findRootBinary(-15, -14, 0.001);*/

	/*const int len = 7;
	int arr[len] = { 1, 3, 7, 4, 6, 2, 5 };
	binaryInsertionSort(arr, 7);

	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;*/

	// bubbleSort();
	int arr[LEN][LEN] = 
	{
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 },
		{ 16, 17, 18, 19, 20 },
		{ 21, 22, 23, 24, 25 }
	};

	rightDiag(arr);
	leftDiag(arr);
	leftUpper(arr);
	leftLower(arr);
	rightUpper(arr);
	rightLower(arr);

	return 0;
}