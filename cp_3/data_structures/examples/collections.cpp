#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

#define all(S) (S.begin(), S.end())

using namespace std;
typedef struct team {
    int id;
    int solved;
    int penalty;
} team;

bool icpc_cmp(team a, team b) {
    if (a.solved != b.solved) return a.solved > b.solved; // sort by problems solved
    else if (a.penalty != b.penalty) return a.penalty > b.penalty; // sort by penalty
    else return a.id > b.id; // sort by id
}

int main(void) 
{   
    int *pos, arr[] = {10, 7, 2, 15, 4};
    vector<int> v(arr, arr + 5);   // another way of initializing
    vector<int>::iterator j;

    // sort is in <algorithm>
    sort(v.rbegin(), v.rend()); // sort descending with vector, use of reverse iterator

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++ ) {
        printf("%d\n", *it); // access the value of the iterator (pointer)
    }

    // sort descending with int array
    sort(arr, arr+5); // ascending
    reverse(arr, arr+5);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", arr[i]);
    }

    random_shuffle(v.begin(), v.end()); // shuffle the content
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        printf("%d\n", *it);
    }

    // multi-field sorting example
   team nus[4] = { {1, 1, 10}, 
                  {2, 3, 60},
                  {3, 1, 20},
                  {4, 3, 60} };

    for (int i = 0 ; i < 4; i++) {
        printf("id: %d, solved: %d, penalty: %d\n",
           nus[i].id, nus[i].solved, nus[i].penalty);
    }

    sort(nus, nus+4, icpc_cmp); // sort using a helper function
    for (int i = 0; i < 4; i++)
    printf("id: %d, solved: %d, penalty: %d\n",
           nus[i].id, nus[i].solved, nus[i].penalty);

    // binary search using lower-bound
    pos = lower_bound(arr, arr+5,7 ); // returns a pointer
    printf("%d\n", *pos);
    j = lower_bound(v.begin(), v.end(), 7);
    printf("%d\n", *j); // search for 7 in the vector v


}