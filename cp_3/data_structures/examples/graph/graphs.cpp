#include "/Users/egehurturk/stdc++.h"

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(void) {
    int V /* vertex */, E /* edge */, total_neighbors, id, weight, a, b;

    // ADJACENCY MATRIX
    int AdjMat[100][100];
    // ADJACENCY LIST
    vector<vii> AdjList;
    // EDGE LIST
    priority_queue<pair<int, pair<int, int> > > EdgeList;

    // INPUTS:
    // Adj Matrix
    //      for each line: |V| entries, 0 or the weight
    // Adj List
    //      for each line: num neighbors, list of neighbors + weight pairs
    // Edge List
    //      for each line: a-b of edge(a,b) and weight

    /*
    
    6
        0  10   0   0 100   0
       10   0   7   0   8   0
        0   7   0   9   0   0
        0   0   9   0  20   5
      100   8   0  20   0   0
        0   0   0   5   0   0
    ------------------------------
    6
    2 2 10 5 100
    3 1 10 3 7 5 8
    2 2 7 4 9
    3 3 9 5 20 6 5
    3 1 100 2 8 4 20
    1 4 5
    ------------------------------
    7
    1 2 10
    1 5 100
    2 3 7
    2 5 8
    3 4 9
    4 5 20
    4 6 5
    */
   freopen("in_07.txt", "r", stdin);

   scanf("%d", &V); // scan the size

   // ADJACENCY MATRIX INPUT
   for (int i = 0; i < V; i++) 
       for (int j = 0; j < V; j++) 
           scanf("%d", &AdjMat[i][j]);
    
    printf("Neighbors of vertex 0: \n");
    for (int j = 0; j < V; j++)                                     // O(|V|)
        if (AdjMat[0][j]) // check if edge exists between 0-j
            printf("Edge 0-%d (weight = %d)\n", j, AdjMat[0][j]);


    // ADJACENCY LIST INPUT
    scanf("%d", &V); // scan the size
    AdjList.assign(V, vector<pair<int, int> >()); // initialize AdjList with V entries of vector<pair<int, int>>

    for (int i = 0; i < V; i++) {
        scanf("%d", &total_neighbors); // get total neighbors for vertex i
        for (int j = 0; j < total_neighbors; j++) {
            scanf("%d %d", &id, &weight); // (C, 2) or (B, 5);
            AdjList[i].push_back(make_pair(id-1, weight)); // store in list
        }
    } 
       
    printf("Neighbors for vertex 0: \n");
    for (vector<pair<int, int> >::iterator it = AdjList[0].begin(); it != AdjList[0].end(); it++) 
        // AdjList[0] is [ (C, 2), (B, 5), ... ]
        // it is a pair in the vector
        // O(k) where k is the number of neighbors
        printf("Edge 0-%d (weight = %d)\n", it->first, it->second);



    // EDGE LIST INPUT
    scanf("%d", &E);
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &weight); // (A, B, 2)
        EdgeList.push(make_pair(-weight, make_pair(a,b))); // trick to reverse sort order
    }

    for (int i = 0; i < E; i++) {
        pair<int, pair<int, int> > edge = EdgeList.top(); EdgeList.pop();
        // negate the weight again
        printf("weight: %d (%d-%d)\n", -edge.first, edge.second.first, edge.second.second);
    }
   
    
}