#include <bits/stdc++.h>

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

using namespace std;
// https://codeforces.com/contest/1592/problem/A


// O(n)
ll maxv(vector<ll> v, ll *indx) {
    ll max = -99;
    ll ind = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= max) 
            max = v[i];
            ind = i;
    }
    *indx = ind;
    return max;
}


int main(void) {
    int T;
    cin >> T;
    while (T--) {

        int n; ll H; 
        cin >> n >> H;
        vector<ll> damages;
        for (int i = 0; i < n; i++) { // O(n)
            ll a; cin >> a;
            damages.push_back(a);
        }   

        // find max of damages
        ll ind;
        ll x = maxv(damages, &ind);    // O(n)

        // find second max
        damages.erase(damages.begin() + ind);
        ll y = maxv(damages, &ind);    // O(n)
        
        ll ans = 0;
        if (H % (x+y) == 0)
            ans = 2 * H / (x+y);
        else if (H % (x+y) <= x) 
            ans = 2 * (H / (x+y)) + 1;
        else
            ans = 2 * (H / (x+y)) + 2;

        cout << ans << endl;
    }

}


/*
2 4
3 7

[3, 7] --> 4 

[2, 1, 7] --> 11



*/