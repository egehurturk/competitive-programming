#include<iostream>
#include <queue>
#include <list>

using namespace std;

class Graph
{
	int V; 
	list<int> *adj; 

public:
	Graph(int V); 

	void addEdge(int v, int w); 

	void BFS(int s); 

	void recursiveBFSUtil(queue<int> &q, vector<bool> &discovered);
	void recursiveBFS(int s);
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

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	queue<int> queue;
	visited[s] = true;
	queue.push(s);

	// 'i' will be used to get all adjacent
	// vertices of a vertex
	list<int>::iterator i;

	while(!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push(*i);
			}
		}
	}
}

void Graph::recursiveBFSUtil(queue<int> &q, vector<bool> &discovered) {
	if (q.empty()) 
		return;

	int v = q.front(); q.pop();
	
	cout << v << " ";

	for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++) {
		if (!discovered[*it]) {
			discovered[*it] = true;
			q.push(*it);
		}
	}
	recursiveBFSUtil(q, discovered);
}

void Graph::recursiveBFS(int s) {
	vector<bool> discovered(V, false);
	queue<int> q;
	q.push(2);
	for (int i = 0; i < V; i++) {
        if (discovered[i] == false) {
            discovered[i] = true;
            q.push(i);
            recursiveBFSUtil(q, discovered);
        }
    }
}



int main()
{

	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.addEdge(1, 4);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	cout << "Following is Recursive Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.recursiveBFS(2);

	cout << endl;

	return 0;
}
