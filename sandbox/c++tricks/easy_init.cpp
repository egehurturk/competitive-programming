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
#include <sstream>


using namespace std;
#define endl '\n'

int main(void) {
    pair<int, int> p;
    vector<int> v;
    p = {3,4}; // p = make_pair(3,4);
    v = {4,5};

    pair<int, pair<char, long long> > pj;
    pj = {3, {'a', 8ll}};

    vector<int> vj;
    v = {1, 2, 5, 2};
	for (auto i: v)
	    cout << i << ' ';
	cout << '\n';

	deque<vector<pair<int, int>>> d;
	d = {{{3, 4}, {5, 6}}, {{1, 2}, {3, 4}}};
	for (auto i: d) {
	    for (auto j: i)
	        cout << j.first << ' ' << j.second << '\n';
    cout << "-\n";
}
}

