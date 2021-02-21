#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

/**
 * Insert: log n
 * search: log n
 */ 

#define ll long long

int main(void) {
    int n, each;
    scanf("%d", &n);
    map<ll int, int> elements;
    vector<int> answer;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &each);
        if (!elements.count(each)) {
            elements.insert(make_pair(each, 1));
            answer.push_back(each);
        } else {
            elements[each]++;
        }
    }

    for (int i = 0; i < answer.size(); ++i) {
        {printf("%d %d\n", answer[i], elements[answer[i]]);}
        
    }
    printf("\n");
}