#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unordered_map<int, vector<int>> Graph;

void DFS(int startNode, const Graph& data, unordered_set<int>& visited)
{
	stack<int> nodes;

	if (visited.find(startNode) == visited.end())
	{
		nodes.push(startNode);
		visited.insert(startNode);
	}

	while (!nodes.empty())
	{
		int node = nodes.top();
		nodes.pop();

		cout << node << " ";

		if (data.find(node) != data.end())
		{
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
	int edgesCount = 0;
	cin >> edgesCount;

	int beginNode = 0;
	int endNode = 0;
	int weight = 0;
	Graph graph;
	for (size_t i = 1; i <= edgesCount; i++)
	{
		cin >> beginNode >> endNode >> weight;
		InsertEdge(beginNode, endNode, graph);
	}

	int startNode = 1;
	TraverseDFS(startNode, graph);
	cout << endl;

	return 0;
}