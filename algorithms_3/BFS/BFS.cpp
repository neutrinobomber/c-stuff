#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

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
	TraverseBFS(startNode, graph);
	cout << endl;

	return 0;
}