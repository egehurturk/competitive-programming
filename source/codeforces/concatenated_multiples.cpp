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

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define deb(X) cout << #X << " is " << X << endl

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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000
#define endl '\n'

/*
https://codeforces.com/contest/1029/problem/D
*/

long long int concat(long long int i, long long int j) {
    // conc(i,j) = i * 10^len(j) + j
    // divisible by k <=> [j mod k] + [(i * 10^len(j)) mod k] = {0, k}
    return i * ((int) pow(10, d(j))) + j;
}

long long int d(long long x) {
    long long d = 0;
    while (x) x/=10, d++;
    return d;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int n, k;
    scanf("%lld %lld", &n, &k);
    long long int ai[n+1]; 
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &ai[i]); // integer
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ai[i] == ai[j]) continue;
            string s1 = to_string(ai[i]); 
            string s2 = to_string(ai[j]); 
            // deb(ai[i]);
            // deb(ai[j]);
            string s = s1 + s2;
            long long int c = stoll(s);
            // deb(c);
            if (c % k == 0) count++;
            // deb(count);
        }
    }

    printf("%d\n", count);
}
