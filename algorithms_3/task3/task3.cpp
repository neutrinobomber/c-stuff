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

void printPath(const vector<int>& parent, int current, int startNode)
{
	if (current == startNode)
	{
		return;
	}

	printPath(parent, parent[current], startNode);
	cout << current << " ";
}

void Dijkstra(vector<Edge>& graph, int startNode, int modifier)
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

	cout << startNode << " ";
	printPath(parent, parent.size() - 1, startNode);
	cout << parent.size() - startNode - 1 << endl;
	
	int cost = 0;
	for (size_t i = 1; i < distances.size(); i++)
	{
		if (distances[i] != infinity)
		{
			cost += distances[i] - modifier;
		}
	}
	cout << cost << endl;
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
	int minWeight = infinity;
	vector<Edge> graph;
	set<int> nodes;
	for (size_t i = 1; i <= edgesCount; i++)
	{
		cin >> beginNode >> endNode >> weight;
		nodes.insert(beginNode);
		nodes.insert(endNode);

		if (weight < minWeight)
		{
			minWeight = weight;
		}

		graph.emplace_back(Edge(beginNode, endNode, weight));
	}

	int modifier = 0;
	if (minWeight != infinity && minWeight < 0)
	{
		modifier = (minWeight * (-1)) + 1;
		for (int i = 0; i < graph.size(); i++)
		{
			graph[i].weight += modifier;
		}
	}

	int start = 1;
	cin >> start;
	Dijkstra(graph, start, modifier);

	return 0;
}