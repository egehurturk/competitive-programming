#include<iostream>
#include <queue>
#include <list>

using namespace std;

class Graph {
	int V;
	list<int> *adj;
	void dfsUtil(int v, bool visited[]);
public:
	Graph(int V);

	void addEdge(int v, int w);

	void BFS(int s);

	void DFS(int s);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::BFS(int s) {
	bool *visited = new bool[V];
	int *dist = new int[V];
	for (int i = 0; i < V; i++) {
		*(visited + i) = false; 
		*(dist+i) = 1e9;
	}

	
	queue<int> q;
	*(visited + s) = true;
	*(dist + s) = 0;
	q.push(s);

	while (!q.empty()) {
		s = q.front();
		cout << s << " ";;
		q.pop();

		for (list<int>::iterator it = adj[s].begin(); it != adj[s].end(); it++) {
			if (!*(visited + *it)) {
				*(visited + *it) = true;
				*(dist + *it) = *(dist + s) + 1;
				// cout << "Distance: " << *(dist + *it) << endl;
				q.push(*it);
			}
		}
	}
}

void Graph::dfsUtil(int v, bool visited[]) {
	visited[v] = true;
	cout << v << " ";

	for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++) 
		if (!visited[*it])
			dfsUtil(*it, visited);
}

void Graph::DFS(int s) {
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		*(visited+i) = false;

	dfsUtil(s, visited);
}

int main(void) {
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.addEdge(1, 4);
	g.addEdge(4, 1);

	g.BFS(4);
	cout << endl;
	g.DFS(4);
	cout << endl;
}

