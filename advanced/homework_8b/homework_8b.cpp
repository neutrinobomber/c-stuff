#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Graph;

void TraverseBFS(int startNode, const Graph& data)
{
	vector<bool> visited(data.size());
	fill(visited.begin(), visited.end(), false);
	queue<int> nodes;

	nodes.push(startNode);
	visited[startNode] = true;

	while (!nodes.empty())
	{
		int node = nodes.front();
		nodes.pop();

		cout << node << " ";

		for (int child : data[node])
		{
			if (!visited[child])
			{
				nodes.push(child);
				visited[child] = true;
			}
		}
	}
}

int main()
{
	Graph graph
	{
		{ 3, 6 },
		{ 2, 3, 4, 5, 6 },
		{ 1, 4, 5 },
		{ 0, 1, 5 },
		{ 1, 2, 6 },
		{ 1, 2, 3 },
		{ 0, 1, 4 }
	};

	TraverseBFS(0, graph);
	cout << endl;

	return 0;
}