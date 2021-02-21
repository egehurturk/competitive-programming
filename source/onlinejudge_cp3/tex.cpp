#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

#define ll long long
#define arr array
#define endl '\n'

using namespace std;

int main(void)
{
    string s;
    bool isFirst(true);
    while (getline(cin, s)) {
        for (string::iterator it = s.begin(); it!=s.end(); it++) {
            if (*it == '"')   {
                if (isFirst)
                    cout << "``";
                else
                    cout << "''";
                isFirst = !isFirst;
                
            }
            else
                cout << *it;
        }
        cout << endl;
    }
 
}