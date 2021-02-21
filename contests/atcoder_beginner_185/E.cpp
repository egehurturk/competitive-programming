#include <iostream>
#include <cstdio>
#include <cmath>
//#include <bitset/stdc++.h>

#define ll long long
#define arr array
#define MAXN 10005 // actually 1000
#define MAXM 1005  // actually 1000

using namespace std;

int A[MAXN], B[MAXM], n, m, dp[MAXN][MAXM]; // uses dynamic programming

int cost(int i, int j) {
    if (i == -1 && j == -1) return 0;
    if (i == -1) return j+1;
    if (j == -1) return i+1;

    if (dp[i][j] != 0) return dp[i][j];

    int u = cost(i-1, j) + 1;
    int v = cost(i, j-1) + 1;
    int w = cost(i-1, j-1) + (A[i] != B[j]);
    return dp[i][j] = min(u, min(v,w));
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m; // get n,m
    for (int i = 0; i < n; i++) { cin >> A[i];}
    for (int j = 0; j < m; j++) { cin >> B[j];  }
    
    cout << cost(n-1, m-1) << endl;
   
}

