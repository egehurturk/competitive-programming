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
#define deb(X) cout << #X << " = " << X << endl

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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000
#define endl '\n'

int lumberjacks[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    cout << "Lumberjacks:" << endl;
    while (N--) {
        int curr;
        int flag = 0;
        int ascending = 0;
        for (int i = 0; i < 10; ++i) cin >> lumberjacks[i];
        ascending = (lumberjacks[0] < lumberjacks[1]) ? 1 : 0;
        for (int i = 1; i < 10-1; i++) {

            if (ascending == 1 && lumberjacks[i] < lumberjacks[i+1]) {
              ;
            }
            else if (ascending == 0 && lumberjacks[i] > lumberjacks[i+1]) {
                ;
            }
            else {flag = 1; break;}
        }
        
        if (flag) cout << "Unordered" << endl;
        else cout << "Ordered" << endl;
    }
}