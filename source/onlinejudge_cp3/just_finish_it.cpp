#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)

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
#define maxN 100000
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, tmp;

    cin >> T;

     REPI (case_number, 1, T) {
        cout << "Case " << case_number << ": ";

        vector<int> p, q;

        cin >> N;

        rep (i, N) {
            cin >> tmp;
            p.push_back(tmp);
        }

        rep (i, N) {
            cin >> tmp;
            q.push_back(tmp);
        }

        bool found = false;

        rep (i, N) {
            int petrol = 0;
            int pos = i;
            bool ok = true;

            rep (j, N) {
                petrol += p[pos];
                petrol -= q[pos];
                if (petrol < 0) {
                    ok = false;
                    if (pos < i) i = N;
                    else i = pos;
                    break;
                }
                pos = (pos + 1) % N;
            }

            if (ok) {
                found = true;
                cout << "Possible from station " << i + 1 << endl;
                break;
            }
        }

        if (!found) cout << "Not possible" << endl;
    }
    

}

// NOT SOLVED