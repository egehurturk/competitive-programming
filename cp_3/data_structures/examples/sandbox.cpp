#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> dl;
    for (int i = 3; i < 50; i++) {
        dl.push_back(i);
    }
    vector<int>::iterator it = dl.begin();
    // cout << it << endl; // cant print the pointer addr
    cout << *it << endl; 
    // Conclusion: Iterators are actually pointers to the container, which is vector<int> in this case
    // it++ means *(it + 1) which accesses next element in the container

    vector<int> aa{1,2,3,4};
    for (auto i = aa.begin(); i != aa.end(); i++) {
        cout << *i << endl;
    }

}