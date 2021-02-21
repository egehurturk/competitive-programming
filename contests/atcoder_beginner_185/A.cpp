#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define arr array

using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    int min = std::min(a1, std::min(a2, std::min(a3, a4)));

    printf("%d\n", min);
}


