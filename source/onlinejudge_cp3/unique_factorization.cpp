/*
 * NOT FINISHED
 */


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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    while ((cin >> n) && n) {
        stack<int> a;
        for(int i=0;i<n;++i) {
            if(n%i==0 && !((i != 1) && (i!=20))) a.push(i);
        }
        // push every factor of n (factor != 1,20) to stack in decreasing order 
        // if n = 20, [(2),4,5,[10]] where [x] is top, (x) is bottom
        int count=0;
        while (!a.empty()) {
            int t=a.pop(); // [(2),4,[5]], t = 10
            int v=n/t; // 2 - 10, 5 - 4
            if (v > t) {;}
            else {
                count++;
                cout << v << " " <<  t;
                if (!isprime(v)) {  

                }  
            }
             

        }
    }
}

bool isprime(int n);