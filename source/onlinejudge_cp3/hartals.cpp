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
#define maxN 3650
#define maxP 100
#define endl '\n'

int T, N, P;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // friday and saturday -> no hartal
    // start at sunday (1)

    cin >> T;
    while (T--) {
        int  h[maxP], ans = 0, w[maxN]={0};
        cin >> N;
        cin >> P;

        for (int i = 0; i < P; i++) {
            cin >> h[i];
        }

        for (int i = 1; i <= P; i++) {
            for (int j = 0; j < (N / h[i-1]); j++) { 
                w[h[i-1] * (j+1) - 1] = ((h[i-1] * (j+1) - 1) % 7 == 5 || (h[i-1] * (j+1) - 1) % 7 == 6) ? 0 : 1;
            }
        }

        for (int j = 0; j < N; j++) {
            ans += w[j];
        }

        cout << ans << endl;


    }
    
}