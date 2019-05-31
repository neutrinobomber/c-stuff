#include <iostream>
#include <limits>

using namespace std;

#define INF 99999 

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

void fillMatrix(int* matrix[], int rows, int cols, int val)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = val;
		}
	}
}

void floydWarshall(int* graph[], int vertexCount)
{
	for (int k = 1; k < vertexCount; k++)
	{
		for (int i = 1; i < vertexCount; i++)
		{
			for (int j = 1; j < vertexCount; j++)
			{
				if (graph[i][k] + graph[k][j] < graph[i][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

int main()
{
	int vertexCount = 0;
	cin >> vertexCount;
	vertexCount += 1;
	int** graph = initMatrix(vertexCount, vertexCount);
	fillMatrix(graph, vertexCount, vertexCount, 0);
	for (int i = 1; i < vertexCount; i++)
	{
		for (int j = 1; j < vertexCount; j++)
		{
			graph[i][j] = INF;
			graph[i][i] = 0;
		}
	}

	int edgesCount = 0;
	cin >> edgesCount;

	int beginNode = 0;
	int endNode = 0;
	int weight = 0;
	for (int i = 1; i <= edgesCount; i++)
	{
		cin >> beginNode >> endNode >> weight;
		graph[beginNode][endNode] = weight;
	}

	int start = 0, end = 0;
	cin >> start >> end;

	floydWarshall(graph, vertexCount);

	cout << graph[start][end - 1] << endl;

	deleteMatrix(graph, vertexCount);

	return 0;
}