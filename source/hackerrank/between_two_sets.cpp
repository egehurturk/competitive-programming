// A very good problem about GCD, LCM, Factorization



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
#define ll long long int

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

ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

ll gcd_v(vector<ll> ar) {
    ll res = ar[0];
    for (ll i = 1; i < ar.size(); i++) {
        res = gcd(ar[i], res);
        if (res == 1) return 1;
    }
    return res;
}

ll lcm_v(vector<ll> arr) 
{ 
    ll ans = arr[0]; 
  
    for (ll i = 1; i < arr.size(); i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 
  

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M; // no of elems in A, B
    cin >> N >> M;
    vector<ll> A;
    vector<ll> B;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    } 
    for (int i = 0; i < M; i++) {
        ll b;
        cin >> b;
        B.push_back(b);
    }
    ll gcd_b = gcd_v(B); // max, bunun seylerinden olmali
    ll lcm_a = lcm_v(A); // min
    int count = 0;
    ll ans = 0;
    for (int i = lcm_a, j = 2; i <= gcd_b; i=lcm_a*j, j++) {
        if (gcd_b % i == 0) 
            ans++;
    }
    cout << ans << endl;

   
}

