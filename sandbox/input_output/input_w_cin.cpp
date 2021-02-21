#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
    // bu satirlar cin ve cout un printf/scanf le 
    // ayni hizda olmasini sagliyo, gerekli.
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number;
    while (cin >> number)
    {
        cout << number & 1 ? "FALSE" : "TRUE"
    }
}