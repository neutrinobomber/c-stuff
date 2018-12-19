#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unordered_map<int, vector<int>> Graph;

void DFS(int node, const Graph& data, unordered_set<int>& visited)
{
	if (visited.find(node) == visited.end())
	{
		visited.insert(node);

		for (int child : data.at(node))
		{
			DFS(child, data, visited);
		}

		cout << node << " ";
	}
}

void TraverseDFS(int startNode, Graph& data)
{
	unordered_set<int> visited;

	DFS(startNode, data, visited);

	for (Graph::iterator iter = data.begin(); iter != data.end(); ++iter)
	{
		int key = iter->first;
		if (visited.find(key) == visited.end())
		{
			DFS(key, data, visited);
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
	Graph graph;

	int edgesCount = 0;
	while (cin >> edgesCount)
	{
		for (size_t i = 0; i < edgesCount; i++)
		{
			int firstNode = 0;
			int secondNode = 0;

			cin >> firstNode >> secondNode;

			InsertEdge(firstNode, secondNode, graph);
			InsertEdge(secondNode, firstNode, graph);
		}

		int startNode = 1 + 87134 % edgesCount;
		TraverseDFS(startNode, graph);
		cout << endl;
	}

	return 0;
}