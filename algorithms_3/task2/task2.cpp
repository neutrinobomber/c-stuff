#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unordered_map<int, vector<int>> Graph;
int counter = 0;

void DFS(Graph& graph, int v)
{
	if (graph.find(v) != graph.end())
	{
		for (int u : graph.at(v))
		{
			DFS(graph, u);
			counter++;
		}
	}
}

void TraverseDFS(int startNode, Graph& data)
{
	DFS(data, startNode);

	/*for (Graph::iterator iter = data.begin(); iter != data.end(); ++iter)
	{
		int key = iter->first;
		DFS(data, key);
	}*/
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
1 2
1 3
1 4
2 5
2 3
3 5
3 4
4 6
5 6
5 7
6 8
6 9
7 8
8 9
*/

/*
7 6
1 2
1 3
2 4
2 5
2 6
3 7
*/
int main()
{
	int verticesCount = 0;
	cin >> verticesCount;
	int edgesCount = 0;
	cin >> edgesCount;

	int beginNode = 0;
	int endNode = 0;
	Graph graph;
	for (size_t i = 1; i <= edgesCount; i++)
	{
		cin >> beginNode >> endNode;
		InsertEdge(beginNode, endNode, graph);
	}

	int startNode = 1;
	TraverseDFS(startNode, graph);
	cout << counter - 2 << endl;

	return 0;
}