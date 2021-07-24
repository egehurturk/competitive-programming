#include <bits/stdc++.h>

using namespace std;

int main() {
    int V, k, id, weight;
    scanf("%d", &V);
    vector<vector<pair<int, int> > > AdjList;
    AdjList.assign(V, vector<pair<int, int> >());

    /**
     * Input for Adjacency List:                            O(V * k)
     */
    for (int i = 0; i < V; i++) {
        scanf("%d", &k); // total neighbors
        for (int j = 0; j < k; j++) {
            scanf("%d %d", &id, &weight);
            AdjList[i].push_back(make_pair(id-1, weight));
        }
    }

    /**
     *  Iterate over all neighbors of Graph:                O(V * k)
     */ 
    for (int i = 0; i < V; i++) {
        for(vector<pair<int, int> >::iterator it = AdjList[i].begin(); it != AdjList[i].end(); it++) {
            printf("Edge %d-%d (weight = %d)\n", i, it->first, it->second);
        }    
    }


    /**
     *  Check for adjacency:                                O(k)
     */
    int i = 2, vj = 2;
    for (vector<pair<int, int> >::iterator ij = AdjList[i].begin(); ij != AdjList[i].end(); ij++) {
        if (ij->first == vj) {
            printf("Adjacency found\n");
        }
    }

    
}

/*

[
    A => < (B, 3), (C, 5) >, 
    B => < (A, 2), (D, 5) >, 
    E => < (D, 6), (C, 2) >,
]


Input:
6                                                   -> Number of vertices
2 2 10 5 100                                        -> 2: number of neighbors (k), rest: [pair<vertex_i, weight_i>]
3 1 10 3 7 5 8                                      ...
2 2 7 4 9                                           ... 
3 3 9 5 20 6 5                                      ...
3 1 100 2 8 4 20                                    ...
1 4 5                                               ... 

Taking input is:
- Scan vertex number
- for i in vertex number:
-       scan neighbor number
-       for j in neighbor number:
-               scan (vertex, weight)
-               push (vertex, weight) into AdjacencyList[i]

# O(V * k) where V is vertex number and k is neighbor number of vertex V_i


Accessing all neighbors of Vertex j:
- for i in AdjacencyList[j]:
-       print j.first, j.second     // j.first is vertex id, j.second is weight

# O(k) where k is number of neighbors of vertex j

Checking if a vertex V_j is adjacent to Vertex V_i
- for i in AdjacencyList[i]:
-       if V_j is i.first:
-           success

# O(k) where k is number of neighbors of vertex i



*/