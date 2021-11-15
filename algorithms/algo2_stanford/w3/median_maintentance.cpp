#include <bits/stdc++.h>

using namespace std;

/**
 * {x1, x2, x3, ..., xn} --> teker teker gelicek
 * 
 * at each step k, mk = median of {x1, x2, ..., xk}
 * if k odd, mk = (k+1) / 2 smallest number of {x1, x2, ..., xk}, else (k)/2th smallest number
 */ 

int main(void) {
    priority_queue<int> h_max;
    priority_queue<int, vector<int>, greater<int>> h_min;
}

