#include <bits/stdc++.h>

using namespace std;

int main() {
    int V;
    scanf("%d", &V);
    int AdjMatrix[V][V];

    /**
     * Input:                                           O(|V^2|)
     */ 
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            scanf("%d", &AdjMatrix[i][j]);
        
    /**
     * Iterating through graph:                         O(|V^2|)
     */  
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++)
            if (AdjMatrix[i][j]) 
                printf("Edge %d-%d (weight = %d)\n", i, j, AdjMatrix[i][j]);

    /**
     * Check for adjacency:                             O(1)
     */ 
    int i = 0, j = 1;
    if (AdjMatrix[i][j])
        printf("Adjacency found\n");
}

/*


0 10 0 0 100 0
10 0 7 0 8 0
0 7 0 9 0 0
0 0 9 0 20 5
100 8 0 20 0 0
[0 0 0 5 0 0]



Input:
6                                                   -> Number of vertices
0 10 0 0 100 0                                      -> Matrix values
10 0 7 0 8 0                                        -> ...
0 7 0 9 0 0                                         -> ...
0 0 9 0 20 5                                        -> ...
100 8 0 20 0 0                                      -> ...  
0 0 0 5 0 0                                         -> ...

Taking input is:
- Scan vertex number
- for i in vertex number:
-       for j in vertex number:
-               scan weight
-               AdjacencyMatrix[i][j] = weight

# O(V^2) where V is vertex number


Accessing all neighbors of Vertex i:
- for i in V:
-       if AdjacencyMatrix[i][j] is not zero:
-           print AdjacencyMatrix[i][j]

# O(V) where V is vertex number

Checking if a vertex V_j is adjacent to Vertex V_i
- if AdjacencyMatrix[i][j] is not zero:
-       print true

# O(1) 

*/