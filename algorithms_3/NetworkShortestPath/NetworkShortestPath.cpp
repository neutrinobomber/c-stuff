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
	for (size_t i = 0; i <= verticesCount; i++)
	{
		cout << i << ": ";
		for (auto vertex : graph[i])
		{
			cout << "(" << vertex.first << ", " << vertex.second << ") ";
		}
		cout << endl;
	}
}

/*
9
14
1 2 2
1 3 3
1 4 4
2 5 3
2 3 1
3 5 3
3 4 2
4 6 5
5 6 1
5 7 5
6 8 6
6 9 6
7 8 1
8 9 1
*/

int main()
{
	int verticesCount = 0;
	cin >> verticesCount;
	vector<pair<int, int>>* graph = new vector<pair<int, int>>[verticesCount + 1];

	int edgesCount = 0;
	cin >> edgesCount;

	int beginNode = 0;
	int endNode = 0;
	int weight = 0;
	for (size_t i = 1; i <= edgesCount; i++)
	{
		cin >> beginNode >> endNode >> weight;
		graph[endNode].push_back(make_pair(beginNode, weight));
	}

	sortGraph(graph, verticesCount);
	printGraph(graph, verticesCount);

	pair<int, int>* shortestPaths = new pair<int, int>[verticesCount + 1];

	for (size_t i = verticesCount; i > 1; i--)
	{
		for (auto vertex : graph[i])
		{
			int weight = vertex.second + shortestPaths[i].second;
			if (weight > shortestPaths[vertex.first].second || shortestPaths[vertex.first].second == 0)
			{
				shortestPaths[vertex.first].first = i;
				shortestPaths[vertex.first].second = weight;
			}
		}
	}

	cout << shortestPaths[1].second << endl;

	cout << 1 << " ";
	int current = 1;
	while (true)
	{
		cout << shortestPaths[current].first << " ";
		current = shortestPaths[current].first;

		if (current == verticesCount)
		{
			break;
		}
	}

	return 0;
}