#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

#define ll long long
#define NROAD 1422
#define endl '\n'
#define deb(x) cout << #x << "=" << x << endl
#define all(x) x.begin(), x.end()

using namespace std;



int main(void)
{
    int n, h, v[NROAD+8];
    vector<int> s;

    while (cin >> n && n) {
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        s.assign(v, v+n);
        sort(s.begin(), s.end()); // ?
        // for (vector<int>::iterator i = s.begin(); i != s.end(); i++)
        //     cout << *i << " ";
        // cout << endl;
        int flag = 0;
        // cout << "Distance from end to last station is " << NROAD - s[n] << endl;
        if ((NROAD - s.back()) > 100) flag = 1;  //
        for (int j = 0; j < n-1; j++) {
            // cout << "Distance between 2 stations: " << s[j+1] - s[j] << endl;
            if (s[j+1] - s[j]> 200) {
                flag = 1;
                break;
            }
        }
        //cout << "flag is " << flag << endl;
        if (flag)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << "POSSIBLE" << endl;
    }
}
