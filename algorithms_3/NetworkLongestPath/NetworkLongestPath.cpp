#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}

void sortGraph(vector<pair<int, int>> graph[], int verticesCount)
{
	for (size_t i = 0; i < verticesCount; i++)
	{
		sort(graph[i].begin(), graph[i].end(), compare);
	}
}

void printGraph(vector<pair<int, int>> graph[], int verticesCount)
{
	for (size_t i = 0; i < verticesCount; i++)
	{
		cout << i << ": ";
		for (auto vertex : graph[i])
		{
			cout << "(" << vertex.first << ", " << vertex.second << ") ";
		}
		cout << endl;
	}
}

int main()
{
	const int verticesCount = 9;
	vector<pair<int, int>> graph[verticesCount + 1];

	graph[1] = vector<pair<int, int>>{ make_pair(3, 3), make_pair(4, 4), make_pair(2, 2) };
	graph[2] = vector<pair<int, int>>{ make_pair(5, 3), make_pair(3, 1) };
	graph[3] = vector<pair<int, int>>{ make_pair(5, 3), make_pair(4, 2) };
	graph[4] = vector<pair<int, int>>{ make_pair(6, 5) };
	graph[5] = vector<pair<int, int>>{ make_pair(7, 5), make_pair(6, 1) };
	graph[6] = vector<pair<int, int>>{ make_pair(8, 6), make_pair(9, 6) };
	graph[7] = vector<pair<int, int>>{ make_pair(8, 1) };
	graph[8] = vector<pair<int, int>>{ make_pair(9, 1) };
	graph[9] = vector<pair<int, int>>{ make_pair(9, 0) };

	sortGraph(graph, verticesCount);
	printGraph(graph, verticesCount);

	int longestPaths[verticesCount + 1][2] = { 0 };

	for (size_t i = verticesCount; i > 1; i--)
	{
		int maxWeight = numeric_limits<int>::min();
		for (auto vertex : graph[i - 1])
		{
			int weight = vertex.second + longestPaths[vertex.first][1];
			if (weight > maxWeight || longestPaths[vertex.first] == 0)
			{
				maxWeight = weight;
				longestPaths[i - 1][0] = vertex.first;
				longestPaths[i - 1][1] = weight;
			}
		}
	}

	cout << longestPaths[1][1] << endl;

	int current = 1;
	cout << 1 << " ";
	while (current != verticesCount)
	{
		cout << longestPaths[current][0] << " ";
		current = longestPaths[current][0];
	}
	cout << endl;

	for (auto el : longestPaths)
	{
		cout << el[1] << " ";
	}
	cout << endl;

	return 0;
}