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
#define maxN 100000
#define endl '\n'

vector<string> divide(string s, int n) {
    vector<string> p;
    int str_size = s.length();
    int i;
    int part_size = str_size / n;
    for (i=0;i<str_size;i++){
        string new_;
        if (i % part_size == 0) {

        } else {
            new_ += s[i];
        }
        p.push_back(new_);
    }
    return p;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int G;
    string g;

    while (cin >> G && G) {
        cin >> g;
        int len = g.length();
        deb(len);
        int groupLen = G / len;
        deb(groupLen);
        stack<char> groupStack;
        vector<string> group;

        group = divide(g, groupLen);

        for (string s: group) cout << s << " ";
        cout << endl;

        for (vector<string>::iterator it = group.begin(); it != group.end(); it++) {
            string one = *it;
            deb(one);
            for (int i = 0; i < one.length(); i++) {
                deb(one[i]);
                groupStack.push(one[i]);
            }
            for (int i = 0; i < one.length(); i++) {
                char a = groupStack.top(); 
                deb(a);
                groupStack.pop();
                cout << a;
            }
        }
        cout << endl;
    }

}