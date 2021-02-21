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
#define uint8_t unsigned char
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
#define maxN 2000000
#define endl '\n'

#define R 'R'
#define D 'D'
#define Z 'Z'

int arr[25]={0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    while (cin >> n) {
        int prev = 0;
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == 'B' || n[i] == 'F' || n[i] == 'P' || n[i] == 'V') {if (prev != 1) { cout <<  "1"; } prev = 1;}
            else if (n[i]=='C'||n[i]=='G'||n[i]=='J'||n[i]=='K'||n[i]=='Q'||n[i]=='S'||n[i]=='X'||n[i]=='Z') { if (prev != 2){cout<<"2";}prev = 2;}
            else if (n[i] == 'D' || n[i] == 'T'){ if(prev!=3){cout<<"3";} prev = 3;}
            else if (n[i] == 'L') {if(prev!=4){cout<<"4";}prev=4;}
            else if (n[i] == 'M' || n[i] == 'N') {if(prev!=5){cout<<"5";}prev=5;}
            else if (n[i] == 'R') {if(prev!=6){cout<<"6";}prev=6;}
            else {prev=0;}
        }
        for (int i = 0; i < n.size(); i++) {
            if (arr[i] == 0) {;}
            else cout << arr[i];
        }
        cout << endl;
    }
}

// you can keep track of the previous elem by assigning it to the value as seen in here