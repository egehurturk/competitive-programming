#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))
#define deb(X) cout << #X << " = " << X << endl;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000
#define endl '\n'

vector<int> prefix_sum(const vector<int> &A) {
    int n = A.size();
    vector<int> res(n, 0);
    res[0] = A[0];
    for (int i = 1; i < n+1; i++) {
        res[i] = res[i-1] + A[i];
    }
    return res;
}

vector<int> difference_sum(const vector<int> &A) {
    int n = A.size();
    vector<int> res(n-1, 0);
    for (int i = 0; i < n-1; i++) {
        res[i] = A[i+1] - A[i];
    }
    return res;
}

int main(void) {
    vector<int> A;
    for (int i = 0; i < 4; i++) {A.push_back(i);}
    vector<int> prefixSum = prefix_sum(A);
    vector<int> suffixSum = difference_sum(A);
    for (vector<int>::iterator it = prefixSum.begin(); it != prefixSum.end(); it++) {
        cout << *it << " "; 
    }
    cout << endl;
    for (vector<int>::iterator ij = suffixSum.begin(); ij != suffixSum.end(); ij++) {
        cout << *ij << " "; 
    }
    cout << endl;
    
}

// 0 1 2 3
// 0 1 3 6
// 1 1 1