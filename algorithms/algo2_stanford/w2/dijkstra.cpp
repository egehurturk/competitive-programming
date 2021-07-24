#include <bits/stdc++.h>

using namespace std;

/* add_directed_Edge: add the edge (u -> v) to graph adj with weight w */
void add_directed_edge(vector<pair<int, int> > adj[], int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
}

void print_graph(vector<pair<int, int> > adj[], int V) {
    for (int v = 0; v < V; v++) {
        cout << "Adjlist of " << v << ": ";
        for (auto x: adj[v]) {
            cout << x.first << " " << x.second << "\t --> \t";
        }
        cout << endl;
        cout << endl;
        
    }
}


/* dijkstra: Compute the shortest path distances from source vertex s to every other vertices */
// NOTE that this version of dijkstra does not use heap data structure, so the running time is 
// O(mn) where m = |E| and n = |V|. 
vector<int> dijkstra(vector<pair<int, int> > adj[], int V, int s) {
    vector<int> X;  // vertices visited
    vector<int> A(V, -999); // shortest path array
    X.push_back(s);
    A[s] = 0;

    while (X.size() != V) {
        int v_s, w_s, weight, minGreedy = 1e7 + 9;
        for (int v: X) {    
            for (auto neighbor: adj[v]) {
                if (find(X.begin(), X.end(), neighbor.first) == X.end()) {
                    if (A[v] + neighbor.second < minGreedy) {
                        minGreedy = A[v] + neighbor.second;
                        v_s = v, w_s = neighbor.first, weight = neighbor.second;
                    }
                }
            }
        }
        X.push_back(w_s);
        A[w_s] = A[v_s] + weight;
    }
    return A;
}

int main(void) {
    int V = 200;
    // Adjacency list for the graph
    vector<pair<int, int> > adj[V];

    // Read the file and store it in adj
    ifstream file("data.txt");
    string str;
    while (getline(file, str)) {
        istringstream iss(str);
        int vertex_processing;
        iss >> vertex_processing; 
        int neighbor, l;    
        char comma;
        while ( iss >> neighbor >> comma >> l ) {
            add_directed_edge(adj, vertex_processing - 1, neighbor - 1, l);
        }
    }
    file.close();

    // Compute the shortest path distances from vertex 0 to all other vertices
    vector<int> shortest_paths = dijkstra(adj, V, 0);
    int indices[10] = {7, 37, 59, 82, 99, 115, 133, 165, 188, 197};
    for (int i = 0; i < 10; i++) {
        cout << shortest_paths[indices[i]-1] << ", ";
    }
    cout << endl;
}