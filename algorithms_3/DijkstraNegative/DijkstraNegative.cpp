#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
#include <limits>
#include <functional>

using namespace std;

const int infinity = numeric_limits<int>::max();

struct Edge
{
public:
	int first;
	int second;
	int weight;

	Edge(int first, int second, int weight) :
		first(first), second(second), weight(weight) {}
};

void printPath(const vector<int>& parent, int current)
{
	if (current == 1)
	{
		return;
	}

	printPath(parent, parent[current]);
	cout << parent[current] << " ";
}

void Dijkstra(vector<Edge>& graph, int startNode)
{
	set<int> nodes;
	for (auto edge : graph)
	{
		nodes.insert(edge.first);
		nodes.insert(edge.second);
	}

	auto nodesToEdges = unordered_map<int, vector<Edge>>();
	for (Edge edge : graph)
	{
		if (nodesToEdges.find(edge.first) == nodesToEdges.end())
		{
			nodesToEdges[edge.first] = vector<Edge>();
		}

		nodesToEdges[edge.first].push_back(edge);
	}

	vector<int> distances(*nodes.rbegin() + 1);
	vector<int> parent(*nodes.rbegin() + 1);
	fill(distances.begin(), distances.end(), infinity);
	auto start = nodes.begin();
	advance(start, startNode - 1);
	distances[*start] = 0;

	auto cmp = [&distances](int first, int second)
	{
		return distances[first] < distances[second];
	};
	set<int, function<bool(int, int)>> queue(cmp);
	queue.insert(*start);

	while (queue.size() != 0)
	{
		int min = *queue.begin();
		queue.erase(min);

		if (distances[min] == infinity)
		{
			continue;
		}

		for (auto edge : nodesToEdges[min])
		{
			int otherNode = edge.first == min ? edge.second : edge.first;

			if (distances[otherNode] == infinity)
			{
				queue.insert(otherNode);
			}

			int newDistance = distances[min] + edge.weight;
			if (newDistance < distances[otherNode])
			{
				parent[otherNode] = min;
				distances[otherNode] = newDistance;
				queue.erase(otherNode);
				queue.insert(otherNode);
			}
		}
	}

	/*for (size_t i = 1; i < distances.size(); i++)
	{
		if (distances[i] != infinity)
		{
			cout << distances[i] << " ";
		}
	}
	cout << endl;*/
	printPath(parent, parent.size() - 1);
	cout << parent.size() - 1 << " ";
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
	vector<Edge> graph;
	set<int> nodes;
	for (size_t i = 1; i <= edgesCount; i++)
	{
		cin >> beginNode >> endNode >> weight;
		nodes.insert(beginNode);
		nodes.insert(endNode);

		graph.emplace_back(Edge(beginNode, endNode, weight));
	}

	Dijkstra(graph, 1);

	return 0;
}