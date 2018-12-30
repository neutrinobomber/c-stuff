#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define FN 87134

using namespace std;

typedef unordered_map<int, vector<int>> Graph;

void BFS(int startNode, const Graph& data, unordered_set<int>& visited)
{
	queue<int> nodes;

	if (visited.find(startNode) == visited.end())
	{
		nodes.push(startNode);
		visited.insert(startNode);
	}

	while (!nodes.empty())
	{
		int node = nodes.front();
		nodes.pop();

		cout << node << " ";

		for (int child : data.at(node))
		{
			if (visited.find(child) == visited.end())
			{
				nodes.push(child);
				visited.insert(child);
			}
		}
	}
}

void TraverseBFS(int startNode, Graph& data)
{
	unordered_set<int> visited;

	BFS(startNode, data, visited);

	for (Graph::iterator iter = data.begin(); iter != data.end(); ++iter)
	{
		int key = iter->first;
		if (visited.find(key) == visited.end())
		{
			BFS(key, data, visited);
		}
	}
}

void InsertEdge(int firstNode, int secondNode, Graph& data)
{
	if (data.find(firstNode) != data.end())
	{
		data[firstNode].push_back(secondNode);
	}
	else
	{
		data[firstNode] = vector<int>{ secondNode };
	}
}

int main()
{
	unsigned edgesCount = 0;
	while (cin >> edgesCount)
	{
		Graph graph;

		for (size_t i = 0; i < edgesCount; i++)
		{
			int firstNode = 0;
			int secondNode = 0;

			cin >> firstNode >> secondNode;

			InsertEdge(firstNode, secondNode, graph);
			InsertEdge(secondNode, firstNode, graph);
		}

		int verticesCount = graph.size();
		int startNode = 1 + FN % verticesCount;
		TraverseBFS(startNode, graph);
		cout << endl;
	}

	return 0;
}