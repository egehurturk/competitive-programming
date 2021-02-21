#include <iostream>
#include <cstdio>

#define ll long long
#define arr array

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, T;
    bool flag = true;
    cin >> N >> M >> T;
    int cap = N, prev = 0;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        N -= (a - prev);
        if (N <= 0) flag = false;
        N = min(cap,  N + (b-a));
        prev = b;
    }
    N -= (T - prev);
    if (N <= 0) flag = false;
    if (!flag) cout << "No" << endl;
    else cout << "Yes" << endl;
   
}
