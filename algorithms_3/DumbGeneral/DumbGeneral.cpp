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

bool compareWeights(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
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
		graph[beginNode].push_back(make_pair(endNode, weight));
	}

	sortGraph(graph, verticesCount);
	printGraph(graph, verticesCount);

	int startNode = 1;
	int tasksToDo = 4;
	int tasksDone = 0;
	auto current = max_element(graph[startNode].begin(), graph[startNode].end(), compareWeights);
	cout << startNode << " ";
	while (tasksDone < tasksToDo - 1)
	{
		cout << current->first << " ";
		current = max_element(graph[current->first].begin(), graph[current->first].end(), compareWeights);
		tasksDone += 1;
	}
	cout << endl;

	return 0;
}