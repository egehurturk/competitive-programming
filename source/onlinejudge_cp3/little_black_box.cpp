#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define FIELDS 7

using namespace std;

typedef struct department {
    string title;
    string first_name;
    string last_name;
    string addr;
    string phone;
    string w_phone;
    string mail;
} department;


int main(void) {
    ios::sync_with_output(0);
    cin.tie(0);
    cout.tie(0);
    vector<department> dps;
    char *o[FIELDS] = malloc(sizeof(string) * FIELDS);
    int n;
    string s;
    cin >> n;
    while (n--) {   
        department dep;
        cin >> s;
        dep.title = s;
        for (int i = 0; i < FIELDS; i++) {
            scanf("%s,", &o[i]);
        }
        dep.first_name = o[0];
        dep.last_nime = o[1];
        dep.addr = o[2];
        dep.phone = o[3];
        dep.w_phone = o[4];
        dep.mail = o[5];

    }

}
    