#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <vector>
#include <limits>
#include <unordered_set>

using namespace std;

typedef vector<vector<unsigned>> Graph;

const unsigned MAX_VALUE = numeric_limits<unsigned>::max();

unsigned minSum;
unsigned curSum;

vector<unsigned> used;
vector<unsigned> cycle;
vector<unsigned> minCycle;

Graph graph;

struct Edge
{
	unsigned from;
	unsigned to;
	unsigned weight;

	Edge(unsigned from, unsigned to, unsigned weight) : 
		from(from), to(to), weight(weight) {}
};

void PrintCycle(unsigned nodesCount)
{
	if (minSum == MAX_VALUE)
	{
		cout << "-1";
		return;
	}

	cout << "1 ";
	for (size_t i = 0; i < nodesCount - 1; i++)
	{
		cout << minCycle[i] + 1 << " ";
	}
}

void Hamilton(unsigned i, unsigned level)
{
	size_t k;
	if ((0 == i) && (level > 0)) 
	{
		if (level == graph.size()) 
		{
			minSum = curSum;
			for (k = 0; k < graph.size(); k++)
			{
				minCycle[k] = cycle[k];
			}
		}
		return;
	}

	if (used[i])
	{
		return;
	}

	used[i] = 1;
	for (k = 0; k < graph.size(); k++)
	{
		if (graph[i][k] && k != i)
		{
			cycle[level] = k;
			curSum += graph[i][k];
			if (curSum < minSum)
			{
				Hamilton(k, level + 1);
			}
			curSum -= graph[i][k];
		}
	}
	used[i] = 0;
}

void Reset()
{
	used = vector<unsigned>(graph.size());
	fill(used.begin(), used.end(), 0);

	cycle = vector<unsigned>(graph.size());
	cycle[0] = 1;

	minCycle = vector<unsigned>(graph.size());

	minSum = MAX_VALUE;
	curSum = 0;
}

void BuildGraph(Graph& graph, const vector<Edge>& edges, unsigned nodesCount)
{
	graph.resize(nodesCount);
	for (size_t i = 0; i < graph.size(); i++)
	{
		graph[i].resize(nodesCount);
		fill(graph[i].begin(), graph[i].end(), 0);
	}

	for (auto edge : edges)
	{
		graph[edge.from - 1][edge.to - 1] = edge.weight;
		graph[edge.to - 1][edge.from - 1] = edge.weight;
	}
}

int main()
{
	unsigned edgesCount = 0;
	while (cin >> edgesCount)
	{
		unordered_set<unsigned> nodes;
		vector<Edge> edges;

		for (size_t i = 0; i < edgesCount; i++)
		{
			unsigned from = 0;
			unsigned to = 0;
			unsigned weight = 0;

			cin >> from >> to >> weight;

			nodes.insert(from);
			nodes.insert(to);

			edges.emplace_back(Edge(from, to, weight));
		}

		BuildGraph(graph, edges, nodes.size());
		Reset();

		Hamilton(0, 0);
		PrintCycle(graph.size());
		cout << endl;
	}

	return 0;
}