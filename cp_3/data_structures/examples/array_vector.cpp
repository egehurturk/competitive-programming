#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main(void) {
    // vector <type> variable (elements)
    vector<int> rooms(9);
    vector<int> a(9, 0); // fill with 0's

    cout << a[0] << endl; // access elements of vectors with [] notation

    // iterators: allows you to access data elements in vector
    // vector::begin() returns an iterator to point at the first element of a c++ vector
    // vector::end() returns an iterator to point at past-the-end element of a c++ vector
    // vector::rbegin() reverses the vector
    // vector::rend() same as rbegin


    // modifiers:
    // vector::push_back(3)  pushes element from the back
    // vector::insert() insert new elements to specified location
    // vector::pop_back() remove elements from back
    // vector::erase() removes a range of elements from a specified location
    // vector::clear() removes all elems

    // examples
    vector<int> vecOfInts(5); // 5 integered array, default is 0
    for (int i = 0; i < vecOfInts.size(); i++) // vector.size() returns the number of elements
        cout << vecOfInts[i] << endl;

    string arr[] = {"first", "second", "third", "fourth"};
    vector<string> vecOfStr(arr, arr + sizeof(arr) / sizeof(string)); // construct from array
    for (int i = 0; i < vecOfStr.size(); i++) {
        cout << vecOfStr[i] << endl;
    }

    vector<string> strVec;
    strVec.push_back("first");
    strVec.push_back("sec");
    strVec.push_back("third");

    vector<string> strVec2(strVec); // initialize vector from another vector

    vector<int> myvector1{ 1, 2, 3 };  // initialize vectors with predefined values
    for(int i=0;i<myvector1.size();++i) cout<<myvector1[i]<<endl;

}