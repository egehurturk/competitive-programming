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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000
#define endl '\n'

int get_first_digit(int n);
int get_three_dig(int n);


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, s;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        string symbol = "?";
        if (n == "1" || n == "4" || n == "78") symbol = "+";
        else if (n.size() > 1 && n[n.size()-2]=='3' && n[n.size() - 1]=='5') symbol = "-";
        else if (n[0]=='9' && n[n.size()-1]=='4') symbol = '*';
        else if (n.size() > 2 && n[0]=='1' && n[1] == '9' && n[2] == '0') symbol = "?";
        cout << symbol << endl;

    }
}
