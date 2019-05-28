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
			int sum = 0;
			for (int col = 0; col < firstCols; col++)
			{
				sum += first[firstRow][col] * second[col][secondCol];
			}

			result[firstRow][secondCol] = sum;
		}
	}
}

int** initMatrix(int rows, int cols)
{
	int** arr = new int* [rows];
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

void copyMatrix(int* from[], int* to[], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			to[i][j] = from[i][j];
		}
	}
}

/*
5
8
1 1 1
1 2 1
2 3 1
2 5 1
3 2 1
3 4 1
4 5 1
5 4 2
*/
void raiseMatrixToPower(int* matrix[], int rows, int cols, int* result[], int power)
{
	if (power > 1)
	{
		matrixMult(matrix, rows, cols, matrix, rows, cols, result);

		if (power > 2)
		{
			int** tempMatrix = initMatrix(rows, cols);
			bool useTemp = true;
			for (int i = 3; i <= power; i++)
			{
				if (useTemp)
				{
					matrixMult(matrix, rows, cols, result, rows, cols, tempMatrix);
					useTemp = false;
				}
				else
				{
					matrixMult(matrix, rows, cols, tempMatrix, rows, cols, result);
					useTemp = true;
				}
			}

			if (!useTemp)
			{
				copyMatrix(tempMatrix, result, rows, cols);
			}

			deleteMatrix(tempMatrix, rows);
		}
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
	int verticesCount = 0;
	cin >> verticesCount;
	verticesCount += 1;
	int** matrix = initMatrix(verticesCount, verticesCount);
	int** result = initMatrix(verticesCount, verticesCount);

	int edgesCount = 0;
	cin >> edgesCount;

	int beginNode = 0;
	int endNode = 0;
	int weight = 0;
	for (int i = 1; i <= edgesCount; i++)
	{
		cin >> beginNode >> endNode >> weight;
		matrix[beginNode][endNode] = weight;
	}

	printMatrix(matrix, verticesCount, verticesCount);

	raiseMatrixToPower(matrix, verticesCount, verticesCount, result, 6);

	cout << endl;
	printMatrix(result, verticesCount, verticesCount);

	deleteMatrix(matrix, verticesCount);
	deleteMatrix(result, verticesCount);

	return 0;
}