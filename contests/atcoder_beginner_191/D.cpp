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
#define ll long long
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))
#define deb(X) cout << #X << " = " << X << endl;
#define pb push_back

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000
#define endl '\n'

float X, Y, R;

bool checkIfLiesInsideCircle(float x, float y) {
  // center'a uzaklik R den ≤ olmali
  float d = R*R - (sqr(X-x) + sqr(Y-y));
  if (d == 0) {
    return true;
  } else if (d > 0) {
    return true;
  } else {
    return false;
  }
}

float binary_search(float left, float right) {
    if (left == right)
        return left;

    if (left > right) 
        return -1;
    
    float middle = (left+right)/2;
    if (!checkIfLiesInsideCircle(middle)) {
        return binary_search(middle+1, right);
    } else {
        return binary_search(left, middle-1);
    }

      // if we reach here, then element was 
    // not present 
    return -1; 
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> X >> Y >> R;

    int ans = 0;
    int l = 0, r = 0;
   
    // span = R * 2;
   

}

 // while (l <= r) { 
 //        int m = l + (r - l) / 2; 
 //        if (!checkIfLiesInsideCircle(m)) {
 //            l = m + 1; 
 //        } else {
 //          r = m - 1; 
 //        }
  
       
 //    } 
















