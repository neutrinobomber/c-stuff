#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<vector<int>> Graph;

void DFS(int node, const Graph& data, vector<bool>& visited)
{
	if (node - 1 > data.size() - 1)
	{
		cout << node << " ";
		return;
	}

	if (!visited[node - 1])
	{
		visited[node - 1] = true;

		for (int child : data[node - 1])
		{
			DFS(child, data, visited);
		}

		cout << node << " ";
	}
}

void TraverseDFS(int startNode, const Graph& data)
{
	vector<bool> visited(data.size());
	fill(visited.begin(), visited.end(), false);

	for (size_t el = startNode; el <= data.size(); el++)
	{
		DFS(el, data, visited);
	}
}

int main()
{
	Graph graph;

	int edgesCount = 0;
	while (cin >> edgesCount)
	{
		for (size_t i = 0; i < edgesCount; i++)
		{
			int firstNode = 0;
			int secondNode = 0;

			cin >> firstNode >> secondNode;

			vector<int> edge { firstNode, secondNode };
			graph.push_back(edge);
		}

		int startNode = 1 + 87134 % edgesCount;
		TraverseDFS(startNode, graph);
		cout << endl;
	}

	return 0;
}