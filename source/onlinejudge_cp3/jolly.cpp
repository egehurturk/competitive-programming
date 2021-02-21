#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

#define MAXN 3000
#define endl '\n'

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while (cin >> n) {
        int dif[MAXN + 4] = {0}, flag = 0, seq[MAXN + 5] = {0};
        for (int i = 0; i < n; ++i) 
            cin >> seq[i];
        for (int i = 1; i < n; i++) {
            if (abs(seq[i] - seq[i-1]) < n)
                dif[abs(seq[i] - seq[i-1])]++;
        }
        for (int i = 1; i < n; i++) {
            if (dif[i] == 0) 
                flag = 1;
        }
        if (flag) cout << "Not jolly" << endl;
        
        else cout << "Jolly" << endl; 
    }   
}