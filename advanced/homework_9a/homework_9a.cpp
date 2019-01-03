#include "pch.h"

// Александър Янков F87134
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
				distances[otherNode] = newDistance;
				queue.erase(otherNode);
				queue.insert(otherNode);
			}
		}
	}

	for (size_t i = 1; i < distances.size(); i++)
	{
		if (distances[i] == infinity)
		{
			cout << -1 << " ";
		}
		else
		{
			cout << distances[i] << " ";
		}
	}
}

int main()
{
	unsigned edgesCount = 0;

	while (cin >> edgesCount)
	{
		vector<Edge> graph;
		set<int> nodes;

		for (size_t i = 0; i < edgesCount; i++)
		{
			int firstNode = 0;
			int secondNode = 0;
			int weight = 0;

			cin >> firstNode >> secondNode >> weight;

			nodes.insert(firstNode);
			nodes.insert(secondNode);

			graph.emplace_back(Edge(firstNode, secondNode, weight));
		}

		for (auto node : nodes)
		{
			Dijkstra(graph, node);
			cout << endl;
		}
	}

	return 0;
}