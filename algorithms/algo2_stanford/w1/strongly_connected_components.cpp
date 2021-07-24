#include <bits/stdc++.h>

#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y) 
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second


typedef vector<vector<pair<int, ll>> > graph;

using namespace std;

const int MX = 875714;		// maximum no. of nodes in graph
vector<bool> visited(MX+1,0);

graph G(MX+1);	 // (edge, cost) pair	

void dfs(int x) {
	visited[x]=true;

	for (auto& i : G[x]) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n;

	for (int i=0; i<MX+1; i++) {
		G[i].clear();
	}

	fill(all(visited),0);



	for (int i = 1 ; i <= m ; i++) {

		int u,v;
		ll c;
		cin >> u >> v >> c;			// 1 based indexing of nodes
		
		G[u].eb(v,c);
		G[v].eb(u,c);
	

	}
	return 0;
}