#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK
};

class Vertex { 
public:
    int data;
    Color color;
    int dist;
    Vertex(int data, Color color, int dist);
};

Vertex::Vertex(int data, Color color, int dist) {
    this->data = data;
    this->color = color;
    this->dist = dist;
}

class Graph {
int numVertices;
vector<Vertex> *adjList;
bool* visited;

public:
    Graph(int vertices);
    void addEdge(Vertex v, Vertex w);
    void BFS(int s);
};


Graph::Graph(int vertices) {
    numVertices = vertices;
    adjList = new vector<Vertex>[vertices];
}

void Graph::addEdge(Vertex v, Vertex w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

void Graph::BFS(int s) {
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) 
        visited[i] = false;

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        cout << "Visited " << cur << " ";
        q.pop();

        for (vector<int>::iterator i = adjList[cur].begin(); i != adjList[cur].end(); ++i) {
            int adjV = *i;
            if (!visited[adjV]) {
                visited[adjV] = true;
                q.push(adjV);
             }
        }
    }
}


int main(void) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}













