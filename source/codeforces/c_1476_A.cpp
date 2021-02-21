#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

#define fill(ar, val) memset(ar, val, sizeof(ar))
#define deb(X) cout << #X << " is " << X << endl

#define uint64 unsigned long long
#define int64 long long
#define ll long long int

#define BIT(n) (1<<(n))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000
#define endl '\n'

// https://codeforces.com/contest/1476/problem/A

void solve(ll n, ll k) {
	if (n % k == 0) 
		cout << n/k << endl;
	else if (n > k) {
		cout << ceil(n / (float) k) << endl;
	} else {
		cout << ceil(k / (float) n) << endl;
	}
}

void solve_t(ll n, ll k) {
    
    ll cf = (n + k - 1) / k;
    k *= cf;
    cout << (k + n - 1) / n << endl;
}

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		ll n, k;
		cin >> n >> k;
		solve(n,k);
		solve_t(n,k);
	}
}
















