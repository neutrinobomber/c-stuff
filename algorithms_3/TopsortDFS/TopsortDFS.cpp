#include <iostream> 
#include <list> 
#include <stack> 
using namespace std;

class Graph
{
	int V;

	list<int>* adj;

	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);
public:
	Graph(int V);

	void addEdge(int v, int w);

	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack)
{
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!visited[*i])
		{
			topologicalSortUtil(*i, visited, Stack);
		}
	}

	Stack.push(v);
}

void Graph::topologicalSort()
{
	stack<int> Stack;

	bool* visited = new bool[V];
	for (int i = 1; i < V; i++)
	{
		visited[i] = false;
	}

	for (int i = 1; i < V; i++)
	{
		if (visited[i] == false)
		{
			topologicalSortUtil(i, visited, Stack);
		}
	}

	while (Stack.empty() == false)
	{
		cout << Stack.top() << " ";
		Stack.pop();
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
	Graph g(verticesCount + 1);
	for (size_t i = 1; i <= edgesCount; i++)
	{
		cin >> beginNode >> endNode >> weight;
		g.addEdge(beginNode, endNode);
	}

	g.topologicalSort();

	return 0;
}