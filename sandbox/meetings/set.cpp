#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

/**
 * Insert: log n
 * search: log n
 * 
 */ 

/**
 * 5 5 5 6 7 6 7
 * 
 * 5 3
 * 6 2
 * 7 2
 */ 

#define ll long long

int main(void) {
    int n, each;
    scanf("%d", &n);
    set<ll int> elements;
    vector<int> answer;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &each);
        if (!elements.count(each)) {
            elements.insert(each);
            answer.push_back(each);
        }
    }

    for (int i = 0; i < answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");
}