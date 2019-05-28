#include <iostream>

using namespace std;

void matrixMult(
	int* first[], 
	int firstRows,
	int firstCols,
	int* second[],
	int secondRows,
	int secondCols, 
	int* result[])
{
	if (firstCols != secondRows)
	{
		return;
	}

	int resultRows = firstRows;
	int resultCols = secondCols;

	for (int firstRow = 0; firstRow < firstRows; firstRow++)
	{
		for (int secondCol = 0; secondCol < secondCols; secondCol++)
		{
			for (int col = 0; col < firstCols; col++)
			{
				result[firstRow][secondCol] += first[firstRow][col] * second[col][secondCol];
			}
		}
	}
}

int** initMatrix(int rows, int cols)
{
	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = 0;
		}
	}

	return arr;
}

void deleteMatrix(int* matrix[], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void printMatrix(int* matrix[], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void fillMatrix(int* matrix[], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = i + j + 1;
		}
	}
}

int main()
{
	int firstRows = 4;
	int firstCols = 4;
	int secondRows = 4;
	int secondCols = 4;

	int** first = initMatrix(firstRows, firstCols);
	int** second = initMatrix(secondRows, secondCols);
	int** result = initMatrix(firstRows, secondCols);

	fillMatrix(first, firstRows, firstCols);
	fillMatrix(second, secondRows, secondCols);

	matrixMult(first, firstRows, firstCols, second, secondRows, secondCols, result);

	printMatrix(first, firstRows, firstCols);
	cout << endl;
	printMatrix(second, secondRows, secondCols);
	cout << endl;
	printMatrix(result, firstRows, secondCols);

	deleteMatrix(first, firstRows);
	deleteMatrix(second, secondRows);
	deleteMatrix(result, firstRows);

	return 0;
}