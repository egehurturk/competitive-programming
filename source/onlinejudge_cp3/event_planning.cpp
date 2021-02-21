#include <iostream>
#include <algorithm>

#define INF 1e9

#define deb(X) cout << #X << " = " << X << endl;
#define ll long long int
using namespace std;

int main(void) {
    int N,B,H, W;
    while (cin >> N >> B >> H >> W) {
        ll budg = INF;
        for (int i = 0; i < H; i++) {
            ll p, maxn = -INF;
            cin >> p;
            for (int j = 0; j < W; j++) {
                ll av;
                cin >> av;
                maxn = max(av, maxn);
            }
            if (maxn >= N) {
                budg = min(budg, N * p);
            }
        }
        if (budg <= B)
            cout << budg << endl;
        else
            cout << "stay home" << endl;
    }
}