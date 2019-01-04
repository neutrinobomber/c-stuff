#include "pch.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define V 4

int TravllingSalesmanProblem(int graph[][V], int startNode)
{
	// store all vertex apart from source vertex 
	vector<int> nodes;
	for (int currentNode = 0; currentNode < V; currentNode++)
	{
		if (currentNode != startNode)
		{
			nodes.push_back(currentNode);
		}
	}

	// store minimum weight Hamiltonian Cycle. 
	int minPath = INT_MAX;
	do
	{
		// store current Path weight(cost) 
		int currentPathWeight = 0;

		// compute current path weight 
		int currentNode = startNode;
		int nextNode;
		for (int nextIdx = 0; nextIdx < nodes.size(); nextIdx++) 
		{
			nextNode = nodes[nextIdx];
			currentPathWeight += graph[currentNode][nextNode];
			currentNode = nextNode;
		}
		currentPathWeight += graph[currentNode][startNode];

		// update minimum 
		minPath = min(minPath, currentPathWeight);

	} while (next_permutation(nodes.begin(), nodes.end()));

	return minPath;
}

int main()
{
	int graph[][V] = 
	{ 
		{ 0, 10, 15, 20 },
		{ 10, 0, 35, 25 },
		{ 15, 35, 0, 30 },
		{ 20, 25, 30, 0 } 
	};

	int startNode = 0;
	cout << TravllingSalesmanProblem(graph, startNode) << endl;

	return 0;
}